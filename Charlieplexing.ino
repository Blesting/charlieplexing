

const int LED_1 = 13;     //LED row 1
const int LED_2 = 12;     //LED row 2    
const int LED_3 = 11;     //LED row 3
const int LED_4 = 10;     //LED row 4
const int LED_5 = 9;     //LED row 5
const int LED_6 = 8;     //LED row 6

int leds[4][5]={{3,1,1,1},{1,1,1,1},{3,2,1,1},{1,2,1,1}};
int forloop = 200; 
int X = 0;
int a;
int xMax = 6;
int xMin = 1;
int yMax = 5;
int yMin = 1;

void setup() 
{
  Serial.begin(9600);
}

void loop(){
  a = sizeof (leds) / sizeof (leds[0]);
  taend_LEDs();
  diagonal_movement();    
  forloop = forloop +2;
  if (forloop == 202){
    forloop = 200;
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
      }
      else if (leds[i][0]==xMin){
        leds[i][3] = 1;
      }
      
      if (X == 0){
        X = 1;
      }
      else if (X == 1){
        X = 0;
      }
    }
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
      }
      X ++;
      if (X == a){
        X = 0;
      }
      
      delay(1);
    }
}
  
void tidligere_movement(){
  for (int i = 0; i <= a; i++) { 
    leds[i][1] = leds[i][1]+1;
    if (leds[i][1] == yMax+1){
      leds[i][1] = yMin-1;
      leds[i][0] = leds[i][0]+1;
      if (leds[i][0] == xMax+1){
        leds[i][0] = xMin;
      }
    }
  }
}

void tidligere_movement_OUTDATED(){
  for (int i = 0; i <= 1; i++) { 
    leds[X][1] = leds[X][1]+1;
    leds[X][0] = leds[X][0]+1;
    if (leds[X][1] == 5){
      leds[X][1] = 1;
      if (leds[X][0] == 1){
        leds[X][0] = 2;
      }
      else if (leds[X][0] == 2){
        leds[X][0] = 3;
      }
      else if (leds[X][0] == 3){
        leds[X][0] = 4;
      }
      else if (leds[X][0] == 4){
        leds[X][0] = 5;
      }
      else if (leds[X][0] == 5){
        leds[X][0] = 1;
      }
      }
    if (X == 0){
      X = 1;
    }
    else if (X == 1){
      X = 0;
    }
  }
}
  
void LED11(){  
  //turn on LED L1
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED12(){
  //turn on LED L2
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);   
  pinMode(LED_3, OUTPUT);      //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}
  
void LED13(){ 
  //turn on LED L3
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);     //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED14(){
  //turn on LED L3
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);     //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED15(){
  //turn on LED L3
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);     //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED21(){
  //turn on LED L4
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, INPUT);    //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}
  
void LED22(){
  //turn on LED L5
  pinMode(LED_1, INPUT);    //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, OUTPUT);    //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}
  
void LED23(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED24(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED25(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED31(){  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED32(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED33(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

  void LED34(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

  void LED35(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED41(){  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED42(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED43(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED44(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED45(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED51(){  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED52(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED53(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}
  
void LED54(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, INPUT);      //row 6
  digitalWrite(LED_6, LOW);
}
  
void LED55(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, HIGH);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, LOW);
}

void LED61(){  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
}

void LED62(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
}

void LED63(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
}

void LED64(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, INPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
}

void LED65(){  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  pinMode(LED_5, OUTPUT);      //row 5
  digitalWrite(LED_5, LOW);
  pinMode(LED_6, OUTPUT);      //row 6
  digitalWrite(LED_6, HIGH);
}
