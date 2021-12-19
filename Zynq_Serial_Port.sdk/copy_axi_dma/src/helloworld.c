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
#include "xtime_l.h"
#include <unistd.h>
#include "Peripherals/DMA.h"
#include <stdlib.h>

#define START_AXI_ADDRESS (0x00000000)
#define AXI_SIZE_BUFFER (4096)
void read_from_axi(int num)
{
//    uint32_t *src = (uint32_t*)START_AXI_ADDRESS;
	int * src = (int*)malloc(AXI_SIZE_BUFFER);
	XTime tStart, tEnd;
	int * dst = (int*)malloc(AXI_SIZE_BUFFER);
	for (int i = 0 ; i < AXI_SIZE_BUFFER /4; i++)
		src[i] = 2020;
	XTime_GetTime(&tStart);
//	memcpy(dst, src, AXI_SIZE_BUFFER);

	DMA_Transfer_0_Standalone(dst, src, AXI_SIZE_BUFFER);


	XTime_GetTime(&tEnd);
	for (int i = 0; i < AXI_SIZE_BUFFER / 4; i++)
//		if (dst[i] != src[i])
			printf("dst[%d] = %d src[%d] = %d\n\t", i, dst[i], i, src[i]);
	float elapsed = 1.0 * (tEnd - tStart) / (COUNTS_PER_SECOND/1000000);
	printf("A5: Output took %.2f us.\n", elapsed);

}

int main()
{
    init_platform();
    int counter = 0;
    while (1) {
    	printf("hello world #%d\n", counter++);
    	sleep(1);
    }
    for (int i = 0 ; i < 1 ; i++) {
       read_from_axi(i);
    }

    cleanup_platform();
    return 0;
}
