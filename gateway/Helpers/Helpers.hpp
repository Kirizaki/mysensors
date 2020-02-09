/**
 * @file Helpers.hpp
 * @author Grzegorz Krajewski
 *
 * Helpers.
 *
 * @license GPL V2
 */

#pragma once

const uint8_t MAX_SENSORS = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage Messages[MAX_SENSORS];

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}

const bool ActiveLow = true;

uint8_t getSensorIdx(uint8_t sensorId) {
  for (uint8_t i = 0; i < MAX_SENSORS; i++) {
    if (Sensors[i].id == sensorId) return(i);
  }

  return(-1);
}