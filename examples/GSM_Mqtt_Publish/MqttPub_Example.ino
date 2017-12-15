#include <MqttPubSub.h>
//mqtts Mqtts("Client ID", "Broker URL", "Port");

mqtts Mqtts("clientId-ABCxyz123", "broker.mqttdashboard.com", "1883"); 

void setup() 
{
Mqtts.Connect();
}

void loop() 
{
Mqtts.Publish("SILVERBACK", "Hello"); 
} 
