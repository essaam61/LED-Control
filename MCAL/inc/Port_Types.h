/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: Port_Types.h
 *       Module: Port
 *
 *  Description:  Type definitions of Port driver  
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

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
typedef uint32 Port_PinType;
typedef enum { PORT_PIN_IN, PORT_PIN_OUT } Port_PinDirectionType;
typedef uint32 Port_PinMode;
typedef enum
{
    PULL_UP =0,
    PULL_DOWN ,
    OPEN_DRAIN,
}Port_PinInternalAttach;

typedef enum
{
    R2R,
    R4R,
    R8R
}Port_PinOutputCurrent;

typedef struct PortConfig {

    Port_PinMode pinmode;
    uint32 port;
    Port_PinType pin;
    Port_PinDirectionType pin_direction;
    uint8 pin_level;
    Port_PinInternalAttach attach;
    Port_PinOutputCurrent current;

  } Port_ConfigType;


 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/