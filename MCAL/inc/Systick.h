/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Systick.h
 *       Module: SysTick
 *
 *  Description:  Header file for SysTick Module
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define SYS_CLOCK_HZ 16000000U-1   // Reload value of 1 second
#define SYSTICK_EN_DI_VALUE 0X05
#define CURRENT_VALUE 0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Systick_Init (void)   
* \Description     : Initializes the SysTick Driver.                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
extern void Systick_Init (void);


/******************************************************************************
* \Syntax          : void SysTick_Handler(void)
* \Description     : Checks the systick call back pointer and calls function in upper layer.                                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                   
*******************************************************************************/
extern void SysTick_Handler(void);


/******************************************************************************
* \Syntax          : void Systick_StartCount (void)   
* \Description     : Enables the systick timer counter to start counting.                      
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  Enables the systick timer counter to start counting.                       
*******************************************************************************/
extern void Systick_StartCount (void);


/******************************************************************************
* \Syntax          : void Systick_EndCount (void)   
* \Description     : Disables the systick timer from counting and reloads it.                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  Disables the systick timer from counting and reloads it.                      
*******************************************************************************/
extern void Systick_EndCount (void);

/******************************************************************************
* \Syntax          : void SysTick_SetCallBack ( void(*Ptr2Func)(void) ) 
* \Description     :                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Setups the SysTick Timer call back                   
*******************************************************************************/
extern void Systick_SetCallBack (void(*Ptr2Func)(void));

#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/
