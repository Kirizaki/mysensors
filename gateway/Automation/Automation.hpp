/**
 * @file Automation.h
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2
 */

#pragma once

#include "../CustomSensor/CustomSensor.hpp"
#include "../Mapping/Mapping.hpp"

void setGPIO(const uint8_t& sensorId, const uint8_t& cmd) {
  CustomSensor sensor = CustomSensor::getSensorById(sensorId, customSensors);
  const uint8_t state = (sensor.activelow == 1) ? !cmd : cmd;

  digitalWrite(sensor.pin, state);
}

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  CustomSensor sensor = CustomSensor::getSensorById(sensorId, customSensors);
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(sensor.id) : cmd;

  saveState(sensor.id, state);
  setGPIO(sensor.pin, state);
  send(sensor.message.set(state));
}

void saloonClick() {
  setOutput(SALOON_1_ID);
  setOutput(SALOON_2_ID);
}
void saloonDoubleClick() {
  // placeholder
}
void saloonLongClick() {
  setOutput(SALOON_1_ID, Relay::OFF);
  setOutput(SALOON_2_ID, Relay::OFF);
}
void gamingRoomClick() {
  setOutput(GAMING_ROOM_1_ID);
  setOutput(GAMING_ROOM_2_ID);
}
void gamingRoomLongClick() {
  setOutput(GAMING_ROOM_1_ID, Relay::OFF);
  setOutput(GAMING_ROOM_2_ID, Relay::OFF);
}
void gamingRoomDoubleClick() {
    setOutput(GAMING_ROOM_1_ID);
}
void bedroomClick() {
  setOutput(BEDROOM_ID);
}
void bedroomLongClick() {
  setOutput(BEDROOM_ID, Relay::OFF);
  setOutput(BED_1_ID, Relay::OFF);
  setOutput(BED_2_ID, Relay::OFF);
}
void bed1Click() {
  setOutput(BED_1_ID);
}
void bed2Click() {
  setOutput(BED_2_ID);
}
void guestsClick() {
  setOutput(GUESTS_ID);
}
void bathroomClick() {
  setOutput(BATHROOM_1_ID);
  setOutput(BATHROOM_2_ID);
}
void bathroomLongClick() {
  setOutput(BATHROOM_1_ID, Relay::OFF);
  setOutput(BATHROOM_2_ID, Relay::OFF);
  setOutput(MIRROR_ID, Relay::OFF);
}
void mirrorClick() {
  setOutput(MIRROR_ID);
}
void kitchenClick() {
  setOutput(KITCHEN_1_ID);
  setOutput(KITCHEN_2_ID);
}
void kitchenLongClick() {
  setOutput(KITCHEN_1_ID, Relay::OFF);
  setOutput(KITCHEN_2_ID, Relay::OFF);
  setOutput(KITCHEN_TABLE_ID, Relay::OFF);
}
void kitchenDoubleClick() {
  setOutput(KITCHEN_2_ID);
}
void kitchenTableClick() {
  setOutput(KITCHEN_TABLE_ID);
}
void workshopClick() {
  setOutput(WORKSHOP_ID);
}
void corridorClick() {
  setOutput(CORRIDOR_ID);
}

void setupButtons() {
  // Setup the button.
  saloon.attachClick(saloonClick);
  saloon.attachLongPressStop(saloonLongClick);
  saloon.attachDoubleClick(saloonDoubleClick);

  gamingRoom.attachClick(gamingRoomClick);
  gamingRoom.attachLongPressStop(gamingRoomLongClick);
  gamingRoom.attachDoubleClick(gamingRoomDoubleClick);

  bedroom.attachClick(bedroomClick);
  bedroom.attachLongPressStop(bedroomLongClick);
  // bedroom.attachDoubleClick(bedroomDoubleClick); ??

  bed1.attachClick(bed1Click);
  bed1.attachLongPressStop(bedroomLongClick);
  bed1.attachDoubleClick(bed2Click);

  bed2.attachClick(bed2Click);
  bed2.attachLongPressStop(bedroomLongClick);
  bed2.attachDoubleClick(bed1Click);

  guests.attachClick(guestsClick);

  bathroom.attachClick(bathroomClick);
  bathroom.attachLongPressStop(bathroomLongClick);
  // bathroom.attachDoubleClick(bathroomDoubleClick); ??

  mirror.attachClick(mirrorClick);

  kitchen.attachClick(kitchenClick);
  kitchen.attachLongPressStop(kitchenLongClick);
  kitchen.attachDoubleClick(kitchenDoubleClick);

  kitchenTable.attachClick(kitchenTableClick);

  workshop.attachClick(workshopClick);

  corridor.attachClick(corridorClick);
  // corridor.attachDuringLongPress(corridorDuringLongClick); ??
}
