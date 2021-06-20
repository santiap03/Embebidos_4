/*
 * MCM_LIB.h
 *
 *  Created on: 11/10/2017
 *      Author:
 *      Revision 1 Ricardo Andrés Velásquez Vélez
 */

#ifndef TPM_LIBRARY_H
#define TPM_LIBRARY_H

#include <stdint.h>

enum {
	kTPM_CMOD_COUNTER_DISABLED,
	kTPM_CMOD_COUNTER_INCREMENT_ON_TPM_CLOCK,
	kTPM_CMOD_COUNTER_INCREMENT_ON_TPM_EXTCLK
};

enum {
	kTPM_PS_DIVIDE_BY_1,
	kTPM_PS_DIVIDE_BY_2,
	kTPM_PS_DIVIDE_BY_3,
	kTPM_PS_DIVIDE_BY_8,
	kTPM_PS_DIVIDE_BY_16,
	kTPM_PS_DIVIDE_BY_32,
	kTPM_PS_DIVIDE_BY_64,
	kTPM_PS_DIVIDE_BY_128
};

#define mTPM_SC_PS(X) (X & 0x00000007U)						// Prescale Factor Selection
#define mTPM_SC_CMOD(X) ((X & 0x00000003U) << 3)			// Clock Mode Selection

enum{
	mTPM_SC_CPWMS =	0x00000020U,							// Center-Aligned PWM Select
	mTPM_SC_TOIE =	0x00000040U,							// Timer Overflow Interrupt Enable
	mTPM_SC_TOF	=	0x00000080U,							// Timer Overflow Flag
	mTPM_SC_DMA =	0x00000100U								// DMA Enable
};

typedef union {
	uint32_t WORD;
    struct {
        uint32_t PS         :3;     						// Prescale Factor Selection
        uint32_t CMOD       :2;     						// Clock Mode Selection
        uint32_t CPWMS      :1;     						// Center-Aligned PWM Select
        uint32_t TOIE       :1;     						// Timer Overflow Interrupt Enable
        uint32_t TOF        :1;     						// Timer Overflow Flag
        uint32_t DMA        :1;     						// DMA Enable
        uint32_t            :23;							// Reserved
    }BITS;
}__tpm_sc_t;

typedef union {
	uint32_t WORD;
    struct{
        uint32_t COUNT      :16;    						// Counter value
        uint32_t            :16;							// Reserved
    }BITS;
}__tpm_cnt_t;

typedef union {
	uint32_t WORD;
    struct {
        uint32_t MOD        :16;    						// Modulo value
        uint32_t            :16;							// Reserved
    }BITS;
}__tpm_mod_t;

enum{
	mTPM_CxSC_DMA = 	0x00000001,							// DMA Enable
	mTPM_CxSC_ELSA = 	0x00000004,							// Edge or Level Select A
	mTPM_CxSC_ELSB = 	0x00000008,							// Edge or Level Select B
	mTPM_CxSC_MSA =		0x00000010,							// Channel Mode Select A
	mTPM_CxSC_MSB = 	0x00000020,							// Channel Mode Select B
	mTPM_CxSC_CHIE = 	0x00000040, 						// Channel Interrupt Enable
	mTPM_CxSC_CHF = 	0x00000080  						// Channel Flag
};

typedef union {
	uint32_t WORD;
    struct {
        uint32_t DMA        :1;     						// DMA Enable
        uint32_t            :1;								// Reserved
        uint32_t ELS        :2; 							// Edge or Level Select B:A
        uint32_t MS        	:2; 							// Channel Mode Select B:A
        uint32_t CHIE       :1;     						// Channel Interrupt Enable
        uint32_t CHF        :1;     						// Channel Flag
        uint32_t            :24;							// Reserved
    }BITS;
}__tpm_cxsc_t;

typedef union {
	uint32_t WORD;
    struct {
        uint32_t VAL        :16;    						// Channel n Value
        uint32_t            :16;							// Reserved
    }BITS;
}__tpm_cxv_t;

enum{
	mTPM_STATUS_CH0F = 	0x00000001, 						//Channel 0 Flag
	mTPM_STATUS_CH1F = 	0x00000002, 						//Channel 1 Flag
	mTPM_STATUS_CH2F = 	0x00000004,							//Channel 2 Flag
	mTPM_STATUS_CH3F = 	0x00000008,							//Channel 3 Flag
	mTPM_STATUS_CH4F = 	0x00000010,							//Channel 4 Flag
	mTPM_STATUS_CH5F = 	0x00000020,							//Channel 5 Flag
	mTPM_STATUS_TOF = 	0x00000100							//Timer Overflow Flag
};

typedef union {
	uint32_t WORD;
    struct {
        uint32_t CH0F       :1;     						//Channel 0 Flag
        uint32_t CH1F       :1;     						//Channel 1 Flag
        uint32_t CH2F       :1;     						//Channel 2 Flag
        uint32_t CH3F       :1;     						//Channel 3 Flag
        uint32_t CH4F       :1;     						//Channel 4 Flag
        uint32_t CH5F       :1;     						//Channel 5 Flag
        uint32_t            :2;								// Reserved
        uint32_t TOF        :1;     						//Timer Overflow Flag
        uint32_t            :23;							// Reserved
    }BITS;
}__tpm_status_t;

enum{
	mTPM_POL_POL0 = 	0x00000001,							// Channel 0 Polarity
	mTPM_POL_POL1 = 	0x00000002,     					// Channel 1 Polarity
	mTPM_POL_POL2 = 	0x00000004,     					// Channel 2 Polarity
	mTPM_POL_POL3 = 	0x00000008, 						// Channel 3 Polarity
	mTPM_POL_POL4 = 	0x00000010,  						// Channel 4 Polarity
	mTPM_POL_POL5 = 	0x00000020							// Channel 5 Polarity
};

typedef union {
	uint32_t WORD;
    struct {
        uint32_t POL0       :1;     						// Channel 0 Polarity
        uint32_t POL1       :1;     						// Channel 1 Polarity
        uint32_t POL2       :1;     						// Channel 2 Polarity
        uint32_t POL3       :1;     						// Channel 3 Polarity
        uint32_t POL4       :1;     						// Channel 4 Polarity
        uint32_t POL5       :1;     						// Channel 5 Polarity
        uint32_t            :26;							// Reserved
    }BITS;
}__tpm_pol_t;

enum{
	kTPM_TRGSEL_CH0_PIN_INPUT_CAPTURE=1,
	kTPM_TRGSEL_CH1_PIN_INPUT_CAPTURE=2,
	kTPM_TRGSEL_CH0orCH1_PIN_INPUT_CAPTURE=3,
	kTPM_TRGSEL_CH2_PIN_INPUT_CAPTURE=4,
	kTPM_TRGSEL_CH0orCH2_PIN_INPUT_CAPTURE=5,
	kTPM_TRGSEL_CH1orCH2_PIN_INPUT_CAPTURE=6,
	kTPM_TRGSEL_CH0orCH1orCH2_PIN_INPUT_CAPTURE=7,
	kTPM_TRGSEL_CH3_PIN_INPUT_CAPTURE=8,
	kTPM_TRGSEL_CH0orCH3_PIN_INPUT_CAPTURE=9,
	kTPM_TRGSEL_CH1orCH3_PIN_INPUT_CAPTURE=10,
	kTPM_TRGSEL_CH0orCH1orCH3_PIN_INPUT_CAPTURE=11,
	kTPM_TRGSEL_CH2orCH3_PIN_INPUT_CAPTURE=12,
	kTPM_TRGSEL_CH0orCH2orCH3_PIN_INPUT_CAPTURE=13,
	kTPM_TRGSEL_CH1orCH2orCH3_PIN_INPUT_CAPTURE=14,
	kTPM_TRGSEL_CH0orCH1orCH2orCH3_PIN_INPUT_CAPTURE=15
};

enum{
	kTPM_DBGMODE_COUNT_DISABLED=0,
	kTPM_DBGMODE_COUNT_ACTIVE=3
};
#define mTPM_CONF_TRGSEL(X) ((X & 0x0000000FU)<<24)		// Trigger Select
#define mTPM_CONF_DBGMODE(X) ((x & 0x00000003)<<6)		// Debug Mode
enum{
	mTPM_CONF_DOZEEN = 		0x00000020,					// Doze Enable
	mTPM_CONF_GTBSYNC = 	0x00000100,					// Global Time Base Synchronization
	mTPM_CONF_GTBEEN = 		0x00000200,					// Global time base enable
	mTPM_CONF_CSOT = 		0x00010000,					// Counter Start on Trigger
	mTPM_CONF_CSOO = 		0x00020000,					// Counter Stop On Overflow
	mTPM_CONF_CROT = 		0x00040000,					// Counter Reload On Trigger
	mTPM_CONF_CPOT = 		0x00080000,					// Counter Pause On Trigger
	mTPM_CONF_TRGPOL = 		0x00400000,					// Trigger Polarity
	mTPM_CONF_TRGSRC = 		0x00800000,					// Trigger Source
};

typedef union {
	uint32_t WORD;
    struct {
        uint32_t            :5;							// Reserved
        uint32_t DOZEEN     :1;							// Doze Enable
        uint32_t DBGMODE    :2;							// Debug Mode
        uint32_t GTBSYNC    :1;							// Global Time Base Synchronization
        uint32_t GTBEEN     :1;							// Global time base enable
        uint32_t            :6;							// Reserved
        uint32_t CSOT       :1;							// Counter Start on Trigger
        uint32_t CSOO       :1;							// Counter Stop On Overflow
        uint32_t CROT       :1;							// Counter Reload On Trigger
        uint32_t CPOT       :1;							// Counter Pause On Trigger
        uint32_t            :2;							// Reserved
        uint32_t TRGPOL     :1;							// Trigger Polarity
        uint32_t TRGSRC     :1;							// Trigger Source
        uint32_t TRGSEL     :4;							// Trigger Select
        uint32_t            :4;							// Reserved
    }BITS;
}__tpm_conf_t;

typedef struct {
    volatile __tpm_sc_t   TPM_SC;        				// 8000
    volatile __tpm_cnt_t  TPM_CNT;       				// 8004
    volatile __tpm_mod_t  TPM_MOD;       				// 8008
    volatile __tpm_cxsc_t TPM_C0SC;      				// 800C
    volatile __tpm_cxv_t  TPM_C0V;       				// 8010
    volatile __tpm_cxsc_t TPM_C1SC;      				// 8014
    volatile __tpm_cxv_t  TPM_C1V;       				// 8018
    volatile __tpm_cxsc_t TPM_C2SC;      				// 801C
    volatile __tpm_cxv_t  TPM_C2V;       				// 8020
    volatile __tpm_cxsc_t TPM_C3SC;      				// 8024
    volatile __tpm_cxv_t  TPM_C3V;       				// 8028
    volatile __tpm_cxsc_t TPM_C4SC;      				// 802C
    volatile __tpm_cxv_t  TPM_C4V;       				// 8030
    volatile __tpm_cxsc_t TPM_C5SC;      				// 8034
    volatile __tpm_cxv_t  TPM_C5V;       				// 8038
    volatile uint32_t     RESERVED_0[5];  				// 803C - 804C
    volatile __tpm_status_t TPM_STATUS;    				// 8050
    volatile uint32_t     RESERVED_1[7];  				// 8054 - 806C
    volatile __tpm_pol_t  TPM_POL;       				// 8070
    volatile uint32_t     RESERVED_2[4];  				// 8074 - 8080
    volatile __tpm_conf_t TPM_CONF;			      		// 8084
}__tpm_t;

///////////////////////////////////////////////////////
//                    TPM0                           //
///////////////////////////////////////////////////////

#define sTPM0           (*((__tpm_t *)(0x40038000)))	// TPM0 Global Structure

#define rTPM0_SC   		sTPM0.TPM_SC.WORD				// TPM0 Status Control
#define bTPM0_PS		sTPM0.TPM_SC.BITS.PS			// Prescale Factor Selection
#define bTPM0_CMOD		sTPM0.TPM_SC.BITS.CMOD			// Clock Mode Selection
#define bTPM0_CPWMS		sTPM0.TPM_SC.BITS.CPWMS			// Center-Aligned PWM Select
#define bTPM0_TOEI		sTPM0.TPM_SC.BITS.TOEI			// Timer Overflow Interrupt Enable
#define bTPM0_TOF_SC	sTPM0.TPM_SC.BITS.TOF			// Timer Overflow Flag
#define bTPM0_DMA		sTPM0.TPM_SC.BITS.DMA			// DMA Enable

#define rTPM0_CNT		sTPM0.TPM_CNT.WORD				// TPM0 Counter
#define bTPM0_COUNT		sTPM0.TPM_CNT.BITS.COUNT		// Counter value

#define rTPM0_MOD		sTPM0.TPM_MOD.WORD				// TPM0 Modulo
#define bTPM0_MOD		sTPM0.TPM_MOD.BITS.MOD			// Counter value

#define rTPM0_C0SC 		sTPM0.TPM_C0SC.WORD				// TPM0 Channel 0 Status Control
#define bTPM0_CH0_DMA	sTPM0.TPM_C0SC.BITS.DMA			// DMA Enable
#define bTPM0_CH0_ELS	sTPM0.TPM_C0SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH0_MS	sTPM0.TPM_C0SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH0_CHIE	sTPM0.TPM_C0SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH0_CHF	sTPM0.TPM_C0SC.BITS.CHF			// Channel Flag

#define rTPM0_C0V		sTPM0.TPM_C0V.WORD				// TPM0 Channel 0 Value
#define bTPM0_CH0_VAL	sTPM0.TPM_C0V.BITS.VAL	// Counter Value

#define rTPM0_C1SC		sTPM0.TPM_C1SC.WORD				// TPM0 Channel 1 Status Control
#define bTPM0_CH1_DMA	sTPM0.TPM_C1SC.BITS.DMA			// DMA Enable
#define bTPM0_CH1_ELS	sTPM0.TPM_C1SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH1_MS	sTPM0.TPM_C1SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH1_CHIE	sTPM0.TPM_C1SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH1_CHF	sTPM0.TPM_C1SC.BITS.CHF			// Channel Flag

#define rTPM0_C1V		sTPM0.TPM_C1V.WORD				// TPM0 Channel 1 Value
#define bTPM0_CH1_VAL	sTPM0.TPM_C1V.BITS.VAL		// Counter Value

#define rTPM0_C2SC		sTPM0.TPM_C2SC.WORD				// TPM0 Channel 2 Status Control
#define bTPM0_CH2_DMA	sTPM0.TPM_C2SC.BITS.DMA			// DMA Enable
#define bTPM0_CH2_ELS	sTPM0.TPM_C2SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH2_MS	sTPM0.TPM_C2SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH2_CHIE	sTPM0.TPM_C2SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH2_CHF	sTPM0.TPM_C2SC.BITS.CHF			// Channel Flag

#define rTPM0_C2V		sTPM0.TPM_C2V.WORD				// TPM0 Channel 2 Value
#define bTPM0_CH2_VAL	sTPM0.TPM_C2V.BITS.VAL		// Counter Value


#define rTPM0_C3SC		sTPM0.TPM_C3SC.WORD				// TPM0 Channel 3 Status Control
#define bTPM0_CH3_DMA	sTPM0.TPM_C3SC.BITS.DMA			// DMA Enable
#define bTPM0_CH3_ELS	sTPM0.TPM_C3SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH3_MS	sTPM0.TPM_C3SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH3_CHIE	sTPM0.TPM_C3SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH3_CHF	sTPM0.TPM_C3SC.BITS.CHF			// Channel Flag

#define rTPM0_C3V		sTPM0.TPM_C3V.WORD				//TPM0 Channel 3 Value
#define bTPM0_CH3_VAL	sTPM0.TPM_C3V.BITS.VAL		// Counter Value

#define rTPM0_C4SC		sTPM0.TPM_C4SC.WORD				// TPM0 Channel 4 Status Control
#define bTPM0_CH_DMA	sTPM0.TPM_C4SC.BITS.DMA			// DMA Enable
#define bTPM0_CH4_ELS	sTPM0.TPM_C4SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH4_MS	sTPM0.TPM_C4SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH4_CHIE	sTPM0.TPM_C4SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH4_CHF	sTPM0.TPM_C4SC.BITS.CHF			// Channel Flag

#define rTPM0_C4V		sTPM0.TPM_C4V.WORD				// TPM0 Channel 4 Value
#define bTPM0_CH4_VAL	sTPM0.TPM_C4V.BITS.VAL		// Counter Value

#define rTPM0_C5SC		sTPM0.TPM_C5SC.WORD				// TPM0 Channel 5 Status Control
#define bTPM0_CH5_DMA	sTPM0.TPM_C5SC.BITS.DMA			// DMA Enable
#define bTPM0_CH5_ELS	sTPM0.TPM_C5SC.BITS.ELSA		// Edge or Level Select
#define bTPM0_CH5_MS	sTPM0.TPM_C5SC.BITS.MSA			// Channel Mode Select
#define bTPM0_CH5_CHIE	sTPM0.TPM_C5SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM0_CH5_CHF	sTPM0.TPM_C5SC.BITS.CHF			// Channel Flag

#define rTPM0_C5V 		sTPM0.TPM_C5V.WORD				// TPM0 Channel 5 Value
#define bTPM0_CH5_VAL	sTPM0.TPM_C5V.BITS.VAL		// Counter Value

#define rTPM0_STATUS 	sTPM0.TPM_STATUS.WORD			// TPM0 Capture and Compare Status
#define bTPM0_CH0F		sTPM0.TPM_STATUS.BITS.CH0F		// Channel 0 Flag
#define bTPM0_CH1F		sTPM0.TPM_STATUS.BITS.CH1F		// Channel 1 Flag
#define bTPM0_CH2F		sTPM0.TPM_STATUS.BITS.CH2F		// Channel 2 Flag
#define bTPM0_CH3F		sTPM0.TPM_STATUS.BITS.CH3F		// Channel 3 Flag
#define bTPM0_CH4F		sTPM0.TPM_STATUS.BITS.CH4F		// Channel 4 Flag
#define bTPM0_CH5F		sTPM0.TPM_STATUS.BITS.CH5F		// Channel 5 Flag
#define bTPM0_TOF_ST	sTPM0.TPM_STATUS.BITS.TOF		// Timer Overflow Flag

#define rTPM0_POL		sTPM0.TPM_POL.WORD				// TPM0 Channel Polarity
#define bTPM0_POL0		sTPM0.TPM_POL.BITS.POL0			// Channel 0 Polarity
#define bTPM0_POL1		sTPM0.TPM_POL.BITS.POL1			// Channel 1 Polarity
#define bTPM0_POL2		sTPM0.TPM_POL.BITS.POL2			// Channel 2 Polarity
#define bTPM0_POL3		sTPM0.TPM_POL.BITS.POL3			// Channel 3 Polarity
#define bTPM0_POL4 		sTPM0.TPM_POL.BITS.POL4			// Channel 4 Polarity
#define bTPM0_POL5		sTPM0.TPM_POL.BITS.POL5			// Channel 5 Polarity

#define rTPM0_CONF		sTPM0.TPM_CONF.WORD				// TPM0 Configuration
#define bTPM0_DOZEEN	sTPM0.TPM_CONF.BITS.DOZEEN		// Doze Enable
#define bTPM0_DBGMODE	sTPM0.TPM_CONF.BITS.DBGMODE		// Debug Mode
#define bTPM0_GTBSYNC	sTPM0.TPM_CONF.BITS.GTBSYNC		// Global Time Base Synchronization
#define bTPM0_GTBEEN	sTPM0.TPM_CONF.BITS.GTBEEN		// Global time base enable
#define bTPM0_CSOT		sTPM0.TPM_CONF.BITS.CSOT		// Counter Start on Trigger
#define bTPM0_CSOO		sTPM0.TPM_CONF.BITS.CSOO		// Counter Stop On Overflow
#define bTPM0_CROT		sTPM0.TPM_CONF.BITS.CROT		// Counter Reload On Trigger
#define bTPM0_CPOT		sTPM0.TPM_CONF.BITS.CPOT		// Counter Pause On Trigger
#define bTPM0_TRGPOL	sTPM0.TPM_CONF.BITS.TRGPOL		// Trigger Polarity
#define bTPM0_TRGSRC	sTPM0.TPM_CONF.BITS.TRGSRC		// Trigger Source
#define bTPM0_TRGSEL	sTPM0.TPM_CONF.BITS.TRGSEL		// Trigger Select

///////////////////////////////////////////////////////
//                    TPM1                           //
///////////////////////////////////////////////////////

#define sTPM1           (*((__tpm_t *)(0x40039000)))	// TPM1 Global Structure

#define rTPM1_SC   		sTPM1.TPM_SC.WORD				// TPM1 Status Control
#define bTPM1_PS		sTPM1.TPM_SC.BITS.PS			// Prescale Factor Selection
#define bTPM1_CMOD		sTPM1.TPM_SC.BITS.CMOD			// Clock Mode Selection
#define bTPM1_CPWMS		sTPM1.TPM_SC.BITS.CPWMS			// Center-Aligned PWM Select
#define bTPM1_TOIE		sTPM1.TPM_SC.BITS.TOIE			// Timer Overflow Interrupt Enable
#define bTPM1_TOF_SC	sTPM1.TPM_SC.BITS.TOF			// Timer Overflow Flag
#define bTPM1_DMA		sTPM1.TPM_SC.BITS.DMA			// DMA Enable

#define rTPM1_CNT		sTPM1.TPM_CNT.WORD				// TPM1 Counter
#define bTPM1_COUNT		sTPM1.TPM_CNT.BITS.COUNT		// Counter value

#define rTPM1_MOD		sTPM1.TPM_MOD.WORD				// TPM1 Modulo
#define bTPM1_MOD		sTPM1.TPM_MOD.BITS.MOD			// Counter value

#define rTPM1_C0SC 		sTPM1.TPM_C0SC.WORD				// TPM1 Channel 0 Status Control
#define bTPM1_CH0_DMA	sTPM1.TPM_C0SC.BITS.DMA			// DMA Enable
#define bTPM1_CH0_ELS	sTPM1.TPM_C0SC.BITS.ELSA		// Edge or Level Select
#define bTPM1_CH0_MS	sTPM1.TPM_C0SC.BITS.MSA			// Channel Mode Select
#define bTPM1_CH0_CHIE	sTPM1.TPM_C0SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM1_CH0_CHF	sTPM1.TPM_C0SC.BITS.CHF			// Channel Flag

#define rTPM1_C0V		sTPM1.TPM_C0V.WORD				// TPM1 Channel 0 Value
#define bTPM1_CH0_VAL	sTPM1.TPM_C0V.BITS.VAL	// Counter Value

#define rTPM1_C1SC		sTPM1.TPM_C1SC.WORD				// TPM1 Channel 1 Status Control
#define bTPM1_CH1_DMA	sTPM1.TPM_C1SC.BITS.DMA			// DMA Enable
#define bTPM1_CH1_ELS	sTPM1.TPM_C1SC.BITS.ELS		// Edge or Level Select
#define bTPM1_CH1_MS	sTPM1.TPM_C1SC.BITS.MS			// Channel Mode Select
#define bTPM1_CH1_CHIE	sTPM1.TPM_C1SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM1_CH1_CHF	sTPM1.TPM_C1SC.BITS.CHF			// Channel Flag

#define rTPM1_C1V		sTPM1.TPM_C1V.WORD				// TPM1 Channel 1 Value
#define bTPM1_CH1_VAL	sTPM1.TPM_C1V.BITS.VAL		// Counter Value

#define rTPM1_STATUS 	sTPM1.TPM_STATUS.WORD			// TPM1 Capture and Compare Status
#define bTPM1_CH0F		sTPM1.TPM_STATUS.BITS.CH0F		// Channel 0 Flag
#define bTPM1_CH1F		sTPM1.TPM_STATUS.BITS.CH1F		// Channel 1 Flag
#define bTPM1_TOF_ST	sTPM1.TPM_STATUS.BITS.TOF		// Timer Overflow Flag

#define rTPM1_POL		sTPM1.TPM_POL.WORD				// TPM1 Channel Polarity
#define bTPM1_POL0		sTPM1.TPM_POL.BITS.POL0			// Channel 0 Polarity
#define bTPM1_POL1		sTPM1.TPM_POL.BITS.POL1			// Channel 1 Polarity

#define rTPM1_CONF		sTPM1.TPM_CONF.WORD				// TPM1 Configuration
#define bTPM1_DOZEEN	sTPM1.TPM_CONF.BITS.DOZEEN		// Doze Enable
#define bTPM1_DBGMODE	sTPM1.TPM_CONF.BITS.DBGMODE		// Debug Mode
#define bTPM1_GTBSYNC	sTPM1.TPM_CONF.BITS.GTBSYNC		// Global Time Base Synchronization
#define bTPM1_GTBEEN	sTPM1.TPM_CONF.BITS.GTBEEN		// Global time base enable
#define bTPM1_CSOT		sTPM1.TPM_CONF.BITS.CSOT		// Counter Start on Trigger
#define bTPM1_CSOO		sTPM1.TPM_CONF.BITS.CSOO		// Counter Stop On Overflow
#define bTPM1_CROT		sTPM1.TPM_CONF.BITS.CROT		// Counter Reload On Trigger
#define bTPM1_CPOT		sTPM1.TPM_CONF.BITS.CPOT		// Counter Pause On Trigger
#define bTPM1_TRGPOL	sTPM1.TPM_CONF.BITS.TRGPOL		// Trigger Polarity
#define bTPM1_TRGSRC	sTPM1.TPM_CONF.BITS.TRGSRC		// Trigger Source
#define bTPM1_TRGSEL	sTPM1.TPM_CONF.BITS.TRGSEL		// Trigger Select

///////////////////////////////////////////////////////
//                    TPM2                           //
///////////////////////////////////////////////////////

#define sTPM2           (*((__tpm_t *)(0x4003A000)))	// TPM2 Global Structure

#define rTPM2_SC   		sTPM2.TPM_SC.WORD				// TPM2 Status Control
#define bTPM2_PS		sTPM2.TPM_SC.BITS.PS			// Prescale Factor Selection
#define bTPM2_CMOD		sTPM2.TPM_SC.BITS.CMOD			// Clock Mode Selection
#define bTPM2_CPWMS		sTPM2.TPM_SC.BITS.CPWMS			// Center-Aligned PWM Select
#define bTPM2_TOIE		sTPM2.TPM_SC.BITS.TOIE			// Timer Overflow Interrupt Enable
#define bTPM2_TOF_SC	sTPM2.TPM_SC.BITS.TOF			// Timer Overflow Flag
#define bTPM2_DMA		sTPM2.TPM_SC.BITS.DMA			// DMA Enable

#define rTPM2_CNT		sTPM2.TPM_CNT.WORD				// TPM2 Counter
#define bTPM2_COUNT		sTPM2.TPM_CNT.BITS.COUNT		// Counter value

#define rTPM2_MOD		sTPM2.TPM_MOD.WORD				// TPM2 Modulo
#define bTPM2_MOD		sTPM2.TPM_MOD.BITS.MOD			// Counter value

#define rTPM2_C0SC 		sTPM2.TPM_C0SC.WORD				// TPM2 Channel 0 Status Control
#define bTPM2_CH0_DMA	sTPM2.TPM_C0SC.BITS.DMA			// DMA Enable
#define bTPM2_CH0_ELS	sTPM2.TPM_C0SC.BITS.ELS		// Edge or Level Select
#define bTPM2_CH0_MS	sTPM2.TPM_C0SC.BITS.MS			// Channel Mode Select
#define bTPM2_CH0_CHIE	sTPM2.TPM_C0SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM2_CH0_CHF	sTPM2.TPM_C0SC.BITS.CHF			// Channel Flag

#define rTPM2_C0V		sTPM2.TPM_C0V.WORD				// TPM2 Channel 0 Value
#define bTPM2_CH0_VAL	sTPM2.TPM_C0V.BITS.VAL	// Counter Value

#define rTPM2_C1SC		sTPM2.TPM_C1SC.WORD				// TPM2 Channel 1 Status Control
#define bTPM2_CH1_DMA	sTPM2.TPM_C1SC.BITS.DMA			// DMA Enable
#define bTPM2_CH1_ELS	sTPM2.TPM_C1SC.BITS.ELS		// Edge or Level Select
#define bTPM2_CH1_MS	sTPM2.TPM_C1SC.BITS.MS			// Channel Mode Select
#define bTPM2_CH1_CHIE	sTPM2.TPM_C1SC.BITS.CHIE		// Channel Interrupt Enable
#define bTPM2_CH1_CHF	sTPM2.TPM_C1SC.BITS.CHF			// Channel Flag

#define rTPM2_C1V		sTPM2.TPM_C1V.WORD				// TPM2 Channel 1 Value
#define bTPM2_CH1_VAL	sTPM2.TPM_C1V.BITS.VAL		// Counter Value

#define rTPM2_STATUS 	sTPM2.TPM_STATUS.WORD			// TPM2 Capture and Compare Status
#define bTPM2_CH0F		sTPM2.TPM_STATUS.BITS.CH0F		// Channel 0 Flag
#define bTPM2_CH1F		sTPM2.TPM_STATUS.BITS.CH1F		// Channel 1 Flag
#define bTPM2_TOF_ST	sTPM2.TPM_STATUS.BITS.TOF		// Timer Overflow Flag

#define rTPM2_POL		sTPM2.TPM_POL.WORD				// TPM2 Channel Polarity
#define bTPM2_POL0		sTPM2.TPM_POL.BITS.POL0			// Channel 0 Polarity
#define bTPM2_POL1		sTPM2.TPM_POL.BITS.POL1			// Channel 1 Polarity

#define rTPM2_CONF		sTPM2.TPM_CONF.WORD				// TPM2 Configuration
#define bTPM2_DOZEEN	sTPM2.TPM_CONF.BITS.DOZEEN		// Doze Enable
#define bTPM2_DBGMODE	sTPM2.TPM_CONF.BITS.DBGMODE		// Debug Mode
#define bTPM2_GTBSYNC	sTPM2.TPM_CONF.BITS.GTBSYNC		// Global Time Base Synchronization
#define bTPM2_GTBEEN	sTPM2.TPM_CONF.BITS.GTBEEN		// Global time base enable
#define bTPM2_CSOT		sTPM2.TPM_CONF.BITS.CSOT		// Counter Start on Trigger
#define bTPM2_CSOO		sTPM2.TPM_CONF.BITS.CSOO		// Counter Stop On Overflow
#define bTPM2_CROT		sTPM2.TPM_CONF.BITS.CROT		// Counter Reload On Trigger
#define bTPM2_CPOT		sTPM2.TPM_CONF.BITS.CPOT		// Counter Pause On Trigger
#define bTPM2_TRGPOL	sTPM2.TPM_CONF.BITS.TRGPOL		// Trigger Polarity
#define bTPM2_TRGSRC	sTPM2.TPM_CONF.BITS.TRGSRC		// Trigger Source
#define bTPM2_TRGSEL	sTPM2.TPM_CONF.BITS.TRGSEL		// Trigger Select

#endif
