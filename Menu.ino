void RunAnimationDependingOnPgm() {
  switch (pgm) {              

  case 0:
    MirroredNoise();     
    break;

  case 1:
    RedClouds();     
    break;

  case 2:
    Lavalamp1();     
    break;

  case 3:
    Lavalamp2();     
    break;

  case 4:
    Lavalamp3();     
    break;

  case 5:
    Lavalamp4();     
    break;

  case 6:
    Lavalamp5();     
    break;

  case 7:
    Constrained1();     
    break;

  case 8:
    RelativeMotion1();     
    break;

  case 9:
    Water();     
    break;

  case 10:
    Bubbles1();     
    break;
    
  case 11:
    TripleMotion();     
    break;  
    
      case 12:
    CrossNoise();     
    break; 
 
     case 13:
    CrossNoise2();     
    break;    

    case 14:
    RandomAnimation();     
    break;    
   
  
  }
}

void ReadButtons () {
  byte NUM_PGM = 14;
  byte DEBOUNCE_DELAY = 100;
  byte STEP_WIDTH = 64;
  button1 = digitalRead(17);
  button2 = digitalRead(18);
  button3 = digitalRead(19);

  // if any button pressed
  if (button1 == LOW || button2 == LOW || button3 == LOW) {

    if (button1 == LOW) { // change (increment) mode
      mode ++;
      delay(DEBOUNCE_DELAY);
      // 0 pgm
      // 1 spd
      // 2 bri
      // 3 red
      // 4 green
      // 5 blue
      // 6 reset
      if (mode == 7) mode = 0;
    }

    if (mode == 0 && button2 == LOW) { // pgm up
      pgm++;
      delay(DEBOUNCE_DELAY);
      if (pgm == NUM_PGM+1) pgm = 0;
    }
    if (mode == 0 && button3 == LOW) { // pgm down
      pgm--;
      delay(DEBOUNCE_DELAY);
      if (pgm == 255) pgm = NUM_PGM;
    }
    if (mode == 1 && button2 == LOW) { // spd up
      spd++;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 1 && button3 == LOW) { // spd down
      spd--;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 2 && button2 == LOW) { // bri up
      brightness = brightness + STEP_WIDTH;
      LEDS.setBrightness(brightness);
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 2 && button3 == LOW) { // bri down
      brightness = brightness - STEP_WIDTH;
      LEDS.setBrightness(brightness);
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 3 && button2 == LOW) { // red up
      red_level = red_level + STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 3 && button3 == LOW) { // red down
      red_level = red_level - STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 4 && button2 == LOW) { // green up
      green_level = green_level + STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 4 && button3 == LOW) { // green down
      green_level = green_level - STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 5 && button2 == LOW) { // blue up
      blue_level = blue_level + STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 5 && button3 == LOW) { // blue down
      blue_level = blue_level - STEP_WIDTH;
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 6 && button2 == LOW) { // reset
      BasicVariablesSetup();
      delay(DEBOUNCE_DELAY);
    }
    if (mode == 6 && button3 == LOW) { // reset
      BasicVariablesSetup();
      delay(DEBOUNCE_DELAY);
    }
  }
}

