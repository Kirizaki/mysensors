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

enum doorbellEnum {OFF, ON, WaitingForRellese};
doorbellEnum doorbellState = OFF;

// Remember to add library to Arduino path
#include <MySensors.h>
#include "./Mapping/Mapping.hpp"
#include "./Automation/Automation.hpp"

// TODO: as this should be fixed, refactor to keep index fixed
// sensor[0] -> msgs[0]
// sensor[1] -> msgs[1]
// etc.
void setup() {
  for(uint8_t idx = 0; idx < maxSensors; idx++) {
    auto sensor = Sensors[idx];
    pinMode(sensor.pin, OUTPUT);
    msgs[idx] = MyMessage(sensor.id, V_STATUS);
    uint8_t currentState = loadState(sensor.id);

    // Check whether EEPROM cell was used before
    if (!(currentState == 0 || 1)) {
      currentState = Relay::OFF;
      saveState(sensor.id, currentState);
    }

    // inverse state if sensors is Active Low
    bool bState = static_cast<bool>(currentState);
    bState = (ActiveLow == sensor.activelow) ? !bState : bState;
    digitalWrite(sensor.pin, bState);
  }
  setupButtons();
  msgs[maxSensors+1]=MyMessage(DOOR_ID, V_TRIPPED);

}

void presentation() {
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Gateway", "1.6");

  // Send actual states
  for (uint8_t idx = 0; idx < maxSensors; idx++) {
    auto sensor = Sensors[idx];
    present(sensor.id, S_BINARY, sensor.description);
    send(msgs[idx].set(loadState(sensor.id)));
  }
  present(DOOR_ID, S_DOOR, "kontaktron drzwi");
  send(msgs[maxSensors+1].set(true));
}

void loop() {
  // Keep sensing buttons
  shelf.tick();
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
  //workshop.tick();
  corridor.tick();
  doorbell.tick();
  door.tick();

  doorbellUpdate();
}

void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_STATUS) {

    // check whether given sensor exists in Sensors cointainer
    const uint8_t idx = getIdx(message.sensor);
    const bool value = message.getBool();

    // Store state in eeprom and send message
    setOutput(Sensors[idx].id, value);
  }
}
