/*
 * Timer.c
 *
 *  Created on: Jul 3, 2019
 *      Author: Ehsan
 */

#include "../Peripherals/Timer.h"

/****************************************************************************/
/**
 *
 * This function sets up the Ticker timer.
 *
 * @param	TtcPsInst is a pointer to the ttc instance.
 * @param	DeviceID is the unique ID for the device.
 * @param	TtcTickIntrID is the unique interrupt ID for the timer.
 * @param	InterruptController is a pointer to the interrupt controller
 *			instance..
 *
 * @return	XST_SUCCESS if everything sets up well, XST_FAILURE otherwise.
 *
 *****************************************************************************/
int SetupTicker(u16 DeviceID, u16 TtcTickIntrID)
{
  int Status;
  TmrCntrSetup *TimerSetup;
  XTtcPs *TtcPsTick;
  XTtcPs *TtcPsInst = &psu_ttc_0;

  TimerSetup = &SettingsTable;
  XScuGic *InterruptController = &intc;

  /*
   * Connect the Intc to the interrupt subsystem such that interrupts can
   * occur.  This function is application specific.
   */
  Status = SetupInterruptSystem(INTC_DEVICE_ID, InterruptController);
  if (Status != XST_SUCCESS) {
      return XST_FAILURE;
  }

  /*
   * Set up appropriate options for Ticker: interval mode without
   * waveform output.
   */
  TimerSetup->Options |= (XTTCPS_OPTION_INTERVAL_MODE |
  XTTCPS_OPTION_WAVE_DISABLE);

  /*
   * Calling the timer setup routine
   *  . initialize device
   *  . set options
   */
  Status = SetupTimer (DeviceID, TtcPsInst);
  if (Status != XST_SUCCESS)
    {
      return Status;
    }

  TtcPsTick = TtcPsInst;

  /*
   * Connect to the interrupt controller
   */
  Status = XScuGic_Connect (InterruptController, TtcTickIntrID, (Xil_InterruptHandler) TickHandler, (void *) TtcPsTick);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }

  /*
   * Enable the interrupt for the Timer counter
   */
  XScuGic_Enable (InterruptController, TtcTickIntrID);

  /*
   * Enable the interrupts for the tick timer/counter
   */
  XTtcPs_EnableInterrupts(TtcPsTick, XTTCPS_IXR_INTERVAL_MASK);

  /*
   * Start the tick timer/counter
   */
  XTtcPs_Start(TtcPsTick);

  return Status;
}
/****************************************************************************/
/**
 *
 * This function sets up a timer counter device, using the information in its
 * setup structure.
 *  . initialize device
 *  . set options
 *  . set interval and prescaler value for given output frequency.
 *
 * @param	DeviceID is the unique ID for the device.
 * @param	TtcPsInst is a pointer to the ttc instance.
 *
 * @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
 *
 *****************************************************************************/
int SetupTimer (u16 DeviceID, XTtcPs *TtcPsInst)
{
  int Status;
  XTtcPs_Config *Config;
  XTtcPs *Timer;
  TmrCntrSetup *TimerSetup;

  TimerSetup = &SettingsTable;

  Timer = TtcPsInst;

  /*
   * Look up the configuration based on the device identifier
   */
  Config = XTtcPs_LookupConfig (DeviceID);
  if (NULL == Config)
    {
      return XST_FAILURE;
    }
  /*
   * Initialize the device
   */
  Status = XTtcPs_CfgInitialize (Timer, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }

  /*
   * Set the options
   */
  XTtcPs_SetOptions (Timer, TimerSetup->Options);

  /*
   * Timer frequency is preset in the TimerSetup structure,
   * however, the value is not reflected in its other fields, such as
   * IntervalValue and PrescalerValue. The following call will map the
   * frequency to the interval and prescaler values.
   */
  XTtcPs_CalcIntervalFromFreq (Timer, TimerSetup->OutputHz,
			       &(TimerSetup->Interval),
			       &(TimerSetup->Prescaler));

  /*
   * Set the interval and prescale
   */
  XTtcPs_SetInterval(Timer, TimerSetup->Interval);
  XTtcPs_SetPrescaler (Timer, TimerSetup->Prescaler);

  return XST_SUCCESS;
}

/****************************************************************************/
/**
 *
 * This function setups the interrupt system such that interrupts can occur.
 * This function is application specific since the actual system may or may not
 * have an interrupt controller.  The TTC could be directly connected to a
 * processor without an interrupt controller.  The user should modify this
 * function to fit the application.
 *
 * @param	IntcDeviceID is the unique ID of the interrupt controller
 * @param	IntcInstacePtr is a pointer to the interrupt controller
 *		instance.
 *
 * @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
 *
 *****************************************************************************/
static int SetupInterruptSystem (u16 IntcDeviceID, XScuGic *IntcInstancePtr)
{
  int Status;
  XScuGic_Config *IntcConfig; /* The configuration parameters of the
   interrupt controller */

  /*
   * Initialize the interrupt controller driver
   */
  IntcConfig = XScuGic_LookupConfig (IntcDeviceID);
  if (NULL == IntcConfig)
    {
      return XST_FAILURE;
    }

  Status = XScuGic_CfgInitialize (IntcInstancePtr, IntcConfig,
				  IntcConfig->CpuBaseAddress);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }

  /*
   * Connect the interrupt controller interrupt handler to the hardware
   * interrupt handling logic in the ARM processor.
   */
  Xil_ExceptionRegisterHandler (XIL_EXCEPTION_ID_IRQ_INT,
				(Xil_ExceptionHandler) XScuGic_InterruptHandler,
				IntcInstancePtr);

  /*
   * Enable interrupts in the ARM
   */
  Xil_ExceptionEnable();

  return XST_SUCCESS;
}

/***************************************************************************/
/**
 *
 * This function is the handler which updates the flag when TTC interrupt is
 * occurred
 *
 * @param	CallBackRef contains a callback reference from the driver, in
 *		this case it is the instance pointer for the TTC driver.
 *
 * @return	None.
 *
 *****************************************************************************/
void TickHandler (void *CallBackRef)
{
  u32 StatusEvent;
  /*
   * Read the interrupt status, then write it back to clear the interrupt.
   */
  StatusEvent = XTtcPs_GetInterruptStatus((XTtcPs * )CallBackRef);
  XTtcPs_ClearInterruptStatus((XTtcPs * )CallBackRef, StatusEvent);

//  printf("X\n");

  XTime_GetTime(&timerEnd);
  //printf("CLK Count : %ld\n", 2 * (timerEnd - timerStart));
  printf("Timer : %.3f us\n", 1.0 * (timerEnd - timerStart) / (COUNTS_PER_SECOND / 1000000));
  XTime_GetTime(&timerStart);

  /*update the flag if interrupt has been occurred*/
  UpdateFlag = TRUE;
}
