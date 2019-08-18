/**
 * @file Mapping.h
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2 ?!
 */

#pragma once

#include <OneButton.h>
#include "../CustomSensor/CustomSensor.h"

const uint8_t RESERVED_ID       = 0;
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

std::vector<CustomSensor> customSensors = std::vector<CustomSensor>() = {
  { CustomSensor(SALOON_1_ID, "Salon S1", 26, 1) },
  { CustomSensor(SALOON_2_ID, "Salon S2", 27, 1) },
  { CustomSensor(SALOON_3_ID, "Salon S2", 27, 1) },
  { CustomSensor(GAMING_ROOM_1_ID, "Salon S3", 28, 1) },
  { CustomSensor(GAMING_ROOM_2_ID, "Salon S3", 28, 1) },
  { CustomSensor(BEDROOM_ID, "Salon S4", 29, 2) },
  { CustomSensor(BED_1_ID, "Salon S5", 30, 2) },
  { CustomSensor(BED_2_ID, "Salon S6", 31, 3) },
  { CustomSensor(GUESTS_ID, "Salon S7", 32, 3) },
  { CustomSensor(BATHROOM_1_ID, "Salon S7", 32, 3) },
  { CustomSensor(BATHROOM_1_ID, "Salon S7", 32, 3) },
  { CustomSensor(MIRROR_ID, "Salon S7", 32, 3) },
  { CustomSensor(FAN_ID, "Salon S7", 32, 3) },
  { CustomSensor(KITCHEN_1_ID, "Salon S7", 32, 3) },
  { CustomSensor(KITCHEN_2_ID, "Salon S7", 32, 3) },
  { CustomSensor(KITCHEN_TABLE_ID, "Salon S7", 32, 3) },
  { CustomSensor(WORKSHOP_ID, "Salon S7", 32, 3) },
  { CustomSensor(CORRIDOR_ID, "Salon S7", 32, 3) },
  { CustomSensor(PUMP_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_1_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_2_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_3_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_4_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_5_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_6_ID, "Salon S7", 32, 3) },
  { CustomSensor(HEATING_7_ID, "Salon S7", 32, 3) },
};

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