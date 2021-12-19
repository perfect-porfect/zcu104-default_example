/*
 * PeripheralCommon.c
 *
 *  Created on: Jul 3, 2019
 *      Author: Ehsan
 */

#include "../Peripherals/PeripheralCommon.h"

XScuGic intc;

XTtcPs psu_ttc_0;

void PeripheralDestructor(void)
{
    /* Stop timer if its started */
    if(XTtcPs_IsStarted(&psu_ttc_0))
      XTtcPs_Stop(&psu_ttc_0);

    /* Disable Cache */
//    Xil_DCacheDisable();
//    Xil_ICacheDisable();
}
