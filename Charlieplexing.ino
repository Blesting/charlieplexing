

const int LED_1 = 13;     //LED row 1
const int LED_2 = 12;     //LED row 2    
const int LED_3 = 11;     //LED row 3
const int LED_4 = 10;     //LED row 4
const int LED_5 = 9;     //LED row 5
const int LED_6 = 8;     //LED row 6
const int LED_7 = 7;      //LED row 7
const int LED_8 = 6;    //LED row 8
const int LED_9 = 5;    //LED row 9
const int LED_10 = 4;   //LED row 10
const int LED_11 = 3;   //LED row 11


int leds[10][6]={{1,1,1,1,1}};
//1. plads er x-position 2. plads er y-position 3. plads er bevægelse i y retning 4. plads er bevægelse i x retning 
//5. plads er x retning cooldown
int forloop = 200; 
int X = 0;
int a;
int xMax = 11;
int xMin = 1;
int yMax = 10;
int yMin = 1;
int r = 0;

#include <Wire.h>

void setup() {
  Wire.begin(1); 
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop(){
  a = sizeof (leds) / sizeof (leds[0]);
  taend_LEDs();
  diagonal_movement();    
  forloop = forloop +2;
  if (forloop == 204){
    forloop = 200;
  }
}

void receiveEvent(int howMany) {
  int len = Wire.available();
  r = Wire.read();
  if (r == 1){
    if (leds[0][3] == 3){
      leds[0][3] == 1;
    }
    else if (leds[0][3] == 2){
      leds[0][3] == 0;
    }
  }
  else if (r == 2){
    if (leds[0][3] == 1){
      leds[0][3] == 3;
    }
    else if (leds[0][3] == 0){
      leds[0][3] == 2;
    }
    leds[0][2] = 0;
  }
  else if (r == 3){
    if (leds[0][3] == 1){
      leds[0][3] == 3;
    }
    else if (leds[0][3] == 0){
      leds[0][3] == 2;
    }
    leds[0][2] = 1;
  }
}

void diagonal_movement(){
    //moveLeft = leds[X][3]
    //moveUp = leds[X][2]
  for (int i = 0; i <= a; i++) { 
      if (leds[i][3]==1){
        leds[i][0] = leds[i][0]+1;
      }
      else if (leds[i][3]==0){
        leds[i][0] = leds[i][0]-1;
      }
      else if (leds[i][3]==2){
        if (leds[i][4] == 0){
          leds[i][0] = leds[i][0]-1;
          leds[i][4] = 1;
        }
        else{
          leds[i][4] = leds[i][4]-1;
        }
      }
      else if (leds[i][3]==3){
        if (leds[i][4] == 0){
          leds[i][0] = leds[i][0]+1;
          leds[i][4] = 1;
        }
        else{
          leds[i][4] = leds[i][4]-1;
        }
      }
      if (leds[i][2]==1){
        leds[i][1] = leds[i][1]+1;
      }
      else if (leds[i][2]==0){
        leds[i][1] = leds[i][1]-1;
      }
      
      if (leds[i][1] == yMax){
        leds[i][2] = 0;
      }
      else if (leds[i][1]==yMin){
        leds[i][2] = 1;
      }
      if (leds[i][0]==xMax){
        leds[i][3] = 0;
        send_message();
      }
      else if (leds[i][0]==xMin){
        leds[i][3] = 1;
        send_message();
      }
      
      if (X == 0){
        X = 1;
      }
      else if (X == 1){
        X = 0;
      }
    }
}
int x = 0;
int y = 0;
void send_message(){
  x = leds[0][0];
  y = leds[0][1];
  Serial.println(x);
  Serial.println(y);
  Wire.beginTransmission(2);
  Wire.write(1);
  Wire.write(x);
  Wire.write(y);
  Wire.endTransmission();
}

void taend_LEDs(){
  for (int i = 0; i <= forloop; i++) {  
    //-----------------------X = 1-----------------------
    if (leds[X][0] == 1){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED11();
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED12();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED13();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED14();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED15();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED16();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED17();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED18();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED19();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED110();
        }
      }
    //-----------------------X = 2-----------------------
    else if (leds[X][0] == 2){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED21();
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED22();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED23();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED24();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED25();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED26();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED27();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED28();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED29();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED210();
        }
      }
    //-----------------------X = 3-----------------------
    else if (leds[X][0] == 3){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED31();
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED32();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED33();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED34();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED35();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED36();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED37();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED38();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED39();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED310();
        }
      }
      //-----------------------X = 4-----------------------
    else if (leds[X][0] == 4){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED41();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED42();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED43();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED44();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED45();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED46();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED47();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED48();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED49();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED410();
        }
      }
        //-----------------------X = 5-----------------------
    else if (leds[X][0] == 5){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED51();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED52();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED53();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED54();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED55();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED56();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED57();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED58();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED59();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED510();
        }
      }
        //-----------------------X = 6-----------------------
    else if (leds[X][0] == 6){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED61();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED62();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED63();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED64();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED65();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED66();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED67();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED68();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED69();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED610();
        }
      } 
        //-----------------------X = 7-----------------------
    else if (leds[X][0] == 7){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED71();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED72();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED73();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED74();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED75();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED76();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED77();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED78();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED79();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED710();
        }
      }
        //-----------------------X = 8-----------------------
    else if (leds[X][0] == 8){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED81();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED82();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED83();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED84();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED85();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED86();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED87();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED88();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED89();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED810();
        }
      }
        //-----------------------X = 9-----------------------
    else if (leds[X][0] == 9){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED91();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED92();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED93();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED94();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED95();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED96();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED97();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED98();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED99();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED910();
        }
      }
        //-----------------------X = 10-----------------------
    else if (leds[X][0] == 10){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED101();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED102();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED103();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED104();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED105();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED106();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED107();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED108();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED109();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED1010();
        }
      }
        //-----------------------X = 11-----------------------
    else if (leds[X][0] == 11){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED111();
        }
      //----------Y=2---------- 
      if (leds[X][1] == 2){
          LED112();
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED113();
        }
      //----------Y=4----------
      if (leds[X][1] == 4){
          LED114();
        }
      //----------Y=5----------
      if (leds[X][1] == 5){
          LED115();
        }
      //----------Y=6----------
      if (leds[X][1] == 6){
          LED116();
        }
      //----------Y=7----------
      if (leds[X][1] == 7){
          LED117();
        }
      //----------Y=8----------
      if (leds[X][1] == 8){
          LED118();
        }
      //----------Y=9----------
      if (leds[X][1] == 9){
          LED119();
        }
      //----------Y=10----------
      if (leds[X][1] == 10){
          LED1110();
        }
      }
      X ++;
      if (X == a){
        X = 0;
      }
      
      delay(1);
    }
  }
  
  


void LED11(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED12(){
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, OUTPUT);      //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
  }
void LED13(){ 
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);     //row 3
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED14(){
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);     //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED15(){
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);     //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED16(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED17(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED18(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED19(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED110(){  
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED21(){
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, INPUT);    //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED22(){
  pinMode(LED_1, INPUT);    //row 1
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, OUTPUT);    //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED23(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED24(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED25(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED26(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED27(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED28(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED29(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED210(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);      //row 3
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED31(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED32(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);     //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED33(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
  void LED34(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
  void LED35(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED36(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED37(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED38(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED39(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED310(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);      //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED41(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED42(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED43(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED44(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED45(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED46(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED47(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED48(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED49(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED410(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED51(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED52(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED53(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED54(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED55(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED56(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED57(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED58(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED59(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED510(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED61(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED62(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED63(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED64(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED65(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED66(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED67(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED68(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED69(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED610(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED71(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED72(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED73(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED74(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED75(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED76(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);  
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED77(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED78(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED79(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED710(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, HIGH);
  pinMode(LED_8, INPUT);      //row 8  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED81(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED82(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED83(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED84(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED85(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED86(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED87(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);  
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED88(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED89(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED810(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, HIGH);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED91(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED92(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED93(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED94(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED95(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED96(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED97(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED98(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, INPUT);     //row 11
}
void LED99(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, INPUT);     //row 11
}
void LED910(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, HIGH);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, LOW);
}
void LED101(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED102(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED103(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED104(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED105(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED106(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED107(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED108(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED109(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, HIGH);
  pinMode(LED_11, INPUT);     //row 11
}
void LED1010(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED111(){  
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED112(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED113(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED114(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED115(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED116(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED117(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, OUTPUT);      //row 7
  digitalWrite(LED_7, LOW);
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED118(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, OUTPUT);      //row 8
  digitalWrite(LED_8, LOW);
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED119(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, OUTPUT);      //row 9
  digitalWrite(LED_9, LOW);
  pinMode(LED_10, INPUT);     //row 10
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
void LED1110(){  
  pinMode(LED_1, INPUT);     //row1
  pinMode(LED_2, INPUT);      //row2
  pinMode(LED_3, INPUT);      //row3
  pinMode(LED_4, INPUT);     //row 4
  pinMode(LED_5, INPUT);      //row 5
  pinMode(LED_6, INPUT);      //row 6
  pinMode(LED_7, INPUT);      //row 7
  pinMode(LED_8, INPUT);      //row 8
  pinMode(LED_9, INPUT);      //row 9
  pinMode(LED_10, OUTPUT);     //row 10
  digitalWrite(LED_10, LOW);
  pinMode(LED_11, OUTPUT);     //row 11
  digitalWrite(LED_11, HIGH);
}
