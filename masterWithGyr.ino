                                          /* == MASTER CODE ==   */  /* == BLUETOOTH INSIDE THE BIKE AND WITH GYROSCOPE == */
#include <MPU6050_tockn.h>
#include <Wire.h>

int led1 = 13;
int led2 = 12;
MPU6050 mpu6050(Wire);

int state = 0; // Receives information of status of helmet lock from slave bluetooth 

void setup() {
     pinMode(7, OUTPUT);
     Serial.begin(38400); // Default communication rate of the Bluetooth module 

      
     Wire.begin();
     mpu6050.begin();
     mpu6050.calcGyroOffsets(true);
     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
}
void loop() {
  mpu6050.update();
  
   if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 
 }

 if (state == '1') {  // State = 1 indicates rider was wearing helmet 
  
    digitalWrite(7, LOW);// sends output to nodeMCU to write low to indicate that NO ALERT should be sent   
    Serial.println("1");
    state = 0;
  
 }
 else if (state == '0') { // State = 0 indicates rider was not wearing helmet 
     digitalWrite(7, HIGH);// sends output to nodeMCU to write low to indicate that  ALERT should be sent     
     Serial.println("0");
     state = 0;
  
 }

  

  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\n");
  
  if(mpu6050.getAngleY()>30){
    digitalWrite(led1, HIGH);
     delay(1000);
    digitalWrite(led1, LOW);    
  }
    if(mpu6050.getAngleY()<-30){
    digitalWrite(led2, HIGH);
     delay(1000);
    digitalWrite(led2, LOW);      
  }
   delay(100);
  


}
