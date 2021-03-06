/******************************************************************************
* File Name: ble_custom_service_config.h
*
* Version: 1.00
*
* Description: This file contains the macros that enable the use of three custom
*              BLE profiles used in this code example
*
* Related Document: CE220331_BLE_UI_RTOS.pdf
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/
/******************************************************************************
* This file contains the macros that enable the use of CapSense Slider, 
* CapSense Button and RGB LED custom BLE profiles used in this code example
*******************************************************************************/

/* Include guard */
#ifndef BLE_CUSTOM_SERVICE_CONFIG_H
#define BLE_CUSTOM_SERVICE_CONFIG_H

/* Header file includes */
#include "project.h"    
    
/* Redefinition of long custom service macros for better readability of the
   code */
#define SLIDER_CCCD_HANDLE      \
(CY_BLE_CAPSENSE_SLIDER_CAPSENSE_SLIDER_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE)
#define BUTTON_CCCD_HANDLE      \
(CY_BLE_CAPSENSE_BUTTON_CAPSENSE_BUTTON_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE)
#define RGB_CCCD_HANDLE         \
(CY_BLE_RGB_LED_RGB_LED_CONTROL_CLIENT_CHARACTERISTIC_CONFIGURATION_DESC_HANDLE)
#define SLIDER_CHAR_HANDLE      \
(CY_BLE_CAPSENSE_SLIDER_CAPSENSE_SLIDER_CHAR_HANDLE)
#define BUTTON_CHAR_HANDLE      \
(CY_BLE_CAPSENSE_BUTTON_CAPSENSE_BUTTON_CHAR_HANDLE)
#define RGB_CHAR_HANDLE         \
(CY_BLE_RGB_LED_RGB_LED_CONTROL_CHAR_HANDLE)

/* For more details on the data formats of CapSense button, CapSense slider and 
   RGB LED Custom BLE Profiles provided by Cypress, see Cypress custom profile
   specifications available at:
   http://www.cypress.com/documentation/software-and-drivers/cypresss-custom-ble-profiles-and-services
*/
    
/* Size of CapSense Button characteristics data in bytes */
#define BUTTON_DATA_LEN     (uint8_t) (0x03u)
/* Button header (position 0)contains the number of buttons */
#define BUTTON_DATA_HEADER  (uint8_t) (0x02u)
#define BUTTON_HEADER_POS   (uint8_t) (0x00u)
/* Buttons masks and positions that store touch data  */
#define BUTTON0_MASK        (uint8_t) (0x01u)
#define BUTTON1_MASK        (uint8_t) (0x02u)
#define BUTTON_MASK_POS0    (uint8_t) (0x02u)
#define BUTTON_MASK_POS1    (uint8_t) (0x01u)
/* Macro used to clear button masks */
#define BUTTON_MASK_CLEAR   (uint8_t) (0x00u)

/* Size of CapSense Slider characteristics data in bytes */    
#define SLIDER_DATA_LEN     (uint8_t) (0x01u)

/* Size of RGB characteristics data in bytes  */
#define RGB_DATA_LEN        (uint8_t) (0x04u)
/* Macro used to turn off all RGB LEDs */    
#define RGB_TURN_OFF_ALL    (uint32_t) (0x00000000u)  

/* Data-type used to access the RGB data as a 4-byte array for BLE GATT
   operations as well as a 32-bit (true color) word in RGBA color space format.
   Intensity value is stored in the Alpha-channel byte */  
typedef union
{
    uint8_t     valueArray[RGB_DATA_LEN];
    uint32_t    colorAndIntensity;
}   rgb_led_data_t; 

#endif /* BLE_CUSTOM_SERVICE_CONFIG_H */   
/* [] END OF FILE */
