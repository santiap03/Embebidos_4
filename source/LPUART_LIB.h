/*
 * LPUART_LIB.h
 *
 *  Created on: 29/10/2017
 *      Author: Ricardo
 */

#ifndef LPUART_LIB_H_
#define LPUART_LIB_H_
#include <stdint.h>

#define mLPUART_BAUD_SBR(X) (X & 0x00001FFFU)				// Baud Rate Modulo Divisor
#define mLPUART_BAUD_MATCFG(X) ((X & 0x00000003U)<<18)		// Match Configuration
#define mLPUART_BAUD_OSR(X) ((X & 0x0000001FU)<<24)			// Over Sampling Ratio

enum{
	mLPUART_BAUD_SBNS =	0x00002000U,						// Stop Bit Number Select
	mLPUART_BAUD_RXEDGIE = 0x00004000U,						// RX Input Active Edge Interrupt Enable
	mLPUART_BAUD_LBKDIE = 0x00008000U,						// LIN Break Detect Interrupt Enable
	mLPUART_BAUD_RESYNCDIS = 0x00010000U,					// Resynchronization Disable
	mLPUART_BAUD_BOTHEDGE =	0x00020000U,					// Both Edge Sampling
	mLPUART_BAUD_RDMAE = 0x00200000U,						// Receiver Full DMA Enable
	mLPUART_BAUD_TDMAE = 0x00800000U,						// Transmitter DMA Enable
	mLPUART_BAUD_M10 = 0x20000000U,							// 10-bit Mode select
	mLPUART_BAUD_MAEN2 = 0x40000000U,						// Match Address Mode Enable 2
	mLPUART_BAUD_MAEN1 = 0x80000000U						// Match Address Mode Enable 1
};

enum{
	kLPUART_MATCFG_ADD_MATCH_WAKEUP,						// Address Match Wakeup
	kLPUART_MATCFG_IDLE_MATCH_WAKEUP,						// Idle Match Wakeup
	kLPUART_MATCFG_MATCH_ON_MATCH_OFF,						// Match On and Match Off
	kLPUART_MATCFG_EN_RWU_DATA_MATCH						// Enables RWU on Data Match and Match On/Off
};

enum{
	kLPUART_OVERSAMPLING_4x = 3,
	kLPUART_OVERSAMPLING_5x,
	kLPUART_OVERSAMPLING_6x,
	kLPUART_OVERSAMPLING_7x,
	kLPUART_OVERSAMPLING_8x,
	kLPUART_OVERSAMPLING_9x,
	kLPUART_OVERSAMPLING_10x,
	kLPUART_OVERSAMPLING_11x,
	kLPUART_OVERSAMPLING_12x,
	kLPUART_OVERSAMPLING_13x,
	kLPUART_OVERSAMPLING_14x,
	kLPUART_OVERSAMPLING_15x,
	kLPUART_OVERSAMPLING_16x,
	kLPUART_OVERSAMPLING_17x,
	kLPUART_OVERSAMPLING_18x,
	kLPUART_OVERSAMPLING_19x,
	kLPUART_OVERSAMPLING_20x,
	kLPUART_OVERSAMPLING_21x,
	kLPUART_OVERSAMPLING_22x,
	kLPUART_OVERSAMPLING_23x,
	kLPUART_OVERSAMPLING_24x,
	kLPUART_OVERSAMPLING_25x,
	kLPUART_OVERSAMPLING_26x,
	kLPUART_OVERSAMPLING_27x,
	kLPUART_OVERSAMPLING_28x,
	kLPUART_OVERSAMPLING_29x,
	kLPUART_OVERSAMPLING_30x,
	kLPUART_OVERSAMPLING_31x,
	kLPUART_OVERSAMPLING_32x
};

typedef union {
	uint32_t WORD;											// Access to the whole register
	struct {
		uint32_t SBR			:13;  						// Baud Rate Modulo Divisor
		uint32_t SBNS			:1;	  						// Stop Bit Number Select
		uint32_t RXEDGIE 		:1;							// RX Input Active Edge Interrupt Enable
		uint32_t LBKDIE			:1;	  						// LIN Break Detect Interrupt Enable
		uint32_t RESYNCDIS		:1;	  						// Resynchronization Disable
		uint32_t BOTHEDGE		:1;	  						// Both Edge Sampling
		uint32_t MATCFG			:2;	  						// Match Configuration
		uint32_t				:1;	  						// Reserved
		uint32_t RDMAE			:1;	  						// Receiver Full DMA Enable
		uint32_t 				:1;	  						// Reserved
		uint32_t TDMAE			:1;	  						// Transmitter DMA Enable
		uint32_t OSR			:5;	  						// Over Sampling Ratio
		uint32_t M10			:1;	  						// 10-bit Mode select
		uint32_t MAEN2			:1;	  						// Match Address Mode Enable 2
		uint32_t MAEN1			:1;	  						// Match Address Mode Enable 1
	} BITS;
} __lpuart_baud_t;

enum{
	mLPUART_STAT_MA2F =	0x00004000U,						// Match 2 Flag
	mLPUART_STAT_MA1F =	0x00008000U,						// Match 1 Flag
	mLPUART_STAT_PF = 0x00010000U,							// Parity Error Flag
	mLPUART_STAT_FE = 0x00020000U,							//Framing Error Flag
	mLPUART_STAT_NF = 0x00040000U,							// Noise Flag
	mLPUART_STAT_OR = 0x00080000U,							// Receiver Overrun Flag
	mLPUART_STAT_IDLE =	0x00100000U,						// Idle Line Flag
	mLPUART_STAT_RDRF =	0x00200000U,						// Receive Data Register Full Flag
	mLPUART_STAT_TC = 0x00400000U,							// Transmission Complete Flag
	mLPUART_STAT_TDRE =	0x00800000U,						// Transmit Data Register Empty Flag
	mLPUART_STAT_RAF = 0x01000000U,							// Receiver Active Flag
	mLPUART_STAT_LBKDE = 0x02000000U,						// LIN Break Detection Enable
	mLPUART_STAT_BRK13 = 0x04000000U,						// Break Character Generation Length
	mLPUART_STAT_RWUID = 0x08000000U,						// Receive Wake Up Idle Detect
	mLPUART_STAT_RXINV = 0x10000000U,						// Receive Data Inversion
	mLPUART_STAT_MSBF =	0x20000000U,						// MSB First
	mLPUART_STAT_RXEDGIF = 0x40000000U,						// LPUART_RX Pin Active Edge Interrupt Flag
	mLPUART_STAT_LBKDIF = 0x80000000U						// LIN Break Detect Interrupt Flag
};
typedef union {
	uint32_t WORD;											// Access to the whole register
	struct {
		uint32_t			:14;	  						//
		uint32_t MA2F		:1;	  							// Match 2 Flag
		uint32_t MA1F 		:1;								// Match 1 Flag
		uint32_t PF			:1;	  							// Parity Error Flag
		uint32_t FE			:1;	  							// Framing Error Flag
		uint32_t NF			:1;	  							// Noise Flag
		uint32_t OR			:1;	  							// Receiver Overrun Flag
		uint32_t IDLE		:1;	  							// Idle Line Flag
		uint32_t RDRF		:1;	  							// Receive Data Register Full Flag
		uint32_t TC			:1;	  							// Transmission Complete Flag
		uint32_t TDRE		:1;								// Transmit Data Register Empty Flag
		uint32_t RAF		:1;	  							// Receiver Active Flag
		uint32_t LBKDE		:1;	  							// LIN Break Detection Enable
		uint32_t BRK13		:1;	  							// Break Character Generation Length
		uint32_t FWUID		:1;	  							// Receive Wake Up Idle Detect
		uint32_t RXINV		:1;	  							// Receive Data Inversion
		uint32_t MSBF		:1;	  							// MSB First
		uint32_t RXEDGIF	:1;	  							// LPUART_RX Pin Active Edge Interrupt Flag
		uint32_t LBKDIF 	:1;								// LIN Break Detect Interrupt Flag
	} BITS;
} __lpuart_stat_t;

#define mLPUART_CTRL_IDLECFG(X) ((X & 0x00000003U)<<8)		// Idle Configuration

enum{
	mLPUART_CTRL_PT = 0x00000001U,							// Parity Type
	mLPUART_CTRL_PE = 0x00000002U,							// Parity Enable
	mLPUART_CTRL_ILT = 0x00000004U,							// Idle Line Type Select
	mLPUART_CTRL_WAKE = 0x00000008U,						// Receiver Wakeup Method Select
	mLPUART_CTRL_M = 0x00000010U,							// 9-Bit or 8-Bit Mode Select
	mLPUART_CTRL_RSRC = 0x00000020U,						// Receiver Source Select
	mLPUART_CTRL_DOZEEN = 0x00000040U,						// Doze Enable
	mLPUART_CTRL_LOOPS = 0x00000080U,						// Loop Mode Select
	mLPUART_CTRL_MA2IE = 0x00004000U,						// Match 2 Interrupt Enable
	mLPUART_CTRL_MA1IE = 0x00008000U,						// Match 1 Interrupt Enable
	mLPUART_CTRL_SBK = 0x00010000U,							// Send Break
	mLPUART_CTRL_RWU = 0x00020000U,							// Receiver Wakeup Control
	mLPUART_CTRL_RE = 0x00040000U,							// Receiver Enable
	mLPUART_CTRL_TE = 0x00080000U,							// Transmitter Enable
	mLPUART_CTRL_ILIE = 0x00100000U,						// Idle Line Interrupt Enable
	mLPUART_CTRL_RIE = 0x00200000U,							// Receiver Interrupt Enable
	mLPUART_CTRL_TCIE = 0x00400000U,						// Transmission Complete Interrupt Enable for
	mLPUART_CTRL_TIE = 0x00800000U,							// Transmit Interrupt Enable
	mLPUART_CTRL_PEIE =	0x01000000U,						// Parity Error Interrupt Enable
	mLPUART_CTRL_FEIE =	0x02000000U,						// Framing Error Interrupt Enable
	mLPUART_CTRL_NEIE =	0x04000000U,						// Noise Error Interrupt Enable
	mLPUART_CTRL_ORIE =	0x08000000U,						// Overrun Interrupt Enable
	mLPUART_CTRL_TXINV = 0x10000000U,						// Transmit Data Inversion
	mLPUART_CTRL_TXDIR = 0x20000000U,						// LPUART_TX Pin Direction in Single-Wire Mode
	mLPUART_CTRL_R9T8 =	0x40000000U,						// Receive Bit 9 / Transmit Bit 8
	mLPUART_CTRL_R8T9 =	0x80000000U							// Receive Bit 8 / Transmit Bit 9
};

enum{
	kLPUART_IDLECFG_1_IDLE_CH,								// 1 idle character
	kLPUART_IDLECFG_2_IDLE_CH,								// 2 idle character
	kLPUART_IDLECFG_4_IDLE_CH,								// 4 idle character
	kLPUART_IDLECFG_8_IDLE_CH,								// 8 idle character
	kLPUART_IDLECFG_16_IDLE_CH,								// 16 idle character
	kLPUART_IDLECFG_32_IDLE_CH,								// 32 idle character
	kLPUART_IDLECFG_64_IDLE_CH,								// 64 idle character
	kLPUART_IDLECFG_128_IDLE_CH								// 128 idle character
};
typedef union {
	uint32_t WORD;										// Access to the whole register
	struct {
		uint32_t PT			:1;	  							// Parity Type
		uint32_t PE			:1;	  							// Parity Enable
		uint32_t ILT		:1;								// Idle Line Type Select
		uint32_t WAKE		:1;	  							// Receiver Wakeup Method Select
		uint32_t M			:1;	  							// 9-Bit or 8-Bit Mode Select
		uint32_t RSRC		:1;	  							// Receiver Source Select
		uint32_t DOZEEN		:1;	  							// Doze Enable
		uint32_t LOOPS		:1;	  							// Loop Mode Select
		uint32_t IDLECFG	:3;	  							// Idle Configuration
		uint32_t 			:3;	  							// Reserved
		uint32_t MA2IE		:1;								// Match 2 Interrupt Enable
		uint32_t MA1IE		:1;	  							// Match 1 Interrupt Enable
		uint32_t SBK		:1;	  							// Send Break
		uint32_t RWU		:1;	  							// Receiver Wakeup Control
		uint32_t RE			:1;	  							// Receiver Enable
		uint32_t TE			:1;	  							// Transmitter Enable
		uint32_t ILIE		:1;	  							// Idle Line Interrupt Enable
		uint32_t RIE		:1;	  							// Receiver Interrupt Enable
		uint32_t TCIE		:1;								// Transmission Complete Interrupt Enable for
		uint32_t TIE		:1;	  							// Transmit Interrupt Enable
		uint32_t PEIE		:1;	  							// Parity Error Interrupt Enable
		uint32_t FEIE		:1;	  							// Framing Error Interrupt Enable
		uint32_t NEIE		:1;	  							// Noise Error Interrupt Enable
		uint32_t ORIE		:1;	  							// Overrun Interrupt Enable
		uint32_t TXINV		:1;	  							// Transmit Data Inversion
		uint32_t TXDIR		:1;	  							// LPUART_TX Pin Direction in Single-Wire Mode
		uint32_t R9T8		:1;								// Receive Bit 9 / Transmit Bit 8
		uint32_t R8T9		:1;	  							// Receive Bit 8 / Transmit Bit 9
	} BITS;
} __lpuart_ctrl_t;

#define mLPUART_DATA_8BITS(X) = (X & 0x000000FFU)			// 8 bits data
#define mLPUART_DATA_9BITS(X) = (X & 0x000001FFU)			// 9 bits data
#define mLPUART_DATA_10BITS(X) = (X & 0x000003FFU)			// 10 bits data

enum{
	mLPUART_DATA_R0T0 =	0x00000001U,						// Read receive data buffer 0 or write transmit data buffer 0
	mLPUART_DATA_R1T1 =	0x00000002U,						// Read receive data buffer 1 or write transmit data buffer 1
	mLPUART_DATA_R2T2 =	0x00000004U,						// Read receive data buffer 2 or write transmit data buffer 2
	mLPUART_DATA_R3T3 =	0x00000008U,						// Read receive data buffer 3 or write transmit data buffer 3
	mLPUART_DATA_R4T4 =	0x00000010U,						// Read receive data buffer 4 or write transmit data buffer 4
	mLPUART_DATA_R5T5 =	0x00000020U,						// Read receive data buffer 5 or write transmit data buffer 5
	mLPUART_DATA_R6T6 =	0x00000040U,						// Read receive data buffer 6 or write transmit data buffer 6
	mLPUART_DATA_R7T7 =	0x00000080U,						// Read receive data buffer 7 or write transmit data buffer 7
	mLPUART_DATA_R8T8 =	0x00000100U,						// Read receive data buffer 8 or write transmit data buffer 8
	mLPUART_DATA_R9T9 =	0x00000200U,						// Read receive data buffer 9 or write transmit data buffer 9
	mLPUART_DATA_IDLINE = 0x00000800U,						// Idle Line
	mLPUART_DATA_RXEMPT = 0x00001000U,						// Receive Buffer Empty
	mLPUART_DATA_FRETSC = 0x00002000U,						// Frame Error / Transmit Special Character
	mLPUART_DATA_PARITYE = 0x00004000U,						// The current received data word contained in DATA[R9:R0] was received with a parity error.
	mLPUART_DATA_NOISY = 0x00008000U						// The current received data word contained in DATA[R9:R0] was received with noise
};

typedef union {
	uint32_t WORD;										// Access to the whole register
	struct {
		uint32_t R0T0		:1;	  							// Read receive data buffer 0 or write transmit data buffer 0.
		uint32_t R1T1		:1;	  							// Read receive data buffer 1 or write transmit data buffer 1.
		uint32_t R2T2 		:1;								// Read receive data buffer 2 or write transmit data buffer 2.
		uint32_t R3T3		:1;	  							// Read receive data buffer 3 or write transmit data buffer 3.
		uint32_t R4T4		:1;	  							// Read receive data buffer 4 or write transmit data buffer 4.
		uint32_t R5T5		:1;	  							// Read receive data buffer 5 or write transmit data buffer 5.
		uint32_t R6T6		:1;	  							// Read receive data buffer 6 or write transmit data buffer 6.
		uint32_t R7T7		:1;	  							// Read receive data buffer 7 or write transmit data buffer 7.
		uint32_t R8T8		:1;	  							// Read receive data buffer 8 or write transmit data buffer 8.
		uint32_t R9T9		:1;	  							// Read receive data buffer 9 or write transmit data buffer 9.
		uint32_t			:1;	  							//
		uint32_t IDLINE		:1;	  							// Idle Line
		uint32_t RXEMPT		:1;	  							// Receive Buffer Empty
		uint32_t FRETSC		:1;	  							// Frame Error / Transmit Special Character
		uint32_t PARITYE	:1;	  							// The current received data word contained in DATA[R9:R0] was received with a parity error.
		uint32_t NOISY		:1;	  							// The current received data word contained in DATA[R9:R0] was received with noise
		uint32_t			:16;							// Reserved
	} BITS;
	struct {
		uint32_t DATA_8BITS :8;								// 8 bits data
		uint32_t			:24;							// Reserved
	}BYTE;
	struct {
		uint32_t DATA_9BITS :9;								// 9 bits data
		uint32_t			:23;							// Reserved
	}BITS9;
	struct {
		uint32_t DATA_10BITS :10;							// 10 bits data
		uint32_t			:22;							// Reserved
	}BITS10;
} __lpuart_data_t;

#define mLPUART_MATCH_MA1(X) = (X & 0x000003FFU)			// Match Address 1
#define mLPUART_MATCH_MA2(X) = ((X & 0x000003FFU)<<16)		// Match Address 2

typedef union {
	uint32_t WORD;										// Access to the whole register
	struct {
		uint32_t MA1		:10;	  						// Match Address 1
		uint32_t 			:6;	  							//
		uint32_t MA2 		:10;							// Match Address 2
		uint32_t			:6;	  							//
	} BITS;
} __lpuart_match_t;

typedef struct{
	volatile __lpuart_baud_t BAUD;							// x000 LPUART Baud Rate Register (LPUART0_BAUD)
	volatile __lpuart_stat_t STAT;							// x004 LPUART Status Register (LPUART0_STAT)
	volatile __lpuart_ctrl_t CTRL;							// x008 LPUART Control Register (LPUART0_CTRL)
	volatile __lpuart_data_t DATA;							// x00C LPUART Data Register (LPUART0_DATA)
	volatile __lpuart_match_t MATCH;						// x010 LPUART Match Address Register (LPUART0_MATCH)
}__lpuart_t;


// LPUART0

#define sLPUART0 (*((__lpuart_t *)(0x40054000)))			// LPUART0 module general register structure

#define rLPUART0_BAUD sLPUART0.BAUD.WORD					// x000 LPUART Baud Rate Register (LPUART0_BAUD)
#define bLPUART0_SBR sLPUART0.BAUD.BITS.SBR  				// Baud Rate Modulo Divisor
#define bLPUART0_SBNS sLPUART0.BAUD.BITS.SBNS	  			// Stop Bit Number Select
#define bLPUART0_RXEDGIE sLPUART0.BAUD.BITS.RXEDGIE			// RX Input Active Edge Interrupt Enable
#define bLPUART0_LBKDIE sLPUART0.BAUD.BITS.LBKDIE	  		// LIN Break Detect Interrupt Enable
#define bLPUART0_RESYNCDIS sLPUART0.BAUD.BITS.RESYNCDIS	  	// Resynchronization Disable
#define bLPUART0_BOTHEDGE sLPUART0.BAUD.BITS.BOTHEDGE	  	// Both Edge Sampling
#define bLPUART0_MATCFG sLPUART0.BAUD.BITS.MATCFG	  		// Match Configuration
#define bLPUART0_RDMAE sLPUART0.BAUD.BITS.RDMAE	  			// Receiver Full DMA Enable
#define bLPUART0_TDMAE sLPUART0.BAUD.BITS.TDMAE	  			// Transmitter DMA Enable
#define bLPUART0_OSR sLPUART0.BAUD.BITS.OSR	  				// Over Sampling Ratio
#define bLPUART0_M10 sLPUART0.BAUD.BITS.M10	  				// 10-bit Mode select
#define bLPUART0_MAEN2 sLPUART0.BAUD.BITS.MAEN2	  			// Match Address Mode Enable 2
#define bLPUART0_MAEN1 sLPUART0.BAUD.BITS.MAEN1	  			// Match Address Mode Enable 1

#define rLPUART0_STAT sLPUART0.STAT.WORD					// x004 LPUART Status Register (LPUART0_STAT)
#define bLPUART0_MA2F sLPUART0.STAT.BITS.MA2F	  			// Match 2 Flag
#define bLPUART0_MA1F sLPUART0.STAT.BITS.MA1F				// Match 1 Flag
#define bLPUART0_PF	sLPUART0.STAT.BITS.PF	  				// Parity Error Flag
#define bLPUART0_FE	sLPUART0.STAT.BITS.FE	  				// Framing Error Flag
#define bLPUART0_NF	sLPUART0.STAT.BITS.NF	  				// Noise Flag
#define bLPUART0_OR	sLPUART0.STAT.BITS.OR	  				// Receiver Overrun Flag
#define bLPUART0_IDLE sLPUART0.STAT.BITS.IDLE	  			// Idle Line Flag
#define bLPUART0_RDRF sLPUART0.STAT.BITS.RDRF	  			// Receive Data Register Full Flag
#define bLPUART0_TC	sLPUART0.STAT.BITS.TC	  				// Transmission Complete Flag
#define bLPUART0_TDRE sLPUART0.STAT.BITS.TDRE				// Transmit Data Register Empty Flag
#define bLPUART0_RAF sLPUART0.STAT.BITS.RAF	  				// Receiver Active Flag
#define bLPUART0_LBKDE sLPUART0.STAT.BITS.LBKDE	  			// LIN Break Detection Enable
#define bLPUART0_BRK13 sLPUART0.STAT.BITS.BRK13	  			// Break Character Generation Length
#define bLPUART0_FWUID sLPUART0.STAT.BITS.FWUID	  			// Receive Wake Up Idle Detect
#define bLPUART0_RXINV sLPUART0.STAT.BITS.RXINV	  			// Receive Data Inversion
#define bLPUART0_MSBF sLPUART0.STAT.BITS.MSBF	  			// MSB First
#define bLPUART0_RXEDGIF sLPUART0.STAT.BITS.RXEDGIF	  		// LPUART_RX Pin Active Edge Interrupt Flag
#define bLPUART0_LBKDIF sLPUART0.STAT.BITS.LBKDIF			// LIN Break Detect Interrupt Flag

#define rLPUART0_CTRL sLPUART0.CTRL.WORD					// x008 LPUART Control Register (LPUART0_CTRL)
#define bLPUART0_PT sLPUART0.CTRL.BITS.PT	  				// Parity Type
#define bLPUART0_PE	sLPUART0.CTRL.BITS.PE	  				// Parity Enable
#define bLPUART0_ILT sLPUART0.CTRL.BITS.ILT					// Idle Line Type Select
#define bLPUART0_WAKE sLPUART0.CTRL.BITS.WAKE	  			// Receiver Wakeup Method Select
#define bLPUART0_M	 sLPUART0.CTRL.BITS.M	  				// 9-Bit or 8-Bit Mode Select
#define bLPUART0_RSRC sLPUART0.CTRL.BITS.RSRC	  			// Receiver Source Select
#define bLPUART0_DOZEEN sLPUART0.CTRL.BITS.DOZEEN	  		// Doze Enable
#define bLPUART0_LOOPS sLPUART0.CTRL.BITS.LOOPS	  			// Loop Mode Select
#define bLPUART0_IDLECFG sLPUART0.CTRL.BITS.IDLECFG	  		// Idle Configuration
#define bLPUART0_MA2IE sLPUART0.CTRL.BITS.MA2IE				// Match 2 Interrupt Enable
#define bLPUART0_MA1IE sLPUART0.CTRL.BITS.MA1IE	  			// Match 1 Interrupt Enable
#define bLPUART0_SBK sLPUART0.CTRL.BITS.SBK	  				// Send Break
#define bLPUART0_RWU sLPUART0.CTRL.BITS.RWU	  				// Receiver Wakeup Control
#define bLPUART0_RE	 sLPUART0.CTRL.BITS.RE	  				// Receiver Enable
#define bLPUART0_TE	 sLPUART0.CTRL.BITS.TE	  				// Transmitter Enable
#define bLPUART0_ILIE sLPUART0.CTRL.BITS.ILIE	  			// Idle Line Interrupt Enable
#define bLPUART0_RIE sLPUART0.CTRL.BITS.RIE	  				// Receiver Interrupt Enable
#define bLPUART0_TCIE sLPUART0.CTRL.BITS.TCIE				// Transmission Complete Interrupt Enable for
#define bLPUART0_TIE sLPUART0.CTRL.BITS.TIE	  				// Transmit Interrupt Enable
#define bLPUART0_PEIE sLPUART0.CTRL.BITS.PEIE	  			// Parity Error Interrupt Enable
#define bLPUART0_FEIE sLPUART0.CTRL.BITS.FEIE	  			// Framing Error Interrupt Enable
#define bLPUART0_NEIE sLPUART0.CTRL.BITS.NEIE	  			// Noise Error Interrupt Enable
#define bLPUART0_ORIE sLPUART0.CTRL.BITS.ORIE	  			// Overrun Interrupt Enable
#define bLPUART0_TXINV sLPUART0.CTRL.BITS.TXINV	  			// Transmit Data Inversion
#define bLPUART0_TXDIR sLPUART0.CTRL.BITS.TDIR	  			// LPUART_TX Pin Direction in Single-Wire Mode
#define bLPUART0_R9T8 sLPUART0.CTRL.BITS.R9T8				// Receive Bit 9 / Transmit Bit 8
#define bLPUART0_R8T9 sLPUART0.CTRL.BITS.R8T9	  			// Receive Bit 8 / Transmit Bit 9

#define rLPUART0_DATA sLPUART0.DATA.WORD					// x00C LPUART Data Register (LPUART0_DATA)
#define bLPUART0_DATA_8BITS sLPUART0.DATA.BYTE.DATA_8BITS	//
#define bLPUART0_DATA_9BITS sLPUART0.DATA.BITS9.DATA_9BITS	//
#define bLPUART0_DATA_10BITS sLPUART0.DATA.BITS10.DATA_10BITS	//
#define bLPUART0_R0T0 sLPUART0.DATA.BITS.R0T0	  			// Read receive data buffer 0 or write transmit data buffer 0.
#define bLPUART0_R1T1 sLPUART0.DATA.BITS.R1T1	  			// Read receive data buffer 1 or write transmit data buffer 1.
#define bLPUART0_R2T2 sLPUART0.DATA.BITS.R2T2				// Read receive data buffer 2 or write transmit data buffer 2.
#define bLPUART0_R3T3 sLPUART0.DATA.BITS.R3T3	  			// Read receive data buffer 3 or write transmit data buffer 3.
#define bLPUART0_R4T4 sLPUART0.DATA.BITS.R4T4	  			// Read receive data buffer 4 or write transmit data buffer 4.
#define bLPUART0_R5T5 sLPUART0.DATA.BITS.R5T5	  			// Read receive data buffer 5 or write transmit data buffer 5.
#define bLPUART0_R6T6 sLPUART0.DATA.BITS.R6T6	  			// Read receive data buffer 6 or write transmit data buffer 6.
#define bLPUART0_R7T7 sLPUART0.DATA.BITS.R7T7	  			// Read receive data buffer 7 or write transmit data buffer 7.
#define bLPUART0_R8T8 sLPUART0.DATA.BITS.R8T8	  			// Read receive data buffer 8 or write transmit data buffer 8.
#define bLPUART0_R9T9 sLPUART0.DATA.BITS.R9T9	  			// Read receive data buffer 9 or write transmit data buffer 9.
#define bLPUART0_IDLINE sLPUART0.DATA.BITS.IDLINE	  		// Idle Line
#define bLPUART0_RXEMPT sLPUART0.DATA.BITS.RXEMPT	  		// Receive Buffer Empty
#define bLPUART0_FRETSC sLPUART0.DATA.BITS.FRETSC	  		// Frame Error / Transmit Special Character
#define bLPUART0_PARITYE sLPUART0.CTRL.BITS.PARITYE	  		// The current received data word contained in DATA[R9:R0] was received with a parity error.
#define bLPUART0_NOISY sLPUART0.DATA.BITS.NOISY	  			// The current received data word contained in DATA[R9:R0] was received with noise

#define rLPUART0_MATCH sLPUART0.MATCH.WORD					// x010 LPUART Match Address Register (LPUART0_MATCH)
#define bLPUART0_MA1 sLPUART0.MATCH.BITS.MA1	  			// Match Address 1
#define bLPUART0_MA2 sLPUART0.MATCH.BITS.MA2				// Match Address 2


// LPUART1

#define sLPUART1 (*((__lpuart_t *)(0x40055000)))			// LPUART1 module general register structure

#define rLPUART1_BAUD sLPUART1.BAUD.WORD					// x000 LPUART Baud Rate Register (LPUART1_BAUD)
#define bLPUART1_SBR sLPUART1.BAUD.BITS.SBR  				// Baud Rate Modulo Divisor
#define bLPUART1_SBNS sLPUART1.BAUD.BITS.SBNS	  			// Stop Bit Number Select
#define bLPUART1_RXEDGIE sLPUART1.BAUD.BITS.RXEDGIE			// RX Input Active Edge Interrupt Enable
#define bLPUART1_LBKDIE sLPUART1.BAUD.BITS.LBKDIE	  		// LIN Break Detect Interrupt Enable
#define bLPUART1_RESYNCDIS sLPUART1.BAUD.BITS.RESYNCDIS	  	// Resynchronization Disable
#define bLPUART1_BOTHEDGE sLPUART1.BAUD.BITS.BOTHEDGE	  	// Both Edge Sampling
#define bLPUART1_MATCFG sLPUART1.BAUD.BITS.MATCFG	  		// Match Configuration
#define bLPUART1_RDMAE sLPUART1.BAUD.BITS.RDMAE	  			// Receiver Full DMA Enable
#define bLPUART1_TDMAE sLPUART1.BAUD.BITS.TDMAE	  			// Transmitter DMA Enable
#define bLPUART1_OSR sLPUART1.BAUD.BITS.OSR	  				// Over Sampling Ratio
#define bLPUART1_M10 sLPUART1.BAUD.BITS.M10	  				// 10-bit Mode select
#define bLPUART1_MAEN2 sLPUART1.BAUD.BITS.MAEN2	  			// Match Address Mode Enable 2
#define bLPUART1_MAEN1 sLPUART1.BAUD.BITS.MAEN1	  			// Match Address Mode Enable 1

#define rLPUART1_STAT sLPUART1.STAT.WORD					// x004 LPUART Status Register (LPUART1_STAT)
#define bLPUART1_MA2F sLPUART1.STAT.BITS.MA2F	  			// Match 2 Flag
#define bLPUART1_MA1F sLPUART1.STAT.BITS.MA1F				// Match 1 Flag
#define bLPUART1_PF	sLPUART1.STAT.BITS.PF	  				// Parity Error Flag
#define bLPUART1_FE	sLPUART1.STAT.BITS.FE	  				// Framing Error Flag
#define bLPUART1_NF	sLPUART1.STAT.BITS.NF	  				// Noise Flag
#define bLPUART1_OR	sLPUART1.STAT.BITS.OR	  				// Receiver Overrun Flag
#define bLPUART1_IDLE sLPUART1.STAT.BITS.IDLE	  			// Idle Line Flag
#define bLPUART1_RDRF sLPUART1.STAT.BITS.RDRF	  			// Receive Data Register Full Flag
#define bLPUART1_TC	sLPUART1.STAT.BITS.TC	  				// Transmission Complete Flag
#define bLPUART1_TDRE sLPUART1.STAT.BITS.TDRE				// Transmit Data Register Empty Flag
#define bLPUART1_RAF sLPUART1.STAT.BITS.RAF	  				// Receiver Active Flag
#define bLPUART1_LBKDE sLPUART1.STAT.BITS.LBKDE	  			// LIN Break Detection Enable
#define bLPUART1_BRK13 sLPUART1.STAT.BITS.BRK13	  			// Break Character Generation Length
#define bLPUART1_FWUID sLPUART1.STAT.BITS.FWUID	  			// Receive Wake Up Idle Detect
#define bLPUART1_RXINV sLPUART1.STAT.BITS.RXINV	  			// Receive Data Inversion
#define bLPUART1_MSBF sLPUART1.STAT.BITS.MSBF	  			// MSB First
#define bLPUART1_RXEDGIF sLPUART1.STAT.BITS.RXEDGIF	  		// LPUART_RX Pin Active Edge Interrupt Flag
#define bLPUART1_LBKDIF sLPUART1.STAT.BITS.LBKDIF			// LIN Break Detect Interrupt Flag

#define rLPUART1_CTRL sLPUART1.CTRL.WORD					// x008 LPUART Control Register (LPUART1_CTRL)
#define bLPUART1_PT sLPUART1.CTRL.BITS.PT	  				// Parity Type
#define bLPUART1_PE	sLPUART1.CTRL.BITS.PE	  				// Parity Enable
#define bLPUART1_ILT sLPUART1.CTRL.BITS.ILT					// Idle Line Type Select
#define bLPUART1_WAKE sLPUART1.CTRL.BITS.WAKE	  			// Receiver Wakeup Method Select
#define bLPUART1_M	 sLPUART1.CTRL.BITS.M	  				// 9-Bit or 8-Bit Mode Select
#define bLPUART1_RSRC sLPUART1.CTRL.BITS.RSRC	  			// Receiver Source Select
#define bLPUART1_DOZEEN sLPUART1.CTRL.BITS.DOZEEN	  		// Doze Enable
#define bLPUART1_LOOPS sLPUART1.CTRL.BITS.LOOPS	  			// Loop Mode Select
#define bLPUART1_IDLECFG sLPUART1.CTRL.BITS.IDLECFG	  		// Idle Configuration
#define bLPUART1_MA2IE sLPUART1.CTRL.BITS.MA2IE				// Match 2 Interrupt Enable
#define bLPUART1_MA1IE sLPUART1.CTRL.BITS.MA1IE	  			// Match 1 Interrupt Enable
#define bLPUART1_SBK sLPUART1.CTRL.BITS.SBK	  				// Send Break
#define bLPUART1_RWU sLPUART1.CTRL.BITS.RWU	  				// Receiver Wakeup Control
#define bLPUART1_RE	 sLPUART1.CTRL.BITS.RE	  				// Receiver Enable
#define bLPUART1_TE	 sLPUART1.CTRL.BITS.TE	  				// Transmitter Enable
#define bLPUART1_ILIE sLPUART1.CTRL.BITS.ILIE	  			// Idle Line Interrupt Enable
#define bLPUART1_RIE sLPUART1.CTRL.BITS.RIE	  				// Receiver Interrupt Enable
#define bLPUART1_TCIE sLPUART1.CTRL.BITS.TCIE				// Transmission Complete Interrupt Enable for
#define bLPUART1_TIE sLPUART1.CTRL.BITS.TIE	  				// Transmit Interrupt Enable
#define bLPUART1_PEIE sLPUART1.CTRL.BITS.PEIE	  			// Parity Error Interrupt Enable
#define bLPUART1_FEIE sLPUART1.CTRL.BITS.FEIE	  			// Framing Error Interrupt Enable
#define bLPUART1_NEIE sLPUART1.CTRL.BITS.NEIE	  			// Noise Error Interrupt Enable
#define bLPUART1_ORIE sLPUART1.CTRL.BITS.ORIE	  			// Overrun Interrupt Enable
#define bLPUART1_TXINV sLPUART1.CTRL.BITS.TXINV	  			// Transmit Data Inversion
#define bLPUART1_TXDIR sLPUART1.CTRL.BITS.TDIR	  			// LPUART_TX Pin Direction in Single-Wire Mode
#define bLPUART1_R9T8 sLPUART1.CTRL.BITS.R9T8				// Receive Bit 9 / Transmit Bit 8
#define bLPUART1_R8T9 sLPUART1.CTRL.BITS.R8T9	  			// Receive Bit 8 / Transmit Bit 9

#define rLPUART1_DATA sLPUART1.DATA.WORD					// x00C LPUART Data Register (LPUART1_DATA)
#define bLPUART1_DATA_8BITS sLPUART1.DATA.BYTE.DATA_8BITS	//
#define bLPUART1_DATA_9BITS sLPUART1.DATA.BITS9.DATA_9BITS	//
#define bLPUART1_DATA_10BITS sLPUART1.DATA.BITS10.DATA_10BITS	//
#define bLPUART1_R0T0 sLPUART1.DATA.BITS.R0T0	  			// Read receive data buffer 0 or write transmit data buffer 0.
#define bLPUART1_R1T1 sLPUART1.DATA.BITS.R1T1	  			// Read receive data buffer 1 or write transmit data buffer 1.
#define bLPUART1_R2T2 sLPUART1.DATA.BITS.R2T2				// Read receive data buffer 2 or write transmit data buffer 2.
#define bLPUART1_R3T3 sLPUART1.DATA.BITS.R3T3	  			// Read receive data buffer 3 or write transmit data buffer 3.
#define bLPUART1_R4T4 sLPUART1.DATA.BITS.R4T4	  			// Read receive data buffer 4 or write transmit data buffer 4.
#define bLPUART1_R5T5 sLPUART1.DATA.BITS.R5T5	  			// Read receive data buffer 5 or write transmit data buffer 5.
#define bLPUART1_R6T6 sLPUART1.DATA.BITS.R6T6	  			// Read receive data buffer 6 or write transmit data buffer 6.
#define bLPUART1_R7T7 sLPUART1.DATA.BITS.R7T7	  			// Read receive data buffer 7 or write transmit data buffer 7.
#define bLPUART1_R8T8 sLPUART1.DATA.BITS.R8T8	  			// Read receive data buffer 8 or write transmit data buffer 8.
#define bLPUART1_R9T9 sLPUART1.DATA.BITS.R9T9	  			// Read receive data buffer 9 or write transmit data buffer 9.
#define bLPUART1_IDLINE sLPUART1.DATA.BITS.IDLINE	  		// Idle Line
#define bLPUART1_RXEMPT sLPUART1.DATA.BITS.RXEMPT	  		// Receive Buffer Empty
#define bLPUART1_FRETSC sLPUART1.DATA.BITS.FRETSC	  		// Frame Error / Transmit Special Character
#define bLPUART1_PARITYE sLPUART1.CTRL.BITS.PARITYE	  		// The current received data word contained in DATA[R9:R0] was received with a parity error.
#define bLPUART1_NOISY sLPUART1.DATA.BITS.NOISY	  			// The current received data word contained in DATA[R9:R0] was received with noise

#define rLPUART1_MATCH sLPUART1.MATCH.WORD					// x010 LPUART Match Address Register (LPUART1_MATCH)
#define bLPUART1_MA1 sLPUART1.MATCH.BITS.MA1	  			// Match Address 1
#define bLPUART1_MA2 sLPUART1.MATCH.BITS.MA2				// Match Address 2
#endif /* LPUART_LIB_H_ */
