                                          /* == MASTER CODE ==   */  /* == BLUETOOTH INSIDE THE BIKE == */

int state = 0; // Receives information of status of helmet lock from slave bluetooth 

void setup() {
     pinMode(13, OUTPUT);
     Serial.begin(38400); // Default communication rate of the Bluetooth module
}
void loop() {
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.write(state);
 }
 
 if (state == '1') {  // State = 1 indicates helmet lock is locked
  
    digitalWrite(13, LOW);// sends output to nodeMCU to write low to indicate that NO ALERT should be sent
    
    Serial.println("1");
    state = 0;
  
 }
 else if (state == '0') { // State = 1 indicates helmet lock is locked
  
     digitalWrite(13, HIGH);// sends output to nodeMCU to write low to indicate that  ALERT should be sent
     
     Serial.println("0");
     state = 0;
  
 }

}
