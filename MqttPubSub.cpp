/*
  mqttP.h - Library for Publishing MQTT messages.
  Created by Silverback pvt limited, August 25, 2017.
  Released into the public domain.
*/



#include "Arduino.h"
#include "MqttPubSub.h"
#include "mqtt.h"
#include <SoftwareSerial.h>
#include <string.h>

using namespace std;

mqtts::mqtts(char* clientId, char* brokerUrl, char* brokerPort)
{
	_brokerPort=brokerPort;
	_brokerUrl=brokerUrl;
	_clientId=clientId;

}

void mqtts::Connect()
{
	

	
  Serial.println("Checking if GPRS is READy?");
  SoftwareSerial GPRS(8, 9); //RX, TX
  Serial.begin (9600); //debug
  GPRS.begin(9600); //GPRS
  
  gprsReady= isGPRSReady();
  if(gprsReady == true)
  {
    Serial.println("GPRS READY!");
  }
  GPRS.println("AT+CIPSHUT");
  Serial.println("AT+CIPSHUT");
  mySerial_read();
  delay(100);
   GPRS.println("AT+CIPMUX=0");
   Serial.println("AT+CIPMUX=0");
   mySerial_read();
   delay(100);
    GPRS.println("AT+CGATT=1");
    Serial.println("AT+CGATT=1");
    mySerial_read();
    delay(100);
 GPRS.println("AT+CSTT=\"zonginternet\",\"\",\"\""); // Puts phone into GPRS mode
 Serial.println("AT+CSTT=\"zonginternet\",\"\",\"\"");
 mySerial_read();
 delay(100); // Wait a second
 GPRS.println("AT+CIICR");
 Serial.println("AT+CIICR");
 mySerial_read();
 delay(2000);
 GPRS.println("AT+CIFSR");
 Serial.println("AT+CIFSR");
 mySerial_read();
 delay(100);
 strcpy(atCommand, "AT+CIPSTART=\"TCP\",\"");
 strcat(atCommand, _brokerUrl);
 strcat(atCommand, "\",\"");
 strcat(atCommand, _brokerPort);
 strcat(atCommand, "\"");
 GPRS.println(atCommand);
 Serial.println(atCommand);
 mySerial_read();
 // Serial.println("AT+CIPSTART=\"TCP\",\"mqttdashboard.com\",\"1883\"");
delay(2000);

 GPRS.println("AT+CIPSEND");
 Serial.println("AT+CIPSEND");
 mySerial_read();
 delay(1000);

 mqttMessageLength = 16 + strlen(_clientId);
 Serial.println(mqttMessageLength);
 mqtt_connect_message(mqttMessage, _clientId);

 for (int j = 0; j < mqttMessageLength; j++) {
 GPRS.write(mqttMessage[j]); // Message contents
 Serial.write(mqttMessage[j]); // Message contents
 }
Serial.println("\u001A");
 GPRS.write(byte(26)); // (signals end of message)
 mySerial_read();
 delay(5000);
 
  }
  
void mqtts::Publish(char* topic, char* message)
{
	_topic=topic;
	_message=message;
  SoftwareSerial GPRS(8, 9); //RX, TX
  Serial.begin (9600); //debug
  GPRS.begin(9600); //GPRS

 GPRS.println("AT+CIPSEND");
 Serial.println("AT+CIPSEND");
 mySerial_read();
 delay(1000);
 mqttMessageLength = 4 + strlen(_topic) + strlen(_message);
 Serial.println(mqttMessageLength);
 mqtt_publish_message(mqttMessage, _topic, _message);

 for (int k = 0; k < mqttMessageLength; k++) {
 GPRS.write(mqttMessage[k]);
 Serial.write((byte)mqttMessage[k]);
 }
 Serial.println("\u001A");
 GPRS.write(byte(26)); // (signals end of message)

 //Serial.println("-------------Sent-------------"); // Message contents
 mySerial_read();
 delay(1000);
}  

void mqtts::Subscribe(char* topic)
{
	_topic=topic;
  SoftwareSerial GPRS(8, 9); //RX, TX
  Serial.begin (9600); //debug
  GPRS.begin(9600); //GPRS
 
 GPRS.println("AT+CIPSEND");
 Serial.println("AT+CIPSEND");
 mySerial_read();
 delay(1000);
 mqttMessageLength = 7 + strlen(_topic);
 Serial.println(mqttMessageLength);
 mqtt_subscribe_message(mqttMessage, _topic);
 
 for (int k = 0; k < mqttMessageLength; k++) {
 GPRS.write(mqttMessage[k]);
 Serial.write((byte)mqttMessage[k]);
 }
 Serial.println("\u001A");
 GPRS.write(byte(26)); // (signals end of message)
 Serial.println("AT+CIPRXGET=4");
 //Serial.println("-------------Sent-------------"); // Message contents
} 


void mqtts::Disconnect()
{
	
	  SoftwareSerial GPRS(8, 9); //RX, TX
  Serial.begin (9600); //debug
  GPRS.begin(9600); //GPRS
 
 GPRS.println("AT+CIPCLOSE");
 Serial.println("AT+CIPCLOSE");
 delay(2000);
  GPRS.println("AT+CIPSHUT");
 Serial.println("AT+CIPSHUT");
 delay(2000);
}

  
boolean mqtts::isGPRSReady()
{
 SoftwareSerial GPRS(8, 9); //RX, TX
 GPRS.println("AT");
 GPRS.println("AT");
 GPRS.println("AT+CGATT=1");
 index = 0;
 while (GPRS.available()){
    data1 = (char)GPRS.read();
    Serial.write(data1);
    gprsStr[index++] = data1;
    }
 Serial.println("Check OK");
 Serial.print("gprs str = ");
 Serial.println(data1);
 if (data1 > -1){
  Serial.println("GPRS OK");
  return true;
 }
 else {
  Serial.println("GPRS NOT OK");
  return false;
 }
}

void mqtts::mySerial_read()

	{ 
		SoftwareSerial mySerial(8, 9); // RX, TX
  
  	mySerial.begin(9600);
  	delay(10);
	
		if (mySerial.available() > 0) 
		{
          
         String letter = mySerial.readString();
         
         Serial.println(letter);
         
        }
        delay(1000);
	}





