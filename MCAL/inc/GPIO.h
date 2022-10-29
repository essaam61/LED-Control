/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File: GPIO.h
 *       Module: GPIO
 *
 *  Description:  Header file for GPIO Module
 *  
 *********************************************************************************************************************/
#ifndef GPIO_H
#define GPIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_Cfg.h"
#include "GPIO_Types.h"
#include "Port.h"

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

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void DioChannel_Init(void)     
* \Description     : Initializes the DIO Driver module.
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
extern void Dio_Init(void);

/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
* \Description     : Returns the value of the specified DIO channel.                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Dio_LevelType (STD_HIGH: The physical level of the corresponding Pin is STD_HIGH,
                                    STD_LOW: The physical level of the corresponding Pin is STD_LOW)                          
*******************************************************************************/
extern Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId );


 /******************************************************************************
* \Syntax          : void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )    
* \Description     : Service to set a level of a channel.                          
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  ChannelId (ID of DIO channel), Level (Value to be written)                          
*******************************************************************************/
extern void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level );


/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
* \Description     : Returns the level of all channels of that port.                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  PortId (ID of DIO Port)                       
*******************************************************************************/
extern Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);


/******************************************************************************
* \Syntax          : void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)   
* \Description     : Service to set a value of the port.                        
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  PortId (ID of DIO Port), Level (Value to be written)                          
*******************************************************************************/
extern void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)  
* \Description     : Service to flip (change from 1 to 0 or from 0 to 1) the level of                  
*                    a channel and return the level of the channel after flip.                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   :  ChannelId (ID of DIO channel)                
*******************************************************************************/
extern Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);


#endif  /* GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: GPIO.h
 *********************************************************************************************************************/
