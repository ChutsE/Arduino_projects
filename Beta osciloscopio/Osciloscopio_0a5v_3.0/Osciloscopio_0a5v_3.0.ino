#include <Adafruit_GFX.h> 
#include <MCUFRIEND_kbv.h>

MCUFRIEND_kbv tft;

#define large 320
#define Width 240
#define down 0x0000
#define up   0x2E40
#define edge 10

#define sensor A15
#define CYAN  0x07FF

int pointime=80; //Rango de tiempo
int convert;
int frametime;



void setup() {
  Serial.begin(9600);

  pinMode(sensor,INPUT);
  tft.reset();
 
  uint16_t identifier = tft.readID(); //Busca el ID del controlador de la pantalla TFT
  tft.begin(identifier);
 
  tft.fillScreen(down); 
  tft.setRotation(2);
  tft.drawRect(edge-1, edge+4, Width-edge-27, large-2*edge-2, 0xFFFF);

  tft.setRotation(1);
  tft.setTextColor(CYAN); 
  tft.setCursor(307,205);  
  tft.println("0v");
  tft.setCursor(307,10);  
  tft.println("5v");  
  
}

void loop() {
  tft.setRotation(2);
  
  frametime=millis();
  for(int i=edge+5;i<=large-edge;i++){
    convert=map(analogRead(sensor),1023,0,edge+1,210-1);
    tft.fillRect(convert,i, 1, 1, up);
    delayMicroseconds(pointime);
  }
  frametime=millis()-frametime;
  
  tft.fillRect(edge,edge+5, Width-edge-29, large-2*edge-4, down);
 
  tft.setRotation(1);
  tft.setTextColor(CYAN);  
  tft.setTextSize(1);     
  tft.setCursor(10,200);  
  tft.println(frametime);
     

}
