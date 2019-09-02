/**
 * @file gateway.ino
 * @author Grzegorz Krajewski
 *
 * Implementation of the MySensors Gateway.
 *
 * @license GPL V2
 */

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

// Remember to add library to Arduino path
#include <ArduinoSTL.h>
#include <MySensors.h>
#include "./CustomSensor/CustomSensor.hpp"
#include "./Mapping/Mapping.hpp"
#include "./Automation/Automation.hpp"

void before() {
  for (const CustomSensor sensor : customSensors) {
    const uint8_t pin = sensor.pin;
    pinMode(pin, OUTPUT);

    uint8_t currentState = loadState(sensor.id);
    // Check whether EEPROM cell was used before
    if (currentState == 0xFF) {
      currentState = Relay::OFF;
      saveState(sensor.id, currentState);
    }
    digitalWrite(pin, currentState);
  }
}

void setup() {
  setupButtons();
}

void presentation()
{
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Gateway", "1.0");

  // Send actual states
  for (CustomSensor sensor : customSensors) {
    const uint8_t id = sensor.id;
    present(id, S_BINARY, sensor.description);
    send(sensor.message.set(loadState(id)));
  }
}

void loop() {
  // Keep sensing buttons
  saloon.tick();
  gamingRoom.tick();
  bedroom.tick();
  bed1.tick();
  bed2.tick();
  guests.tick();
  bathroom.tick();
  mirror.tick();
  kitchen.tick();
  kitchenTable.tick();
  workshop.tick();
  corridor.tick();
}

void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_STATUS) {
    CustomSensor sensor = CustomSensor::getSensorById(message.sensor, customSensors);
    const bool value = message.getBool();
    // Store state in eeprom
    saveState(sensor.id, value);
    // Change relay state
    digitalWrite(sensor.pin, value);
    // Send ACK
    send(sensor.message.set(value));
  }
}
