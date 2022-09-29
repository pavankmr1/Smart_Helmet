int IRSensor = 2; // connect ir sensor to arduino pin 2




void setup() 
{

   Serial.begin(9600);

  pinMode (IRSensor, INPUT); // sensor pin INPUT

}

void loop()
{
  int statusSensor = digitalRead (IRSensor);
  Serial.println(statusSensor);
  delay(1000);
 /* if (statusSensor == 1)
   Serial.println("1");
  }
  else
  {
   Serial.println("0");
  }*/
  
}
