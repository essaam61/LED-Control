/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  Configures the interrupts priorities and enable values.
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define xxx 0
#define xxy 1
#define xyy 2
#define yyy 3
#define GroupCombination xxx
#define APINT_VECTKEY 0xFA05
#define PRIGROUP_XXX_BIT 0x400
#define PRIGROUP_XXY_BIT 0x500
#define PRIGROUP_XYY_BIT 0x600
#define PRIGROUP_YYY_BIT 0x700

#define PRI0_VALUE 0x00
#define PRI1_VALUE 0x00
#define PRI2_VALUE 0x00
#define PRI3_VALUE 0x00
#define PRI4_VALUE 0x00
#define PRI5_VALUE 0x00
#define PRI6_VALUE 0x00
#define PRI7_VALUE 0x00
#define PRI8_VALUE 0x00
#define PRI9_VALUE 0x00
#define PRI10_VALUE 0x00

#define SYSPRI1_VALUE 0x00
#define SYSPRI2_VALUE 0x00
#define SYSPRI3_VALUE 0x00


#define EN0_VALUE 0x00
#define EN1_VALUE 0x00
#define EN2_VALUE 0x00
#define EN3_VALUE 0x00

#define SCBSYS_VALUE 0x00


#define STINT_BIT 0x02

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define EnableInterrupts()      __asm(" CPSIE i")

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
