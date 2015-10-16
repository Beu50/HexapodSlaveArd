#include <Wire.h>

//byte initialString [

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

  char sentArr[Wire.available()];
  char parseArr[1][4];
  byte i = 0;
  
  while (1 < Wire.available()) {
    char c = Wire.read(); // receive byte as a character
    sentArr[i] = c;
    i++;
  }
    
  //Serial.println("");
  
  for (int j = 0; j < 30; j++) {
    //Serial.println(Wire.available());
    //Serial.println(j);
    Serial.print(sentArr[j]);
  }
  //Serial.println("");
  //Serial.print(sentArr[100]);
}
  //int x = Wire.read();    // receive byte as an integer
  //Serial.print("     ");
  //Serial.println(x);         // print the integer
