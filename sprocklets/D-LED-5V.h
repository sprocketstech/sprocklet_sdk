
#pragma once

#include <stdint.h>
 

#define DLED5V_DEVICE_ID 0xdead
#define DLED5V_DEVICE_VERSION 0x0001


/**********************************************
 * Registers
 */
/* The device ID -- should always be 0xdead */
#define DLED5V_DEVICE_ID_REGISTER 0
/* The device version -- should always be 0x0001  */
#define DLED5V_DEVICE_VERSION_REGISTER 2
/* The device's address */
#define DLED5V_DEVICE_ADDRESS_REGISTER 4 
/* The state of the LED (boolean) */
#define DLED5V_LED_STATE_REGISTER 5 
/* The effect to run for the LED (DLED5V_EFFECTS) */
#define DLED5V_LED_EFFECT_REGISTER 6 
/* The brightness of the LED (0=off, 255=full bright) (uint8) */
#define DLED5V_LED_BRIGHTNESS_REGISTER 7 
/* The action to take when the switch is pressed (DLED5V_SW_ACTION) */
#define DLED5V_SWITCH_ACTION_REGISTER 8 
/* The type of switch attached (DSPROCKLET_SWITCH_TYPE) */
#define DLED5V_SWITCH_TYPE_REGISTER 9 
/* The time to hold the switch's state (in ms) (uint16) */
#define DLED5V_SWITCH_AGE_REGISTER 10 
/* The state of the switch if a toggle switch (uint8) */
#define DLED5V_SWITCH_TOGGLE_STATE_REGISTER 12 
/* The number of clicks if a momentary switch (uint8) */
#define DLED5V_SWITCH_MOMENTARY_CLICK_COUNT_REGISTER 13 
/* The length of the press if a momentary switch (in ms) (uint32) */
#define DLED5V_SWITCH_MOMENTARY_PRESS_DURATION_REGISTER 14      
    


/**********************************************
* Enumerations
*/
enum DLED5V_EFFECTS
{
    DLED5V_EFFECT_STATIC = 0, 
    DLED5V_EFFECT_SLOW_BLINK = 1, 
    DLED5V_EFFECT_FAST_BLINK = 2, 
    DLED5V_EFFECT_BREATHE = 3, 
    DLED5V_EFFECT_CANDLE = 4, 
    DLED5V_EFFECT_SPARKLE = 5
};    

enum DLED5V_SW_ACTION
{
    DLED5V_ACTION_NONE = 0, 
    DLED5V_ACTION_TOGGLE_LED = 1, 
    DLED5V_ACTION_LED_OFF = 2, 
    DLED5V_ACTION_LED_ON = 3
};    
