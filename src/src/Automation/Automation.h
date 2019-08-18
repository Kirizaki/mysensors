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

void click(const uint8_t& sensorId) {
  CustomSensor sensor = CustomSensor::getSensorById(sensorId, customSensors);
  const uint8_t state = !loadState(sensor.id);
  saveState(sensor.id, state);
  digitalWrite(sensor.pin, state);
  sensor.sendMsg();
}

void click(const uint8_t& sensorId, const bool& state) {
  CustomSensor sensor = CustomSensor::getSensorById(sensorId, customSensors);
  saveState(sensor.id, state);
  digitalWrite(sensor.pin, state);
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
  click(SALOON_1_ID, false);
  click(SALOON_2_ID, false);
}
void gamingRoomClick() {
  click(GAMING_ROOM_1_ID);
  click(GAMING_ROOM_2_ID);
}
void gamingRoomLongClick() {
  click(GAMING_ROOM_1_ID, false);
  click(GAMING_ROOM_2_ID, false);
}
void gamingRoomDoubleClick() {
    click(GAMING_ROOM_1_ID);
}
void bedroomClick() {
  click(BEDROOM_ID);
}
void bedroomLongClick() {
  click(BEDROOM_ID, false);
  click(BED_1_ID, false);
  click(BED_2_ID, false);
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
  click(BATHROOM_1_ID, false);
  click(BATHROOM_2_ID, false);
  click(MIRROR_ID, false);
}
void mirrorClick() {
  click(MIRROR_ID);
}
void kitchenClick() {
  click(KITCHEN_1_ID);
  click(KITCHEN_2_ID);
}
void kitchenLongClick() {
  click(KITCHEN_1_ID, false);
  click(KITCHEN_2_ID, false);
  click(KITCHEN_TABLE_ID, false);
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