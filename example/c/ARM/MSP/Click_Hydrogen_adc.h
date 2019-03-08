#include "Click_Hydrogen_types.h"


void hydrogen_adcInit()
{
    ADC_Init();
    ADC_Set_Input_Channel( _ADC_CHANNEL_15 );
}

uint32_t hydrogen_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 15 );
    
    return readADC;
}