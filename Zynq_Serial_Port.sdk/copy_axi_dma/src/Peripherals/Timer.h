/*
 * Timer.h
 *
 *  Created on: Jul 3, 2019
 *      Author: Ehsan
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_

#include <stdio.h>
#include <stdlib.h>

#include "../Peripherals/PeripheralCommon.h"
#include "xparameters.h"
#include "xstatus.h"
#include "xil_io.h"
#include "xil_exception.h"
#include "xttcps.h"
#include "xscugic.h"
#include "xil_printf.h"


#define INTC_DEVICE_ID		XPAR_SCUGIC_0_DEVICE_ID
/* Tick timer counter's output frequency */
#define	TICK_TIMER_FREQ_HZ	100

/**************************** Type Definitions *******************************/
typedef struct {
	u32 OutputHz;		/* Output frequency */
	XInterval Interval;	/* Interval value */
	u8 Prescaler;		/* Prescaler value */
	u16 Options;		/* Option settings */
} TmrCntrSetup;

/* Set up routines for timer counters */
int SetupTicker(u16 DeviceID, u16 TtcTickIntrID);

static int SetupTimer(u16 DeviceID, XTtcPs *TtcPsInst);

static int SetupInterruptSystem(u16 IntcDeviceID, XScuGic *IntcInstancePtr);

static void TickHandler(void *CallBackRef);

/* Ticker timer counter initial setup, only output freq */
static TmrCntrSetup SettingsTable = {TICK_TIMER_FREQ_HZ, 0, 0, 0};

/* Flag to update the seconds counter */
static volatile u8 UpdateFlag;

static XTime timerStart = 0, timerEnd;

#endif /* SRC_TIMER_H_ */
