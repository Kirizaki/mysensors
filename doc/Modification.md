## gateway/Mapping/Mapping.hpp

`// Child ID declaration of relays`
change to names convenient for you
Child ID should be set form 1 to maximum 254 without numbers skips.

`// Vector containing child ID, description, output pin`
Next change vector use child ID's just declared and set description and output pin.


End of file contains Push buttons declaration, defined as:
OneButton **NAME**(**PIN**, true)
where **NAME** is name of pushbutton used then in automation definitions and **PIN** is physical connection to Arduino.

## gateway/Automation/Automation.hpp
Start at end of file form **void setupPushbutton** function which declares what actions will be activated on push buttons declared on mapping.hpp, there are 5 possible actions
1. attachClick
2. attachDoubleClick
3. attachLongPressStart
4. attachLongPressStop
5. attachDuringLongPress

then setOutput is used to change state in each scenario.
SetOutput gets CHILD ID and by default is flipping state of this relay
you can also set second parameter to Relay::ON or Relay::OFF to set that state to ON or OFF.

## gateway/CustomSensor/CustomSensor.hpp

No modifications needed.