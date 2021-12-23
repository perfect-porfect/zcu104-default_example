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
#include "addresses.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <xtime_l.h>
#include <math.h>
#include <stdint.h>

void wait_for_core1_signal(int val)
{
	volatile int* new_val = (volatile int*)(FLAG_ADDRESS_CORE0);
	while (1) {
		if (*new_val == val)
			break;
	}
}

void set_value_core1(volatile int val)
{
	volatile int* new_val = (volatile int*)(FLAG_ADDRESS_CORE1);
	*new_val = val;
}

void start_sample(const int start_core1, const int end_core1)
{
	int counter_to_core1 = start_core1;
	int counter_from_core1 = end_core1;
	XTime start, end;
	while (counter_to_core1 < counter_from_core1) {
		XTime_GetTime(&start);
		set_value_core1(counter_to_core1);
		wait_for_core1_signal(counter_from_core1);
		XTime_GetTime(&end);
//		printf("#%d:  CORE0 Output took %.2f us.\n", counter_to_core1,  1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
		counter_from_core1--;
		counter_to_core1++;
	}
}

float generate_random(float upper)
{
	return (float)((float)rand() / (float)(RAND_MAX) / upper) ;
}

void check_value_shared(int* address, int val)
{
	while(*(volatile int*) address != (volatile int) val);
}

void set_value_shared(int* address, int val)
{
	*(volatile int*) address = (volatile int) val;
}


int main()
{
	init_platform();
	printf("Core 0 start\n");
	start_sample(0, 1);
	set_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x11);
    array_type* arrays_num = (array_type*)(MASTER_CORE_START_DDR_ADDRESS + 0x50000);
	uint32_t array_size = ARRAY_SIZE;
	int half_array_size = ARRAY_SIZE / 2;

	array_type value = 0.0;
	for (int i = 0 ; i < array_size; i++) {
		arrays_num[i] = value; //generate_random(12.32123);
		value += 0.0001;
	}


	/****** Start SUM all array just in core0 *******/
	XTime start, end;
	XTime_GetTime(&start);
	array_type sum = 0;
	for (int i = 0 ; i < array_size; i++)
		sum += arrays_num[i];
	XTime_GetTime(&end);
	long long int * val = (long long int*)(&sum);
	printf("CORE0 all array sum took %.2f us.\nsum is: 0x%x\n",  1.0 * (end - start) / (COUNTS_PER_SECOND/1000000), *val);
	printf("\n\n\n");

	sum = 0;
	for (int i = 0 ; i < array_size; i++) {
		sum += arrays_num[i];
		if (i == half_array_size - 1) {
			printf("First sum half is: ‌0x%x\n", sum);
			sum = 0;
		}
	}

	printf("Second sum half is: ‌0x%x\n", sum);
	printf("\n\n\n");

	memcpy((array_type*)SHM_CORE1_START_ADDRESS, arrays_num, array_size);

	/****** Start SUM half array in core0 and another half in core1 *******/
	array_type main_sum = 0;
	XTime_GetTime(&start);

	set_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x01);
	sum = 0;
	for (int i = half_array_size; i < array_size; i++)
			sum += arrays_num[i];

	check_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x01);
	set_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x00);
	volatile array_type* result = (volatile array_type*)(FLAG_SUM_VALUE_ADDRESS);
	main_sum = (sum + *result);

	XTime_GetTime(&end);
	printf("Two cores sum took: %.2f us.\nHalf sum core0: 0x%x , half sum core1: 0x%x , main_sum: 0x%x\n",  1.0 * (end - start) / (COUNTS_PER_SECOND/1000000), sum, *(volatile array_type*)(FLAG_SUM_VALUE_ADDRESS), main_sum);
	printf("\n\n\n");

	/* Start SUM odd, even */
	sleep(2);
	sum = 0;
	main_sum = 0;
	XTime_GetTime(&start);
	set_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x01);

	for (int i = 0; i < array_size; i+=2)
			sum += arrays_num[i];
	check_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x01);
	main_sum = (sum + *(volatile array_type*)(FLAG_SUM_VALUE_ADDRESS));
	XTime_GetTime(&end);

	printf("Two cores Even & Odd mode took:  %.2f us.\nHalf sum core0: 0x%x , half sum core1: 0x%x , main_sum: 0x%x\n",  1.0 * (end - start) / (COUNTS_PER_SECOND/1000000), sum, *(volatile array_type*)(FLAG_SUM_VALUE_ADDRESS), main_sum);



	cleanup_platform();
	return 0;
}

