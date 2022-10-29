/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  Type Definitions of Interrupt Control driver.   
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

// Processor Exceptions //
typedef enum
{
    
    //Reserved               //0
    Reset=1,
    NMI,                     //2
    HardFault,               //3
    MemoryManagementFault,   //4
    BusFault,                //5
    UsageFault,              //6
    //Reserved               //7-10
    SVCall=11,          
    DebugMonitor,            //12
    //Reserved               //13
    PENDSV=14,
    SysTick,                 //15

}IntCtrl_ProcInterruptType;


// Interrupts // 
typedef enum
{
    GPIO_Port_A,
    GPIO_Port_B,
    GPIO_Port_C,
    GPIO_Port_D,
    GPIO_Port_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM0_Fault,
    PWM0_Generator_0,
    PWM0_Generator_1,
    PWM0_Generator_2,
    QEI0,
    ADC0_Sequence_0,
    ADC0_Sequence_1,
    ADC0_Sequence_2,
    ADC0_Sequence_3,
    Watchdog_Timer,     //both 0 and 1
    Bit16_32_Timer0A,        
    Bit16_32_Timer0B,        
    Bit16_32_Timer1A,          
    Bit16_32_Timer1B,       
    Bit16_32_Timer2A,            
    Bit16_32_Timer2B,            
    Analog_Comparator_0,
    Analog_Comparator_1,
    //Reserved          //27
    System_Control=28,
    FlashMemory_EEPROM_Control,
    GPIO_Port_F,
    //Reserved          //31-32
    UART2=33,
    SSI1,
    Bit16_32_Timer_3A,            
    Bit16_32_Timer_3B,           
    I2C1,
    QEI1,
    CAN0,
    CAN1,
    //Reserved          //41-42
    Hibernation_Module=43,
    USB,
    PWM0_Generator_3,
    uDMA_Software,
    uDMA_Error,
    ADC1_Sequence_0,
    ADC1_Sequence_1,
    ADC1_Sequence_2,
    ADC1_Sequence_3,
    //Reserved          //52-56
    SSI2=57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,
    //Reserved          //64-67
    I2C2=68,
    I2C3,
    Bit16_32_Timer4A,        
    Bit16_32_Timer4B,           
    //Reserved          //72-91
    Bit16_64_Timer5A=92, 
    Bit16_64_Timer5B,
    Bit32_64_Timer0A,        
    Bit32_64_Timer0B,        
    Bit32_64_Timer1A,          
    Bit32_64_Timer1B,       
    Bit32_64_Timer2A,            
    Bit32_64_Timer2B,  
    Bit32_64_Timer_3A,            
    Bit32_64_Timer_3B,   
    Bit32_64_Timer_4A,            
    Bit32_64_Timer_4B, 
    Bit32_64_Timer_5A,            
    Bit32_64_Timer_5B,     
    System_Exception,   //(imprecise)       
    //Reserved          //107-133
    PWM1_Generator_0=134,
    PWM1_Generator_1,
    PWM1_Generator_2,
    PWM1_Generator_3,
    PWM1_Fault,

    None=200

}IntCtrl_InterruptType;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
