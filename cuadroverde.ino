#include <UTFTGLUE.h>
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0);
int centerX = 240, centerY = 160;
float pixelSize;
float rWidth = 14.0;
float rHeight = 5.0;
int maxX = 320-1;
int maxY = 320-1;
void setup()
{
  randomSeed(analogRead(0));
  myGLCD.InitLCD();
}

void loop()
{
  int maxX=480-1;
  int maxY=320-1;
  int minMaxXY=maxY;
  int xCenter=maxX/2;
  int yCenter=maxY/2;
 
  myGLCD.clrScr();
  myGLCD.setColor(125, 225, 75);
  float side=0.95F * minMaxXY, sideHalf=0.5F * side,
        h=sideHalf * 1.73,
        xA, yA, xB,yB,xC,yC, xD, yD,
        xA1, yA1, xB1, yB1, xC1, yC1, xD1 , yD1,  p, q;
        q=0.05F;
        p=1-q;
        xA=xCenter-sideHalf;
        yA=yCenter-0.5F*h;
        xB=xCenter+sideHalf;
        yB=yA;
        xC=xB;
        yC=yCenter+0.5F*h;
        xD=xCenter-sideHalf;
        yD=yC;
        for(int i=0; i<50; i++){
            myGLCD.drawLine(iX(xA), iY(yA), iX(xB), iY(yB));
            myGLCD.drawLine(iX(xB), iY(yB), iX(xC), iY(yC));
            myGLCD.drawLine(iX(xC), iY(yC), iX(xD), iY(yD));
            myGLCD.drawLine(iX(xD), iY(yD), iX(xA), iY(yA));
            xA1=p *xA + q * xB;
            yA1=p *yA + q * yB;
            xB1=p *xB + q * xC;
            yB1=p *yB + q * yC;
            xC1=p *xC + q * xD;
            yC1=p *yC + q * yD;
            xD1=p *xD + q * xA;
            yD1=p *yD + q * yA;
            xA=xA1; xB=xB1; xC=xC1; xD=xD1;
            yA=yA1; yB=yB1; yC=yC1; yD=yD1;
            
          }
         delay(10);
 
}
int iX(float x)
{
return x + 0.5;
}
int iY(float y)
{
return maxY - y - 0.5;
}
