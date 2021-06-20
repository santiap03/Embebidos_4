/*
 * UART_LIB.h
 *
 *  Created on: 27/10/2017
 *      Author: Ricardo Andrés Velásquez
 */

#ifndef UART_LIB_H_
#define UART_LIB_H_

#define mUART_BDH_SBR(X) (X & 0x1F)						// UART Baud Rate Bits
enum{
	mUART_BDH_RXEDGIE = 0x40							// RxD Input Active Edge Interrupt Enable
};

typedef union {
	uint8_t BYTE;										// Acceso a todo el registro
	struct {
		uint8_t	SBR		:5;	  							// UART Baud Rate Bits
		uint8_t 		:1;	  							// Reserved
		uint8_t RXEDGIE :1;								// RxD Input Active Edge Interrupt Enable
		uint8_t 		:1;								// Reserved
	} BITS;
} __uart_bdh_t;

typedef union {
	uint8_t BYTE;										// Acceso a todo el registro
	struct {
		uint8_t	SBR		:8;	  							// UART Baud Rate Bits
		} BITS;
} __uart_bdl_t;

enum{
	mUART_C1_PT =	0x01,								// Parity Type
	mUART_C1_PE =	0x02,								// Parity Enable
	mUART_C1_ILT =	0x04,								// Idle Line Type Select
	mUART_C1_WAKE =	0x08,								// Receiver Wakeup Method Select
	mUART_C1_M =	0x10,								// 9-bit or 8-bit Mode Select
	mUART_C1_RSRC =	0x20,								// Receiver Source Select
	mUART_C1_LOOPS = 0x80								// Loop Mode Select
};

typedef union {
	uint8_t BYTE;										// Acceso a todo el registro
	struct {
		uint8_t	PT		:1;	  							// Parity Type
		uint8_t PE		:1;	  							// Parity Enable
		uint8_t ILT		:1;								// Idle Line Type Select
		uint8_t WAKE	:1;								// Receiver Wakeup Method Select
		uint8_t M		:1;								// 9-bit or 8-bit Mode Select
		uint8_t RSRC	:1;								// Receiver Source Select
		uint8_t			:1;								// Reserved
		uint8_t LOOPS	:1;								// Loop Mode Select
	} BITS;
} __uart_c1_t;

enum{
	mUART_C2_SBK =	0x01,								// Send Break
	mUART_C2_RWU =	0x02,								// Receiver Wakeup Control
	mUART_C2_RE =	0x04,								// Receiver Enable
	mUART_C2_TE =	0x08,								// Transmitter Enable
	mUART_C2_ILIE =	0x10,								// Idle Line Interrupt Enable
	mUART_C2_RIE =	0x20,								// Receiver Full Interrupt or DMA Transfer Enable
	mUART_C2_TCIE =	0x40,								// Transmission Complete Interrupt Enable
	mUART_C2_TIE =	0x80								// Transmitter Interrupt or DMA Transfer Enable
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	SBK		:1;	  							// Send Break
		uint8_t RWU		:1;	  							// Receiver Wakeup Control
		uint8_t RE		:1;								// Receiver Enable
		uint8_t	TE		:1;	  							// Transmitter Enable
		uint8_t	ILIE	:1;	  							// Idle Line Interrupt Enable
		uint8_t	RIE		:1;	  							// Receiver Full Interrupt or DMA Transfer Enable
		uint8_t	TCIE	:1;	  							// Transmission Complete Interrupt Enable
		uint8_t	TIE		:1;	  							// Transmitter Interrupt or DMA Transfer Enable
	} BITS;
} __uart_c2_t;

enum{
	mUART_S1_PF =	0x01,								// Parity Error Flag
	mUART_S1_FE =	0x02,								// Framing Error Flag
	mUART_S1_NF =	0x04,								// Noise Flag
	mUART_S1_OR =	0x08,								// Receiver Overrun Flag
	mUART_S1_IDLE =	0x10,								// Idle Line Flag
	mUART_S1_RDRF =	0x20,								// Receive Data Register Full Flag
	mUART_S1_TC =	0x40,								// Transmit Complete Flag
	mUART_S1_TDRE =	0x80								// Transmit Data Register Empty Flag
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	PF		:1;	  							// Parity Error Flag
		uint8_t FE		:1;	  							// Framing Error Flag
		uint8_t NF 		:1;								// Noise Flag
		uint8_t	OR		:1;	  							// Receiver Overrun Flag
		uint8_t	IDLE	:1;	  							// Idle Line Flag
		uint8_t	RDRF	:1;	  							// Receive Data Register Full Flag
		uint8_t	TC		:1;	  							// Transmit Complete Flag
		uint8_t	TDRE	:1;	  							// Transmit Data Register Empty Flag
	} BITS;
} __uart_s1_t;

enum{
	mUART_S2_RAF =		0x01,							// Receiver Active Flag
	mUART_S2_BRK13 =	0x04,							// Break Transmit Character Length
	mUART_S2_RWUID =	0x08,							// Receive Wakeup Idle Detect
	mUART_S2_RXINV =	0x10,							// Receive Data Inversion
	mUART_S2_MSBF =		0x20,							// Most Significant Bit First
	mUART_S2_RXEDGIF =	0x40							// RxD Pin Active Edge Interrupt Flag
};

typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	RAF		:1;	  							// Receiver Active Flag
		uint8_t 		:1;	  							// Reserved
		uint8_t BRK13	:1;								// Break Transmit Character Length
		uint8_t	RWUID	:1;	  							// Receive Wakeup Idle Detect
		uint8_t	RXINV	:1;	  							// Receive Data Inversion
		uint8_t	MSBF	:1;	  							// Most Significant Bit First
		uint8_t	RXEDGIF	:1;	  							// RxD Pin Active Edge Interrupt Flag
		uint8_t			:1;	  							// Reserved
	} BITS;
} __uart_s2_t;

enum{
	mUART_C3_PEIE =		0x01,							// Parity Error Interrupt Enable
	mUART_C3_FEIE =		0x02,							// Framing Error Interrupt Enable
	mUART_C3_NEIE =		0x04,							// Noise Error Interrupt Enable
	mUART_C3_ORIE =		0x08,							// Overrun Error Interrupt Enable
	mUART_C3_TXINV =	0x10,							// Transmit Data Inversion.
	mUART_C3_TXDIR =	0x20,							// Transmitter Pin Data Direction in Single-Wire mode
	mUART_C3_T8 =		0x40,							// Transmit Bit 8
	mUART_C3_R8 =		0x80							// Received Bit 8
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	PEIE	:1;	  							// Parity Error Interrupt Enable
		uint8_t FEIE	:1;	  							// Framing Error Interrupt Enable
		uint8_t NEIE	:1;								// Noise Error Interrupt Enable
		uint8_t	ORIE	:1;	  							// Overrun Error Interrupt Enable
		uint8_t	TXINV	:1;	  							// Transmit Data Inversion.
		uint8_t	TXDIR	:1;	  							// Transmitter Pin Data Direction in Single-Wire mode
		uint8_t	T8		:1;	  							// Transmit Bit 8
		uint8_t	R8		:1;	  							// Received Bit 8
	} BITS;
} __uart_c3_t;

typedef uint8_t __uart_d_t;

typedef uint8_t __uart_ma1_t;

typedef uint8_t __uart_ma2_t;

#define mUART_C4_BRFA(X) (X & 0x1F) 					// Baud Rate Fine Adjust
enum{
	mUART_C4_M10 =		0x20,							// 10-bit Mode select
	mUART_C4_MAEN2 =	0x40,							// Match Address Mode Enable 2
	mUART_C4_MAEN1 =	0x80							// Match Address Mode Enable 1
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	BRFA	:5;	  							// Baud Rate Fine Adjust
		uint8_t	M10		:1;	  							// 10-bit Mode select
		uint8_t	MAEN2	:1;	  							// Match Address Mode Enable 2
		uint8_t	MAEN1	:1;	  							// Match Address Mode Enable 1
	} BITS;
} __uart_c4_t;

enum{
	mUART_C5_RDMAS =	0x20,							// Receiver Full DMA Select
	mUART_C5_TDMAS =	0x80							// Transmitter DMA Select
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t			:5;	  							// Reserved
		uint8_t RDMAS	:1;	  							// Receiver Full DMA Select
		uint8_t  		:1;								// Reserved
		uint8_t	TDMAS	:1;	  							// Transmitter DMA Select
	} BITS;
} __uart_c5_t;

enum{
	mUART_C7816_ISO_7816E =	0x01,						// ISO-7816 Functionality Enabled
	mUART_C7816_TTYPE =	0x02,							// Transfer Type
	mUART_C7816_INIT =	0x04,							// Detect Initial Character
	mUART_C7816_ANACK =	0x08,							// Generate NACK on Error
	mUART_C7816_ONACK =	0x10,							// Generate NACK on Overflow
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	ISO_7816E:1;	  						// ISO-7816 Functionality Enabled
		uint8_t TTYPE	:1;	  							// Transfer Type
		uint8_t INIT 	:1;								// Detect Initial Character
		uint8_t	ANACK	:1;	  							// Generate NACK on Error
		uint8_t	ONACK	:1;	  							// Generate NACK on Overflow
		uint8_t			:3;	  							// Reserved
	} BITS;
} __uart_c7816_t;

enum{
	mUART_IE7816_RXTE =		0x01,						// Receive Threshold Exceeded Interrupt Enable
	mUART_IE7816_TXTE =		0x02,						// Transmit Threshold Exceeded Interrupt Enable
	mUART_IE7816_GTVE =		0x04,						// Guard Timer Violated Interrupt Enable
	mUART_IE7816_ADTE =		0x08,						// ATR Duration Timer Interrupt Enable
	mUART_IE7816_INITDE =	0x10,						// Initial Character Detected Interrupt Enable
	mUART_IE7816_BWTE =		0x20,						// Block Wait Timer Interrupt Enable
	mUART_IE7816_CWTE =		0x40,						// Character Wait Timer Interrupt Enable
	mUART_IE7816_WTE =		0x80						// Wait Timer Interrupt Enable
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	RXTE	:1;	  							// Receive Threshold Exceeded Interrupt Enable
		uint8_t TXTE	:1;	  							// Transmit Threshold Exceeded Interrupt Enable
		uint8_t GTVE	:1;								// Guard Timer Violated Interrupt Enable
		uint8_t	ADTE	:1;	  							// ATR Duration Timer Interrupt Enable
		uint8_t	INITDE	:1;	  							// Initial Character Detected Interrupt Enable
		uint8_t	BWTE	:1;	  							// Block Wait Timer Interrupt Enable
		uint8_t	CWTE	:1;	  							// Character Wait Timer Interrupt Enable
		uint8_t	WTE		:1;	  							// Wait Timer Interrupt Enable
	} BITS;
} __uart_ie7816_t;

enum{
	mUART_IS7816_RXT =		0x01,						// Receive Threshold Exceeded Interrupt
	mUART_IS7816_TXT =		0x02,						// Transmit Threshold Exceeded Interrupt
	mUART_IS7816_GTV =		0x04,						// Guard Timer Violated Interrupt
	mUART_IS7816_ADT =		0x08,						// ATR Duration Time Interrupt
	mUART_IS7816_INITD =	0x10,						// Initial Character Detected Interrupt
	mUART_IS7816_BWT =		0x20,						// Block Wait Timer Interrupt
	mUART_IS7816_CWT =		0x40,						// Character Wait Timer Interrupt
	mUART_IS7816_WT =		0x80						// Wait Timer Interrupt
};
typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	RXT		:1;	  							// Receive Threshold Exceeded Interrupt
		uint8_t TXT		:1;	  							// Transmit Threshold Exceeded Interrupt
		uint8_t GTV		:1;								// Guard Timer Violated Interrupt
		uint8_t	ADT		:1;	  							// ATR Duration Time Interrupt
		uint8_t	INITD	:1;	  							// Initial Character Detected Interrupt
		uint8_t	BWT		:1;	  							// Block Wait Timer Interrupt
		uint8_t	CWT		:1;	  							// Character Wait Timer Interrupt
		uint8_t	WT		:1;	  							// Wait Timer Interrupt
	} BITS;
} __uart_is7816_t;

typedef uint8_t __uart_wp7816_t;
typedef uint8_t __uart_wn7816_t;
typedef uint8_t __uart_wf7816_t;

#define mUART_ET7816_RXTHRESHOLD(X) (X & 0x0F)
#define mUART_ET7816_TXTHRESHOLD(X) ((X & 0x0F)<<4)

typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	RXTHRESHOLD		:4;	  					// Receive NACK Threshold
		uint8_t TXTHRESHOLD		:4;	  					// Transmit NACK Threshold
	} BITS;
} __uart_et7816_t;

typedef uint8_t __uart_tl7816_t;
typedef uint8_t __uart_ap7816a_t0_t;
typedef uint8_t __uart_ap7816b_t0_t;
typedef uint8_t __uart_wp7816a_tn_t;
typedef uint8_t __uart_wp7816b_tn_t;

#define mUART_WGP7816_T1_BGI(X) (X & 0x0F)
#define mUART_WGP7816_T1_CWI1(X) ((X & 0x0F)<<4)

typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	BGI		:4;	  							// Block Guard Time Integer (C7816[TTYPE] = 1)
		uint8_t CWI1	:4;	  							// Character Wait Time Integer 1 (C7816[TTYPE] = 1)
	} BITS;
} __uart_wgp7816_t1_t;

#define mUART_WP7816C_T1_CWI2(X) (X & 0x1F)				// Character Wait Time Integer 2 (C7816[TTYPE] = 1)

typedef union {
	uint8_t BYTE;										// Access to the whole register
	struct {
		uint8_t	CWI2	:5;	  							// Character Wait Time Integer 2 (C7816[TTYPE] = 1)
		uint8_t 		:3;	  							// Reserved
	} BITS;
} __uart_wp7816c_t1_t;

typedef struct{
	volatile __uart_bdh_t BDH;							// xC000 UART Baud Rate Registers: High (UART2_BDH)
	volatile __uart_bdl_t BDL;							// xC001 UART Baud Rate Registers: Low (UART2_BDL)
	volatile __uart_c1_t C1;							// xC002 UART Control Register 1 (UART2_C1)
	volatile __uart_c2_t C2;							// xC003 UART Control Register 2 (UART2_C2)
	volatile __uart_s1_t S1;							// xC004 UART Status Register 1 (UART2_S1)
	volatile __uart_s2_t S2;							// xC005 UART Status Register 2 (UART2_S2)
	volatile __uart_c3_t C3;							// xC006 UART Control Register 3 (UART2_C3)
	volatile __uart_d_t D;								// xC007 UART Data Register (UART2_D)
	volatile __uart_ma1_t MA1;							// xC008 UART Match Address Registers 1 (UART2_MA1)
	volatile __uart_ma2_t MA2;							// xC009 UART Match Address Registers 2 (UART2_MA2)
	volatile __uart_c4_t C4;							// xC00A UART Control Register 4 (UART2_C4)
	volatile __uart_c5_t C5;							// xC00B UART Control Register 5 (UART2_C5)
	volatile uint8_t RESERVED0[12]; 					// xC00C - xC017 RESERVED
	volatile __uart_c7816_t C7816;						// xC018 UART 7816 Control Register (UART2_C7816)
	volatile __uart_ie7816_t IE7816;					// xC019 UART 7816 Interrupt Enable Register (UART2_IE7816)
	volatile __uart_is7816_t IS7816;					// xC01A UART 7816 Interrupt Status Register (UART2_IS7816)
	volatile __uart_wp7816_t WP7816;					// xC01B UART 7816 Wait Parameter Register (UART2_WP7816)
	volatile __uart_wn7816_t WN7816;					// xC01C UART 7816 Wait N Register (UART2_WN7816)
	volatile __uart_wf7816_t WF7816;					// xC01D UART 7816 Wait FD Register (UART2_WF7816)
	volatile __uart_et7816_t ET7816;					// xC01E UART 7816 Error Threshold Register (UART2_ET7816)
	volatile __uart_tl7816_t TL7816;					// xC01F UART 7816 Transmit Length Register (UART2_TL7816)
	volatile uint8_t RESERVED1[26];						// xC020 - xC039
	volatile __uart_ap7816a_t0_t AP7816A_T0;			// xC03A UART 7816 ATR Duration Timer Register A
	volatile __uart_ap7816b_t0_t AP7816B_T0;			// xC03B UART 7816 ATR Duration Timer Register B
	volatile __uart_wp7816a_tn_t WP7816A_Tn;			// xC03C UART 7816 Wait Parameter Register A
	volatile __uart_wp7816b_tn_t WP7816B_Tn;			// xC03D UART 7816 Wait Parameter Register B
	volatile __uart_wgp7816_t1_t WGP7816_T1;			// xC03E UART 7816 Wait and Guard Parameter Register
	volatile __uart_wp7816c_t1_t WP7816C_T1;			// xC03F UART 7816 Wait Parameter Register C
}__uart_t;

#define sUART2 (*((__uart_t *)(0x4006C000)))			// UART2 module general register structure

#define rUART2_BDH sUART2.BDH.BYTE						// xC000 UART Baud Rate Registers: High (UART2_BDH)
#define bUART2_SBRH sUART2.BDH.BITS.SBR	  				// UART Baud Rate Bits
#define bUART2_RXEDGIE sUART2.BDH.BITS.RXEDGIE			// RxD Input Active Edge Interrupt Enable

#define rUART2_BDL sUART2.BDL.BYTE						// xC001 UART Baud Rate Registers: Low (UART2_BDL)
#define bUART2_SBRL sUART2.BDL.BITS.SBR	 				// UART Baud Rate Bits

#define rUART2_C1 sUART2.C1.BYTE						// xC002 UART Control Register 1 (UART2_C1)
#define bUART2_PT sUART2.C1.BITS.PT	  					// Parity Type
#define bUART2_PE sUART2.C1.BITS.PE	  					// Parity Enable
#define bUART2_ILT sUART2.C1.BITS.ILT					// Idle Line Type Select
#define bUART2_WAKE sUART2.C1.BITS.WAKE					// Receiver Wakeup Method Select
#define bUART2_M sUART2.C1.BITS.M						// 9-bit or 8-bit Mode Select
#define bUART2_RSRC sUART2.C1.BITS.RSRC					// Receiver Source Select
#define bUART2_LOOPS sUART2.C1.BITS.LOOPS				// Loop Mode Select

#define rUART2_C2 sUART2.C2.BYTE						// xC003 UART Control Register 2 (UART2_C2)
#define bUART2_SBK sUART2.C2.BITS.SBK	  				// Send Break
#define bUART2_RWU sUART2.C2.BITS.RWU	  				// Receiver Wakeup Control
#define bUART2_RE sUART2.C2.BITS.RE						// Receiver Enable
#define bUART2_TE sUART2.C2.BITS.TE	  					// Transmitter Enable
#define bUART2_ILIE sUART2.C2.BITS.ILIE					// Idle Line Interrupt Enable
#define bUART2_RIE sUART2.C2.BITS.RIE					// Receiver Full Interrupt or DMA Transfer Enable
#define bUART2_TCIE sUART2.C2.BITS.TCIE 				// Transmission Complete Interrupt Enable
#define bUART2_TIE sUART2.C2.BITS.TIE					// Transmitter Interrupt or DMA Transfer Enable

#define rUART2_S1 sUART2.S1.BYTE						// xC004 UART Status Register 1 (UART2_S1)
#define bUART2_PF sUART2.S1.BITS.PF						// Parity Error Flag
#define bUART2_FE sUART2.S1.BITS.FE						// Framing Error Flag
#define bUART2_NF  sUART2.S1.BITS.NF					// Noise Flag
#define bUART2_OR sUART2.S1.BITS.OR						// Receiver Overrun Flag
#define bUART2_IDLE sUART2.S1.BITS.IDLE					// Idle Line Flag
#define bUART2_RDRF sUART2.S1.BITS.RDRF					// Receive Data Register Full Flag
#define bUART2_TC sUART2.S1.BITS.TC						// Transmit Complete Flag
#define bUART2_TDRE sUART2.S1.BITS.TDRE					// Transmit Data Register Empty Flag

#define rUART2_S2 sUART2.S2.BYTE						// xC005 UART Status Register 2 (UART2_S2)
#define bUART2_RAF sUART2.S2.BITS.RAF					// Receiver Active Flag
#define bUART2_BRK13 sUART2.S2.BITS.BRK13				// Break Transmit Character Length
#define bUART2_RWUID sUART2.S2.BITS.RWUID				// Receive Wakeup Idle Detect
#define bUART2_RXINV sUART2.S2.BITS.RXINV				// Receive Data Inversion
#define bUART2_MSBF sUART2.S2.BITS.MSBF					// Most Significant Bit First
#define bUART2_RXEDGIF sUART2.S2.BITS.RXDEGIF			// RxD Pin Active Edge Interrupt Flag

#define rUART2_C3 sUART2.C3.BYTE						// xC006 UART Control Register 3 (UART2_C3)
#define bUART2_PEIE sUART2.C3.BITS.PEIE					// Parity Error Interrupt Enable
#define bUART2_FEIE sUART2.C3.BITS.FEIE					// Framing Error Interrupt Enable
#define bUART2_NEIE sUART2.C3.BITS.NEIE					// Noise Error Interrupt Enable
#define bUART2_ORIE sUART2.C3.BITS.ORIE					// Overrun Error Interrupt Enable
#define bUART2_TXINV sUART2.C3.BITS.TXINV				// Transmit Data Inversion.
#define bUART2_TXDIR sUART2.C3.BITS.TXDIR				// Transmitter Pin Data Direction in Single-Wire mode
#define bUART2_T8 sUART2.C3.BITS.T8						// Transmit Bit 8
#define bUART2_R8 sUART2.C3.BITS.R8						// Received Bit 8

#define rUART2_D sUART2.D								// xC007 UART Data Register (UART2_D)

#define rUART2_MA1 sUART2.MA1							// xC008 UART Match Address Registers 1 (UART2_MA1)

#define rUART2_MA2 sUART2.MA2							// xC009 UART Match Address Registers 2 (UART2_MA2)

#define rUART2_C4 sUART2.C4.BYTE						// xC00A UART Control Register 4 (UART2_C4)
#define bUART2_BRFA sUART2.C4.BITS.BRFA					// Baud Rate Fine Adjust
#define bUART2_M10 sUART2.C4.BITS.M10					// 10-bit Mode select
#define bUART2_MAEN2 sUART2.C4.BITS.MAEN2				// Match Address Mode Enable 2
#define bUART2_MAEN1 sUART2.C4.BITS.MAEN1				// Match Address Mode Enable 1

#define rUART2_C5 sUART2.C5.BYTE						// xC00B UART Control Register 5 (UART2_C5)
#define bUART2_RDMAS sUART2.C5.BITS.RDMAS				// Receiver Full DMA Select
#define bUART2_TDMAS sUART2.C5.BITS.TDMAS				// Transmitter DMA Select

#define rUART2_C7816 sUART2.C7816.BYTE					// xC018 UART 7816 Control Register (UART2_C7816)
#define bUART2_ISO_7816E sUART2.C7816.BITS.7816E		// ISO-7816 Functionality Enabled
#define bUART2_TTYPE sUART2.C7816.BITS.TTYPE			// Transfer Type
#define bUART2_INIT sUART2.C7816.BITS.INIT				// Detect Initial Character
#define bUART2_ANACK sUART2.C7816.BITS.ANACK			// Generate NACK on Error
#define bUART2_ONACK sUART2.C7816.BITS.ONACK			// Generate NACK on Overflow

#define rUART2_IE7816 sUART2.IE7816.BYTE				// xC019 UART 7816 Interrupt Enable Register (UART2_IE7816)
#define bUART2_RXTE sUART2.IE7816.BITS.RXTE				// Receive Threshold Exceeded Interrupt Enable
#define bUART2_TXTE sUART2.IE7816.BITS.TXTE				// Transmit Threshold Exceeded Interrupt Enable
#define bUART2_GTVE sUART2.IE7816.BITS.GTVE				// Guard Timer Violated Interrupt Enable
#define bUART2_ADTE sUART2.IE7816.BITS.ADTE				// ATR Duration Timer Interrupt Enable
#define bUART2_INITDE sUART2.IE7816.BITS.INITDE			// Initial Character Detected Interrupt Enable
#define bUART2_BWTE sUART2.IE7816.BITS.BWTE				// Block Wait Timer Interrupt Enable
#define bUART2_CWTE sUART2.IE7816.BITS.CWTE				// Character Wait Timer Interrupt Enable
#define bUART2_WTE sUART2.IE7816.BITS.WTE				// Wait Timer Interrupt Enable

#define rUART2_IS7816 sUART2.IS7816.BYTE				// xC01A UART 7816 Interrupt Status Register (UART2_IS7816)
#define bUART2_RXT sUART2.IS7816.BITS.RXT				// Receive Threshold Exceeded Interrupt
#define bUART2_TXT sUART2.IS7816.BITS.TXT				// Transmit Threshold Exceeded Interrupt
#define bUART2_GTV sUART2.IS7816.BITS.GTV				// Guard Timer Violated Interrupt
#define bUART2_ADT sUART2.IS7816.BITS.ADT				// ATR Duration Time Interrupt
#define bUART2_INITD sUART2.IS7816.BITS.INITD			// Initial Character Detected Interrupt
#define bUART2_BWT sUART2.IS7816.BITS.BWT				// Block Wait Timer Interrupt
#define bUART2_CWT sUART2.IS7816.BITS.CWT				// Character Wait Timer Interrupt
#define bUART2_WT sUART2.IS7816.BITS.WT					// Wait Timer Interrupt

#define rUART2_WP7816 sUART2.WP7816						// xC01B UART 7816 Wait Parameter Register (UART2_WP7816)

#define rUART2_WN7816 sUART2.WN7816						// xC01C UART 7816 Wait N Register (UART2_WN7816)

#define rUART2_WF7816 sUART2.WF7816						// xC01D UART 7816 Wait FD Register (UART2_WF7816)

#define rUART2_ET7816 sUART2.ET7816.BYTE				// xC01E UART 7816 Error Threshold Register (UART2_ET7816)
#define bUART2_RXTHRESHOLD sUART2.ET7816.BITS.RXTHRESHOLD	// Receive NACK Threshold
#define bUART2_TXTHRESHOLD sUART2.ET7816.BITS.TXTHRESHOLD	// Transmit NACK Threshold

#define rUART2_TL7816 sUART2.TL7816						// xC01F UART 7816 Transmit Length Register (UART2_TL7816)

#define rUART2_AP7816A_T0 sUART2.AP7816A_T0				// xC03A UART 7816 ATR Duration Timer Register A

#define rUART2_AP7816B_T0 sUART2.AP7816B_T0				// xC03B UART 7816 ATR Duration Timer Register B

#define rUART2_WP7816A_Tn sUART2.WP7816A_Tn				// xC03C UART 7816 Wait Parameter Register A

#define rUART2_WP7816B_Tn sUART2.WP7816B_Tn				// xC03D UART 7816 Wait Parameter Register B

#define rUART2_WGP7816_T1 sUART2.WGP7816_T1.BYTE		// xC03E UART 7816 Wait and Guard Parameter Register
#define bUART2_BGI sUART2.WGP7816_T1.BITS.BGI			// Block Guard Time Integer (C7816[TTYPE] = 1)
#define bUART2_CWI1 sUART2.WGP7816_T1.BITS.CWI1			// Character Wait Time Integer 1 (C7816[TTYPE] = 1)

#define rUART2_WP7816C_T1 sUART2.WP7816C_T1.BYTE		// xC03F UART 7816 Wait Parameter Register C
#define bUART2_CWI2 sUART2.WP7816C_T1.BITS.CWI2			// Character Wait Time Integer 2 (C7816[TTYPE] = 1)

#endif /* UART_LIB_H_ */
