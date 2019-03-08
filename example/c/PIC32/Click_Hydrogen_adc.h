#include "Click_Hydrogen_types.h"


void hydrogen_adcInit()
{
    ADC1_Init();
}

uint32_t hydrogen_readADC()
{
    uint32_t readADC;
    
    readADC = ADC1_Read( 8 );
    
    return readADC;
}