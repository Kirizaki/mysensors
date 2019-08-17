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
  CustomSensor(const uint8_t& _id, const String& _desc, const uint8_t& _pin, const uint8_t& _zone = 0) {
    id = _id;
    description = _desc;
    pin = _pin;
    zone = _zone;
    message = MyMessage(id, V_LIGHT);
  };

  static CustomSensor getSensorById(const uint8_t& sensorId, const vector<CustomSensor>& sensors) {
    for (const CustomSensor sensor : sensors) {
      if (sensor.id == sensorId) return sensor;
    }

    return CustomSensor(0, "UNKNOWN", 0);
  }

  uint8_t id;
  String description;
  uint8_t pin;
  uint8_t zone;
  MyMessage message;
};

vector<CustomSensor> customSensors = vector<CustomSensor>() = {
  { CustomSensor(1, "Salon S1", 26) },
  { CustomSensor(2, "Salon S2", 27) },
  { CustomSensor(3, "Salon S3", 28) },
  { CustomSensor(4, "Salon S4", 29) },
  { CustomSensor(5, "Salon S5", 30) },
  { CustomSensor(6, "Salon S6", 31) },
  { CustomSensor(7, "Salon S7", 32) }
};

void before() {
  for (const CustomSensor sensor : customSensors) {
    const uint8_t pin = sensor.pin;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, loadState(sensor.id) ? 1 : 0);
  }
}

void setup() { 
   // Setup the button.
  button1.attachClick(click1);
  button7.attachClick(click7);
}

MyMessage msg(1, V_LIGHT);

void presentation()  
{   
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Relay", "1.1");
  
  // Send actual states
  for (const CustomSensor sensor : customSensors) {
    const uint8_t id = sensor.id;
    present(id, S_LIGHT, sensor.description.begin());
    send(sensor.message.set(loadState(id)));
  }
}

void loop() { 
  // keep sensing buttons
  button1.tick();
  button7.tick();
}

void click1() {
  const CustomSensor sensor = CustomSensor::getSensorById(1, customSensors);
  saveState(sensor.id, !loadState(sensor.id));
  digitalWrite(sensor.pin, loadState(sensor.id) ? 1 : 0);
  send(sensor.message.set(loadState(sensor.id)));
} // click1

void click7() {
  const CustomSensor sensor = CustomSensor::getSensorById(7, customSensors);
  saveState(sensor.id, !loadState(sensor.id));
  digitalWrite(sensor.pin, loadState(sensor.id) ? 1 : 0);
  send(sensor.message.set(loadState(sensor.id)));
} // click7
 
void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_LIGHT) {
    const CustomSensor sensor = CustomSensor::getSensorById(message.sensor, customSensors);
     // Change relay state
     digitalWrite(sensor.pin, message.getBool() ? 1 : 0);
     // Store state in eeprom
     saveState(sensor.id, message.getBool());
    // wyslac potwierdzenie zmiany!
    send(sensor.message.set(loadState(sensor.id)));
   } 
}