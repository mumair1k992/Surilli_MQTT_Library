/*
  mqtts.h - Library for receiving message.
  Created by Junaid Alam at Silverback pvt limited, August 25, 2017.
  Released into the public domain.
*/



#ifndef MqttPubSub_h
#define MqttPubSub_h

#include "Arduino.h"


class mqtts
{
  public:
    mqtts(char* clientId, char* brokerUrl, char* brokerPort);
    void Publish(char* topic, char* message);
    void Subscribe(char*topic);
	void Connect();
	void Disconnect();
    void mySerial_read();
    boolean isGPRSReady();
  
  
  public:
String gprsStr = "";
int index = 0;
byte data1;
char atCommand[50];
byte mqttMessage[127];
int mqttMessageLength = 0;

char* _message;
char* _topic;
char* _brokerPort;
char* _brokerUrl;
char* _clientId;


//bolean flags
boolean smsReady = false;
boolean smsSent = false;
boolean gprsReady = false;
boolean mqttSent = false;
};

#endif
