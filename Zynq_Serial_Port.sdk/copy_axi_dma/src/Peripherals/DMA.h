/*
 * DMA.h
 *
 *  Created on: Jul 2, 2019
 *      Author: Ehsan
 */

#ifndef SRC_DMA_H_
#define SRC_DMA_H_

#include "../Peripherals/PeripheralCommon.h"
#include "xzdma.h"
#include "xil_cache.h"

#ifdef XPAR_INTC_0_DEVICE_ID
#include "xintc.h"
#else
#include "xscugic.h"
#endif

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#define ZDMA_DEVICE_ID		XPAR_XZDMA_0_DEVICE_ID /* ZDMA device Id */
#ifdef XPAR_INTC_0_DEVICE_ID
#define INTC		XIntc
#define ZDMA_INTC_DEVICE_ID	XPAR_INTC_0_DEVICE_ID
#define ZDMA_INTR_DEVICE_ID	XPAR_INTC_0_ZDMA_0_VEC_ID /**< ZDMA Interrupt Id */
#else
#define INTC		XScuGic
#define ZDMA_INTC_DEVICE_ID	XPAR_SCUGIC_SINGLE_DEVICE_ID
/**< SCUGIC Device ID */
#define ZDMA_INTR_DEVICE_ID	XPAR_XADMAPS_0_INTR /**< ZDMA Interrupt Id */
#endif

typedef enum
{
  DMA_SUCCESS, DMA_READ_ERROR, DMA_WRTE_ERROR, DMA_DRIVER_ERROR, DMA_MODE_CONFIG_ERROR, DMA_INTC_CONNECTION_ERROR
}DMA_Result;

int DMA_Transfer(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done0 = 0;
/* Error status */
volatile static int ErrorStatus0 = 0;
int DMA_Transfer_0(void *dst, void *src, unsigned int size);
int DMA_Transfer_0_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done1 = 0;
/* Error status */
volatile static int ErrorStatus1 = 0;
int DMA_Transfer_1(void *dst, void *src, unsigned int size);
int DMA_Transfer_1_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done2 = 0;
/* Error status */
volatile static int ErrorStatus2 = 0;
int DMA_Transfer_2(void *dst, void *src, unsigned int size);
int DMA_Transfer_2_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done3 = 0;
/* Error status */
volatile static int ErrorStatus3 = 0;
int DMA_Transfer_3(void *dst, void *src, unsigned int size);
int DMA_Transfer_3_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done4 = 0;
/* Error status */
volatile static int ErrorStatus4 = 0;
int DMA_Transfer_4(void *dst, void *src, unsigned int size);
int DMA_Transfer_4_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done5 = 0;
/* Error status */
volatile static int ErrorStatus5 = 0;
int DMA_Transfer_5(void *dst, void *src, unsigned int size);
int DMA_Transfer_5_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done6 = 0;
/* Error status */
volatile static int ErrorStatus6 = 0;
int DMA_Transfer_6(void *dst, void *src, unsigned int size);
int DMA_Transfer_6_Standalone(void *dst, void *src, unsigned int size);

/* Transfer done flag */
volatile static int Done7 = 0;
/* Error status */
volatile static int ErrorStatus7 = 0;
int DMA_Transfer_7(void *dst, void *src, unsigned int size);
int DMA_Transfer_7_Standalone(void *dst, void *src, unsigned int size);

#endif /* SRC_DMA_H_ */
