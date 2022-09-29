                                    /* == SLAVE CODE == */   
                                    
                                   /* == BLUETOOTH AND PROXIMITY SENSOR INSIDE THE HELMET == */
                                    

int IRSensor = 2; // connect ir sensor to arduino pin 2

void setup() {
    
  Serial.begin(38400); // Default communication rate of the Bluetooth module AND PROXIMITY
  pinMode (IRSensor, INPUT); // sensor pin INPUT
}

void loop() {
 

  int statusSensor = digitalRead(IRSensor);
 
  
 
 if (statusSensor == 0) {

  Serial.write("1"); // Sends '1' to the master indicates that rider is wearing helmet
 }
 else {

   Serial.write("0"); // sends '0' to the master indicates that rider is not wearing helmet
 }  
 delay(1000);
}
