/**
 * @file gateway.ino
 * @author Grzegorz Krajewski
 *
 * Implementation of the MySensors Gateway.
 *
 * @license GPL V2 ?!
 */

// Enable debug prints to serial monitor
#define MY_DEBUG

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

// Remember to add library over IDE
#include <ArduinoSTL.h>
#include <MySensors.h>
#include "OneButton.h"

OneButton button1(A1, true);
OneButton button7(A7, true);

using namespace std;

class CustomSensor {
public:
  CustomSensor(const uint8_t& _id, const String& _desc, const uint8_t& _pin, const uint8_t& _zone) {
    id = _id;
    description = _desc;
    pin = _pin;
    zone = _zone;
    message = MyMessage(id, V_LIGHT);
  }

  static CustomSensor getSensorById(const uint8_t& sensorId, const vector<CustomSensor>& sensors) {
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

vector<CustomSensor> customSensors = vector<CustomSensor>() = {
  { CustomSensor(1, "Salon S1", 26, 1) },
  { CustomSensor(2, "Salon S2", 27, 1) },
  { CustomSensor(3, "Salon S3", 28, 1) },
  { CustomSensor(4, "Salon S4", 29, 2) },
  { CustomSensor(5, "Salon S5", 30, 2) },
  { CustomSensor(6, "Salon S6", 31, 3) },
  { CustomSensor(7, "Salon S7", 32, 3) }
};

void before() {
  for (const CustomSensor sensor : customSensors) {
    const uint8_t pin = sensor.pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, loadState(sensor.id));
  }
}

void setup() {
  // Setup the button.
  button1.attachClick(click1);
  button7.attachClick(click7);
}

void presentation()
{
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Relay", "1.1");

  // Send actual states
  for (CustomSensor sensor : customSensors) {
    present(sensor.id, S_LIGHT, sensor.description.begin());
    sensor.sendMsg();
  }
}

void loop() {
  // Keep sensing buttons
  button1.tick();
  button7.tick();
}

void click1() {
  CustomSensor sensor = CustomSensor::getSensorById(1, customSensors);
  saveState(sensor.id, !loadState(sensor.id));
  digitalWrite(sensor.pin, loadState(sensor.id));
  sensor.sendMsg();
}

void click7() {
  CustomSensor sensor = CustomSensor::getSensorById(7, customSensors);
  saveState(sensor.id, !loadState(sensor.id));
  digitalWrite(sensor.pin, loadState(sensor.id));
  sensor.sendMsg();
}

void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_LIGHT) {
    CustomSensor sensor = CustomSensor::getSensorById(message.sensor, customSensors);
    // Store state in eeprom
    saveState(sensor.id, message.getBool());
    // Change relay state
    digitalWrite(sensor.pin, message.getBool());
    // Send ACK
    sensor.sendMsg();
  }
}