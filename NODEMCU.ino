#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "pavan"; // Network SSID

const char* password = "123pavan"; // Network Password

int val;

int Inpin = 5; //GPIO Pin Connected at D1 Pin



WiFiClient client;

unsigned long myChannelNumber = 1226011; // Channel Number 

const char * myWriteAPIKey = "9DBVSOONKLKF34T9"; // Write API Key

void setup()

{
pinMode(5,INPUT);

Serial.begin(9600);

delay(10);

WiFi.begin(ssid, password);// Connect to WiFi network

ThingSpeak.begin(client);

}



void loop()

{

val = digitalRead(Inpin); //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor
delay(100);

// if val = 1 then the rider was not wearing the helmet so that ALERT will be sent to mobile , if val = 0 he was wearing the helmet so that ALERT will be sent to mobile


ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak

delay(100);
}
