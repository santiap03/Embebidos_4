/*
 * PIT_LIB.h: Periodic Interrupt Timer
 *
 *  Created on: 24/09/2017
 *      Author: Juan Fernando Mosquera
 *      Revision : Ricardo Andrés Velásquez Vélez
 */

#ifndef PIT_LIB_H_
#define PIT_LIB_H_
#include <stdint.h>


/****************Start Bits Fields Type Definition******************/

enum{
	mPIT_MCR_FRZ = 0x00000001u,
	mPIT_MCR_MDIS = 0x00000002u
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t FRZ 	    : 1;  						// Freeze
		uint32_t MDIS  		: 1; 						// Module Disable
		uint32_t Reserved   : 30; 						// Reserved
	}BITS;
}__pit_mcr_t;												// PIT Module Control Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t  LTH; 									// Life Timer value High

	}BITS;
}__pit_ltmr64h_t;											// PIT Upper Lifetime Timer Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t LTL  ; 								// Life Timer value Low

	}BITS;
}__pit_ltmr64l_t;											// PIT Lower Lifetime Timer Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t  TSV; 									// Timer Start value

	}BITS;
}__pit_ldval_t;											// Timer Load Value Register

typedef union{
	uint32_t WORD;
	struct{
		uint32_t TVL;									// Current Timer Value

	}BITS;
}__pit_cval_t;											// Current Timer Value Register

enum{
	mPIT_TCTRL_TEN = 0x00000001u,
	mPIT_TCTRL_TIE = 0x00000002u,
	mPIT_TCTRL_CHN = 0x00000004u
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t TEN :1; 								// Timer Enable
		uint32_t TIE :1; 								// Timer Interrupt Enable
		uint32_t CHN :1; 								// Chain Mode
		uint32_t 	 :29;

	}BITS;
}__pit_tctrl_t;											// Timer Control Register

enum{
	mPIT_TFLG_TIF = 0x00000001
};

typedef union{
	uint32_t WORD;
	struct{
		uint32_t TIF : 1; //Timer Interrupt Flag
		uint32_t 	 :31;

	}BITS;
}__pit_tflg_t;//Timer Flag Register

/****************End Bits Fields Type Definition********************/





/****************Start Fields Structure Definition******************/

typedef struct{
	volatile __pit_mcr_t 		PIT_MCR;					// 0x7000
	volatile uint32_t 			RESERVED0[55];    			// 0x7004 to 0x70DC
	volatile __pit_ltmr64h_t 	PIT_LTMR64H;				// 0x70E0
	volatile __pit_ltmr64l_t 	PIT_LTMR64L;				// 0x70E4
	volatile uint32_t 			RESERVED1[6];    			// 0x70E8 to 0x70FC
	volatile __pit_ldval_t 		PIT_LDVAL0;					// 0x7100
	volatile __pit_cval_t    	PIT_CVAL0;  				// 0x7104
	volatile __pit_tctrl_t   	PIT_TCTRL0; 				// 0x7108
	volatile __pit_tflg_t  		PIT_TFLG0; 					// 0x710C
	volatile __pit_ldval_t  	PIT_LDVAL1; 				// 0x7110
	volatile __pit_cval_t  		PIT_CVAL1; 					// 0x7114
	volatile __pit_tctrl_t  	PIT_TCTRL1; 				// 0x7118
	volatile __pit_tflg_t  		PIT_TFLG1; 					// 0x711C
} __pit_t;

/**************** End Fields Structure Definition ********************/




/******************** Start MACROs per Register **********************/

#define sPIT (*((__pit_t *)(0x40037000)))						// PIT Global Structure

//para PIT_MCR
#define rPIT_MCR sPIT.PIT_MCR.WORD							// PIT Module Control Register (PIT_MCR)
#define bPIT_FRZ sPIT.PIT_MCR.BITS.FRZ						// Freeze
#define bPIT_MDIS sPIT.PIT_MCR.BITS.MDIS					// Module Disable - (PIT section)

//para PIT_LTMR64H
#define rPIT_LTMR64H sPIT.PIT_LTMR64H.WORD					// PIT Upper Lifetime Timer Register (PIT_LTMR64H)
#define bPIT_LTH sPIT.PIT_LTMR64H.BITS.LTH					// Life Timer value High

//para PIT_LTMR64L
#define rPIT_LTMR64L sPIT.PIT_LTMR64L.WORD					// PIT Lower Lifetime Timer Register (PIT_LTMR64L)
#define bPIT_LTL sPIT.PIT_LTMR64L.BITS.LTL					// Life Timer value Low

//para PIT_LDVAL0
#define rPIT_LDVAL0 sPIT.PIT_LDVAL0.WORD					// Timer Load Value Register 0 (PIT_LDVAL0)
#define bPIT_CH0_TSV sPIT.PIT_LDVAL0.BITS.TSV				// Timer Start Value

//para PIT_CVAL0
#define rPIT_CVAL0 sPIT.PIT_CVAL0.WORD						// Timer Load Value Register 0 (PIT_LDVAL0)
#define bPIT_CH0_TVL sPIT.PIT_CVAL0.BITS.TVL				// Current Timer Value

//para PIT_TCTRL0
#define rPIT_TCTRL0 sPIT.PIT_TCTRL0.WORD					// Timer Control Register 0 (PIT_TCTRL0)
#define bPIT_CH0_TEN sPIT.PIT_TCTRL0.BITS.TEN				// Timer Enable
#define bPIT_CH0_TIE sPIT.PIT_TCTRL0.BITS.TIE				// Timer Interrupt Enable
#define bPIT_CH0_CHN sPIT.PIT_TCTRL0.BITS.CHN				// Chain Mode

//para PIT_TFLG0
#define rPIT_TFLG0 sPIT.PIT_TFLG0.WORD						// Timer Flag Register 0 (PIT_TFLG0)
#define bPIT_CH0_TIF sPIT.PIT_TFLG0.BITS.TIF				// Timer Interrupt Flag

//para PIT_LDVAL1
#define rPIT_LDVAL1 sPIT.PIT_LDVAL1.WORD					// Timer Load Value Register 1 (PIT_LDVAL1)
#define bPIT_CH1_TSV sPIT.PIT_LDVAL1.BITS.TSV				// Timer Start Value

//para PIT_CVAL1
#define rPIT_CVAL1 sPIT.PIT_CVAL1.WORD						// Current Timer Value Register 1 (PIT_CVAL1)
#define bPIT_CH1_TVL sPIT.PIT_CVAL1.BITS.TVL				// Current Timer Value

//para PIT_TCTRL1
#define rPIT_TCTRL1 sPIT.PIT_TCTRL1.WORD					// Timer Control Register 1 (PIT_TCTRL1)
#define bPIT_CH1_TEN sPIT.PIT_TCTRL1.BITS.TEN				// Timer Enable
#define bPIT_CH1_TIE sPIT.PIT_TCTRL1.BITS.TIE				// Timer Interrupt Enable
#define bPIT_CH1_CHN sPIT.PIT_TCTRL1.BITS.CHN				// Chain Mode

//para PIT_TFLG1
#define rPIT_TFLG1 sPIT.PIT_TFLG1.WORD						// Timer Flag Register 1 (PIT_TFLG1)
#define bPIT_CH1_TIF sPIT.PIT_TFLG1.BITS.TIF				// Timer Interrupt Flag


/****************End MACROs per Register****************************/


#endif



