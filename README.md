
# Surilli_MQTT_Library 

Arduino library for MQTT support, including access to Surilli.IO. Works with
the Surilli GSM, Arduino Yun, ESP8266 Arduino platforms, and anything that supports
Arduino's Client interface (like Ethernet shield).

See included examples for how to use the library to access an MQTT service to
publish and subscribe.

<!-- START COMPATIBILITY TABLE -->

## Compatibility

MCU                | Tested Works | Doesn't Work|
------------------ | :----------: | :----------:|
Atmega328 @ 16MHz  |- [x] Works   |- [x] Finish |     
Atmega32u4 @ 16MHz |- [x] Works  |             |    
Atmega32u4 @ 8MHz  |- [x] Works  |             |    
ESP8266            |- [x] Works  |             |   
Atmega2560 @ 16MHz |- [x] Works  |             |           
ATSAM21D           |- [x] Works  |             |                                
- [x] Works 
- [x] ATmega328 @ 16MHz : Arduino UNO
- [x] ATmega32u4 @ 16MHz : Arduino Leonardo,
- [x] ATmega32u4 @ 8MHz : Surilli GSM
- [x] ESP8266 : Surilli Wifi
- [x] ATmega2560 @ 16MHz : Arduino Mega
- [x] ATSAM21D : Arduino Zero, Surilli Basic

<!-- END COMPATIBILITY TABLE -->
