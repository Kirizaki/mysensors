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

  digitalWrite(Sensors[sensorId].pin, bState);
}

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  uint8_t ID = getId(sensorId);
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(Sensors[ID].id) : cmd;

  saveState(Sensors[ID].id, state);
  setGPIO(Sensors[ID].pin, state);
  send(msgs[ID].set(state));
}

void clickCallback(void* pSensorId) {
  const uint8_t sensorId = static_cast<uint8_t>(reinterpret_cast<intptr_t>(pSensorId));
  setOutput(sensorId);
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
  setOutput(BEDROOM_ID, Relay::OFF);
  setOutput(BED_1_ID, Relay::OFF);
  setOutput(BED_2_ID, Relay::OFF);
}
void bathroomClick() {
  setOutput(BATHROOM_1_ID);
  setOutput(BATHROOM_2_ID);
}
void bathroomOff() {
  setOutput(BATHROOM_1_ID, Relay::OFF);
  setOutput(BATHROOM_2_ID, Relay::OFF);
  setOutput(MIRROR_ID, Relay::OFF);
}
void kitchenClick() {
  setOutput(KITCHEN_1_ID);
  setOutput(KITCHEN_2_ID);
}
void kitchenOff() {
  setOutput(KITCHEN_1_ID, Relay::OFF);
  setOutput(KITCHEN_2_ID, Relay::OFF);
  setOutput(KITCHEN_TABLE_ID, Relay::OFF);
}


void setupButtons() {
  // Setup the button.
  saloon.attachClick(saloonClick);
  saloon.attachLongPressStop(saloonOff);
  uint8_t saloon2id = SALOON_2_ID;
  saloon.attachDoubleClick(clickCallback, &saloon2id);

  gamingRoom.attachClick(gamingRoomClick);
  gamingRoom.attachLongPressStop(gamingRoomOff);
  uint8_t gamingRoom1id = GAMING_ROOM_1_ID;
  gamingRoom.attachDoubleClick(clickCallback, &gamingRoom1id);

  uint8_t bedroomId = BEDROOM_ID;
  bedroom.attachClick(clickCallback, &bedroomId);
  bedroom.attachLongPressStop(bedroomOff);

  uint8_t bed1id = BED_1_ID;
  bed1.attachClick(clickCallback, &bed1id);
  bed1.attachLongPressStop(bedroomOff);
  uint8_t bed2id = BED_2_ID;
  bed1.attachDoubleClick(clickCallback, &bed2id);

  bed2.attachClick(clickCallback, &bed2id);
  bed2.attachLongPressStop(bedroomOff);
  bed2.attachDoubleClick(clickCallback, &bed1id);

  uint8_t guestsId = GUESTS_ID;
  guests.attachClick(clickCallback, &guestsId);

  bathroom.attachClick(bathroomClick);
  bathroom.attachLongPressStop(bathroomOff);

  uint8_t mirrorId = MIRROR_ID;
  mirror.attachClick(clickCallback, &mirrorId);

  kitchen.attachClick(kitchenClick);
  kitchen.attachLongPressStop(kitchenOff);
  uint8_t kitchen2id = KITCHEN_2_ID;
  kitchen.attachDoubleClick(clickCallback, &kitchen2id);

  uint8_t kitchenTableId = KITCHEN_TABLE_ID;
  kitchenTable.attachClick(clickCallback, &kitchenTableId);

  uint8_t workshopId = WORKSHOP_ID;
  workshop.attachClick(clickCallback, &workshopId);

  uint8_t corridorId = CORRIDOR_ID;
  corridor.attachClick(clickCallback, &corridorId);
}
