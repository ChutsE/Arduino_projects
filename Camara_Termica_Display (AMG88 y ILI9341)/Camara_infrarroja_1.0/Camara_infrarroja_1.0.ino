#include <Wire.h>
#include <Adafruit_AMG88xx.h>

Adafruit_AMG88xx amg;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];


#include <Adafruit_GFX.h> ¿
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;

#define SizeArray 63
#define CYAN  0x07FF
#define sizepix 30
#define edge 30

float Sum;

int x, y; //coordenadas

int a; //valor entero de temp


void setup()
{

  Serial.begin(9600);
  amg.begin();
  tft.reset();

  uint16_t identifier = tft.readID(); //Busca el ID del controlador de la pantalla TFT
  tft.begin(identifier);


  tft.fillScreen(0x0000);     // fondo de la pantalla
  tft.setRotation(0);

  tft.setTextColor(CYAN);   // Definimos el color del texto como CYAN
  tft.setTextSize(3);       //  establecemos el tamañodel texto
  tft.setCursor(20, 3);   // Usamos los valores  como coordenas de del los ej X,Y
  tft.println("THERMAL CAM");  // Eescrivimos (Hola TFT) en el display enla cordenada especificada anterio mente



  delay(100);

}


void loop() {


  amg.readPixels(pixels);

  Print_values();

  Print_Array();


}




void Print_values() {

  tft.fillRect(10, 290, 88, 30, 0x0000);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.setCursor(10, 270);
  tft.println("Medium:");
  tft.setTextSize(3);
  tft.setCursor(10, 290);
  tft.println(pixels[21]);


  Sum = 0;
  for (int i = 0; i <= SizeArray; i++)
    Sum = Sum + pixels[i];


  tft.fillRect(125, 290, 88, 30, 0x0000);
  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.setCursor(125, 270);
  tft.println("Average:");
  tft.setTextSize(3);
  tft.setCursor(125, 290);
  tft.println(Sum / (SizeArray + 1));


}



void Print_Array() {

  for (int i = 0; i <= SizeArray; i++) {

    x = i;
    y = i / 8;
    switch (y)
    {
      case 0: x = x - 8 * y;
        break;
      case 1: x = x - 8 * y;
        break;
      case 2: x = x - 8 * y;
        break;
      case 3: x = x - 8 * y;
        break;
      case 4: x = x - 8 * y;
        break;
      case 5: x = x - 8 * y;
        break;
      case 6: x = x - 8 * y;
        break;
      case 7: x = x - 8 * y;
        break;
    }

    a = pixels[i];
    Serial.print(i);
    Serial.print(". ");
    Serial.print(a);
    Serial.println();

    switch (a) {
      case 40:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFFF);
        break;
      case 39:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFF9);
        break;
      case 38:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFF3);
        break;
      case 37:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFEC);
        break;
      case 36:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFE6);
        break;
      case 35:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFE0);
        break;
      case 34:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFE40);
        break;
      case 33:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFCC0);
        break;
      case 32:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFB20);
        break;
      case 31:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF9A0);
        break;
      case 30:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF800);
        break;
      case 29:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF806);
        break;
      case 28:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF80C);
        break;
      case 27:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF813);
        break;
      case 26:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF819);
        break;
      case 25:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xF81F);
        break;
      case 24:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xC81F);
        break;
      case 23:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x911F);
        break;
      case 22:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x601F);
        break;
      case 21:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x301F);
        break;
      case 20:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x001F);
        break;
      case 19:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x0019);
        break;
      case 18:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x0013);
        break;
      case 17:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x000C);
        break;
      case 16:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x0006);
        break;
      case 15:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0x0000 );
        break;
      default:
        tft.fillRect(x * sizepix, y * sizepix + edge, sizepix, sizepix, 0xFFFF );
    }
  }

}
