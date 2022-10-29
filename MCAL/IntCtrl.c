/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "tm4c123gh6pm.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

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
* \Syntax          : void IntCtrl_Init (IntCtrl_InterruptType InterruptNo, IntCtrl_ProcInterruptType ProcInterruptNo)  
* \Description     : Initializes Nvic/Scb Module by parsing the configuration into Nvic/SCB Registers                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
void IntCtrl_Init (IntCtrl_InterruptType InterruptNo, IntCtrl_ProcInterruptType ProcInterruptNo)
{
    /*TODO: Configure Grouping/Subgrouping System in APINT register in SCB*/
    #if (GroupCombination == xxx)
    SCB_APINT = APINT_VECTKEY | PRIGROUP_XXX_BIT;
    #elif (GroupCombination == xxy)
    SCB_APINT = APINT_VECTKEY | PRIGROUP_XXY_BIT;
    #elif (GroupCombination == xyy)
    SCB_APINT = APINT_VECTKEY | PRIGROUP_XYY_BIT;
    #elif (GroupCombination == yyy)
    SCB_APINT = APINT_VECTKEY | PRIGROUP_YYY_BIT;
    #endif
    

    /*TODO: Assign Group/Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
    if (InterruptNo <= 3)
        NVIC_PRI0 = PRI0_VALUE;
    else if(InterruptNo > 3 && InterruptNo <= 7)
        NVIC_PRI1 = PRI1_VALUE;
    else if(InterruptNo > 7 && InterruptNo <= 11)
        NVIC_PRI2 = PRI2_VALUE;
    else if(InterruptNo > 11 && InterruptNo <= 15)
        NVIC_PRI3 = PRI3_VALUE;
    else if(InterruptNo > 15 && InterruptNo <= 19)
        NVIC_PRI4 = PRI4_VALUE;
    else if(InterruptNo > 19 && InterruptNo <= 23)
        NVIC_PRI5 = PRI5_VALUE;
    else if(InterruptNo > 23 && InterruptNo <= 27)
        NVIC_PRI6 = PRI6_VALUE;
    else if(InterruptNo > 27 && InterruptNo <= 31)
        NVIC_PRI7 = PRI7_VALUE;
    else if(InterruptNo > 31 && InterruptNo <= 35)
        NVIC_PRI8 = PRI8_VALUE;
    else if(InterruptNo > 35 && InterruptNo <= 39)
        NVIC_PRI9 = PRI9_VALUE;
    else if(InterruptNo > 39 && InterruptNo <= 43)
        NVIC_PRI10 = PRI10_VALUE;


    if(ProcInterruptNo >= 4 && ProcInterruptNo <= 6)
        SCB_SYSPRI1 = SYSPRI1_VALUE;
    else if(ProcInterruptNo == 11)
        SCB_SYSPRI2 = SYSPRI3_VALUE;
    else if(ProcInterruptNo >= 12 && ProcInterruptNo <= 15)
        SCB_SYSPRI3 = SYSPRI3_VALUE;


    /*TODO: Enable/Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    if (InterruptNo <= 31)
	    NVIC_EN0 = EN0_VALUE;
    else if (InterruptNo > 31 & InterruptNo <=63 )
	    NVIC_EN1 = EN1_VALUE;
    else if (InterruptNo > 63 & InterruptNo <=95 )
	    NVIC_EN2 = EN2_VALUE;
    else if (InterruptNo > 95 & InterruptNo <=127 )
	    NVIC_EN3 = EN3_VALUE;

    if(ProcInterruptNo >= 4 && ProcInterruptNo <=6)
        SCB_SYSHNDCTRL = SCBSYS_VALUE;
    else if (ProcInterruptNo == 15)
        NVIC_ST_CTRL_R |= STINT_BIT;
	


    EnableInterrupts(); 	/* Enable interrupts to the processor. */
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
