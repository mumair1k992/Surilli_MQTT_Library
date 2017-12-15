
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
Atmega328 @ 16MHz  |     [x]      |             |     
Atmega32u4 @ 16MHz |              |             |    
Atmega32u4 @ 8MHz  |              |             |    
ESP8266            |              |             |   
Atmega2560 @ 16MHz |              |             |           
ATSAM21D           |              |             |                                

  * ATmega328 @ 16MHz : Arduino UNO
  * ATmega32u4 @ 16MHz : Arduino Leonardo,
  * ATmega32u4 @ 8MHz : Surilli GSM
  * ESP8266 : Surilli Wifi
  * ATmega2560 @ 16MHz : Arduino Mega
  * ATSAM21D : Arduino Zero, Surilli Basic

<!-- END COMPATIBILITY TABLE -->
