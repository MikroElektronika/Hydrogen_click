/*
Example for Hydrogen Click

    Date          : Jan 2019.
    Author        : Nenad Filipovic

Test configuration AVR :
    
    MCU              : ATMEGA32
    Dev. Board       : EasyAVR v7 
    AVR Compiler ver : v7.0.1.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO and LOG structures, sets AN pin as input.
- Application Initialization - Initialization driver enables GPIO and ADC, also starts write log.
- Application Task - (code snippet) This is a example which demonstrates the use of Hydrogen Click board.
     Hydrogen Click reads ADC value.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart changes for every 1 sec.

Additional Functions :

- void hydrogen_adcInit() - Function ADC initialization.
- uint32_t hydrogen_readADC() - Function read ADC value.

*/

#include "Click_Hydrogen_types.h"
#include "Click_Hydrogen_config.h"
#include "Click_Hydrogen_adc.h"

uint16_t valueADC;
char logText[ 50 ];

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );

    mikrobus_logInit( _LOG_USBUART, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    hydrogen_gpioDriverInit( (T_HYDROGEN_P)&_MIKROBUS1_GPIO );
    Delay_100ms();

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( "  Hydrogen  click  ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    hydrogen_adcInit();
    Delay_100ms();

    mikrobus_logWrite( " ADC Initializated ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
}

void applicationTask()
{
    valueADC = hydrogen_readADC();
    Delay_100ms();

    IntToStr( valueADC, logText );
    mikrobus_logWrite( " ADC value: ", _LOG_TEXT );
    mikrobus_logWrite( logText, _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}