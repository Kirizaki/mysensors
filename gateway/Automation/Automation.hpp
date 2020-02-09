/**
 * @file Automation.hpp
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2
 */

#pragma once

#include "../Mapping/Mapping.hpp"

void setGPIO(const uint8_t& sensorId, const uint8_t& cmd) {
  bool bState = static_cast<bool>(cmd);
  bState = (ActiveLow == Sensors[sensorId].activelow) ? !bState : bState;

  //simpler way of fliping 1 to 0 and 0 to 1
  //const uint8_t State = (ActiveLow == Sensors[sensorId].activelow) ? 1 - cmd : cmd;
  digitalWrite(Sensors[sensorId].pin, bState);
}

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  uint8_t Id = getId(sensorId);
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(Sensors[Id].id) : cmd;

  saveState(Sensors[Id].id, state);
  setGPIO(Id, state);
  send(msgs[Id].set(state));
}

void saloonClick() {
  setOutput(SALOON_1_ID);
  setOutput(SALOON_2_ID);
}
void saloonOff() {
  setOutput(SALOON_1_ID, Relay::OFF);
  setOutput(SALOON_2_ID, Relay::OFF);
}
void gamingRoomClick() {
  setOutput(GAMING_ROOM_1_ID);
  setOutput(GAMING_ROOM_2_ID);
}
void gamingRoomOff() {
  setOutput(GAMING_ROOM_1_ID, Relay::OFF);
  setOutput(GAMING_ROOM_2_ID, Relay::OFF);
}
void bedroomOff() {
  setOutput(BEDROOM_1_ID, Relay::OFF);
  setOutput(BEDROOM_2_ID, Relay::OFF);
  setOutput(BED_1_ID, Relay::OFF);
  setOutput(BED_2_ID, Relay::OFF);
}
void bedroomClick() {
  setOutput(BEDROOM_1_ID);
  setOutput(BEDROOM_2_ID);
}
void bathroomClick() {
  setOutput(BATHROOM_ID);
  setOutput(BATHROOM_LED_ID);
}
void bathroomOff() {
  setOutput(BATHROOM_ID, Relay::OFF);
  setOutput(BATHROOM_LED_ID, Relay::OFF);
  setOutput(MIRROR_ID, Relay::OFF);
}
void kitchenClick() {
  setOutput(KITCHEN_ID);
  setOutput(KITCHEN_LED_ID);
}
void kitchenOff() {
  setOutput(KITCHEN_ID, Relay::OFF);
  setOutput(KITCHEN_LED_ID, Relay::OFF);
  setOutput(KITCHEN_TABLE_ID, Relay::OFF);
}

void setupButtons() {
  // Setup the button.
  saloon.attachClick(saloonClick);
  saloon.attachLongPressStop(saloonOff);
  saloon.attachDoubleClick(setOutput, SALOON_2_ID);

  gamingRoom.attachClick(gamingRoomClick);
  gamingRoom.attachLongPressStop(gamingRoomOff);
  gamingRoom.attachDoubleClick(setOutput, GAMING_ROOM_1_ID);

  bedroom.attachClick(bedroomClick);
  bedroom.attachLongPressStop(bedroomOff);
  bedroom.attachDoubleClick(setOutput, BEDROOM_2_ID);

  bed1.attachClick(setOutput, BED_1_ID);
  bed1.attachLongPressStop(bedroomOff);
  bed1.attachDoubleClick(setOutput, BED_2_ID);

  bed2.attachClick(setOutput, BED_2_ID);
  bed2.attachLongPressStop(bedroomOff);
  bed2.attachDoubleClick(setOutput, BED_1_ID);

  guests.attachClick(setOutput, GUESTS_ID);

  bathroom.attachClick(bathroomClick);
  bathroom.attachLongPressStop(bathroomOff);

  mirror.attachClick(setOutput, MIRROR_ID);

  kitchen.attachClick(kitchenClick);
  kitchen.attachLongPressStop(kitchenOff);
  kitchen.attachDoubleClick(setOutput, KITCHEN_LED_ID);

  kitchenTable.attachClick(setOutput, KITCHEN_TABLE_ID);

  workshop.attachClick(setOutput, WORKSHOP_ID);

  corridor.attachClick(setOutput, CORRIDOR_ID);
}
