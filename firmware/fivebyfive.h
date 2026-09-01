#pragma once

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03, K04, \
    E0_BTN, E1_BTN, E2_BTN, E3_BTN, E4_BTN \
) { \
    { K00, K01, K02, K03, K04 }, \
    { E0_BTN, E1_BTN, E2_BTN, E3_BTN, E4_BTN } \
}
