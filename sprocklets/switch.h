
#pragma once

#include <stdint.h>
 
enum DSPROCKLET_SWITCH_TYPE
{
	/* No switch attached */
    DSPROCKLET_SWITCH_NONE = 0, 
	/* A momentary switch is attached */
    DSPROCKLET_SWITCH_MOMENTARY = 1, 
	/* A toggle switch is attached */
    DSPROCKLET_SWITCH_TOGGLE = 2
};    