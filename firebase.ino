
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>   

#define FIREBASE_HOST "alert-c07d1.firebaseio.com"      
#define FIREBASE_AUTH "yDDdGwliiju3b20Lz8ktrx7exvhmd2ryIBouaj5a"            
#define WIFI_SSID "dlink"   // Network SSID                               
#define WIFI_PASSWORD "98685578"    // Network Password



int val;

int Inpin = 5; //GPIO Pin Connected at D1 Pin




void setup()

{
  pinMode(5,INPUT);

  Serial.begin(115200);              
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                  
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    }
  Serial.println();
  Serial.print("Connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());                               //prints local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);                 // connect to the firebase
 
    
}


void loop()

{

  val = digitalRead(Inpin); //Read Analog values and Store in val variable

  Serial.print(val); //Print on Serial Monitor
  delay(100);

  // if val = 1 then the rider was not wearing the helmet  , if val = 0 he was wearing the helmet 

  Firebase.pushInt("status", val);  //sends data to firebase
  
    // handle error 
    if (Firebase.failed()) 
    {
 
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error()); 
      return;
    }

  delay(100);
}



   
        
 
        
 
