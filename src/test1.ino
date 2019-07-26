

// Enable debug prints to serial monitor
#define MY_DEBUG 

// Enable serial gateway
#define MY_GATEWAY_SERIAL

// Define a lower baud rate for Arduino's running on 8 MHz (Arduino Pro Mini 3.3V & SenseBender)
#if F_CPU == 16000000L
#define MY_BAUD_RATE 115200
#endif

// Flash leds on rx/tx/err
// #define MY_LEDS_BLINKING_FEATURE
// Set blinking period
// #define MY_DEFAULT_LED_BLINK_PERIOD 300

// Inverses the behavior of leds
// #define MY_WITH_LEDS_BLINKING_INVERSE

// Enable inclusion mode
#define MY_INCLUSION_MODE_FEATURE
// Enable Inclusion mode button on gateway
#define MY_INCLUSION_BUTTON_FEATURE

// Inverses behavior of inclusion button (if using external pullup)
//#define MY_INCLUSION_BUTTON_EXTERNAL_PULLUP

// Set inclusion mode duration (in seconds)
#define MY_INCLUSION_MODE_DURATION 60 
// Digital pin used for inclusion mode button
#define MY_INCLUSION_MODE_BUTTON_PIN  3 

// Uncomment to override default HW configurations
//#define MY_DEFAULT_ERR_LED_PIN 4  // Error led pin
//#define MY_DEFAULT_RX_LED_PIN  6  // Receive led pin
//#define MY_DEFAULT_TX_LED_PIN  5  // the PCB, on board LED

#include <MySensors.h>  
#include <Bounce2.h>

// Enable repeater functionality for this node
#define MY_REPEATER_FEATURE


#define RELAY_1  4  // Arduino Digital I/O pin number for first relay (second on pin+1 etc)
#define NUMBER_OF_RELAYS 1 // Total number of attached relays
#define RELAY_ON 1  // GPIO value to write to turn on attached relay
#define RELAY_OFF 0 // GPIO value to write to turn off attached relay

#define BUTTON_PIN A1


void before() { 
  for (int sensor=1, pin=RELAY_1; sensor<=NUMBER_OF_RELAYS;sensor++, pin++) {
    // Then set relay pins in output mode
    pinMode(pin, OUTPUT);   
    // Set relay to last known state (using eeprom storage) 
    digitalWrite(pin, loadState(sensor)?RELAY_ON:RELAY_OFF);
  }
}
Bounce debouncer = Bounce();

void setup() { 
  // Setup locally attached sensors
  delay(10000);
   // Setup the button.
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // After setting up the button, setup debouncer.
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);
  //presentation();
}
void presentation()  
{   
  // Send the sketch version information to the gateway and Controller
  sendSketchInfo("Relay", "1.0");

  for (int sensor=1, pin=RELAY_1; sensor<=NUMBER_OF_RELAYS;sensor++, pin++) {
    // Register all sensors to gw (they will be created as child devices)
    present(sensor, S_LIGHT);
  }
}

MyMessage msg(1, V_LIGHT);

void loop() { 
  // Send locally attached sensor data here 
  if (debouncer.update()) {
    // Get the update value.
    int value = debouncer.read();
    // Send in the new value.
    if(value == LOW){
         saveState(1, !loadState(1));
         digitalWrite(RELAY_1, loadState(1)?RELAY_ON:RELAY_OFF);
         send(msg.set(loadState(1)));
    }
  }
}


void receive(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.type==V_LIGHT) {
     // Change relay state
     digitalWrite(message.sensor-1+RELAY_1, message.getBool()?RELAY_ON:RELAY_OFF);
     // Store state in eeprom
     saveState(message.sensor, message.getBool());
     // Write some debug info
     Serial.print("Incoming change for sensor:");
     Serial.print(message.sensor);
     Serial.print(", New status: ");
     Serial.println(message.getBool());
   } 
}
