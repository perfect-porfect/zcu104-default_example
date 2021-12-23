#ifndef __ADDRESSES_H_
#define __ADDRESSES_H_


#define START_DDR_ADDRESS  					            	(0x00)
#define DDR_SIZE                                            (0x80000000)  									/* 2GB */
#define DDR_SIZE_FOR_SLAVE_CORES                            (0x4000000) 									/* 64MB */
#define CORES_COUNT                                         (4)
#define SHM_DDR_SIZE_FOR_MASTER_CORE                        (0x1000000) 									/* 16MB */
#define SHM_DDR_SIZE_FOR_SLAVE_CORE1                        (0x1000000)
#define SHM_DDR_SIZE_FOR_SLAVE_CORE2                        (0x1000000)
#define SHM_DDR_SIZE_FOR_SLAVE_CORE3                        (0x1000000)
#define SHM_DRR_SIZE 										(SHM_DDR_SIZE_FOR_MASTER_CORE+ SHM_DDR_SIZE_FOR_SLAVE_CORE1+ SHM_DDR_SIZE_FOR_SLAVE_CORE2+ SHM_DDR_SIZE_FOR_SLAVE_CORE3)
#define SLAVE_CORE1_DDR_SIZE                                DDR_SIZE_FOR_SLAVE_CORES
#define SLAVE_CORE2_DDR_SIZE                                DDR_SIZE_FOR_SLAVE_CORES
#define SLAVE_CORE3_DDR_SIZE                                DDR_SIZE_FOR_SLAVE_CORES

/* CORE0 ADDRESSES   */
#define MASTER_CORE_START_DDR_ADDRESS		            	START_DDR_ADDRESS
#define MASTER_CORE_DDR_SIZE         		            	(DDR_SIZE - (((CORES_COUNT - 1) * DDR_SIZE_FOR_SLAVE_CORES) + SHM_DRR_SIZE)) /* (0x70000000) = 1792 MB   */
#define	MASTER_CORE_END_DDR_ADDRESS                         (MASTER_CORE_START_DDR_ADDRESS + MASTER_CORE_DDR_SIZE)            /* (0x70000000)  */

/* CORE1 ADDRESSES   */
#define CORE1_START_DDR_ADDRESS			 	            	MASTER_CORE_END_DDR_ADDRESS       					   /* 0x7000.0000   */
#define CORE1_DDR_SIZE         			 	            	SLAVE_CORE1_DDR_SIZE							  /* 64MB       */
#define	CORE1_END_DDR_ADDRESS              	            	(CORE1_START_DDR_ADDRESS + CORE1_DDR_SIZE)            /* END_ADDRESS 0x7400.0000   */

/* CORE2 ADDRESSES   */
#define CORE2_START_DDR_ADDRESS			 	            	CORE1_END_DDR_ADDRESS       					  /* 0x7400.0000     */
#define CORE2_DDR_SIZE         			 	            	SLAVE_CORE2_DDR_SIZE 							  /* 64MB    */
#define	CORE2_END_DDR_ADDRESS              	            	(CORE2_START_DDR_ADDRESS + CORE2_DDR_SIZE) 	      /* END_ADDRESS 0x7800.0000   */

/* CORE3 ADDRESSES   */
#define CORE3_START_DDR_ADDRESS			 	            	CORE2_END_DDR_ADDRESS        					  /* 0x7800.0000    */
#define CORE3_DDR_SIZE         			 	            	SLAVE_CORE3_DDR_SIZE 							  /* 64MB       */
#define	CORE3_END_DDR_ADDRESS              	            	(CORE3_START_DDR_ADDRESS + CORE3_DDR_SIZE) 	       /* END_ADDRESS 0x7C00.0000   */

/* SHARED MEMORY     */
#define SHM_START_DDR_ADDRESS                               CORE3_END_DDR_ADDRESS                       	     /*   0x7C000000    */
#define SHM_END_DDR_ADDRESS					            	(SHM_START_DDR_ADDRESS        + SHM_DRR_SIZE)

#define SHM_MASTER_CORE_START_ADDRESS		            	SHM_START_DDR_ADDRESS                         		 /*   0x7C000000    */
#define SHM_MASTER_CORE_END_ADDRESS							(SHM_MASTER_CORE_START_ADDRESS + SHM_DDR_SIZE_FOR_MASTER_CORE)

#define SHM_CORE1_START_ADDRESS				            	SHM_MASTER_CORE_END_ADDRESS
#define SHM_CORE1_END_ADDRESS				            	(SHM_CORE1_START_ADDRESS + SHM_DDR_SIZE_FOR_SLAVE_CORE1)

#define SHM_CORE2_START_ADDRESS				            	SHM_CORE1_END_ADDRESS
#define SHM_CORE2_END_ADDRESS				            	(SHM_CORE2_START_ADDRESS + SHM_DDR_SIZE_FOR_SLAVE_CORE2)

#define SHM_CORE3_START_ADDRESS				            	SHM_CORE2_END_ADDRESS
#define SHM_CORE3_END_ADDRESS				            	(SHM_CORE3_START_ADDRESS       + SHM_DDR_SIZE_FOR_SLAVE_CORE3)

#define SHM_MASTER_CORE_DDR_SIZE			            	SHM_DDR_SIZE_FOR_MASTER_CORE
#define SHM_CORE1_CORE_DDR_SIZE				                SHM_DDR_SIZE_FOR_SLAVE_CORE1
#define SHM_CORE2_CORE_DDR_SIZE				                SHM_DDR_SIZE_FOR_SLAVE_CORE2
#define SHM_CORE3_CORE_DDR_SIZE				                SHM_DDR_SIZE_FOR_SLAVE_CORE3


/* SHARED MEMORY STRUCTURE DETAIL */

#define ARRAY_SIZE  (10)
#define FLAG_ADDRESS_CORE1 (0xFFFC0000)

#define FLAG_START_PROCESS_CORE_1_ADDRESS    (SHM_CORE1_END_ADDRESS - 8)
#define FLAG_FINISHE_PROCESS_CORE_1_ADDRESS  (SHM_CORE1_END_ADDRESS - 16)
#define FLAG_SUM_VALUE_ADDRESS_CORE1_ADDRESS (SHM_CORE1_END_ADDRESS - 24)

#define FLAG_START_PROCESS_CORE_2_ADDRESS    (SHM_CORE2_END_ADDRESS - 8)
#define FLAG_FINISHE_PROCESS_CORE_2_ADDRESS  (SHM_CORE2_END_ADDRESS - 16)
#define FLAG_SUM_VALUE_ADDRESS_CORE2_ADDRESS (SHM_CORE2_END_ADDRESS - 24)

#define FLAG_START_PROCESS_CORE_3_ADDRESS    (SHM_CORE3_END_ADDRESS - 8)
#define FLAG_FINISHE_PROCESS_CORE_3_ADDRESS  (SHM_CORE3_END_ADDRESS - 16)
#define FLAG_SUM_VALUE_ADDRESS_CORE3_ADDRESS (SHM_CORE3_END_ADDRESS - 24)


#define FLAG_ADDRESS_CORE0 (FLAG_ADDRESS_CORE1 + 12)

typedef double array_type;
typedef uint64_t* cast_hex_type;

#endif
