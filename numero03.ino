#include <UTFTGLUE.h>              //use GLUE class and constructor



UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args


#define NEGRO      0xF800

//UTF myGLCD();
int centerX = 0, centerY = 0;
float pixelSize;
float rWidth = 32.0;
float rHeight = 24.0;
int maxX = 320-1;
int maxY = 240-1;

int rojo, azul, verde;

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  pixelSize = max(rWidth/maxX, rHeight/maxY);
  Serial.begin(9600);

  rojo = rand() % (256);
  azul = rand() % (256);
  verde = rand() % (256);
    
}

//formulas modo isotropico

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;
  
  myGLCD.clrScr();
  //myGLCD.setColor(255,255, 255);
  
  //myGLCD.fillCircle(iX(16), iY(1), 10);

  
  

  
  for(float i=22; i>0; i-=3){
      myGLCD.setColor(rojo,azul, verde);
      myGLCD.fillCircle(iX(16), iY(i), 10);
      delay(200);
      myGLCD.setColor(0,0,0);
      myGLCD.fillCircle(iX(16), iY(i), 10);
  }

  rojo = rand() % (256);
  azul = rand() % (256);
  verde = rand() % (256);


  for(float i=1; i<23; i+=3){
      myGLCD.setColor(rojo,azul, verde);
      myGLCD.fillCircle(iX(16), iY(i), 10);
      delay(200);
      myGLCD.setColor(0,0,0);
      myGLCD.fillCircle(iX(16), iY(i), 10);
  }


  

  delay(1000);
}

int iX(float x){ 
  //return Math.round(centerX + x/pixelSize); 
   return ( centerX+ x/pixelSize + 0.5 );
}
int iY(float y){    
  return ( centerY+ y/pixelSize - 0.5 );
  //return Math.round(centerY + y/pixelSize);
}
