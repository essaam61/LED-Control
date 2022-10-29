/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static uint32 Dio_Base_Addr[PORTS_NUMBER] = {    
    GPIO_PORTA_BASE_ADDRESS,
    GPIO_PORTB_BASE_ADDRESS,
    GPIO_PORTC_BASE_ADDRESS,
    GPIO_PORTD_BASE_ADDRESS,
    GPIO_PORTE_BASE_ADDRESS,
    GPIO_PORTF_BASE_ADDRESS
};

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
* \Syntax          : void Dio_Init(void)     
* \Description     : Initializes the DIO Driver module.                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
void Dio_Init(void)
{
    Port_ConfigType PORTF[DIOPORT_PINS_SIZE_USED] = 
    { { NORMAL_MODE, GPIO_Port, Channel_1, PORT_PIN_OUT, PinLevel_InitValue},
      { NORMAL_MODE, GPIO_Port, Channel_2, PORT_PIN_OUT, PinLevel_InitValue},
      { NORMAL_MODE, GPIO_Port, Channel_3, PORT_PIN_OUT, PinLevel_InitValue} };

    for(int i=0 ; i < DIOPORT_PINS_SIZE_USED ; i++)
        Port_Init(&PORTF[i]);
	
}


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
Dio_LevelType Dio_ReadChannel ( Dio_ChannelType ChannelId )
{
    Dio_PortType PortId = ChannelId / DIOPORT_SIZE;
    uint8 DioPin = ChannelId % DIOPORT_SIZE;
    uint32 PortBaseAddr = Dio_Base_Addr[PortId];

    return GPIODATA(PortBaseAddr)&(STD_HIGH<<DioPin);
}

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
void Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
    Dio_PortType PortId = ChannelId / DIOPORT_SIZE;
    uint8 DioPin = ChannelId % DIOPORT_SIZE;
    uint32 PortBaseAddr = Dio_Base_Addr[PortId];
    
    if (Level == STD_HIGH)
    {
        GPIODATA(PortBaseAddr) |= (STD_HIGH<<DioPin);   /* Writes a value to the specified pin or channel  */
    }
    else if (Level == STD_LOW)
    {
        GPIODATA(PortBaseAddr) &= ~(STD_HIGH<<DioPin);    /* Writes a value to the specified pin or channel  */
    }

}


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
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId) {

    return GPIODATA(Dio_Base_Addr[PortId]);
}

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
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level) {

    GPIODATA(Dio_Base_Addr[PortId]) = Level;
}


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
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId) {
    Dio_PortType PortId = ChannelId / DIOPORT_SIZE;
    uint8 DioPin = ChannelId % DIOPORT_SIZE;
    uint32 PortBaseAddr = Dio_Base_Addr[PortId];

    GPIODATA(PortBaseAddr) ^= (STD_HIGH<<DioPin);
    return Dio_ReadChannel(ChannelId);

}



/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
