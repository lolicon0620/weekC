#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0
#define BUTTON 2
byte previousState=1, presentState=1, patternNumber=0;
const int row[] = {
  ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {
  COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

byte scan[8][8] = {
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,0,0,1}
};

byte L[8][8] = {
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,0}};
byte O[8][8] = {
  {1,1,0,0,0,0,1,1},
  {1,0,1,1,1,1,0,1},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {1,0,1,1,1,1,0,1},
  {1,1,0,0,0,0,1,1}};
byte I[8][8] = {
  {0,0,0,0,0,0,0,0},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {1,1,1,0,0,1,1,1},
  {0,0,0,0,0,0,0,0}};
byte C[8][8] = {
  {1,1,0,0,0,0,0,0},
  {1,0,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {1,0,1,1,1,1,1,1},
  {1,1,0,0,0,0,0,0}};
byte N[8][8] = {
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,1,0,0},
  {0,0,0,0,1,1,0,0},
  {0,0,1,0,0,1,0,0},
  {0,0,1,1,0,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,0,1,1,1,1,0,0}};




void setup()
{
  
  for (byte i = 0; i <= sizeof(row); i++) {
    pinMode(row[i], OUTPUT);
  }
  for (byte i = 0; i <= sizeof(col); i++) {
    pinMode(col[i], OUTPUT);
  }  

  pinMode(2, INPUT_PULLUP);
  
}

void loop()
{


  presentState=digitalRead(BUTTON);
  if(presentState==0&&previousState==1){
    patternNumber++;
    if(patternNumber>6)
      patternNumber=0;
}
  if(patternNumber==0)
    showPattern(L);
  else if(patternNumber==1)
    showPattern(O);
  else if(patternNumber==2)
    showPattern(L);
  else if(patternNumber==3)
    showPattern(I);
  else if(patternNumber==4)
    showPattern(C);
  else if(patternNumber==5)
    showPattern(O);
  else if(patternNumber==6)
    showPattern(N);
    else
    patternNumber=0;
    
   delay(2);
   previousState=presentState;
 }

void showPattern(byte matrix[8][8]){
  for(byte i = 0; i < 8; i++){
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], 1 - scan[i][j]);
      digitalWrite(col[j], 1 - matrix[i][j]);	
    }
    for(byte j = 0; j < 8; j++){
      digitalWrite(row[j], HIGH);
      digitalWrite(col[j], LOW);	
    }
  }
}
