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

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  // test whether sensor with given ID exists and get it's index in container
  // TODO: Add debug message when idx is wrong & in any other places where: Sensors[idx]
  uint8_t idx = getIdx(sensorId);
  auto sensor = Sensors[idx];

  // check whether flip state of sensor
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(sensor.id) : cmd;
  saveState(sensor.id, state);

  // inverse state if sensors is Active Low
  bool bState = static_cast<bool>(state);
  bState = (ActiveLow == sensor.activelow) ? !bState : bState;

  digitalWrite(sensor.pin, bState);
  send(msgs[idx].set(state));
}

void clickCallback(void* pSensorId) {
  // TODO: Test whether this can be null or nullptr or unexpected value
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
  setOutput(SALOON_SHELF_ID, Relay::OFF);
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
  setOutput(KITCHEN_LED1_ID);
  setOutput(KITCHEN_LED2_ID);
}
void kitchenOff() {
  setOutput(KITCHEN_ID, Relay::OFF);
  setOutput(KITCHEN_LED1_ID, Relay::OFF);
  setOutput(KITCHEN_LED2_ID, Relay::OFF);
  setOutput(KITCHEN_TABLE_ID, Relay::OFF);
}

void doorbellClick() {
  doorbellState = ON;
}

void doorbellUpdate(){
  switch (doorbellState) {
    case ON:
      setOutput(DOORBELL_ID, Relay::ON);
      doorbellState = WaitingForRellese;
      break;
    case WaitingForRellese:
      if ( !(doorbell.isLongPressed()) ) {
        setOutput(DOORBELL_ID, Relay::OFF);
        doorbellState = OFF;
      }
      break;
  }
}

void doorOpen(){
  send(msgs[maxSensors+1].set(false));
}

void doorClose() {
  send(msgs[maxSensors+1].set(true));
}

void setupButtons() {
  // Setup the button.
  shelf.attachClick(clickCallback,SALOON_SHELF_ID);
  shelf.attachLongPressStop(saloonOff);
  shelf.attachDoubleClick(clickCallback, SALOON_2_ID);

  saloon.attachClick(saloonClick);
  saloon.attachLongPressStop(saloonOff);
  saloon.attachDoubleClick(clickCallback, SALOON_2_ID);

  gamingRoom.attachClick(gamingRoomClick);
  gamingRoom.attachLongPressStop(gamingRoomOff);
  gamingRoom.attachDoubleClick(clickCallback, GAMING_ROOM_1_ID);

  bedroom.attachClick(bedroomClick);
  bedroom.attachLongPressStop(bedroomOff);
  bedroom.attachDoubleClick(clickCallback, BEDROOM_2_ID);

  bed1.attachClick(clickCallback, BED_1_ID);
  bed1.attachLongPressStop(bedroomOff);
  bed1.attachDoubleClick(clickCallback, BED_2_ID);

  bed2.attachClick(clickCallback, BED_2_ID);
  bed2.attachLongPressStop(bedroomOff);
  bed2.attachDoubleClick(clickCallback, BED_1_ID);

  guests.attachClick(clickCallback, GUESTS_ID);

  bathroom.attachClick(bathroomClick);
  bathroom.attachLongPressStop(bathroomOff);

  mirror.attachClick(clickCallback, MIRROR_ID);
  mirror.attachDoubleClick(clickCallback, FAN_ID);

  kitchen.attachClick(kitchenClick);
  kitchen.attachLongPressStop(kitchenOff);
  kitchen.attachDoubleClick(clickCallback, KITCHEN_LED1_ID);

  kitchenTable.attachClick(clickCallback, KITCHEN_TABLE_ID);

  //workshop.attachClick(clickCallback, WORKSHOP_ID);

  corridor.attachClick(clickCallback, CORRIDOR_ID);
  corridor.attachDoubleClick(clickCallback, WORKSHOP_ID);

  doorbell.attachPressStart(doorbellClick);
  door.attachLongPressStart(doorOpen);
  door.attachLongPressStop(doorClose);
}
