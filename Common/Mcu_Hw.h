/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Mcu_Hw.h
 *       Module: Mcu_Hw
 *
 *  Description:  Header file for Registers definition
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct {

    uint32 VECACT    :8;
    uint32           :3;
    uint32 RETBASE   :1;
    uint32 VECPEND   :8;
    uint32           :2;
    uint32 ISRPEND   :1;
    uint32 ISRPRE    :1;
    uint32           :1;
    uint32 PENDSTCLR :1;
    uint32 PENDSTSET :1;
    uint32 UNPENDSV  :1;
    uint32 PENDSV    :1;
    uint32           :2;
    uint32 NMITSET   :1;

}INTCTRL_BF;

typedef union {
    uint32 R;
    uint32 INTCTRL_BF;
}INTCTRL_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*****************************************************************************
// Cortex-M4 Peripherals Registers
*****************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS  0xE000E000
// System Timer (SysTick) Registers //
#define STCTRL                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010))
#define STRELOAD                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014))
#define STCURRENT                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018))

// Nested Vectored Interrupt Controller (NVIC) Registers //
#define NVIC_EN0                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define NVIC_EN1                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define NVIC_EN2                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define NVIC_EN3                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define NVIC_EN4                          *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))
#define NVIC_DIS0                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define NVIC_DIS1                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define NVIC_DIS2                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define NVIC_DIS3                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define NVIC_DIS4                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))
#define NVIC_PEND0                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define NVIC_PEND1                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204))
#define NVIC_PEND2                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208))
#define NVIC_PEND3                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C))
#define NVIC_PEND4                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210))
#define NVIC_UNPEND0                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
#define NVIC_UNPEND1                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x284))
#define NVIC_UNPEND2                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x288))
#define NVIC_UNPEND3                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x28C))
#define NVIC_UNPEND4                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x290))
#define NVIC_ACTIVE0                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define NVIC_ACTIVE1                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304))
#define NVIC_ACTIVE2                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308))
#define NVIC_ACTIVE3                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C))
#define NVIC_ACTIVE4                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310))
#define NVIC_PRI0                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define NVIC_PRI1                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define NVIC_PRI2                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define NVIC_PRI3                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define NVIC_PRI4                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define NVIC_PRI5                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define NVIC_PRI6                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define NVIC_PRI7                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define NVIC_PRI8                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define NVIC_PRI9                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define NVIC_PRI10                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define NVIC_PRI11                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define NVIC_PRI12                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define NVIC_PRI13                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define NVIC_PRI14                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define NVIC_PRI15                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define NVIC_PRI16                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define NVIC_PRI17                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define NVIC_PRI18                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define NVIC_PRI19                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define NVIC_PRI20                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
/*
#define PRI21                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI22                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI23                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI24                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI25                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI26                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI27                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI28                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI29                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI30                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI31                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI32                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI33                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define PRI34                         *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
*/
#define NVIC_SWTRIG                        *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))

// System Control Block (SCB) Registers //
#define SCB_ACTLR                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))
#define SCB_CPUID                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))
#define SCB_INTCTRL                     *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define SCB_VTABLE                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define SCB_APINT                       *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SCB_SYSCTRL                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
#define SCB_CFGCTRL                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define SCB_SYSPRI1                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SCB_SYSPRI2                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SCB_SYSPRI3                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SCB_SYSHNDCTRL                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define SCB_FAULTSTAT                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28))
#define SCB_HFAULTSTAT                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C))
#define SCB_MMADDR                      *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34))
#define SCB_FAULTADDR                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38))

// Memory Protection Unit (MPU) Registers //
#define MPUTYPE                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD90))
#define MPUCTRL                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD94))
#define MPUNUMBER                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD98))
#define MPUBASE                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD9C))
#define MPUATTR                     *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDA0))
#define MPUBASE1                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDA4))
#define MPUATTR1                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDA8))
#define MPUBASE2                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDAC))
#define MPUATTR2                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDB0))
#define MPUBASE3                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDB4))
#define MPUATTR3                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xDB8))

// Floating-Point Unit (FPU) Registers //
#define CPAC                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD88))
#define FPCC                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF34))
#define FPCA                    *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF38))
#define FPDSC                   *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF3C))


/*****************************************************************************
// System Control Registers
*****************************************************************************/
#define SYSCTL_BASE_ADDRESS  0x400FE000
#define SYSCTL_PRGPIO         *((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0xA08))
#define SYSCTL_RCGCGPIO       *((volatile uint32_t *)(SYSCTL_BASE_ADDRESS+0x608))


/*****************************************************************************
// Tiva C TM4C123GH6PM GPIO Registers
*****************************************************************************/
#define GPIO_PORTA_BASE_ADDRESS      0x40004000
#define GPIO_PORTB_BASE_ADDRESS      0x40005000
#define GPIO_PORTC_BASE_ADDRESS      0x40006000
#define GPIO_PORTD_BASE_ADDRESS      0x40007000
#define GPIO_PORTE_BASE_ADDRESS      0x40024000
#define GPIO_PORTF_BASE_ADDRESS      0x40025000

#define GPIODATA(PortAddress)	    *((volatile uint32_t*)(PortAddress+ 0x03FC))	
#define GPIODIR(PortAddress)	    *((volatile uint32_t*)(PortAddress+ 0x0400))	
#define GPIOIS(PortAddress)		    *((volatile uint32_t*)(PortAddress+ 0x0404))	
#define GPIOIBE(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0408))	
#define GPIOIEV(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x040C))	
#define GPIOIM(PortAddress)		    *((volatile uint32_t*)(PortAddress+ 0x0410))	
#define GPIORIS(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0414))	
#define GPIOMIS(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0418))	
#define GPIOICR(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x041C))	
#define GPIOAFSEL(PortAddress)      *((volatile uint32_t*)(PortAddress+ 0x0420))	
#define GPIODR2R(PortAddress) 	    *((volatile uint32_t*)(PortAddress+ 0x0500))	
#define GPIODR4R(PortAddress) 	    *((volatile uint32_t*)(PortAddress+ 0x0504))	
#define GPIODR8R(PortAddress)	    *((volatile uint32_t*)(PortAddress+ 0x0508))	
#define GPIOODR(PortAddress) 	    *((volatile uint32_t*)(PortAddress+ 0x050C))	
#define GPIOPUR(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0510))	
#define GPIOPDR(PortAddress) 	    *((volatile uint32_t*)(PortAddress+ 0x0514))	
#define GPIOSLR(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0518))	
#define GPIODEN(PortAddress) 	    *((volatile uint32_t*)(PortAddress+ 0x051C))	
#define GPIOLOCK(PortAddress)	    *((volatile uint32_t*)(PortAddress+ 0x0520))	
#define GPIOCR(PortAddress)		    *((volatile uint32_t*)(PortAddress+ 0x0524))	
#define GPIOAMSEL(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x0528))	
#define GPIOPCTL(PortAddress)		*((volatile uint32_t*)(PortAddress+ 0x052C))	

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
