/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "math/include/mathlib.h"
#include "xtime_l.h"
#include "lut_mat.h"
#include "unistd.h"
#include <arm_neon.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define PI 3.1415926535

#define CALC_COS_ANGLE_MAP(RADIAN) \
		({\
	float ret = -cosf(RADIAN); \
	ret = ANGLE_MAP(ret); \
	ret; \
})

#define ANGLE_MAP(VAL) \
		({\
	float num = VAL; \
	if (num > PI)   \
	num -= 2*PI;   \
	else if (VAL < -PI)   \
	num += PI;   \
	num;\
})

//struct Measured
//{
//    float min;
//    int index;
//};
int test_algorithm(float a0, float a1)
{
	XTime start, end;
	XTime_GetTime(&start);

	float result_mat[LUT_ROW];
	float a2 = ANGLE_MAP(a1 + a0);
	float a3 = ANGLE_MAP(a1 - a0);

	for (int row = 0; row < LUT_ROW; row++) {
		float num0 = LUT_MAT[row][0];
		float num1 = LUT_MAT[row][1];
		float num2 = LUT_MAT[row][2];
		float num3 = LUT_MAT[row][3];

		float ret0 = ANGLE_MAP(num0 * a0);
		float ret1 = ANGLE_MAP(num1 * a1);
		float ret2 = ANGLE_MAP(num2 * a2);
		float ret3 = ANGLE_MAP(num3 * a3);

		ret0 /= ret1;
		ret1 /= ret2;
		ret2 /= ret3;
		ret3 /= ret0;
		float final_ret = ret0 + ret1 + ret2 + ret3;
		result_mat[row] = final_ret;
	}
	int index = 0;
	float min = result_mat[0];
	for (int i = 1; i < LUT_ROW; i++) {
		if (result_mat[i] < min) {
			min = result_mat[i];
			index = i;
		}
	}
	XTime_GetTime(&end);

	printf("Output test_algorithm took %.2f us.\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
	return index;
}



int find_measured_min(float a0, float a1)
{
	XTime start, end;
	XTime_GetTime(&start);

	float result_mat[LUT_ROW];
	float a2 = ANGLE_MAP(a1 + a0);
	float a3 = ANGLE_MAP(a1 - a0);

	for (int row = 0; row < LUT_ROW; row++) {
		float num0 = LUT_MAT[row][0];
		float num1 = LUT_MAT[row][1];
		float num2 = LUT_MAT[row][2];
		float num3 = LUT_MAT[row][3];

		float ret0 = ANGLE_MAP(num0 - a0);
		float ret1 = ANGLE_MAP(num1 - a1);
		float ret2 = ANGLE_MAP(num2 - a2);
		float ret3 = ANGLE_MAP(num3 - a3);

		ret0 = CALC_COS_ANGLE_MAP(ret0);
		ret1 = CALC_COS_ANGLE_MAP(ret1);
		ret2 = CALC_COS_ANGLE_MAP(ret2);
		ret3 = CALC_COS_ANGLE_MAP(ret3);
		float final_ret = ret0 + ret1 + ret2 + ret3;
		result_mat[row] = final_ret;
	}

	/*   Find min   */
	int index = 0;
	float min = result_mat[0];
	for (int i = 1; i < LUT_ROW; i++) {
		if (result_mat[i] < min) {
			min = result_mat[i];
			index = i;
		}
	}

	XTime_GetTime(&end);
	printf("Output normal took %.2f us.\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));

	return index;
}

int find_measured_min_simd(float a0, float a1)
{
	XTime start, end;
	XTime_GetTime(&start);
	float result_mat [LUT_ROW];
	float32x4_t a;
	a[0] = a0;
	a[1] = a1;
	a[2] = ANGLE_MAP(a1 + a0);
	a[3] = ANGLE_MAP(a1 - a0);
	int row = 0;

	for (; row < LUT_ROW; row++) {
		float32x4_t nums;
		nums[0] = LUT_MAT[row][0];
		nums[1] = LUT_MAT[row][1];
		nums[2] = LUT_MAT[row][2];
		nums[3] = LUT_MAT[row][3];
		float32x4_t nums1 = vsubq_f32(nums, a);
		__f32x4_t inputs;
		inputs[0] = ANGLE_MAP(nums1[0]);
		inputs[1] = ANGLE_MAP(nums1[1]);
		inputs[2] = ANGLE_MAP(nums1[2]);
		inputs[3] = ANGLE_MAP(nums1[3]);
		__f32x4_t rets = -__v_cosf(inputs);

		float final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		result_mat[row] = final_ret;
	}

	/*   Find min   */
	int index = 0;
	float min = result_mat[0];
	for (int i = 1; i < LUT_ROW; i++) {
		if (result_mat[i] < min) {
			min = result_mat[i];
			index = i;
		}
	}
	XTime_GetTime(&end);
	printf("Output SIMD took %.2f us.\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
	return index;
}

int find_measured_min_simd_unroll(float a0, float a1)
{
	XTime start, end;
	XTime_GetTime(&start);
	float a2 = ANGLE_MAP(a1 + a0) ;
	float a3 = ANGLE_MAP(a1 - a0);
	float num0;
	float num1;
	float num2;
	float num3;
	float final_ret;
	__f32x4_t inputs;
	__f32x4_t rets;
	num0 = LUT_MAT[0][0];
	num1 = LUT_MAT[0][1];
	num2 = LUT_MAT[0][2];
	num3 = LUT_MAT[0][3];
	inputs[0] = ANGLE_MAP(num0 - a0);
	inputs[1] = ANGLE_MAP(num1 - a1);
	inputs[2] = ANGLE_MAP(num2 - a2);
	inputs[3] = ANGLE_MAP(num3 - a3);
	rets = -__v_cosf(inputs);
	float min_value = rets[0] + rets[1] + rets[2] + rets[3];
	int min_index = 0;
	for (int row = 1; row < LUT_ROW; row +=4) {
		num0 = LUT_MAT[row][0];
		num1 = LUT_MAT[row][1];
		num2 = LUT_MAT[row][2];
		num3 = LUT_MAT[row][3];
		inputs[0] = ANGLE_MAP(num0 - a0);
		inputs[1] = ANGLE_MAP(num1 - a1);
		inputs[2] = ANGLE_MAP(num2 - a2);
		inputs[3] = ANGLE_MAP(num3 - a3);
		rets = -__v_cosf(inputs);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];

		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row;
		}

		num0 = LUT_MAT[row + 1][0];
		num1 = LUT_MAT[row + 1][1];
		num2 = LUT_MAT[row + 1][2];
		num3 = LUT_MAT[row + 1][3];
		inputs[0] = ANGLE_MAP(num0 - a0);
		inputs[1] = ANGLE_MAP(num1 - a1);
		inputs[2] = ANGLE_MAP(num2 - a2);
		inputs[3] = ANGLE_MAP(num3 - a3);
		rets = -__v_cosf(inputs);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row + 1;
		}


		num0 = LUT_MAT[row + 2][0];
		num1 = LUT_MAT[row + 2][1];
		num2 = LUT_MAT[row + 2][2];
		num3 = LUT_MAT[row + 2][3];
		inputs[0] = ANGLE_MAP(num0 - a0);
		inputs[1] = ANGLE_MAP(num1 - a1);
		inputs[2] = ANGLE_MAP(num2 - a2);
		inputs[3] = ANGLE_MAP(num3 - a3);
		rets = -__v_cosf(inputs);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row + 2;
		}


		num0 = LUT_MAT[row + 3][0];
		num1 = LUT_MAT[row + 3][1];
		num2 = LUT_MAT[row + 3][2];
		num3 = LUT_MAT[row + 3][3];
		inputs[0] = ANGLE_MAP(num0 - a0);
		inputs[1] = ANGLE_MAP(num1 - a1);
		inputs[2] = ANGLE_MAP(num2 - a2);
		inputs[3] = ANGLE_MAP(num3 - a3);
		rets = -__v_cosf(inputs);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row + 3;
		}

	}
	XTime_GetTime(&end);
	printf("Output SIMD_Unroll took %.2f us.\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
	return min_index;
}

int find_measured_min_simd_unroll_sub_intrinsic(float a0, float a1)
{
	XTime start, end;
	XTime_GetTime(&start);
	float32x4_t a;
	a[0] = a0;
	a[1] = a1;
	a[2] = ANGLE_MAP(a1 + a0);
	a[3] = ANGLE_MAP(a1 - a0);

	float32x4_t nums;
	float final_ret;
	__f32x4_t rets;
	nums[0] = LUT_MAT[0][0];
	nums[1] = LUT_MAT[0][1];
	nums[2] = LUT_MAT[0][2];
	nums[3] = LUT_MAT[0][3];
	float32x4_t subRes = vsubq_f32(nums, a);
	rets = -__v_cosf(subRes);
	float min_value = rets[0] + rets[1] + rets[2] + rets[3];
	int min_index = 0;
	for (int row = 1; row < LUT_ROW; ) {


		nums[0] = LUT_MAT[row][0];
		nums[1] = LUT_MAT[row][1];
		nums[2] = LUT_MAT[row][2];
		nums[3] = LUT_MAT[row][3];
		subRes = vsubq_f32(nums, a);
		nums[0] = ANGLE_MAP(subRes[0]);
		nums[1] = ANGLE_MAP(subRes[1]);
		nums[2] = ANGLE_MAP(subRes[2]);
		nums[3] = ANGLE_MAP(subRes[3]);
		//		rets = -__v_cosf(nums);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];

		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row;
		}


		row++;
		nums[0] = LUT_MAT[row][0];
		nums[1] = LUT_MAT[row][1];
		nums[2] = LUT_MAT[row][2];
		nums[3] = LUT_MAT[row][3];
		subRes = vsubq_f32(nums, a);
		nums[0] = ANGLE_MAP(subRes[0]);
		nums[1] = ANGLE_MAP(subRes[1]);
		nums[2] = ANGLE_MAP(subRes[2]);
		nums[3] = ANGLE_MAP(subRes[3]);
		//		rets = -__v_cosf(nums);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row;
		}

		row++;
		nums[0] = LUT_MAT[row][0];
		nums[1] = LUT_MAT[row][1];
		nums[2] = LUT_MAT[row][2];
		nums[3] = LUT_MAT[row][3];
		subRes = vsubq_f32(nums, a);
		nums[0] = ANGLE_MAP(subRes[0]);
		nums[1] = ANGLE_MAP(subRes[1]);
		nums[2] = ANGLE_MAP(subRes[2]);
		nums[3] = ANGLE_MAP(subRes[3]);
		//		rets = -__v_cosf(nums);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row;
		}

		row++;
		nums[0] = LUT_MAT[row][0];
		nums[1] = LUT_MAT[row][1];
		nums[2] = LUT_MAT[row][2];
		nums[3] = LUT_MAT[row][3];
		subRes = vsubq_f32(nums, a);
		nums[0] = ANGLE_MAP(subRes[0]);
		nums[1] = ANGLE_MAP(subRes[1]);
		nums[2] = ANGLE_MAP(subRes[2]);
		nums[3] = ANGLE_MAP(subRes[3]);
		//		rets = -__v_cosf(nums);
		final_ret = rets[0] + rets[1] + rets[2] + rets[3];
		if (final_ret < min_value) {
			min_value = final_ret;
			min_index = row;
		}
		row++;
	}
	XTime_GetTime(&end);
	printf("Output SIMD_Unroll took %.2f us.\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
	return min_index;
}

uint32_t find_min(float* _BUF, uint32_t _S_IDX, uint32_t _E_IDX, float _VAL)
{
	typeof(*(_BUF))* eafi_buf = (_BUF);
	uint32_t eafi_mIdx = (_E_IDX) * 0.5F;
	uint32_t eafi_sIdx = (_S_IDX);
	uint32_t eafi_eIdx = (_E_IDX);

	while (eafi_sIdx < eafi_eIdx)
	{
		eafi_mIdx = (eafi_sIdx + eafi_eIdx) * 0.5F;
		if ((_VAL) < eafi_buf[eafi_mIdx])
			eafi_eIdx = eafi_mIdx - 1;
		else
			eafi_sIdx = eafi_mIdx + 1;
	}

	/* eafi_mIdx is the index of nearest element to input */
	return eafi_mIdx;
}


uint32_t binarySearch(float arr[], uint32_t start, uint32_t end, float x)
{
	uint32_t m ;
    float last_val;
    while (start <= end) {
        m = start + (end - start) / 2;
        last_val = arr[m];

        if (arr[m] == x)
            return m;

        if (x > last_val)
            start = m + 1;
        else
            end = m - 1;
    }
    float diff_start = fabs(x - arr[start]);
    float diff_end = fabs(x - arr[end]);
    if (diff_start > diff_end)
        return end;
    else
        return start;
}

uint32_t new_algorithm(float a0, float a1)
{

	XTime start, end;
	XTime_GetTime(&start);
	float a2, a3;
	a2 = ANGLE_MAP(a1 + a0);
	a3 = ANGLE_MAP(a1 - a0);
	float all_cos_sum = cosf(a1)+ cosf(a0)+ cosf(a2)+ cosf(a3);
	uint32_t index = binarySearch(lookup_distance_values, 0, LUT_ROW - 1,  all_cos_sum);

	XTime_GetTime(&end);
	printf("Output for distance algorithm took %.2f us. and index is: %d\n", 1.0 * (end - start) / (COUNTS_PER_SECOND/1000000), index);
	return index;
}

float generate_random(float upper)
{
	return (float)((float)rand() / (float)(RAND_MAX) / upper) ;
}

int main()
{
	init_platform();
	for (int row = 0 ; row < LUT_ROW; row++) {
		for (int col = 0 ; col < LUT_COL; col++) {
			LUT_MAT[row][col] = LUT_MAT[row][col] * PI /180.0;
		}
	}
//	int ret_std1 = find_measured_min(-124.56 * PI /180.0 , 123.22 * PI /180.0);
//	int ret_simd1 = find_measured_min_simd(-124.56 * PI /180.0 , 123.22 * PI /180.0);
//	int ret_std2 = find_measured_min(-135.01 * PI /180.0 , 118.47 * PI /180.0);
//	int ret_simd2 = find_measured_min_simd(-135.01 * PI /180.0 , 118.47 * PI /180.0);

	int ret_stdtest = test_algorithm(-124.56 * PI /180.0 , 123.22 * PI /180.0);

	//	int ret_simd_unroll1 = find_measured_min_simd_unroll(-124.56 * PI /180.0 , 123.22 * PI /180.0);
	//	int ret_simd_unroll2 = find_measured_min_simd_unroll(-135.01 * PI /180.0 , 118.47 * PI /180.0);
	//	int ret_simd_unroll3 = find_measured_min_simd_unroll(23.423 * PI /180.0 , -22.061 * PI /180.0);
	//	int ret_simd_unroll4 = find_measured_min_simd_unroll(26.698 * PI /180.0 , -15.96 * PI /180.0);

//	int ret_simd_unroll3 = find_measured_min_simd_unroll_sub_intrinsic(23.423 * PI /180.0 , -22.061 * PI /180.0);
//	int ret_simd_unroll4 = find_measured_min_simd_unroll_sub_intrinsic(26.698 * PI /180.0 , -15.96 * PI /180.0);
//
//	for (int i = 0 ; i < 1000; i++) {
//		float rand_num1 =  generate_random(1.998783452);
//		float rand_num2 =  generate_random(1.998783452);
//		uint32_t index = new_algorithm(rand_num1, rand_num2);
//		printf("%d \n", index);
//	}
//

	printf("ret for test algorithm: %d \n", ret_stdtest);

//	printf("ret for normal mode: %d &  %d\n" , ret_std1, ret_std2);
//	printf("ret for SIMD mode: %d &  %d\n" , ret_simd1, ret_simd2);
//	printf("ret for SIMD_Unroll mode for worst case: %d &  %d\n" , ret_simd_unroll3, ret_simd_unroll4);
//
//	while(1) {
//		sleep(10);
//	}

	cleanup_platform();
	return 0;
}
