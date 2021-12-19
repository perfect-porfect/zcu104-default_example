/*
 * DMA.c
 *
 *  Created on: Jul 2, 2019
 *      Author: Ehsan
 */

#include "../Peripherals/DMA.h"

static int  SetupInterruptSystem(INTC *IntcInstancePtr, XZDma *InstancePtr, u16 IntrId);

int DMA_Transfer(void *dst, void *src, unsigned int size)
{
  int sizeDiv = size / 8;
  DMA_Transfer_0(((char*)src) + (0 * sizeDiv), ((char*)dst) + (0 * sizeDiv), sizeDiv);
  DMA_Transfer_1(((char*)src) + (1 * sizeDiv), ((char*)dst) + (1 * sizeDiv), sizeDiv);
  DMA_Transfer_2(((char*)src) + (2 * sizeDiv), ((char*)dst) + (2 * sizeDiv), sizeDiv);
  DMA_Transfer_3(((char*)src) + (3 * sizeDiv), ((char*)dst) + (3 * sizeDiv), sizeDiv);
  DMA_Transfer_4(((char*)src) + (4 * sizeDiv), ((char*)dst) + (4 * sizeDiv), sizeDiv);
  DMA_Transfer_5(((char*)src) + (5 * sizeDiv), ((char*)dst) + (5 * sizeDiv), sizeDiv);
  DMA_Transfer_6(((char*)src) + (6 * sizeDiv), ((char*)dst) + (6 * sizeDiv), sizeDiv);
  DMA_Transfer_7(((char*)src) + (7 * sizeDiv), ((char*)dst) + (7 * sizeDiv), sizeDiv);

//  while(Done0 != 1);

  while(Done0 != 1 || Done1 != 1 || Done2 != 1 || Done3 != 1 || Done4 != 1 || Done5 != 1 || Done6 != 1 || Done7 != 1);

  Done0 = 0;
  Done1 = 0;
  Done2 = 0;
  Done3 = 0;
  Done4 = 0;
  Done5 = 0;
  Done6 = 0;
  Done7 = 0;

  return XST_SUCCESS;
}

static XZDma psu_gdma_0;
static void DoneHandler0(void *CallBackRef);
static void ErrorHandler0(void *CallBackRef, u32 Mask);
int DMA_Transfer_0(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_0_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_0, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_0, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_0, XZDMA_HANDLER_DONE, (void *) DoneHandler0, &psu_gdma_0);
  XZDma_SetCallBack (&psu_gdma_0, XZDMA_HANDLER_ERROR, (void *) ErrorHandler0, &psu_gdma_0);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_0, XPAR_PSU_GDMA_0_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_0, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_0, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start(&psu_gdma_0, &Data, 1);

  return DMA_SUCCESS;
}
int DMA_Transfer_0_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_0(src, dst, size);

  while(Done0 != 1);

  Done0 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus0)
    {
      if (ErrorStatus0 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus0 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_1;
static void DoneHandler1(void *CallBackRef);
static void ErrorHandler1(void *CallBackRef, u32 Mask);
int DMA_Transfer_1(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_1_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_1, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_1, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_1, XZDMA_HANDLER_DONE, (void *) DoneHandler1, &psu_gdma_1);
  XZDma_SetCallBack (&psu_gdma_1, XZDMA_HANDLER_ERROR, (void *) ErrorHandler1, &psu_gdma_1);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_1, XPAR_PSU_GDMA_1_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_1, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_1, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_1, &Data, 1);

  return DMA_SUCCESS;
}
int DMA_Transfer_1_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_1(src, dst, size);

  while(Done1 != 1);

  Done1 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus1)
    {
      if (ErrorStatus1 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus1 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_2;
static void DoneHandler2(void *CallBackRef);
static void ErrorHandler2(void *CallBackRef, u32 Mask);
int DMA_Transfer_2(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_2_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_2, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_2, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_2, XZDMA_HANDLER_DONE, (void *) DoneHandler2, &psu_gdma_2);
  XZDma_SetCallBack (&psu_gdma_2, XZDMA_HANDLER_ERROR, (void *) ErrorHandler2, &psu_gdma_2);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_2, XPAR_PSU_GDMA_2_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_2, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_2, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_2, &Data, 1);

  return XST_SUCCESS;
}
int DMA_Transfer_2_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_2(src, dst, size);

  while(Done2 != 1);

  Done2 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus2)
    {
      if (ErrorStatus2 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus2 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_3;
static void DoneHandler3(void *CallBackRef);
static void ErrorHandler3(void *CallBackRef, u32 Mask);
int DMA_Transfer_3(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_3_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_3, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_3, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_3, XZDMA_HANDLER_DONE, (void *) DoneHandler3, &psu_gdma_3);
  XZDma_SetCallBack (&psu_gdma_3, XZDMA_HANDLER_ERROR, (void *) ErrorHandler3, &psu_gdma_3);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_3, XPAR_PSU_GDMA_3_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_3, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_3, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_3, &Data, 1);

  return XST_SUCCESS;
}
int DMA_Transfer_3_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_3(src, dst, size);

  while(Done3 != 1);

  Done3 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus3)
    {
      if (ErrorStatus3 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus3 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_4;
static void DoneHandler4(void *CallBackRef);
static void ErrorHandler4(void *CallBackRef, u32 Mask);
int DMA_Transfer_4(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_4_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_4, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_4, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_4, XZDMA_HANDLER_DONE, (void *) DoneHandler4, &psu_gdma_4);
  XZDma_SetCallBack (&psu_gdma_4, XZDMA_HANDLER_ERROR, (void *) ErrorHandler4, &psu_gdma_4);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_4, XPAR_PSU_GDMA_4_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_4, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_4, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_4, &Data, 1);

  return XST_SUCCESS;
}
int DMA_Transfer_4_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_4(src, dst, size);

  while(Done4 != 1);

  Done4 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus4)
    {
      if (ErrorStatus4 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus4 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_5;
static void DoneHandler5(void *CallBackRef);
static void ErrorHandler5(void *CallBackRef, u32 Mask);
int DMA_Transfer_5(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_5_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_5, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_5, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_5, XZDMA_HANDLER_DONE, (void *) DoneHandler5, &psu_gdma_3);
  XZDma_SetCallBack (&psu_gdma_5, XZDMA_HANDLER_ERROR, (void *) ErrorHandler5, &psu_gdma_3);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_5, XPAR_PSU_GDMA_5_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_5, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_5, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_5, &Data, 1);

  return XST_SUCCESS;
}
int DMA_Transfer_5_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_5(src, dst, size);

  while(Done5 != 1);

  Done5 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus5)
    {
      if (ErrorStatus5 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus5 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_6;
static void DoneHandler6(void *CallBackRef);
static void ErrorHandler6(void *CallBackRef, u32 Mask);
int DMA_Transfer_6(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_6_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_6, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_6, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_6, XZDMA_HANDLER_DONE, (void *) DoneHandler6, &psu_gdma_6);
  XZDma_SetCallBack (&psu_gdma_6, XZDMA_HANDLER_ERROR, (void *) ErrorHandler6, &psu_gdma_6);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_6, XPAR_PSU_GDMA_6_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_6, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_6, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_6, &Data, 1);

  return DMA_SUCCESS;
}
int DMA_Transfer_6_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_6(src, dst, size);

  while(Done6 != 1);

  Done6 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus6)
    {
      if (ErrorStatus6 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus6 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

static XZDma psu_gdma_7;
static void DoneHandler7(void *CallBackRef);
static void ErrorHandler7(void *CallBackRef, u32 Mask);
int DMA_Transfer_7(void *dst, void *src, unsigned int size)
{
  int Status;
  XZDma_Config *Config;
  XZDma_DataConfig Configure; /* Configuration values */
  XZDma_Transfer Data;

  /*
   * Initialize the ZDMA driver so that it's ready to use.
   * Look up the configuration in the config table,
   * then initialize it.
   */
  Config = XZDma_LookupConfig (XPAR_PSU_GDMA_7_DEVICE_ID);
  if (NULL == Config)	return DMA_DRIVER_ERROR;

  Status = XZDma_CfgInitialize (&psu_gdma_7, Config, Config->BaseAddress);
  if (Status != XST_SUCCESS)	return DMA_DRIVER_ERROR;

  /*
   * Invalidating destination address and flushing
   * source address in cache
   */
  if (!Config->IsCacheCoherent)
    {
      Xil_DCacheFlushRange ((INTPTR) src, size);
      Xil_DCacheInvalidateRange ((INTPTR) dst, size);
    }

  /* ZDMA has set in simple transfer of Normal mode */
  Status = XZDma_SetMode (&psu_gdma_7, FALSE, XZDMA_NORMAL_MODE);
  if (Status != XST_SUCCESS)	return DMA_MODE_CONFIG_ERROR;

  /* Interrupt call back has been set */
  XZDma_SetCallBack (&psu_gdma_7, XZDMA_HANDLER_DONE, (void *) DoneHandler7, &psu_gdma_7);
  XZDma_SetCallBack (&psu_gdma_7, XZDMA_HANDLER_ERROR, (void *) ErrorHandler7, &psu_gdma_7);

  /* Connect to the interrupt controller. */
  Status = SetupInterruptSystem (&intc, &psu_gdma_7, XPAR_PSU_GDMA_7_INTR);
  if (Status != XST_SUCCESS)	return DMA_INTC_CONNECTION_ERROR;

  /* Enable required interrupts */
  XZDma_EnableIntr(&psu_gdma_7, (XZDMA_IXR_ALL_INTR_MASK));

  /* Configuration settings */
  Configure.OverFetch = 1;
  Configure.SrcIssue = 0x1F;
  Configure.SrcBurstType = XZDMA_INCR_BURST;
  Configure.SrcBurstLen = 0xF;
  Configure.DstBurstType = XZDMA_INCR_BURST;
  Configure.DstBurstLen = 0xF;
  Configure.SrcCache = 0x2;
  Configure.DstCache = 0x2;
  if (Config->IsCacheCoherent)
    {
      Configure.SrcCache = 0xF;
      Configure.DstCache = 0xF;
    }
  Configure.SrcQos = 0;
  Configure.DstQos = 0;

  XZDma_SetChDataConfig (&psu_gdma_7, &Configure);

  /*
   * Transfer elements
   */
  Data.DstAddr = (UINTPTR) dst;
  Data.DstCoherent = 1;
  Data.Pause = 0;
  Data.SrcAddr = (UINTPTR) src;
  Data.SrcCoherent = 1;
  Data.Size = size; /* Size in bytes */

  /* Initiates the data transfer */
  XZDma_Start (&psu_gdma_7, &Data, 1);

  return DMA_SUCCESS;
}
int DMA_Transfer_7_Standalone(void *dst, void *src, unsigned int size)
{
  int DMA_Result = DMA_Transfer_7(src, dst, size);

  while(Done7 != 1);

  Done7 = 0;

  /* More error can be extracted with other MASKs defined in DMA library */
  if (ErrorStatus7)
    {
      if (ErrorStatus7 & XZDMA_IXR_AXI_WR_DATA_MASK)
	return DMA_WRTE_ERROR;
      if (ErrorStatus7 & XZDMA_IXR_AXI_RD_DATA_MASK)
	return DMA_READ_ERROR;
    }

  return DMA_Result;
}

/*****************************************************************************/
/**
 * This function sets up the interrupt system so interrupts can occur for the
 * ZDMA. This function is application-specific. The user should modify this
 * function to fit the application.
 *
 * @param	IntcInstancePtr is a pointer to the instance of the INTC.
 * @param	InstancePtr contains a pointer to the instance of the ZDMA
 *		driver which is going to be connected to the interrupt
 *		controller.
 * @param	IntrId is the interrupt Id and is typically
 *		XPAR_<ZDMA_instance>_INTR value from xparameters.h.
 *
 * @return
 *		- XST_SUCCESS if successful
 *		- XST_FAILURE if failed
 *
 * @note		None.

 *
 ****************************************************************************/
int SetupInterruptSystem(INTC *IntcInstancePtr, XZDma *InstancePtr, u16 IntrId)
{
  int Status;

#ifdef XPAR_INTC_0_DEVICE_ID
#ifndef TESTAPP_GEN
  /* Initialize the interrupt controller and connect the ISRs */
  Status = XIntc_Initialize(IntcInstancePtr, ZDMA_INTC_DEVICE_ID);
  if (Status != XST_SUCCESS)
    {

      xil_printf("Failed init intc\r\n");
      return XST_FAILURE;
    }
#endif
  /*
   * Connect the driver interrupt handler
   */
  Status = XIntc_Connect(IntcInstancePtr, IntrId,
      (XInterruptHandler)XZDma_IntrHandler, InstancePtr);
  if (Status != XST_SUCCESS)
    {

      xil_printf("Failed connect intc\r\n");
      return XST_FAILURE;
    }
#ifndef TESTAPP_GEN
  /*
   * Start the interrupt controller such that interrupts are enabled for
   * all devices that cause interrupts.
   */
  Status = XIntc_Start(IntcInstancePtr, XIN_REAL_MODE);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }
#endif

  /*
   * Enable the interrupt for the ZDMA device.
   */
  XIntc_Enable(IntcInstancePtr, IntrId);
#ifndef TESTAPP_GEN
  Xil_ExceptionInit();
  Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
      (Xil_ExceptionHandler)XIntc_InterruptHandler,
      (void *)IntcInstancePtr);
#endif
#else
#ifndef TESTAPP_GEN
  XScuGic_Config *IntcConfig; /* Config for interrupt controller */

  /*
   * Initialize the interrupt controller driver
   */
  IntcConfig = XScuGic_LookupConfig(ZDMA_INTC_DEVICE_ID);
  if (NULL == IntcConfig)
    {
      return XST_FAILURE;
    }

  Status = XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig,
      IntcConfig->CpuBaseAddress);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }

  /*
   * Connect the interrupt controller interrupt handler to the
   * hardware interrupt handling logic in the processor.
   */
  Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
      (Xil_ExceptionHandler) XScuGic_InterruptHandler,
      IntcInstancePtr);
#endif

  /*
   * Connect a device driver handler that will be called when an
   * interrupt for the device occurs, the device driver handler
   * performs the specific interrupt processing for the device
   */
  Status = XScuGic_Connect (IntcInstancePtr, IntrId,
			    (Xil_ExceptionHandler) XZDma_IntrHandler,
			    (void *) InstancePtr);
  if (Status != XST_SUCCESS)
    {
      return XST_FAILURE;
    }

  /*
   * Enable the interrupt for the device
   */
  XScuGic_Enable (IntcInstancePtr, IntrId);
#endif
#ifndef TESTAPP_GEN

  /*
   * Enable interrupts
   */
  Xil_ExceptionEnableMask(XIL_EXCEPTION_IRQ);
#endif

  return XST_SUCCESS;
}
static void DoneHandler0(void *CallBackRef)
{
  Done0 = 1;
}
static void ErrorHandler0(void *CallBackRef, u32 Mask)
{
  ErrorStatus0 = Mask;
}

static void DoneHandler1(void *CallBackRef)
{
  Done1 = 1;
}
static void ErrorHandler1(void *CallBackRef, u32 Mask)
{
  ErrorStatus1 = Mask;
}

static void DoneHandler2(void *CallBackRef)
{
  Done2 = 1;
}
static void ErrorHandler2(void *CallBackRef, u32 Mask)
{
  ErrorStatus2 = Mask;
}

static void DoneHandler3(void *CallBackRef)
{
  Done3 = 1;
}
static void ErrorHandler3(void *CallBackRef, u32 Mask)
{
  ErrorStatus3 = Mask;
}

static void DoneHandler4(void *CallBackRef)
{
  Done4 = 1;
}
static void ErrorHandler4(void *CallBackRef, u32 Mask)
{
  ErrorStatus4 = Mask;
}

static void DoneHandler5(void *CallBackRef)
{
  Done5 = 1;
}
static void ErrorHandler5(void *CallBackRef, u32 Mask)
{
  ErrorStatus5 = Mask;
}

static void DoneHandler6(void *CallBackRef)
{
  Done6 = 1;
}
static void ErrorHandler6(void *CallBackRef, u32 Mask)
{
  ErrorStatus6 = Mask;
}

static void DoneHandler7(void *CallBackRef)
{
  Done7 = 1;
}
static void ErrorHandler7(void *CallBackRef, u32 Mask)
{
  ErrorStatus7 = Mask;
}
