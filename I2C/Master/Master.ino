#include <Wire.h>
#include <ESP8266WiFi.h>

void setup() {
 Wire.begin(0,2); // join i2c bus (address optional for master)
Serial.begin(115200);
}



void loop() {

    
    for(int i=0;i<=63;i++){
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(i);    
    Wire.endTransmission();    // stop transmitting
    Serial.print("i es:  ");
    Serial.println(i);// sends one byte
    }
    
 

 
 delay(2000);
}
