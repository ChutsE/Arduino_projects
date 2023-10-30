#include <Adafruit_GFX.h> 
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define large 320
#define Width 240
#define down 0x0000
#define up   0x2E40
#define edge 10

#define sensor A15
#define frametime 1
int convert;

void setup() {
  Serial.begin(9600);

  pinMode(sensor,INPUT);
  tft.reset();

  uint16_t identifier = tft.readID(); //Busca el ID del controlador de la pantalla TFT
  tft.begin(identifier);

   tft.fillScreen(down); 
   tft.setRotation(2);
   tft.drawRect(edge-1, edge-1, Width-edge-27, large-2*edge+5, 0xFFFF);
}

void loop() {


  for(int i=edge;i<=large-edge;i++){
  convert=map(analogRead(sensor),0,1023,edge,210);
  tft.fillRect(convert,i, 1, 1, up);
  delay(frametime);
  }
 tft.fillRect(edge,edge, Width-edge-29, large-2*edge+1, down);
}
