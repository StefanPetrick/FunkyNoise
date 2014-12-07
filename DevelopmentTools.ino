/*
Some useful functions for developing and debugging.
 Contains some magic numbers and is written specificly
 for the SmartMatrix.
 
 Providing the following functions:
 
 ShowPalette
 Show3Layers
 -----------------------------------------------------------------
 */


// Show the current palette.

void ShowPalette() {
  for(int i = 0; i < NUM_LEDS; i++) {
    byte color = i / (NUM_LEDS / 256);
    byte bri = 255; 
    leds[i] = ColorFromPalette( currentPalette, color, bri );
  }
}


// Show 3 small 16x16 versions of the 3 noise planes
// to keep track what is going on where when.
// Useful to check before you start merging layers.
// Expects a 32x32 matrix to be the output device.


void Show3Layers() {
  for(uint8_t i = 0; i < 16; i++) {
    for(uint8_t j = 0; j < 16; j++) {
      leds[XY(i,j)] = ColorFromPalette( currentPalette, noise[0][i*2][j*2] , 255 );
    }
  }
  for(uint8_t i = 16; i < 32; i++) {
    for(uint8_t j = 0; j < 16; j++) {
      leds[XY(i,j)] = ColorFromPalette( currentPalette, noise[1][(i-16)*2][j*2] , 255 );
    }
  }
  for(uint8_t i = 0; i < 16; i++) {
    for(uint8_t j = 16; j < 32; j++) {
      leds[XY(i,j)] = ColorFromPalette( currentPalette, noise[2][i*2][(j-16)*2] , 255 );
    }
  }
}


void ShowParameters(byte layer) {
  Serial.print("L");
  Serial.print(layer);
  Serial.print(" ");
  Serial.print(x[layer]); 
  Serial.print(" "); 
  Serial.print(y[layer]); 
  Serial.print(" "); 
  Serial.print(z[layer]); 
  Serial.print(" ");
  Serial.print(scale_x[layer]); 
  Serial.print(" ");
  Serial.print(scale_y[layer]); 
  Serial.print(" ");   
}

// output 8 bit of the noise value of noise[layer][0][0]
void SerialWriteNoiseValue(byte layer) {
  Serial.print("Layer");
  Serial.print(layer);
  Serial.print(": ");
  Serial.print(noise[layer][0][0]);
  Serial.print("  ");
}

