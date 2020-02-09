/**
 * @file Mapping.hpp
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2
 */

#pragma once

#include <OneButton.h>

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}
const bool ActiveLow = true;

// Child ID declaration of relays
const uint8_t SALOON_1_ID       = 11;
const uint8_t SALOON_2_ID       = 12;
const uint8_t SALOON_SHELF_ID   = 13;
const uint8_t GAMING_ROOM_1_ID  = 21;
const uint8_t GAMING_ROOM_2_ID  = 22;
const uint8_t BEDROOM_1_ID      = 31;
const uint8_t BEDROOM_2_ID      = 32;
const uint8_t BED_1_ID          = 33;
const uint8_t BED_2_ID          = 34;
const uint8_t GUESTS_ID         = 41;
const uint8_t BATHROOM_ID       = 51;
const uint8_t BATHROOM_LED_ID   = 52;
const uint8_t MIRROR_ID         = 53;
const uint8_t FAN_ID            = 54;
const uint8_t KITCHEN_ID        = 61;
const uint8_t KITCHEN_LED_ID    = 62;
const uint8_t KITCHEN_TABLE_ID  = 63;
const uint8_t WORKSHOP_ID       = 71;
const uint8_t CORRIDOR_ID       = 81;
const uint8_t HEATING_1_ID      = 10;
const uint8_t HEATING_2_ID      = 20;
const uint8_t HEATING_3_ID      = 30;
const uint8_t HEATING_4_ID      = 40;
const uint8_t HEATING_5_ID      = 50;
const uint8_t HEATING_6_ID      = 60;
const uint8_t HEATING_7_ID      = 70;

typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

SensorsStruct Sensors [] = {
//  Child ID           description       pin activelow
  { SALOON_1_ID,       "Salon S1",       20, false },
  { SALOON_2_ID,       "Salon S2",       21, false },
  { SALOON_SHELF_ID,   "Salon Połka",    22, false },
  { GAMING_ROOM_1_ID,  "Gralnia S1",     23, false },
  { GAMING_ROOM_2_ID,  "Gralnia S2",     24, false },
  { BEDROOM_1_ID,      "Sypialnia S1",   25, false },
  { BEDROOM_2_ID,      "Sypialnia S2",   26, false },
  { BED_1_ID,          "łóżko 1",        27, false },
  { BED_2_ID,          "łóżko 2",        28, false },
  { GUESTS_ID,         "Gościnny",       29, false },
  { BATHROOM_ID,       "łazienka",       30, false },
  { BATHROOM_LED_ID,   "Prysznic",       31, false },
  { MIRROR_ID,         "Lustro",         32, false },
  { FAN_ID,            "Wentylator",     33, false },
  { KITCHEN_ID,        "Kuchnia",        34, false },
  { KITCHEN_LED_ID,    "Kuchnia ledy",   35, false },
  { KITCHEN_TABLE_ID,  "Kuchnia stolik", 36, false },
  { WORKSHOP_ID,       "Warsztat",       37, false },
  { CORRIDOR_ID,       "Korytarz",       38, false },
  { HEATING_1_ID,      "Strefa 1",       41, false },
  { HEATING_2_ID,      "Strefa 2",       42, false },
  { HEATING_3_ID,      "Strefa 3",       43, false },
  { HEATING_4_ID,      "Strefa 4",       44, false },
  { HEATING_5_ID,      "Strefa 5",       45, false },
  { HEATING_6_ID,      "Strefa 6",       46, false },
  { HEATING_7_ID,      "Strefa 7",       47, false },
};
const uint8_t maxSensors = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage msgs[maxSensors];

uint8_t getIdx(uint8_t sensorId) {
  for (uint8_t i = 0; i < maxSensors; i++) {
    if (Sensors[i].id == sensorId) return(i);
  }
  return(-1);
}

// Pushbuttons declaration
// Remember that names should be consistent with main loop in gateway.ino
OneButton saloon(A1, true);
OneButton gamingRoom(A2, true);
OneButton bedroom(A3, true);
OneButton bed1(A4, true);
OneButton bed2(A5, true);
OneButton guests(A6, true);
OneButton bathroom(A7, true);
OneButton mirror(A8, true);
OneButton kitchen(A9, true);
OneButton kitchenTable(A10, true);
OneButton workshop(A11, true);
OneButton corridor(A12, true);
