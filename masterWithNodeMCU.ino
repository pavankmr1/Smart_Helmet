/*                == MASTER CODE ==   */

#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

int state = 0;

const char* ssid = "pavan"; //Your Network SSID

const char* password = "123pavan"; //Your Network Password

WiFiClient client;

unsigned long myChannelNumber = 1226011; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "NYB44L9S6A6X136S"; //Your Write API Key

void setup()

  {
     Serial.begin(38400); // Default communication rate of the Bluetooth module

     Serial.begin(115200);

     delay(10);

     // Connect to WiFi network

     WiFi.begin(ssid, password);



     ThingSpeak.begin(client);

  }



void loop()

{
   if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.write(state);
 }
 
 if (state == '1') {
    Serial.println("1");
    ThingSpeak.writeField(myChannelNumber, 1,state, myWriteAPIKey); //Update in ThingSpeak
    delay(100);
    state = 0;
  
 }
 else if (state == '0') {
    
    Serial.println("0");
    ThingSpeak.writeField(myChannelNumber, 1,state, myWriteAPIKey); //Update in ThingSpeak
    delay(100);
    state = 0;
   
  
 }


}

 
