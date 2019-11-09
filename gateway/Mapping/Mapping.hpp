/**
 * @file Mapping.h
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2
 */

#pragma once

#include <OneButton.h>
#include "../CustomSensor/CustomSensor.hpp"

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}

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
const uint8_t PUMP_ID           = 19;
const uint8_t HEATING_1_ID      = 20;
const uint8_t HEATING_2_ID      = 21;
const uint8_t HEATING_3_ID      = 22;
const uint8_t HEATING_4_ID      = 23;
const uint8_t HEATING_5_ID      = 24;
const uint8_t HEATING_6_ID      = 25;
const uint8_t HEATING_7_ID      = 26;

// Vector contaning child ID, description, output pin
std::vector<CustomSensor> customSensors = std::vector<CustomSensor>() = {
  { CustomSensor(SALOON_1_ID,       "Salon S1",       24, 0) },
  { CustomSensor(SALOON_2_ID,       "Salon S2",       25, 0) },
  { CustomSensor(SALOON_3_ID,       "Salon Lampka",   26, 0) },
  { CustomSensor(GAMING_ROOM_1_ID,  "Gralnia S1",     27, 0) },
  { CustomSensor(GAMING_ROOM_2_ID,  "Gralnia S2",     28, 0) },
  { CustomSensor(BEDROOM_ID,        "Sypialnia",      29, 0) },
  { CustomSensor(BED_1_ID,          "Lozko 1",        30, 0) },
  { CustomSensor(BED_2_ID,          "Lozko 2",        31, 0) },
  { CustomSensor(GUESTS_ID,         "Goscinny",       32, 0) },
  { CustomSensor(BATHROOM_1_ID,     "Lazienka",       33, 0) },
  { CustomSensor(BATHROOM_2_ID,     "Prysznic",       34, 0) },
  { CustomSensor(MIRROR_ID,         "Lustro",         35, 0) },
  { CustomSensor(FAN_ID,            "Wentylator",     36, 0) },
  { CustomSensor(KITCHEN_1_ID,      "Kuchnia",        37, 0) },
  { CustomSensor(KITCHEN_2_ID,      "Kuchnia ledy",   38, 0) },
  { CustomSensor(KITCHEN_TABLE_ID,  "Kuchnia stolik", 39, 0) },
  { CustomSensor(WORKSHOP_ID,       "Warsztat",       40, 0) },
  { CustomSensor(CORRIDOR_ID,       "Korytarz",       41, 0) },
  { CustomSensor(PUMP_ID,           "Pompa",          42, 1) },
  { CustomSensor(HEATING_1_ID,      "Strefa 1",       43, 1) },
  { CustomSensor(HEATING_2_ID,      "Strefa 2",       44, 1) },
  { CustomSensor(HEATING_3_ID,      "Strefa 3",       45, 1) },
  { CustomSensor(HEATING_4_ID,      "Strefa 4",       46, 1) },
  { CustomSensor(HEATING_5_ID,      "Strefa 5",       47, 1) },
  { CustomSensor(HEATING_6_ID,      "Strefa 6",       48, 1) },
  { CustomSensor(HEATING_7_ID,      "Strefa 7",       49, 1) },
};

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
