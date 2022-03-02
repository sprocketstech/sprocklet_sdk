
#pragma once

#include <stdint.h>
 

#define DLEDWS_DEVICE_ID 0xde02
#define DLEDWS_DEVICE_VERSION 0x0001


/**********************************************
 * Registers
 */
/* The device ID -- should always be 0xde02 */
#define DLEDWS_DEVICE_ID_REGISTER 0
/* The device version -- should always be 0x0001  */
#define DLEDWS_DEVICE_VERSION_REGISTER 2
/* The device's address */
#define DLEDWS_DEVICE_ADDRESS_REGISTER 4 
/* The action to take when the switch is pressed (DLEDWS_SW_ACTION) */
#define DLEDWS_SWITCH_ACTION_REGISTER 5 
/* The type of switch attached (DSPROCKLET_SWITCH_TYPE) */
#define DLEDWS_SWITCH_TYPE_REGISTER 6 
/* The time to hold the switch's state (in ms) (uint16) */
#define DLEDWS_SWITCH_AGE_REGISTER 7 
/* The state of the switch if a toggle switch (uint8) */
#define DLEDWS_SWITCH_TOGGLE_STATE_REGISTER 9 
/* The number of clicks if a momentary switch (uint8) */
#define DLEDWS_SWITCH_MOMENTARY_CLICK_COUNT_REGISTER 10 
/* The length of the press if a momentary switch (in ms) (uint32) */
#define DLEDWS_SWITCH_MOMENTARY_PRESS_DURATION_REGISTER 11 
/* The number of LEDs in the strip (1-80) (uint8) */
#define DLEDWS_NUM_LEDS_REGISTER 15 
/* The state of the LEDs (boolean) */
#define DLEDWS_LED_STATE_REGISTER 16 
/* Set the brightness of all LEDs (0=off, 255=full bright) (uint8) */
#define DLEDWS_GLOBAL_BRIGHTNESS_REGISTER 17 
/* Set the red value of all LEDs (0=no red, 255=full red) (uint8) */
#define DLEDWS_GLOBAL_RED_REGISTER 18 
/* Set the green value of all LEDs (0=no green, 255=full green) (uint8) */
#define DLEDWS_GLOBAL_GREEN_REGISTER 19 
/* Set the blue value of all LEDs (0=no blue, 255=full blue) (uint8) */
#define DLEDWS_GLOBAL_BLUE_REGISTER 20 
/* Not a register, per se, but rather the start of individual color values of each LED in the strip.  Each LED as an G, R, and a B value of one byte.  So this register is the green value of the first LED, the next register is the red value of the first LED, then the blue value of the first LED, followed by the green value of the second LED, and so on. (uint8) */
#define DLEDWS_RGB_START_REGISTER 21      
    


/**********************************************
* Enumerations
*/
enum DLEDWS_SW_ACTION
{
    DLEDWS_ACTION_NONE = 0, 
    DLEDWS_ACTION_TOGGLE_LED = 1, 
    DLEDWS_ACTION_LED_OFF = 2, 
    DLEDWS_ACTION_LED_ON = 3
};    
