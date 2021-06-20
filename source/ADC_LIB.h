/*
 * ADC_LIB.h: Analog-to-Digital converter
 *
 *  Created on: 22/09/2017
 *      Author: Juan Pablo Arango Atehortúa
 *      Revision 1 : Ricardo Andrés Velásquez
 */

#ifndef ADC_LIB_H_
#define ADC_LIB_H_
#include <stdint.h>
/*******************************************************************/
/****************Start Bits Fields Type Definition******************/
/*******************************************************************/
enum{
	kADC_ADCH_DADP0=0, 										// When DIFF=0, DADP0 is selected as input
	kADC_ADCH_DAD0=0,										// when DIFF=1, DAD0 is selected as input
	kADC_ADCH_DADP1=1,										// When DIFF=0, DADP1 is selected as input
	kADC_ADCH_DAD1=1,										// when DIFF=1, DAD1 is selected as input.
	kADC_ADCH_DADP2=2,										// When DIFF=0, DADP2 is selected as input
	kADC_ADCH_DAD2=2,										// when DIFF=1, DAD2 is selected as input
	kADC_ADCH_DADP3=3,										// When DIFF=0, DADP3 is selected as input
	kADC_ADCH_DAD3=3,										// when DIFF=1, DAD3 is selected as input
	kADC_ADCH_AD4=4,										// When DIFF=0, AD4 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD5=5,										// When DIFF=0, AD5 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD6=6,										// When DIFF=0, AD6 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD7=7,										// When DIFF=0, AD7 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD8=8,										// When DIFF=0, AD8 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD9=9,										// When DIFF=0, AD9 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD10=10,										// When DIFF=0, AD10 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD11=11,										// When DIFF=0, AD11 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD12=12,										// When DIFF=0, AD12 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD13=13,										// When DIFF=0, AD13 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD14=14,										// When DIFF=0, AD14 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD15=15,										// When DIFF=0, AD15 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD16=16,										// When DIFF=0, AD16 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD17=17,										// When DIFF=0, AD17 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD18=18,										// When DIFF=0, AD18 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD19=19,										// When DIFF=0, AD19 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD20=20,										// When DIFF=0, AD20 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD21=21,										// When DIFF=0, AD21 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD22=22,										// When DIFF=0, AD22 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_AD23=23,										// When DIFF=0, AD23 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_TEMP_SENSOR_SENDED=26,						// When DIFF=0, Temp Sensor (single-ended) is selected as input
	kADC_ADCH_TEMP_SENSOR_DIFF=26,							// when DIFF=1, Temp Sensor	(differential) is selected as input
	kADC_ADCH_BANDGAP_SENDED=27,							// When DIFF=0,Bandgap (single-ended) is selected as input
	kADC_ADCH_BANDGAP_DIFF=27,								// when DIFF=1, Bandgap (differential) is selected as input
	kADC_ADCH_VREFSH=29,									// When DIFF=0, VREFSH is selected as input. Voltage reference selected is determined by SC2[REFSEL]
	kADC_ADCH_NVREFSH=29,									// when DIFF=1, -VREFSH (differential) is selected as input. Voltage reference selected is determined by SC2[REFSEL]
	kADC_ADCH_VREFSL=30,									// When DIFF=0,VREFSL is selected as input
	kADC_ADCH_DISABLED=30,									// Module is disabled
};

enum{
	kADC_ADCH_SE0=0, 										// When DIFF=0, ADC0_DP0/ADC0_SE0 is selected as input
	kADC_ADCH_DP0_DM0=0,									// when DIFF=1, ADC0_DP0 and ADC0_DM0 are selected as input.
	kADC_ADCH_SE1=1,										// When DIFF=0, ADC0_DP1/ADC0_SE1 is selected as input
	kADC_ADCH_DP1_DM1=1,									// when DIFF=1, ADC0_DP1 and ADC0_DM1 are selected as input.
	kADC_ADCH_SE2=2,										// When DIFF=0, ADC0_DP2/ADC0_SE2 is selected as input
	kADC_ADCH_DP2_DM2=2,									// when DIFF=1, ADC0_DP2 and ADC0_DM2 are selected as input
	kADC_ADCH_SE3=3,										// When DIFF=0, ADC0_DP3/ADC0_SE3 is selected as input
	kADC_ADCH_DP3_DM3=3,									// when DIFF=1, ADC0_DP3 and ADC0_DM3 are selected as input
	kADC_ADCH_SE4a=4,										// When DIFF=0, ADC0_DM0/ADC0_SE4a is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE5a=5,										// When DIFF=0, AADC0_DM1/ADC0_SE5a is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE6a=6,										// When DIFF=0, ADC0_DM2/ADC0_SE6a is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE7a=7,										// When DIFF=0, AD7 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE4b=4,										// When DIFF=0, AD8 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE5b=5,										// When DIFF=0, AD9 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE6b=6,										// When DIFF=0, AD10 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE7b=7,										// When DIFF=0, AD11 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE8=8,										// When DIFF=0, AD12 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE9=9,										// When DIFF=0, AD13 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE11=11,										// When DIFF=0, AD14 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE12=12,										// When DIFF=0, AD15 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE13=13,										// When DIFF=0, AD16 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE14=14,										// When DIFF=0, AD17 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE15=15,										// When DIFF=0, AD18 is selected as input; when DIFF=1, it is reserved
	kADC_ADCH_SE23=23
};

#define mADC_SC1n_ADCH(X) (X & 0x0000001FU)					// Input channel select

enum{
	mADC_SC1n_DIFF = 0x00000020U,							// Differential Mode Enable
	mADC_SC1n_AIEN = 0x00000040U,							// Interrupt Enable
	mADC_SC1n_COCO = 0x00000080U,							// Conversion Complete Flag
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t ADCH   : 5;  								// Input channel select
		uint32_t DIFF   : 1;  								// Differential Mode Enable
		uint32_t AIEN   : 1;  								// Interrupt Enable
		uint32_t COCO   : 1; 								// Conversion Complete Flag
		uint32_t        : 24;
	}BITS;
}__adc_sc1n_t;//ADC Status & control Registers 1

enum{
	kADC_ADICLK_BUS_CLOCK,
	kADC_ADICLK_BUS_CLOCK_DIVIDED_BY_2,
	kADC_ADICLK_ALTCLK,
	kADC_ADICLK_OSCERCLK=2,
	kADC_ADICLK_ASYNCHRONOUS_CLK
};

enum{
	kADC_ADIV_DIVIDE_BY_1,
	kADC_ADIV_DIVIDE_BY_2,
	kADC_ADIV_DIVIDE_BY_4,
	kADC_ADIV_DIVIDE_BY_8
};

enum{
	kADC_MODE_SE_8_BITS,
	kADC_MODE_SE_12_BITS,
	kADC_MODE_SE_10_BITS,
	kADC_MODE_SE_16_BITS,
	kADC_MODE_DIFF_9_BITS=0,
	kADC_MODE_DIFF_13_BITS=1,
	kADC_MODE_DIFF_11_BITS=2,
	kADC_MODE_diff_16_BITS=3
};

#define mADC_CFG1_ADICLK(X) (X & 0x00000003U)				// Input Clock Select
#define mADC_CFG1_MODE(X) ((X & 0x00000003U)<<2)			// Conversion mode selection
#define mADC_CFG1_ADIV(X) ((X & 0x00000003U)<<5)			// Clock Divide Select

enum{
	mADC_CFG1_ADLSMP = 0x00000010U,							// Sample Time Configuration
	mADC_CFG1_ADLPC = 0x00000080U							// Low-Power Configuration
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t ADICLK : 2; 								// Input Clock Select
		uint32_t MODE   : 2; 								// Conversion mode selection
		uint32_t ADLSMP : 1; 								// Sample Time Configuration
		uint32_t ADIV   : 2; 								// Clock Divide Select
		uint32_t ADLPC  : 1; 								// Low-Power Configuration
		uint32_t        : 24;
	}BITS;
}__adc_cfg1_t;//ADC Configuration Register 1

enum{
	kADC_ADLSTS_24_CYCLES, 								   // Default longest sample time; 20 extra ADCK cycles; 24 ADCK cycles total
	kADC_ADLSTS_16_CYCLES, 								   // 12 extra ADCK cycles; 16 ADCK cycles total sample time
	kADC_ADLSTS_10_CYCLES, 								   // 6 extra ADCK cycles; 10 ADCK cycles total sample time
	kADC_ADLSTS_6_CYCLES 								   // 2 extra ADCK cycles; 6 ADCK cycles total sample time
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t ADLSTS  : 2; 								// Long Sample Time Select
		uint32_t ADHSC   : 1; 								// High-Speed Configuration
		uint32_t ADACKEN : 1; 								// Asynchronous Clock Output Enable
		uint32_t MUXSEL  : 1; 								// ADC Mux Select
		uint32_t         : 27;
	}BITS;
}__adc_cfg2_t;								  				// ADC Configuration Register 2

typedef union{
	uint32_t WORD;
	struct{
		uint32_t D  : 16; //Data Result
		uint32_t    : 16;
	}BITS;
}__adc_rn_t;												// ADC Data Result Registers

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CV  : 16; 								    //Compare Value
		uint32_t    : 16;
	}BITS;
}__adc_cvn_t;												//ADC Compare Value Registers


enum{
	kADC_REFSEL_VREFH_VREFL, 								// Default voltage reference pin pair, that is, external pins VREFH and VREFL
	kADC_REFSEL_VALTH_VALTL, 								// Alternate reference pair, that is, VALTH and VALTL
	kADC_REFSEL_VDDA_VSSA=1	 								// Alternate reference pair in KL27
};

#define mADC_SC2_REFSEL(X) (X & 0x00000003U)				// Voltage Reference Selection

enum{
	mADC_SC2_DMAEN = 0x00000004U,							// DMA Enable
	mADC_SC2_ACREN = 0x00000008U,							// Conversion Function Range Enable
	mADC_SC2_ACFGT = 0x00000010U,							// Conversion Function Greater Than Enable
	mADC_SC2_ACFE = 0x00000020U,							// Conversion Trigger Select
	mADC_SC2_ADACT = 0x00000040U,							// Conversion Active
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t REFSEL: 2; 								// Voltage Reference Selection
		uint32_t DMAEN : 1; 								// DMA Enable
		uint32_t ACREN : 1; 								// Conversion Function Range Enable
		uint32_t ACFGT : 1; 								// Conversion Function Greater Than Enable
		uint32_t ACFE  : 1; 								// Compare Function Enable
		uint32_t ADTRG : 1;									// Conversion Trigger Select
		uint32_t ADACT : 1; 								// Conversion Active
		uint32_t       : 24;
	}BITS;
}__adc_sc2_t;												//ADC Status & control Register 2

enum{
	kADC_AVGS_4_SAMPLES,
	kADC_AVGS_8_SAMPLES,
	kADC_AVGS_16_SAMPLES,
	kADC_AVGS_32_SAMPLES
};

#define mADC_SC3_AVGS(X) (X & 0x00000003)					//Hardware Average Select

enum{
	mADC_SC3_AVGE = 0x00000004U,							// Hardware Average Enable
	mADC_SC3_ADCO = 0x00000008U,							// Continuous Conversion Enable
	mADC_SC3_CALF = 0x00000040U,							// Calibration Failed Flag
	mADC_SC3_CAL = 0x00000080U,								// Calibration
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t AVGS : 2; 									// Hardware Average Select
		uint32_t AVGE : 1; 									// Hardware Average Enable
		uint32_t ADCO : 1; 									// Continuous Conversion Enable
		uint32_t      : 2;									// Reserved
		uint32_t CALF : 1; 									// Calibration Failed Flags
		uint32_t CAL  : 1; 									// Calibration
		uint32_t      : 24;									// Reserved
	}BITS;
}__adc_sc3_t;												// ADC Status & control Register 3

typedef union{
	uint32_t WORD;
	struct{
		uint32_t OFS  : 16; 								//Offset Error Correction Value
		uint32_t      : 16;									// Reserved
	}BITS;
}__adc_ofs_t;																																				//ADC Offset Correction Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t PG   : 16; 								// Plus-Side Gain
		uint32_t      : 16;									// Reserved
	}BITS;
}__adc_pg_t;												// ADC Plus-Side Gain Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t MG   : 16; 								// Minus-Side Gain
		uint32_t      : 16;									// Reserved
	}BITS;
}__adc_mg_t;												// ADC Minus-Side Gain Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLPD : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clpd_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLPS : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clps_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLP4 : 10; 								// Calibration Value
		uint32_t      : 22;									// Reserved
	}BITS;
}__adc_clp4_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLP3 : 9; 									// Calibration Value
		uint32_t      : 23;									// Reserved
	}BITS;
}__adc_clp3_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLP2 : 8; 									// Calibration Value
		uint32_t      : 24;									// Reserved
	}BITS;
}__adc_clp2_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLP1 : 7; 									// Calibration Value
		uint32_t      : 25;									// Reserved
	}BITS;
}__adc_clp1_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLP0 : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clp0_t;												// ADC Plus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLMD : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clmd_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLMS : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clms_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLM4 : 10; 								// Calibration Value
		uint32_t      : 22;									// Reserved
	}BITS;
}__adc_clm4_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLM3 : 9; 									// Calibration Value
		uint32_t      : 23;									// Reserved
	}BITS;
}__adc_clm3_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLM2 : 8; 									// Calibration Value
		uint32_t      : 24;									// Reserved
	}BITS;
}__adc_clm2_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLM1 : 7; 									// Calibration Value
		uint32_t      : 25;									// Reserved
	}BITS;
}__adc_clm1_t;												// ADC Minus-Side General Calibration Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t CLM0 : 6; 									// Calibration Value
		uint32_t      : 26;									// Reserved
	}BITS;
}__adc_clm0_t;												// ADC Minus-Side General Calibration Value Register


/*******************************************************************/
/****************End Bits Fields Type Definition********************/
/*******************************************************************/


/*******************************************************************/
/****************Start Fields Structure Definition******************/
/*******************************************************************/
typedef struct{
	volatile __adc_sc1n_t SC1A;								// 0xB000 ADC Status and Control Registers 1 (ADC0_SC1A)
	volatile __adc_sc1n_t SC1B;								// 0xB004 ADC Status and Control Registers 1 (ADC0_SC1B)
	volatile __adc_cfg1_t CFG1;								// 0xB008 ADC Configuration Register 1 (ADC0_CFG1)
	volatile __adc_cfg2_t CFG2;								// 0xB00C ADC Configuration Register 2 (ADC0_CFG2)
	volatile __adc_rn_t   RA;  								// 0xB010 ADC Data Result Register (ADC0_RA)
	volatile __adc_rn_t   RB;  								// 0xB014 ADC Data Result Register (ADC0_RB)
	volatile __adc_cvn_t  CV1; 								// 0xB018 Compare Value Registers (ADC0_CV1)
	volatile __adc_cvn_t  CV2; 								// 0xB01C Compare Value Registers (ADC0_CV2)
	volatile __adc_sc2_t  SC2; 								// 0xB020 Status and Control Register 2 (ADC0_SC2)
	volatile __adc_sc3_t  SC3; 								// 0xB024 Status and Control Register 3 (ADC0_SC3)
	volatile __adc_ofs_t  OFS; 								// 0xB028 ADC Offset Correction Register (ADC0_OFS)
	volatile __adc_pg_t   PG;  								// 0xB02C ADC Plus-Side Gain Register (ADC0_PG)
	volatile __adc_mg_t   MG;  								// 0xB030 ADC Minus-Side Gain Register (ADC0_MG)
	volatile __adc_clpd_t CLPD;								// 0xB034 ADC Plus-Side General Calibration Value Register (ADC0_CLPD)
	volatile __adc_clps_t CLPS;								// 0xB038 ADC Plus-Side General Calibration Value Register (ADC0_CLPS)
	volatile __adc_clp4_t CLP4;								// 0xB03C ADC Plus-Side General Calibration Value Register (ADC0_CLP4)
	volatile __adc_clp3_t CLP3;								// 0xB040 ADC Plus-Side General Calibration Value Register (ADC0_CLP3)
	volatile __adc_clp2_t CLP2;								// 0xB044 ADC Plus-Side General Calibration Value Register (ADC0_CLP2)
	volatile __adc_clp1_t CLP1;								// 0xB048 ADC Plus-Side General Calibration Value Register (ADC0_CLP1)
	volatile __adc_clp0_t CLP0;								// 0xB04C ADC Plus-Side General Calibration Value Register (ADC0_CLP0)
	volatile uint32_t    RESERVED0;							// 0xB050 Reserved
	volatile __adc_clmd_t CLMD;								// 0xB054 ADC Minus-Side General Calibration Value Register (ADC0_CLMD)
	volatile __adc_clms_t CLMS;								// 0xB058 ADC Minus-Side General Calibration Value Register	(ADC0_CLMS)
	volatile __adc_clm4_t CLM4;								// 0xB05C ADC Minus-Side General Calibration Value Register	(ADC0_CLM4)
	volatile __adc_clm3_t CLM3;								// 0xB060 ADC Minus-Side General Calibration Value Register	(ADC0_CLM3)
	volatile __adc_clm2_t CLM2;								// 0xB064 ADC Minus-Side General Calibration Value Register	(ADC0_CLM2)
	volatile __adc_clm1_t CLM1;								// 0xB068 ADC Minus-Side General Calibration Value Register	(ADC0_CLM1)
	volatile __adc_clm0_t CLM0;								// 0xB06C ADC Minus-Side General Calibration Value Register	(ADC0_CLM0)
} __adc0_t;
/*******************************************************************/
/****************End Fields Structure Definition********************/
/*******************************************************************/

/*******************************************************************/
/****************Start MACROs per Register**************************/
/*******************************************************************/
#define sADC0 (*((__adc0_t *)(0x4003B000)))					// ADC0  module general register structure

//para ADC0_SC1A
#define rADC0_SC1A sADC0.SC1A.WORD							// ADC Status and Control Registers 1 (ADCx_SC1A)
#define bADC0_A_ADCH sADC0.SC1A.BITS.ADCH					// Input channel select
#define bADC0_A_DIFF sADC0.SC1A.BITS.DIFF					// Differential Mode Enable
#define bADC0_A_AIEN sADC0.SC1A.BITS.AIEN					// Interrupt Enable
#define bADC0_A_COCO sADC0.SC1A.BITS.COCO					// Conversion Complete Flag

//para ADC0_SC1B
#define rADC0_SC1B sADC0.SC1B.WORD							// ADC Status and Control Registers 1 (ADCx_SC1B)
#define bADC0_B_ADCH sADC0.SC1B.BITS.ADCH					// Conversion mode selection
#define bADC0_B_DIFF sADC0.SC1B.BITS.DIFF					// Sample Time Configuration
#define bADC0_B_AIEN sADC0.SC1B.BITS.AIEN					// Clock Divide Select
#define bADC0_B_COCO sADC0.SC1B.BITS.COCO					// Low-Power Configuration

//para ADC0_CFG1
#define rADC0_CFG1 sADC0.CFG1.WORD							// ADC Configuration Register 1 (ADCx_CFG1)
#define bADC0_ADICLK sADC0.CFG1.BITS.ADICLK					// Input Clock Select
#define bADC0_MODE   sADC0.CFG1.BITS.MODE					// Conversion mode selection
#define bADC0_ADLSMP sADC0.CFG1.BITS.ADLSMP					// Sample Time Configuration
#define bADC0_ADIV   sADC0.CFG1.BITS.ADIV					// Clock Divide Select
#define bADC0_ADLPC  sADC0.CFG1.BITS.ADLPC					// Low-Power Configuration

//para ADC0_CFG2
#define rADC0_CFG2 sADC0.CFG2.WORD							// ADC Configuration Register 2 (ADCx_CFG2)
#define bADC0_ADLSTS  sADC0.CFG2.BITS.ADLSTS				// Long Sample Time Select
#define bADC0_ADHSC   sADC0.CFG2.BITS.ADHSC					// High-Speed Configuration
#define bADC0_ADACKEN sADC0.CFG2.BITS.ADACKEN				// Asynchronous Clock Output Enable
#define bADC0_MUXSEL  sADC0.CFG2.BITS.MUXSEL				// ADC Mux Select

//para ADC0_RA
#define rADC0_RA  sADC0.RA.WORD								// ADC Data Result Register (ADCx_Rn)
#define bADC0_A_D sADC0.RA.BITS.D							// Data result

//para ADC0_RB
#define rADC0_RB  sADC0.RB.WORD								// ADC Data Result Register (ADCx_Rn)
#define bADC0_B_D sADC0.RB.BITS.D							// Data result

//para ADC0_CV1
#define rADC0_CV1   sADC0.CV1.WORD							// Compare Value Registers (ADCx_CV1)
#define bADC0_CV1 sADC0.CV1.BITS.CV							// Compare Value

//para ADC0_CV2
#define rADC0_CV2   sADC0.CV2.WORD							// Compare Value Registers (ADCx_CV2)
#define bADC0_CV2 sADC0.CV2.BITS.CV							// Compare Value

//para ADC0_SC2
#define rADC0_SC2   sADC0.SC2.WORD							// Status and Control Register 2 (ADCx_SC2)
#define bADC0_REFSEL sADC0.SC2.BITS.REFSEL					// Voltage Reference Selection
#define bADC0_DMAEN  sADC0.SC2.BITS.DMAEN					// DMA Enable
#define bADC0_ACREN  sADC0.SC2.BITS.ACREN					// Compare Function Range Enable
#define bADC0_ACFGT  sADC0.SC2.BITS.ACFGT					// Compare Function Greater Than Enable
#define bADC0_ACFE   sADC0.SC2.BITS.ACFE					// Compare Function Enable
#define bADC0_ADTRG  sADC0.SC2.BITS.ADTRG					// Conversion Trigger Select
#define bADC0_ADACT  sADC0.SC2.BITS.ADACT					// Conversion Active

//para ADC0_SC3
#define rADC0_SC3 sADC0.SC3.WORD							// Status and Control Register 3 (ADCx_SC3)
#define bADC0_AVGS sADC0.SC3.BITS.AVGS						// Hardware Average Select
#define bADC0_AVGE sADC0.SC3.BITS.AVGE						// Hardware Average Enable
#define bADC0_ADCO sADC0.SC3.BITS.ADCO						// Continuous Conversion Enable
#define bADC0_CALF sADC0.SC3.BITS.CALF						// Calibration Failed Flag
#define bADC0_CAL  sADC0.SC3.BITS.CAL						// Calibration

//para ADC0_OFS
#define rADC0_OFS sADC0.OFS.WORD							// ADC Offset Correction Register (ADCx_OFS)
#define bADC0_OFS sADC0.OFS.BITS.OFS						// Offset Error Correction Value

//para ADC0_PG
#define rADC0_PG  sADC0.PG.WORD								// ADC Plus-Side Gain Register (ADCx_PG)
#define bADC0_PG  sADC0.PG.BITS.PG							// Plus-Side Gain
//para ADC0_MG
#define rADC0_MG  sADC0.MG.WORD								// ADC Minus-Side Gain Register (ADCx_MG)
#define bADC0_MG  sADC0.MG.BITS.MG							// Minus-Side Gain
//para ADC0_CLPD
#define rADC0_CLPD sADC0.CLPD.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLPD)
#define bADC0_CLPD sADC0.CLPD.BITS.CLPD						// Calibration Value
//para ADC0_CLPS
#define rADC0_CLPS sADC0.CLPS.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLPS)
#define bADC0_CLPS sADC0.CLPS.BITS.CLPS						// Calibration Value
//para ADC0_CLP4
#define rADC0_CLP4 sADC0.CLP4.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLP4)
#define bADC0_CLP4 sADC0.CLP4.BITS.CLP4						// Calibration Value
//para ADC0_CLP3
#define rADC0_CLP3 sADC0.CLP3.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLP3)
#define bADC0_CLP3 sADC0.CLP3.BITS.CLP3						// Calibration Value
//para ADC0_CLP2
#define rADC0_CLP2 sADC0.CLP2.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLP2)
#define bADC0_CLP2 sADC0.CLP2.BITS.CLP2						// Calibration Value
//para ADC0_CLP1
#define rADC0_CLP1 sADC0.CLP1.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLP1)
#define bADC0_CLP1 sADC0.CLP1.BITS.CLP1						// Calibration Value
//para ADC0_CLP0
#define rADC0_CLP0 sADC0.CLP0.WORD							// ADC Plus-Side General Calibration Value Register (ADCx_CLP0)
#define bADC0_CLP0 sADC0.CLP0.BITS.CLP0						// Calibration Value
//para ADC0_CLMD
#define rADC0_CLMD sADC0.CLMD.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLMD)
#define bADC0_CLMD sADC0.CLMD.BITS.CLMD						// Calibration Value
//para ADC0_CLMS
#define rADC0_CLMS sADC0.CLMS.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLMS)
#define bADC0_CLMS sADC0.CLMS.BITS.CLMS						// Calibration Value
//para ADC0_CLM4
#define rADC0_CLM4 sADC0.CLM4.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLM4)
#define bADC0_CLM4 sADC0.CLM4.BITS.CLM4						// Calibration Value
//para ADC0_CLM3
#define rADC0_CLM3 sADC0.CLM3.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLM3)
#define bADC0_CLM3 sADC0.CLM3.BITS.CLM3						// Calibration Value
//para ADC0_CLM2
#define rADC0_CLM2 sADC0.CLM2.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLM2)
#define bADC0_CLM2 sADC0.CLM2.BITS.CLM2						// Calibration Value
//para ADC0_CLM1
#define rADC0_CLM1 sADC0.CLM1.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLM1)
#define bADC0_CLM1 sADC0.CLM1.BITS.CLM1						// Calibration Value
//para ADC0_CLM0
#define rADC0_CLM0 sADC0.CLM0.WORD							// ADC Minus-Side General Calibration Value Register (ADCx_CLM0)
#define bADC0_CLM0 sADC0.CLM0.BITS.CLM0						// Calibration Value

/*******************************************************************/
/****************End MACROs per Register****************************/
/*******************************************************************/

#endif
