/**
 * @file Automation.h
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2 ?!
 */

#include "../CustomSensor/CustomSensor.h"
#include "../Mapping/Mapping.h"

void click(const uint8_t& sensorId, uint8_t cmd = Relay::CMD_FLIP) {
  CustomSensor sensor = CustomSensor::getSensorById(sensorId, customSensors);
  bool currentState = loadState(sensor.id);
  if (cmd == Relay::CMD_FLIP) {
    currentState = !currentState;
  } else {
    currentState = cmd;
  }

  saveState(sensor.id, currentState);
  digitalWrite(sensor.pin, currentState);

  sensor.sendMsg();
}

void saloonClick() {
  click(SALOON_1_ID);
  click(SALOON_2_ID);
}
void saloonDoubleClick() {
  // placeholder
}
void saloonLongClick() {
  click(SALOON_1_ID, Relay::CMD_OFF);
  click(SALOON_2_ID, Relay::CMD_OFF);
}
void gamingRoomClick() {
  click(GAMING_ROOM_1_ID);
  click(GAMING_ROOM_2_ID);
}
void gamingRoomLongClick() {
  click(GAMING_ROOM_1_ID, Relay::CMD_OFF);
  click(GAMING_ROOM_2_ID, Relay::CMD_OFF);
}
void gamingRoomDoubleClick() {
    click(GAMING_ROOM_1_ID);
}
void bedroomClick() {
  click(BEDROOM_ID);
}
void bedroomLongClick() {
  click(BEDROOM_ID, Relay::CMD_OFF);
  click(BED_1_ID, Relay::CMD_OFF);
  click(BED_2_ID, Relay::CMD_OFF);
}
void bed1Click() {
  click(BED_1_ID);
}
void bed2Click() {
  click(BED_2_ID);
}
void guestsClick() {
  click(GUESTS_ID);
}
void bathroomClick() {
  click(BATHROOM_1_ID);
  click(BATHROOM_2_ID);
}
void bathroomLongClick() {
  click(BATHROOM_1_ID, Relay::CMD_OFF);
  click(BATHROOM_2_ID, Relay::CMD_OFF);
  click(MIRROR_ID, Relay::CMD_OFF);
}
void mirrorClick() {
  click(MIRROR_ID);
}
void kitchenClick() {
  click(KITCHEN_1_ID);
  click(KITCHEN_2_ID);
}
void kitchenLongClick() {
  click(KITCHEN_1_ID, Relay::CMD_OFF);
  click(KITCHEN_2_ID, Relay::CMD_OFF);
  click(KITCHEN_TABLE_ID, Relay::CMD_OFF);
}
void kitchenDoubleClick() {
  click(KITCHEN_2_ID);
}
void kitchenTableClick() {
  click(KITCHEN_TABLE_ID);
}
void workshopClick() {
  click(WORKSHOP_ID);
}
void corridorClick() {
  click(CORRIDOR_ID);
}