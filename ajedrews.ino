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

void setup()
{
  randomSeed(analogRead(0));
  
// Setup the LCD
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);
  pixelSize = max(rWidth/maxX, rHeight/maxY);
  Serial.begin(9600);

}

//formulas modo isotropico

void loop()
{
  int buf[318];
  int x, x2;
  int y, y2;
  int r;
  
  myGLCD.clrScr();
  myGLCD.setColor(255,255, 255);
  
//myGLCD.setColor(255,255, 0);
//myGLCD.drawRect(0, 0, 319, 239);

//myGLCD.drawPixel(iX(1), iY(1));

/*
  myGLCD.fillScr(0, 0, 255);
  myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect(80, 70, 239, 169);
*/

//myGLCD.drawRect(iX(4), iY(0), iX(8), iY(3));
//myGLCD.drawRect(iX(8), iY(0), iX(12), iY(3));

//myGLCD.setColor(0,255, 255);

int scolor = 0;
for(int i=0; i<8; i++){
  int yy = i*3;
  for(int j=0; j<8; j++){
    int xx=j*4;

    if(scolor == 0){
        if( (j+1) % 2 == 0){
            myGLCD.setColor(255,255, 255);
        }else{
            myGLCD.setColor(0,0,0);
        }
    }
    
    if(scolor == 1){
        if( (j+1) % 2 == 0){
            myGLCD.setColor(0,0,0);
        }else{
            myGLCD.setColor(255,255, 255);
        }
    }
    myGLCD.fillRect(iX(xx), iY(yy), iX(xx+4), iY(yy+3));
    //myGLCD.drawRect(iX(xx), iY(yy), iX(xx+4), iY(yy+3));  
  }
  if(scolor == 0){
    scolor = 1;  
  }else{
    scolor = 0;
  }
}



myGLCD.setColor(0,0,255);
peon(0,1);
peon(1,1);
peon(2,1);
peon(3,1);
peon(4,1);
peon(5,1);
peon(6,1);
peon(7,1);
torre(0,0);
torre(7,0);
caballo(1,0);
caballo(6,0);
alfil(2,0);
alfil(5,0);
rey(3,0);
reina(4,0);


myGLCD.setColor(255,0,255);
peon(0,6);
peon(1,6);
peon(2,6);
peon(3,6);
peon(4,6);
peon(5,6);
peon(6,6);
peon(7,6);
torre(0,7);
torre(7,7);
caballo(1,7);
caballo(6,7);
alfil(2,7);
alfil(5,7);
rey(3,7);
reina(4,7);

//myGLCD.drawPixel(iX(0), iY(0)); //2.9, 3.9


delay(8000);
}

float funcion(float x){
  //return x*x*x ;//+ 2*x*x + 3;
  return cos(x);
}

int iX(float x){ 
  //return Math.round(centerX + x/pixelSize); 
   return ( centerX+ x/pixelSize - 0.5 );
}
int iY(float y){    
  return ( centerY+ y/pixelSize + 0.5 );
  //return Math.round(centerY + y/pixelSize);
}

void peon(float xxx, float yyy){
// peon(1,2, 3,4);
/*
float yyy = 1;
float xxx = 2;
*/
float yr = yyy*3.0;
float xr = xxx*4.0;


myGLCD.fillCircle(iX(xr+2), iY(yr+2.4), 5);
myGLCD.fillRect(iX(xr+3.2), iY(yr+2.1), iX(xr+1), iY(yr+1.7));
myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));


/*
myGLCD.setColor(255,255,0);
myGLCD.fillCircle(iX(2), iY(2.4), 5);
myGLCD.fillRect(iX(3.2), iY(2.1), iX(1), iY(1.7));
myGLCD.fillRect(iX(2.6), iY(0.9), iX(1.5), iY(1.7));
myGLCD.fillRect(iX(3.1), iY(0.6), iX(1.0), iY(0.8));
myGLCD.fillRect(iX(3.6), iY(0.3), iX(0.5), iY(0.5));
myGLCD.fillRect(iX(4.1), iY(0), iX(0), iY(0.2));
*/
}


void torre(float xxx, float yyy){
float yr = yyy*3.0;
float xr = xxx*4.0;

myGLCD.fillRect(iX(xr+3.3), iY(yr+2.1), iX(xr+0.8), iY(yr+1.7));
myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));


myGLCD.fillRect(iX(xr+3.5), iY(yr+2.6), iX(xr+3.0), iY(yr+1.7));
myGLCD.fillRect(iX(xr+2.6), iY(yr+2.6), iX(xr+1.6), iY(yr+1.7));
myGLCD.fillRect(iX(xr+1.2), iY(yr+2.6), iX(xr+0.7), iY(yr+1.7));
}



void caballo(float xxx, float yyy){
float yr = yyy*3.0;
float xr = xxx*4.0;



myGLCD.fillRect(iX(xr+3.5), iY(yr+2.0), iX(xr+1.4), iY(yr+1.6));
myGLCD.fillRect(iX(xr+3.2), iY(yr+2.1), iX(xr+1.3), iY(yr+1.7));
myGLCD.fillRect(iX(xr+2.9), iY(yr+2.2), iX(xr+1.2), iY(yr+1.8));
myGLCD.fillRect(iX(xr+2.6), iY(yr+2.3), iX(xr+1.3), iY(yr+1.9));
myGLCD.fillRect(iX(xr+2.3), iY(yr+2.4), iX(xr+1.4), iY(yr+2.0));
myGLCD.fillRect(iX(xr+2.0), iY(yr+2.5), iX(xr+1.5), iY(yr+2.1));

myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.6));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));

}



void alfil(float xxx, float yyy){
float yr = yyy*3.0;
float xr = xxx*4.0;


myGLCD.fillRect(iX(xr+3.2), iY(yr+2.1), iX(xr+1), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.0), iY(yr+2.4), iX(xr+1.2), iY(yr+2.0));
myGLCD.fillRect(iX(xr+2.6), iY(yr+2.7), iX(xr+1.6), iY(yr+2.3));
myGLCD.fillRect(iX(xr+2.4), iY(yr+3.0), iX(xr+1.8), iY(yr+2.6));

myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));

}


void rey(float xxx, float yyy){
float yr = yyy*3.0;
float xr = xxx*4.0;


myGLCD.fillRect(iX(xr+3.2), iY(yr+2.1), iX(xr+1), iY(yr+1.7));
myGLCD.fillRect(iX(xr+2.4), iY(yr+2.4), iX(xr+1.8), iY(yr+2.0));
myGLCD.fillRect(iX(xr+2.8), iY(yr+2.7), iX(xr+1.4), iY(yr+2.3));
myGLCD.fillRect(iX(xr+2.4), iY(yr+3.0), iX(xr+1.8), iY(yr+2.6));

myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));

}


void reina(float xxx, float yyy){
float yr = yyy*3.0;
float xr = xxx*4.0;

myGLCD.fillRect(iX(xr+3.2), iY(yr+2.1), iX(xr+1), iY(yr+1.7));
myGLCD.fillRect(iX(xr+1.3), iY(yr+2.8), iX(xr+1), iY(yr+2.0));
myGLCD.fillRect(iX(xr+1.8), iY(yr+2.8), iX(xr+1.5), iY(yr+2.0));
myGLCD.fillRect(iX(xr+2.3), iY(yr+2.8), iX(xr+2.0), iY(yr+2.0));
myGLCD.fillRect(iX(xr+2.8), iY(yr+2.8), iX(xr+2.5), iY(yr+2.0));
myGLCD.fillRect(iX(xr+3.3), iY(yr+2.8), iX(xr+3.0), iY(yr+2.0));


myGLCD.fillRect(iX(xr+2.6), iY(yr+0.9), iX(xr+1.5), iY(yr+1.7));
myGLCD.fillRect(iX(xr+3.1), iY(yr+0.6), iX(xr+1.0), iY(yr+0.8));
myGLCD.fillRect(iX(xr+3.6), iY(yr+0.3), iX(xr+0.5), iY(yr+0.5));
myGLCD.fillRect(iX(xr+4.1), iY(yr), iX(xr), iY(yr+0.2));

}
