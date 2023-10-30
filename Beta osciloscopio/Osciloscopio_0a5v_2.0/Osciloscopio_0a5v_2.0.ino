#include <Adafruit_GFX.h> 
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define large 300
#define down 0x0000
#define up   0x2E40
#define edge 10

#define sensor A3

int convert[large-1];

void setup() {
  Serial.begin(9600);

  pinMode(sensor,INPUT);
  tft.reset();

  uint16_t identifier = tft.readID(); //Busca el ID del controlador de la pantalla TFT
  tft.begin(identifier);

   tft.fillScreen(down); 
   tft.setRotation(2);
}

void loop() {

  for(int i=0;i<large;i++){
  convert[i]=map(analogRead(sensor),0,1023,edge,210);
  tft.fillRect(convert[i],0, 1, 1, up);

  for(int j=1;j<=i;j++){
  tft.fillRect(convert[i-j],j, 1, 1, up);
  tft.fillRect(convert[i-j],j-1, 1, 1, down);
  }

  }
tft.fillScreen(down);
}
