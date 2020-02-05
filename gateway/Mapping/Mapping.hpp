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
const uint8_t SALOON_1_ID       = 1;
const uint8_t SALOON_2_ID       = 2;
const uint8_t SALOON_3_ID       = 3;
const uint8_t GAMING_ROOM_1_ID  = 4;
const uint8_t GAMING_ROOM_2_ID  = 5;
const uint8_t BEDROOM_ID        = 6;
const uint8_t BED_1_ID          = 7;
const uint8_t BED_2_ID          = 8;
const uint8_t GUESTS_ID         = 9;
const uint8_t BATHROOM_1_ID     = 10;
const uint8_t BATHROOM_2_ID     = 11;
const uint8_t MIRROR_ID         = 12;
const uint8_t FAN_ID            = 13;
const uint8_t KITCHEN_1_ID      = 14;
const uint8_t KITCHEN_2_ID      = 15;
const uint8_t KITCHEN_TABLE_ID  = 16;
const uint8_t WORKSHOP_ID       = 17;
const uint8_t CORRIDOR_ID       = 18;
const uint8_t HEATING_1_ID      = 20;
const uint8_t HEATING_2_ID      = 21;
const uint8_t HEATING_3_ID      = 22;
const uint8_t HEATING_4_ID      = 23;
const uint8_t HEATING_5_ID      = 24;
const uint8_t HEATING_6_ID      = 25;
const uint8_t HEATING_7_ID      = 26;

typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

// TODO: Move to separate file
SensorsStruct Sensors [] = {
  { SALOON_1_ID,       "Salon S1",       24, false },
  { SALOON_2_ID,       "Salon S2",       25, false },
  { SALOON_3_ID,       "Salon Lampka",   26, false },
  { GAMING_ROOM_1_ID,  "Gralnia S1",     27, false },
  { GAMING_ROOM_2_ID,  "Gralnia S2",     28, false },
  { BEDROOM_ID,        "Sypialnia",      29, false },
  { BED_1_ID,          "Lozko 1",        30, false },
  { BED_2_ID,          "Lozko 2",        31, false },
  { GUESTS_ID,         "Goscinny",       32, false },
  { BATHROOM_1_ID,     "Lazienka",       33, false },
  { BATHROOM_2_ID,     "Prysznic",       34, false },
  { MIRROR_ID,         "Lustro",         35, false },
  { FAN_ID,            "Wentylator",     36, false },
  { KITCHEN_1_ID,      "Kuchnia",        37, false },
  { KITCHEN_2_ID,      "Kuchnia ledy",   38, false },
  { KITCHEN_TABLE_ID,  "Kuchnia stolik", 39, false },
  { WORKSHOP_ID,       "Warsztat",       40, false },
  { CORRIDOR_ID,       "Korytarz",       41, false },
  { HEATING_1_ID,      "Strefa 1",       43, ActiveLow },
  { HEATING_2_ID,      "Strefa 2",       44, ActiveLow },
  { HEATING_3_ID,      "Strefa 3",       45, ActiveLow },
  { HEATING_4_ID,      "Strefa 4",       46, ActiveLow },
  { HEATING_5_ID,      "Strefa 5",       47, ActiveLow },
  { HEATING_6_ID,      "Strefa 6",       48, ActiveLow },
  { HEATING_7_ID,      "Strefa 7",       49, ActiveLow },
};
const int maxSensors = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage msgs[maxSensors];

uint8_t getId(uint8_t sensorId) {
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
