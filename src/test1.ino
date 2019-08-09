// Enable debug prints to serial monitor
#define MY_DEBUG 

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

#include <MySensors.h>  
#include "OneButton.h"

#define RELAY_1  26  // Arduino Digital I/O pin number for first relay (second on pin+1 etc)
#define NUMBER_OF_RELAYS 13 // Total number of attached relays

OneButton button1(A1, true);

void before() { 
  for (int sensor=1, pin=RELAY_1; sensor<=NUMBER_OF_RELAYS;sensor++, pin++) {
    // Then set relay pins in output mode
    pinMode(pin, OUTPUT);   
    // Set relay to last known state (using eeprom storage) 
    digitalWrite(pin, loadState(sensor)?1:0);
  }
}

void setup() { 
   // Setup the button.
  button1.attachClick(click1);
  //presentation();
}
void presentation()  
{   
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Relay", "1.1");
  present(1, S_LIGHT, "salon S1");
    MyMessage msg(1, V_LIGHT);
    send(msg.set(loadState(1)));
  present(2, S_LIGHT, "salon S2");
    msg.setSensor(2);
    send(msg.set(loadState(2)));
  present(3, S_LIGHT, "gralnia S1");
    msg.setSensor(3);
    send(msg.set(loadState(3)));
  present(4, S_LIGHT, "gralnia S2");
  present(5, S_LIGHT, "sypialnia S1");
  present(6, S_LIGHT, "sypialnia S2");
  present(7, S_LIGHT, "sypialnia S3");
}

MyMessage msg(1, V_LIGHT);

void loop() { 
  // keep sensing buttons
  button1.tick();
}
void click1() {
  saveState(1, !loadState(1));
  digitalWrite(RELAY_1, loadState(1)?1:0);
         MyMessage msg(1, V_LIGHT);
         send(msg.set(loadState(1)));
} // click1
 
void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_LIGHT) {
     // Change relay state
     digitalWrite(message.sensor-1+RELAY_1, message.getBool()?1:0);
     // Store state in eeprom
     saveState(message.sensor, message.getBool());
    // wyslac potwierdzenie zmiany!
    msg.setSensor(message.sensor);
    send(msg.set(loadState(message.sensor)));
   } 
}