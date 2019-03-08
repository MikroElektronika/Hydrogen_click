#include "Click_Hydrogen_types.h"


void hydrogen_adcInit()
{
    ADC1_Init();
    ADC1_Set_Input_Channel( 0x01 );
}

uint32_t hydrogen_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 1 );
    
    return readADC;
}