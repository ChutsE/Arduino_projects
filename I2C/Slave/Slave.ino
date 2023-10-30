#include <Wire.h>

void setup() {
 Wire.begin(8);                // join i2c bus with address #8
 
 Serial.begin(115200);           // start serial for output
}

void loop() {
 Wire.onReceive(receiveEvent); // register event
}

// function that executes whenever(siempre que) data is received from master
// this function is registered as an event, see setup()
void receiveEvent() {
  
 int x = Wire.read();    // receive byte as an integer
 Serial.println(x);         // print the integer
 
}
