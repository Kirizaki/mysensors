/**
 * @file CustomSensor.h
 * @author Grzegorz Krajewski
 *
 * Representation of Custom Sensor class.
 *
 * @license GPL V2 ?!
 */


#pragma once

#include <ArduinoSTL.h>
#include <MySensors.h>


class CustomSensor {
public:
  CustomSensor(const uint8_t& _id, const String& _desc, const uint8_t& _pin, const uint8_t& _zone) {
    id = _id;
    description = _desc;
    pin = _pin;
    zone = _zone;
    message = MyMessage(id, V_LIGHT);
  }

  static CustomSensor getSensorById(const uint8_t& sensorId, const std::vector<CustomSensor>& sensors) {
    for (const CustomSensor sensor : sensors) {
      if (sensor.id == sensorId) return sensor;
    }

    return CustomSensor(0, "UNKNOWN", 0, 0);
  }

  void sendMsg() {
    send(message.set(loadState(id)));
  }

  uint8_t id;
  String description;
  uint8_t pin;
  uint8_t zone;
  MyMessage message;
};