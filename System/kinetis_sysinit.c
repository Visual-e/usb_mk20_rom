/*
 *    kinetis_sysinit.c - Default init routines for Flycatcher
 *                     		Kinetis ARM systems
 *    Copyright © 2012 Freescale semiConductor Inc. All Rights Reserved.
 */
 
#include "kinetis_sysinit.h"
#include "derivative.h"

/**
 **===========================================================================
 **  External declarations
 **===========================================================================
 */
#if __cplusplus
extern "C" {
#endif
extern uint32_t __vector_table[];
extern unsigned long _estack;
extern void __thumb_startup(void);
#if __cplusplus
}
#endif

extern void USB_ISR(void);

void USB_ISR_TMP(void)
{
USB_ISR();
}

/**
 **===========================================================================
 **  Default interrupt handler
 **===========================================================================
 */
void Default_Handler(void)
{
	__asm("bkpt");
}

/**
 **===========================================================================
 **  Reset handler
 **===========================================================================
 */


void __init_hardware(void)
{
	SCB_VTOR = (uint32_t)__vector_table; /* Set the interrupt vector table position */
	// Disable the Watchdog because it may reset the core before entering main().
	/* Write 0xC520 to the unlock register */
	WDOG_UNLOCK = 0xC520;

	/* Followed by 0xD928 to complete the unlock */
	WDOG_UNLOCK = 0xD928;

	/* Clear the WDOGEN bit to disable the watchdog */
	WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK;

}

/* Weak definitions of handlers point to Default_Handler if not implemented */
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

void SVC_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

void PendSV_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

void DMA0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_RC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void VLD_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LLWU_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WDOG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void SPI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2S0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void I2S1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_CEA709IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_ERR_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_ERR_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_ERR_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CMP0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CMP1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FTM0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FTM1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void CMT_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_AlarmIRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_SecondsIRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PIT0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PIT1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PIT2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PIT3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PDB_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void USB_ISR_IRQHandler(void) __attribute__ ((weak, alias("USB_ISR_TMP")));
void USB_CD_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void TSI_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void MCG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void LPT_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PORTA_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PORTB_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PORTC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PORTD_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void PORTE_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));

/* The Interrupt Vector Table */
void (* const InterruptVector[])(void) __attribute__ ((section(".vectortable"))) = {
    /* Processor exceptions */
    (void(*)(void)) &_estack,
    __thumb_startup,
    NMI_Handler,
    HardFault_Handler,
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
    0,
    0,
    0,
    0,
    SVC_Handler,
	DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* Interrupts */
	DMA0_IRQHandler,			// 0:  DMA Channel 0 transfer complete
	DMA1_IRQHandler,			// 1:  DMA Channel 1 transfer complete
	DMA2_IRQHandler,			// 2:  DMA Channel 2 transfer complete
	DMA3_IRQHandler,			// 3:  DMA Channel 3 transfer complete
	DMA4_IRQHandler,			// 4:  DMA Channel 4 transfer complete
	DMA5_IRQHandler,			// 5:  DMA Channel 5 transfer complete
	FLASH_CC_IRQHandler,		// 6:  Flash memory command complete
	FLASH_RC_IRQHandler,		// 7:  Flash memory read collision
	VLD_IRQHandler,				// 8:  Low Voltage Detect, Low Voltage Warning
	LLWU_IRQHandler,			// 9:  Low Leakage Wakeup
	WDOG_IRQHandler,			//10:  WDOG interrupt
	I2C0_IRQHandler,			//11:  I2C0 interrupt
	SPI0_IRQHandler,			//12:  SPI 0 interrupt
	I2S0_IRQHandler,			//13:  I2S transmit interrupt
	I2S1_IRQHandler,			//14:  I2S receive interrupt
	UART0_CEA709IRQHandler,		//15:  UART 0 intertrupt
	UART0_IRQHandler,			//16:  UART 0 intertrupt
	UART0_ERR_IRQHandler,		//17:  UART 0 error intertrupt
	UART1_IRQHandler,			//18:  UART 1 intertrupt
	UART1_ERR_IRQHandler,		//19:  UART 1 error intertrupt
	UART2_IRQHandler,			//20:  UART 2 intertrupt
	UART2_ERR_IRQHandler,		//21:  UART 2 error intertrupt
	ADC0_IRQHandler,			//22:  ADC 0 interrupt
	CMP0_IRQHandler,			//23:  CMP 0 High-speed comparator interrupt
	CMP1_IRQHandler,			//24:  CMP 1 interrupt
	FTM0_IRQHandler,			//25:  FTM 0 interrupt
	FTM1_IRQHandler,			//26:  FTM 1 interrupt
	CMT_IRQHandler,				//27:  CMT intrrupt
	RTC_AlarmIRQHandler,		//28:  RTC alarm interrupt
	RTC_SecondsIRQHandler,		//29:  RTC seconds interrupt
	PIT0_IRQHandler,			//30:  PIT 0 interrupt
	PIT1_IRQHandler,			//31:  PIT 1 interrupt
	PIT2_IRQHandler,			//32:  PIT 2 interrupt
	PIT3_IRQHandler,			//33:  PIT 3 interrupt
	PDB_IRQHandler,				//34:  PDB interrupt
	USB_ISR_IRQHandler,			//35:  USB OTG interrupt
	USB_CD_IRQHandler,			//36:  USB Charger Detect interrupt
	TSI_IRQHandler,				//37:  TSI interrupt
	MCG_IRQHandler,				//38:  MCG interrupt
	LPT_IRQHandler,				//39:  LPT interrupt
	PORTA_IRQHandler,			//40:  PORT A interrupt
	PORTB_IRQHandler,			//41:  PORT B interrupt
	PORTC_IRQHandler,			//42:  PORT C interrupt
	PORTD_IRQHandler,			//43:  PORT D interrupt
	PORTE_IRQHandler,			//44:  PORT E interrupt

};

