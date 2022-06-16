#pragma once

#include <stdint.h>
#include <sprocklets/Sprocklet_defs.h>

#define DLED5V_DEVICE_ID 0xde01
#define DLED5V_DEVICE_VERSION 0x0001

/**********************************************
 * Registers
 */

const uint8_t DLED5V_LED_STATE_REGISTER = SPROCKLET_START_REGISTER;
const uint8_t DLED5V_LED_EFFECT_REGISTER = DLED5V_LED_STATE_REGISTER + 0x01;
const uint8_t DLED5V_LED_BRIGHTNESS_REGISTER = DLED5V_LED_EFFECT_REGISTER + 0x01;
const uint8_t DLED5V_SW_TYPE_REGISTER = DLED5V_LED_BRIGHTNESS_REGISTER + 0x01;
const uint8_t DLED5V_SW_DETECT_REGISTER = DLED5V_SW_TYPE_REGISTER + 0x01;
const uint8_t DLED5V_SW_STATE_REGISTER = DLED5V_SW_DETECT_REGISTER + 0x01;

/**********************************************
 * Effects
 */

enum DLED5V_EFFECTS
{
    DLED5V_EFFECT_STATIC = 0,
    DLED5V_EFFECT_SLOW_BLINK,
    DLED5V_EFFECT_FAST_BLINK,
    DLED5V_EFFECT_BREATHE,
    DLED5V_EFFECT_CANDLE,
    DLED5V_EFFECT_SPARKLE
};

/**********************************************
 * Switch type
 */
enum DLED5V_SWITCH_TYPE
{
    DLED5V_SWITCH_NONE = 0,
    DLED5V_SWITCH_MOMENTARY,
    DLED5V_SWITCH_TOGGLE
};

/**********************************************
 * Switch operations to detect - only valid for momentary switches
 */
enum DLED5V_SWITCH_DETECT
{
    DLED5V_SWITCH_DETECT_NONE = 0,
    DLED5V_SWITCH_DETECT_LONG = 1,
    DLED5V_SWITCH_DETECT_VERYLONG = 2,
    DLED5V_SWITCH_DETECT_DOUBLE_PRESS = 4,
    DLED5V_SWITCH_DETECT_TRIPLE_PRESS = 8,
};

/**********************************************
 * Current state of the switch
 */
enum DLED5V_SWITCH_STATE
{
    DLED5V_SWITCH_OFF = 0,         // off and on are valid for toggle
    DLED5V_SWITCH_ON,              // off and on are valid for toggle
    DLED5V_SWITCH_PRESS,           // press is only valid for momentary
    DLED5V_SWITCH_LONG_PRESS,      // long press is only valid for momentary
    DLED5V_SWITCH_VERY_LONG_PRESS, // very long press is only valid for momentary
    DLED5V_SWITCH_DOUBLE_PRESS,    // double press is only valid for momentary
    DLED5V_SWITCH_TRIPLE_PRESS,    // triple press is only valid for momentary
};
