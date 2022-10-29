/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: LED_BP.h
 *       Module: LED Blink Protocol Software Component
 *
 *  Description:  Header file for LED BP Software Component
 *  
 *********************************************************************************************************************/
#ifndef LED_BP_H
#define LED_BP_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Systick.h"
#include "LED.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RESET 0

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
* \Syntax          : void LED_Blink (int color, int ONTime, int OFFTime)
* \Description     : Lights a LED for the given ON time, and dim it for the given OFF time.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
void LED_Blink (uint32 color, uint32 ONTime, uint32 OFFTime);

/******************************************************************************
* \Syntax          : void TimerCount (void) 
* \Description     : Counts the timer ISR ticks.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
extern void TimerCount (void);
 
#endif  /* LED_BP_H */

/**********************************************************************************************************************
 *  END OF FILE: LED_BP.h
 *********************************************************************************************************************/
