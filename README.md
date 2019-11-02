# MySensors

Serial Gateway based on [MySensors](https://www.mysensors.org/) protocol communicating with [HomeAssistant](https://www.home-assistant.io/).
Only Relays are visible as child id.
All buttons are handled internally and gateway is sending relay status after action.

Buttons are set to:
  - Short click - flip status of relays in zone
  - Relese of long click - switch off all relays in zone
  - Double click - flip on relay in zone

At this point sketch is done for only ON/OFF status of relays.

## Dependencies

1. MySensors
2. OneButton
3. ArduinoSTL

**Note**: All above must be installed via Arduino IDE

## Build

1. Download Arduino IDE
2. Download dependencies via Arduino IDE
3. Download [this](https://github.com/th0m4sek/mysensors/archive/master.zip) repository
4. Open sketch source file (`gateway/gateway.ino`) in Arduino IDE
5. Click a Upload button to build and upload sketch

## Modifications

See [doc/Modification.md](doc/Modification.md) for detalis helping addopting this project for your needs.

## Additional Info

### Serial API
https://www.mysensors.org/download/serial_api_20

### Sketches
https://www.mysensors.org/about/arduino#basic-structure-of-sketches

## To do
  - lights dimming
  - add ds18b20 sensors reading
  - sense if HASS (HomeAssistant) is working to bypass heating control locally
  - small LCD for local control of heating
  - fix https://github.com/th0m4sek/mysensors/issues/8

## License

[GNU General Public License, version 2](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)
