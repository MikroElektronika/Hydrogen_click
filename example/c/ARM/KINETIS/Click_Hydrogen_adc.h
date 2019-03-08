#include "Click_Hydrogen_types.h"


void hydrogen_adcInit()
{
    ADC0_Init();
    ADC0_Set_Input_Channel( _ADC_CHANNEL_12 );
}

uint32_t hydrogen_readADC()
{
    uint32_t readADC;
    
    readADC = ADC0_Read( 12 );
    
    return readADC;
}