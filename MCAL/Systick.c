/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  System Tick Timer
 *
 *      \details  Initializes the SysTick timer and provides a specific periodicity to increase tick counter.
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Systick.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
/* Global pointer to function used to point to upper layer functions for use in Call Back */
static void (*Systick_CallBack_Ptr)(void) = NULL_PTR;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Systick_Init (void)
{
    STCTRL &= (~SYSTICK_EN_DI_VALUE);                  /*  Disable SysTick. */
    STRELOAD = SYS_CLOCK_HZ;        /*  Sets the period of the SysTick counter. */
    STCURRENT = CURRENT_VALUE;                  /*  Reload SysTick Counter  */
    STCTRL|= SYSTICK_EN_DI_VALUE;  /*  Enables the SysTick Counter and System Clock   */
}


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
void SysTick_Handler(void)
{
    if(Systick_CallBack_Ptr != NULL_PTR)
    {
        (*Systick_CallBack_Ptr)(); 
    }    

}


/******************************************************************************
* \Syntax          : void Systick_StartCount (void)   
* \Description     : Enables the systick timer counter to start counting.                       
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                     
*******************************************************************************/
void Systick_StartCount (void)
{
    STCTRL |= SYSTICK_EN_DI_VALUE;         /*  Enable the SysTick Counter.   */
}


/******************************************************************************
* \Syntax          : void Systick_EndCount (void)   
* \Description     : Disables the systick timer from counting and reloads it.                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                
*******************************************************************************/
void Systick_EndCount (void)
{
    STCTRL &= (~SYSTICK_EN_DI_VALUE);                  /*  Disable SysTick. */
    STCURRENT = CURRENT_VALUE;        /*  Reload SysTick Counter  */
}


/******************************************************************************
* \Syntax          : void Systick_SetCallBack ( void(*Ptr2Func)(void) )
* \Description     : takes a pointer to function for upper layers function with                          
*                    the concept of call back.                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Ptr2Func (Address of Call Back Function)                  
* \Parameters (out): None                                                      
* \Return value:   : None                
*******************************************************************************/
void Systick_SetCallBack ( void(*Ptr2Func)(void) )
{
    Systick_CallBack_Ptr = Ptr2Func;
}

/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/