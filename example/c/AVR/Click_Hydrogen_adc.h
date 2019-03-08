#include "Click_Hydrogen_types.h"


void hydrogen_adcInit()
{
    ADC_Init();
}

uint32_t hydrogen_readADC()
{
    uint32_t readADC;
    
    readADC = ADC_Read( 7 );
    
    return readADC;
}