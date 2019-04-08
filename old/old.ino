void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
