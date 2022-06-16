#pragma once

#include <stdint.h>
#include <sprocklets/Sprocklet_defs.h>

#define DLEDWS_DEVICE_ID 0xde02
#define DLEDWS_DEVICE_VERSION 0x0001

/**********************************************
 * Registers
 */
const uint8_t DLEDWS_SW_TYPE_REGISTER = SPROCKLET_START_REGISTER;
const uint8_t DLEDWS_SW_DETECT_REGISTER = DLEDWS_SW_TYPE_REGISTER + 0x01;
const uint8_t DLEDWS_SW_STATE_REGISTER = DLEDWS_SW_DETECT_REGISTER + 0x01;
const uint8_t DLEDWS_NUM_LEDS_REGISTER = DLEDWS_SW_STATE_REGISTER + 0x01;
const uint8_t DLEDWS_RGB_START = DLEDWS_NUM_LEDS_REGISTER + 0x01;

/**********************************************
 * Switch type
 */
enum DLED5V_SWITCH_TYPE
{
    DLEDWS_SWITCH_NONE = 0,
    DLEDWS_SWITCH_MOMENTARY,
    DLEDWS_SWITCH_TOGGLE
};

/**********************************************
 * Switch operations to detect - only valid for momentary switches
 */
enum DLEDWS_SWITCH_DETECT
{
    DLEDWS_SWITCH_DETECT_NONE = 0,
    DLEDWS_SWITCH_DETECT_LONG = 1,
    DLEDWS_SWITCH_DETECT_VERYLONG = 2,
    DLEDWS_SWITCH_DETECT_DOUBLE_PRESS = 4,
    DLEDWS_SWITCH_DETECT_TRIPLE_PRESS = 8,
};

/**********************************************
 * Current state of the switch
 */
enum DLEDWS_SWITCH_STATE
{
    DLEDWS_SWITCH_OFF = 0,         // off and on are valid for toggle
    DLEDWS_SWITCH_ON,              // off and on are valid for toggle
    DLEDWS_SWITCH_PRESS,           // press is only valid for momentary
    DLEDWS_SWITCH_LONG_PRESS,      // long press is only valid for momentary
    DLEDWS_SWITCH_VERY_LONG_PRESS, // very long press is only valid for momentary
    DLEDWS_SWITCH_DOUBLE_PRESS,    // double press is only valid for momentary
    DLEDWS_SWITCH_TRIPLE_PRESS,    // triple press is only valid for momentary
};
