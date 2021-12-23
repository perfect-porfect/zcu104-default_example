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
#include <unistd.h>
#include "../../../core0_shared_memory/src/addresses.h"
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <xtime_l.h>
#include <xil_cache.h>

void set_value_core0(int val)
{
	volatile int* new_val = (volatile int*)(FLAG_ADDRESS_CORE0);
	*new_val = val;
}

void wait_for_core0_signal(volatile int val)
{
	volatile int* new_val = (volatile int*)(FLAG_ADDRESS_CORE1);
	while (1) {
		if (*new_val == val)
			break;
	}
}

void start_sample(const int start_core0, const int end_core0)
{
	XTime start, end;
	int counter_to_core0 = start_core0;
	int counter_from_core0 = end_core0;

	while (counter_from_core0 < counter_to_core0) {
		XTime_GetTime(&start);
		wait_for_core0_signal(counter_from_core0);
		set_value_core0(counter_to_core0);
		XTime_GetTime(&end);
//		printf("#%d: CORE1 Output took %.2f us.\n", counter_from_core0,  1.0 * (end - start) / (COUNTS_PER_SECOND/1000000));
		counter_to_core0--;
		counter_from_core0++;
	}
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
	uint32_t array_size = ARRAY_SIZE;
	int half_array_size = array_size / 2;

	printf("Core 1 start\n");
	start_sample(1, 0);

	/*START SUM HALF */
	check_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x01);
	set_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x00);
	volatile array_type* arrays_num = (volatile array_type*)(MASTER_CORE_START_DDR_ADDRESS + 0x50000);
	array_type sum = 0;

	for (int i = 0 ; i < half_array_size; i++)
		sum += arrays_num[i];

	*(volatile array_type*)(FLAG_SUM_VALUE_ADDRESS) = sum;
	set_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x01);
//	printf("1: sum is: %f\n", sum);

	sum = 0;
	/* Start sum even */
	check_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x01);
	set_value_shared(((int*)FLAG_START_PROCESS_CORE_1_ADDRESS), 0x00);
	for (int i = 1 ; i < array_size; i+=2)
		sum += arrays_num[i];

//	printf("2: sum is: %f\n", sum);
	*(volatile array_type*)(FLAG_SUM_VALUE_ADDRESS) = sum;
	set_value_shared(((int*)FLAG_FINISHE_PROCESS_CORE_1_ADDRESS), 0x01);


	cleanup_platform();
	return 0;
}
