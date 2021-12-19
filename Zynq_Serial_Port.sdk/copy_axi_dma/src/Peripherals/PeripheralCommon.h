/*
 * PeripheralCommon.h
 *
 *  Created on: Jul 3, 2019
 *      Author: Ehsan
 */

#ifndef SRC_PERIPHERALS_PERIPHERALCOMMON_H_
#define SRC_PERIPHERALS_PERIPHERALCOMMON_H_

#include "xtime_l.h"
#include "xparameters.h"
#include "xttcps.h"
#include "xil_cache.h"

#ifdef XPAR_INTC_0_DEVICE_ID
#include "xintc.h"
#else
#include "xscugic.h"
#endif

extern XScuGic intc;

extern XTtcPs psu_ttc_0;

void PeripheralDestructor(void);

#endif /* SRC_PERIPHERALS_PERIPHERALCOMMON_H_ */
