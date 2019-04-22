#include <UTFTGLUE.h>              //use GLUE class and constructor
UTFTGLUE myGLCD(0,A2,A1,A3,A4,A0); //all dummy args

//int centerX = 30, centerY = 220;
int centerX = 10, centerY = 230;
float pixelSize;
float rWidth = 22.0;
float rHeight = 22.0;
int maxX = 320-1;
int maxY = 240-1;


bool matriz[][20] = { 
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };


bool repuesto[][20] = { 
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };



void setup()
{
  randomSeed(analogRead(0));
  myGLCD.InitLCD();
  myGLCD.setFont(SmallFont);

  pixelSize = max(rWidth/maxX, rHeight/maxY);
  Serial.begin(9600);
}

void loop()
{
  myGLCD.clrScr();

  
  myGLCD.setColor(255, 255, 0);
 
 for(int i=0; i<20; i++){  
  int ii = i+1;
    for(int j=0; j<20; j++){
        int jj = j+1;
        if(matriz[i][j]==1){
            myGLCD.setColor(255, 0, 0);   
        }else{
          myGLCD.setColor(0, 0, 255);
        }
        dibuja(i,j);
        pasar(i,j);   
    }
 }
  delay(4000);



 for(int i=0; i<20; i++){  
    for(int j=0; j<20; j++){
          matriz[i][j] = repuesto[i][j];
    }
 }

  delay(1000);


  
}

void dibuja(int xx, int yy){
  int y= 19-xx;
  int x= yy;
  myGLCD.drawRect(iX(x),iY(y),  iX(x+1),iY(y+1));  
}

void pasar(int i, int j){
   int imasuno=i+1;
   int imenosuno=i-1;  
   int jmasuno=j+1;
   int jmenosuno=j-1;
   int contador = 0;

   if(imenosuno > -1){
      if(jmenosuno > -1){
          contador = contador + (int) matriz[imenosuno][jmenosuno];
      } 
      if(jmasuno < 20){
          contador = contador + (int) matriz[imenosuno][jmasuno];
      } 
      contador = contador + (int) matriz[imenosuno][j];
   }


   
   if(imasuno < 20){
      if(jmenosuno > -1){
          contador = contador + (int) matriz[imasuno][jmenosuno];
      } 
      if(jmasuno < 20){
          contador = contador + (int) matriz[imasuno][jmasuno];
      } 
      contador = contador + (int) matriz[imasuno][j];
   }

   
      if(jmenosuno > -1){
          contador = contador + (int) matriz[i][jmenosuno];
      } 
      if(jmasuno < 20){
          contador = contador + (int) matriz[i][jmasuno];
      } 

      if(matriz[i][j] == 1 && (contador == 2 || contador == 3)){
          repuesto[i][j] = 1;
      }else{
          if(matriz[i][j] == 0 && contador == 3 ){
              repuesto[i][j] = 1;
          }else{
            
                repuesto[i][j] = 0;
      
          }
      }
   
}

int iX(float x){ 
  //return Math.round(centerX + x/pixelSize); 
   return ( centerX+ x/pixelSize + 0.5 );
}
int iY(float y){    
  return ( centerY- y/pixelSize - 0.5 );
  //return Math.round(centerY + y/pixelSize);
}
