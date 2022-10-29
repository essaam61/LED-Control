/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"

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
* \Syntax          : void Port_Init (const Port_ConfigType * ConfigPtr)  
* \Description     : Initializes the Port Driver module.                                
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr (Pointer to configuration set)                 
* \Parameters (out): None                                                      
* \Return value:   : None                          
*******************************************************************************/
void Port_Init (const Port_ConfigType * ConfigPtr)
{

    switch(ConfigPtr->pinmode)
    {
        case (NORMAL_MODE): {

        /*  PORT A Configuration  */
        if (ConfigPtr->port == PortA)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}                /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTA_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTA_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTA_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTA_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTA_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTA_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTA_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }


        /*  PORT B Configuration  */
        if (ConfigPtr->port == PortB)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}                /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTB_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTB_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTB_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTB_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTB_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTB_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTB_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }


        /*  PORT C Configuration  */
        if (ConfigPtr->port == PortC)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}                /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTC_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTC_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTC_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTC_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTC_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTC_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTC_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }


        /*  PORT D Configuration  */
        if (ConfigPtr->port == PortD)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}                /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTD_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTD_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTD_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTD_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTD_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTD_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTD_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }


        /*  PORT E Configuration  */
        if (ConfigPtr->port == PortE)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}                /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTE_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTE_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTE_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTE_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTE_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTE_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTE_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }
        

        /*  PORT F Configuration  */
        if (ConfigPtr->port == PortF)
        {
            SYSCTL_RCGCGPIO |= ConfigPtr->port;                           /*  Enabling the GPIO Port B Peripheral   */
            while((SYSCTL_PRGPIO&ConfigPtr->port) == 0){}        /*      Wait for the GPIO module to be ready    */
            GPIOLOCK(GPIO_PORTF_BASE_ADDRESS) = GPIO_LOCK_KEY;                   /*  Unlocking PORTF Pins for use   */
            GPIOCR(GPIO_PORTF_BASE_ADDRESS)  |= GPIO_CR_NO;                           /* Enable writing to PUR */
            if (ConfigPtr->pin_direction == PORT_PIN_IN)
            {
                GPIODIR(GPIO_PORTF_BASE_ADDRESS) &= (~ConfigPtr->pin);          /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTF_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;           /* Enable pins PF0, PF4. */
            }
            else if (ConfigPtr->pin_direction == PORT_PIN_OUT)
            {
                GPIODATA(GPIO_PORTF_BASE_ADDRESS) = ConfigPtr->pin_level;
                GPIODIR(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;     /* Sets the direction of the specified pin */
                switch(ConfigPtr->attach)
                {
                    case(PULL_UP): {
                        GPIOPUR(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Up Resistance on Push Buttons  */
                        break;
                    }
                    case(PULL_DOWN): {
                        GPIOPDR(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Enable Pull Down Resistance on Push Buttons  */
                        break;
                    }
                    case(OPEN_DRAIN): {
                        GPIOODR(GPIO_PORTF_BASE_ADDRESS)|= ConfigPtr->pin;            /* Enable Open Drain on Push Buttons  */
                        break;
                    }
                    default: {}
                }
                GPIODEN(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;
            }

            switch(ConfigPtr->current)
            {
                case(R2R): {
                    GPIODR2R(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 2mA drive for GPIO pin  */
                    break;
                }
                case(R4R): {                        
                    GPIODR4R(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 4mA drive for GPIO pin  */
                    break;
                    }
                case(R8R): {
                    GPIODR8R(GPIO_PORTF_BASE_ADDRESS) |= ConfigPtr->pin;            /* Select 8mA drive for GPIO pin  */
                    break;
                }
                default: {}

            }
        }

        break;
    }

        case (SPECIAL_MODE): 
        {
            break;
        }

        default: {}
    }


}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
