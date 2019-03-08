/*
    __hydrogen_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __hydrogen_driver.h
@brief    Hydrogen Driver
@mainpage Hydrogen Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HYDROGEN
@brief      Hydrogen Click Driver
@{

| Global Library Prefix | **HYDROGEN** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Jan 2019.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HYDROGEN_H_
#define _HYDROGEN_H_

/** 
 * @macro T_HYDROGEN_P
 * @brief Driver Abstract type 
 */
#define T_HYDROGEN_P    const uint8_t*

/** @defgroup HYDROGEN_COMPILE Compilation Config */              /** @{ */

//  #define   __HYDROGEN_DRV_SPI__                            /**<     @macro __HYDROGEN_DRV_SPI__  @brief SPI driver selector */
//  #define   __HYDROGEN_DRV_I2C__                            /**<     @macro __HYDROGEN_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HYDROGEN_DRV_UART__                           /**<     @macro __HYDROGEN_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HYDROGEN_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup HYDROGEN_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HYDROGEN_INIT Driver Initialization */              /** @{ */

#ifdef   __HYDROGEN_DRV_SPI__
void hydrogen_spiDriverInit(T_HYDROGEN_P gpioObj, T_HYDROGEN_P spiObj);
#endif
#ifdef   __HYDROGEN_DRV_I2C__
void hydrogen_i2cDriverInit(T_HYDROGEN_P gpioObj, T_HYDROGEN_P i2cObj, uint8_t slave);
#endif
#ifdef   __HYDROGEN_DRV_UART__
void hydrogen_uartDriverInit(T_HYDROGEN_P gpioObj, T_HYDROGEN_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void hydrogen_gpioDriverInit(T_HYDROGEN_P gpioObj);
                                                                       /** @} */
/** @defgroup HYDROGEN_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Get the correction factor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @return
 * float value of the calculated correction factor
 *
 * Function get the correction factor to correct for temperature and humidity.
*/
float hydrogen_getCorrectionFactor( float temperature, float humidity );

/**
 * @brief Get the resistance of the sensor function
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the sensor resistance in kOhm
 *
 * Function get the resistance of the sensor, ie. measurement adc value
 * of MQ-8 sensor on Hydrogen click board.
*/
float hydrogen_getResistance( uint32_t adcValue );

/**
 * @brief Get the corrected resistance of the sensor function
 *
 * @param[in] temperature                    float value of the ambient air temperature
 *
 * @param[in] humidity                       float value of the relative humidity
 *
 * @param[in] adcValue                       the measurement adc value
 *
 * @return
 * float value of the corrected sensor resistance kOhm
 *
 * Function get the corrected resistance of the sensor, ie. measurement adc value
 * of MQ-8 sensor on Hydrogen click board.
*/
float hydrogen_getCorrectedResistance( float temperature, float humidity, uint32_t adcValue );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Hydrogen_STM.c
    @example Click_Hydrogen_TIVA.c
    @example Click_Hydrogen_CEC.c
    @example Click_Hydrogen_KINETIS.c
    @example Click_Hydrogen_MSP.c
    @example Click_Hydrogen_PIC.c
    @example Click_Hydrogen_PIC32.c
    @example Click_Hydrogen_DSPIC.c
    @example Click_Hydrogen_AVR.c
    @example Click_Hydrogen_FT90x.c
    @example Click_Hydrogen_STM.mbas
    @example Click_Hydrogen_TIVA.mbas
    @example Click_Hydrogen_CEC.mbas
    @example Click_Hydrogen_KINETIS.mbas
    @example Click_Hydrogen_MSP.mbas
    @example Click_Hydrogen_PIC.mbas
    @example Click_Hydrogen_PIC32.mbas
    @example Click_Hydrogen_DSPIC.mbas
    @example Click_Hydrogen_AVR.mbas
    @example Click_Hydrogen_FT90x.mbas
    @example Click_Hydrogen_STM.mpas
    @example Click_Hydrogen_TIVA.mpas
    @example Click_Hydrogen_CEC.mpas
    @example Click_Hydrogen_KINETIS.mpas
    @example Click_Hydrogen_MSP.mpas
    @example Click_Hydrogen_PIC.mpas
    @example Click_Hydrogen_PIC32.mpas
    @example Click_Hydrogen_DSPIC.mpas
    @example Click_Hydrogen_AVR.mpas
    @example Click_Hydrogen_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __hydrogen_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */