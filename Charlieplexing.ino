

const int LED_1 = 13;     //LED row 1
const int LED_2 = 12;     //LED row 2    
const int LED_3 = 11;     //LED row 3
const int LED_4 = 10;     //LED row 4

int leds[2][3]={{1,1},{3,1}};
int forloop = 200; 
int X = 0;

void setup() 
{
  
}

void loop()
{
  for (int i = 0; i <= forloop; i++) {  
    //-----------------------X = 1-----------------------
    if (leds[X][0] == 1){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED11();
          delay(1);
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED12();
          delay(1);
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED13();
          delay(1);
        }
      }
    //-----------------------X = 2-----------------------
    else if (leds[X][0] == 2){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED21();
          delay(1);
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED22();
          delay(1);
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED23();
          delay(1);
        }
      }
    //-----------------------X = 3-----------------------
    else if (leds[X][0] == 3){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED31();
          delay(1);
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED32();
          delay(1);
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED33();
          delay(1);
        }
      }
      //-----------------------X = 4-----------------------
    else if (leds[X][0] == 4){
      //----------Y=1----------
      if (leds[X][1] == 1){
          LED41();
          delay(1);
        }
      //----------Y=2----------
      if (leds[X][1] == 2){
          LED42();
          delay(1);
        }
      //----------Y=3----------
      if (leds[X][1] == 3){
          LED43();
          delay(1);
        }
      }
    X ++;
    if (X == 2){
      X = 0;
    }
    }

    leds[X][1] = leds[X][1]+1;
    if (leds[X][1] == 4){
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
        leds[X][0] = 1;
      }
      
      }

    forloop = forloop +5;
    if (forloop == 300){
      forloop = 200;
    }
    
    

    
  }
  
  
  
void LED11()
{  
  //turn on LED L1
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);      //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
}
void LED12()
{
  //turn on LED L2
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);   
  pinMode(LED_3, OUTPUT);      //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  }
void LED13()
{ 
  //turn on LED L3
  pinMode(LED_1, OUTPUT);      //row 1
  digitalWrite(LED_1, HIGH);
  pinMode(LED_2, INPUT);     //row 2
  digitalWrite(LED_2, LOW);  
  pinMode(LED_3, INPUT);     //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
}
void LED21()
{
  //turn on LED L4
  pinMode(LED_1, OUTPUT);     //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);    //row 2
  digitalWrite(LED_2, HIGH);  
  pinMode(LED_3, INPUT);    //row 3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  }
void LED22()
{
  //turn on LED L5
  pinMode(LED_1, INPUT);    //row 1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row 2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, OUTPUT);    //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, INPUT);      //row 4
  digitalWrite(LED_4, LOW);
  }
void LED23()
{  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, HIGH);
  pinMode(LED_3, INPUT);     //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);      //row 4
  digitalWrite(LED_4, LOW);
  }
  void LED31()
{  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  }
  void LED32()
{  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);     //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, INPUT);     //row 4
  digitalWrite(LED_4, LOW);
  }
  void LED33()
{  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, HIGH);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, LOW);
  }
  void LED41()
{  
  //turn on LED L6
  pinMode(LED_1, OUTPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  }
  void LED42()
{  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, OUTPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, INPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  }
  void LED43()
{  
  //turn on LED L6
  pinMode(LED_1, INPUT);     //row1
  digitalWrite(LED_1, LOW);
  pinMode(LED_2, INPUT);      //row2
  digitalWrite(LED_2, LOW);
  pinMode(LED_3, OUTPUT);      //row3
  digitalWrite(LED_3, LOW);
  pinMode(LED_4, OUTPUT);     //row 4
  digitalWrite(LED_4, HIGH);
  }

