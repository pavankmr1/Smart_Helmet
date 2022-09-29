
#include <MPU6050_tockn.h>
#include <Wire.h>
int led1 = 13;
int led2 = 12;
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  mpu6050.update();
  //Serial.print("angleX : ");
  //Serial.print(mpu6050.getAngleX());
  Serial.print("\n");
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
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
  //Serial.print("\tangleZ : ");
  //Serial.println(mpu6050.getAngleZ());
  delay(100);
}
