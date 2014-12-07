/*
A bunch of animations demonstrating how to creatively combine
simple functions for particulary stunning effects.
 
 NoiseInNoise8()
 BasicNoise16()
 MirroredNoise16()
 RedClouds()
 NoiseIn2Layers()
 
 Noise3Layer
 
 Lavalamp1 (red lava)
 Lavalamp2 (red tiger structure)
 -----------------------------------------------------------------
 */


// NoiseInNoise() draws a constrained 8-bit noise.  
// The areas below a threshold are filled with the same
// noise data - just rotated and with a different color repeating
// frequency.
// 108 fps

/*
void NoiseInNoise8() {
 
 // move in the noise space
 x++;
 z++;
 scale = 23;
 
 // calculate the noise array
 fillnoise8();
 
 for(int i = 0; i < kMatrixWidth; i++) {
 for(int j = 0; j < kMatrixHeight; j++) {
 // if noise value is under a magic threshold
 // fill with a reversed noise mapping
 if (noise[j][i] < 128) {
 leds[XY(i,j)] = CHSV( 3 * noise[j][i], 255, noise[i][j] );
 }
 // if the noise value is above
 // fill with the origin mapping
 else {
 leds[XY(i,j)] = CHSV( 4 * noise[i][j], 255, noise[i][j] );
 }
 }
 }
 }
 
 
 // BasicNoise16() draws a classic noise space with a rainbow stripes palette.
 // A colorfull noise streaming to the left.
 // 108 fps
 
 void BasicNoise16() {
 
 // move within the noise space
 x_0 += 100;
 z_0 += 100;
 scale_0 = 4000;
 PaletteRainbowStripes();
 
 // calculate the noise array
 fillnoise16();
 
 for(int i = 0; i < kMatrixWidth; i++) {
 for(int j = 0; j < kMatrixHeight; j++) {
 
 // map the noise values down
 uint16_t index = noise16[i][j] >> 8;
 uint16_t   bri = noise16[i][j] >> 8;
 // assign a color from the HSV space
 CRGB color = ColorFromPalette( currentPalette, index, bri);
 
 leds[XY(i,j)] = color;
 }
 }
 }
 
 
 //
 
 void MirroredNoise16() {
 
 // move within the noise space
 x_0 += 100;
 z_0 += 100;
 scale_0 = 4000;
 PaletteRainbowStripes();
 
 // calculate the noise array
 fillnoise16();
 
 for(int i = 0; i < kMatrixWidth; i++) {
 for(int j = 0; j < kMatrixHeight; j++) {
 
 // map the noise values down
 uint16_t index = ((noise16[i][j] >> 8) + (noise16[kMatrixWidth-1-i][j] >> 8))/2;
 uint16_t   bri = 255;
 // assign a color from the HSV space
 CRGB color = ColorFromPalette( currentPalette, index, bri);
 
 leds[XY(i,j)] = color;
 }
 }
 }
 
 
 
 // RedClouds() draws a constrained noise space with a palette 
 // softening the edges.
 // Upstreaming red clouds.
 // 108 fps
 
 void RedClouds() {
 
 // clear the screenbuffer
 CLS();
 
 // move within the noise space
 x_0 = beatsin16(1)*10;
 y_0 = y_0 + 1000;
 z_0 = z_0 + 100;
 scale_0 = 6000;
 
 // calculate the noise array
 fillnoise16();
 
 for(int i = 0; i < kMatrixWidth; i++) {
 for(int j = 0; j < kMatrixHeight; j++) {
 
 // map the noise values down to a byte range
 uint16_t index = noise16[i][j] >> 8;
 uint16_t   bri = 255;
 // assign a color depending on the actual palette
 CRGB color = ColorFromPalette( currentPalette, index, bri);
 
 // draw only the part lower than the threshold
 if (index < 128) { 
 leds[XY(i,j)] = color;
 }
 }
 }
 }
 
 
 void NoiseIn2Layers() {
 
 PaletteRainbowStripes();
 //Pal();
 
 x_0 -= 100;
 z_0 += 100;
 scale_0 = 2000;
 
 FillNoiseLayer0();
 
 x_1 = beatsin16(4, 0, 100000);
 y_1 = beatsin16(3, 0, 100000);
 z_1 += 300;
 scale_1 = 5000;
 
 FillNoiseLayer1();
 
 for(int i = 0; i < kMatrixWidth; i++) {
 for(int j = 0; j < kMatrixHeight; j++) {
 
 // map the noise values down
 uint16_t index = ((noise0[i][j] >> 8) + (noise1[i][j] >> 8)) / 2;
 uint16_t   bri = index;
 // assign a color from the HSV space
 CRGB color = ColorFromPalette( currentPalette, index-60, bri);
 
 leds[XY(i,j)] = color;
 }
 }
 
 //monitor one pixel
 leds[XY(((noise0[0][0] >> 8) + (noise1[0][0] >> 8))/16,0)] = 0xFFFFFF;
 }
 */

// one layer 16 bit noise, 108 fps

void SimpleNoise() {
  Pal();

  FillNoise(0);

  x[0] += 1000;
  y[0] += 1000;
  z[0] = 7000;
  scale_x[0] = 4000;
  scale_y[0] = 6000;

  for(uint8_t i = 0; i < kMatrixWidth; i++) {
    for(uint8_t j = 0; j < kMatrixHeight; j++) {

      // map the noise values down to a byte range
      uint8_t color = noise[0][i][j] >> 8;
      uint8_t   bri = color;
      // assign a color depending on the actual palette
      CRGB pixel = ColorFromPalette( currentPalette, color*2, bri );

      leds[XY(i,j)] = pixel;
    }
  }
}

// 2 layer 16 bit noise, 72 fps

void SimpleNoise2Layers() {

  Pal();

  x[0] += 1000;
  y[0] += 1000;
  z[0] = 7000;
  scale_x[0] = 4000;
  scale_y[0] = 6000;
  FillNoise(0);  

  x[1] -= 500;
  y[1] -= 100;
  z[1] = 3000;
  scale_x[1] = 3000;
  scale_y[1] = 2000;
  FillNoise(1);

  for(uint8_t i = 0; i < kMatrixWidth; i++) {
    for(uint8_t j = 0; j < kMatrixHeight; j++) {

      // map the noise values down to a byte range
      uint8_t color = ((noise[0][i][j] >> 8) + (noise[1][i][j] >> 8)) / 2;
      uint8_t   bri = color;
      // assign a color depending on the actual palette
      CRGB pixel = ColorFromPalette( currentPalette, color*2, bri );

      leds[XY(i,j)] = pixel;
    }
  }
}

// 3 layer 16 bit noise, 54 fps

void Noise3Layer() {

  Pal();

  x[0] = 5* beatsin16(3, 200, 64000);
  y[0] += 1000;
  z[0] = 7000;
  scale_x[0] = 2000;
  scale_y[0] = 2000;
  FillNoise(0);  

  x[1] -= 500;
  y[1] = 2 * beatsin16(2, 200, 64000);
  ;
  z[1] = 3000;
  scale_x[1] = 3000;
  scale_y[1] = 2000;
  FillNoise(1);

  x[2] -= 100;
  y[2] -= 100;
  z[2] += 100;
  scale_x[2] = beatsin16(15, 200, 3000);
  scale_y[2] = beatsin16(17, 100, 2000);
  FillNoise(2);

  /*
  for(uint8_t i = 0; i < kMatrixWidth; i++) {
   for(uint8_t j = 0; j < kMatrixHeight; j++) {
   
   // map the noise values down to a byte range
   uint8_t color = ( (noise[0][i][j] >> 8) 
   + (noise[1][i][j] >> 8)
   + (noise[2][i][j] >> 8) ) / 3;
   
   uint8_t   bri = color;
   
   // assign a color depending on the actual palette
   CRGB pixel = ColorFromPalette( currentPalette, color*3, bri );
   
   leds[XY(i,j)] = pixel;
   }
   }
   */
  Show3Layers();  
}

//Lavalamp1
//works good with the RedBlack palette
void Lavalamp1() {  
  //Pal();
  
  PaletteRed();
  colorshift = 0;

  x[0] = beatsin16(3, 200, 64000);
  y[0] += 100;
  z[0] = 7000;
  scale_x[0] = 6000;
  scale_y[0] = 8000;
  FillNoise(0); 
 
   x[1] = beatsin16(2, 200, 64000);
  y[1] += 130;
  z[1] = 7000;
  scale_x[1] = 6000;
  scale_y[1] = 8000;
  FillNoise(1);   

  x[2] = beatsin16(4, 200, 6400);
  y[2] += 1000;
  z[2] = 3000;
  scale_x[2] = 7000;
  scale_y[2] = 8000;
  FillNoise(2);

  noisesmoothing = 200;

  //Show3Layers();
  MergeMethod1(2);
}

//designed for black red palette
void Lavalamp2() {  
  //Pal();
  PaletteRed();
  
  noisesmoothing = 200;

  x[0] = beatsin16(3, 200, 64000);
  y[0] = beatsin16(4, 200, 64000);
  z[0] = 7000;
  scale_x[0] = beatsin16(2, 6000, 8000);
  scale_y[0] = beatsin16(1, 4000, 12000);
  FillNoise(0);  
  
    x[1] = beatsin16(5, 200, 64000);
  y[1] = beatsin16(6, 200, 64000);
  z[1] = 6000;
  scale_x[1] = 6000;
  scale_y[1] = 8000;
  FillNoise(1);  

  x[2] = beatsin16(4, 200, 6400);
  y[2] += 1000;
  z[2] = 3000;
  scale_x[2] = 7000;
  scale_y[2] = 8000;
  FillNoise(2);
  //CorrectBrightness();


  
  //colorshift = beatsin8(5, 0, 255);
  
  //Show3Layers();
  MergeMethod1(2);
  
}



void Lavalamp3() { 
 
  noisesmoothing = 40;
  Pal();
  //PaletteRed();

  //x[0] = beatsin16(3, 200, 64000);
  y[0] += 100;
  z[0] = 7000;
  scale_x[0] = 6000;
  scale_y[0] = 6000;
  FillNoise(0);  

  //x[1] = beatsin16(4, 200, 64000);
  y[1] += 200;
  z[1] = 3000;
  scale_x[1] = 7000;
  scale_y[1] = 8000;
  FillNoise(1);
  //CorrectBrightness();

  //x[2] += 2500;
  y[2] += 250;
  z[2] = 6000;
  scale_x[2] = 20000;
  scale_y[2] = 8000;
  FillNoise(2);  
  
  //colorshift = beatsin8(1, 0, 255);
  
  //Show3Layers();
  MergeMethod1(1);
  
}


void Lavalamp4() { 
  
  currentPalette = CRGBPalette16( 
  CHSV( 0, 255, 0 ), 
  CHSV( 0, 255, 255   ), 
  CHSV( 0, 255, 0   ),
  CHSV( 160, 255, 255)); 
 
  noisesmoothing = 150;
  //Pal();
  //PaletteRed();

  //x[0] = beatsin16(3, 200, 64000);
  y[0] += 100;
  z[0] = 7000;
  scale_x[0] = 6000;
  scale_y[0] = 6000;
  FillNoise(0);  

  //x[1] = beatsin16(4, 200, 64000);
  y[1] += 200;
  z[1] = 3000;
  scale_x[1] = 7000;
  scale_y[1] = 8000;
  FillNoise(1);
  //CorrectBrightness();

  //x[2] += 2500;
  y[2] += 250;
  z[2] = 6000;
  scale_x[2] = 20000;
  scale_y[2] = 8000;
  FillNoise(2);  
  
  //colorshift = beatsin8(1, 0, 255);
  
  //Show3Layers();
  MergeMethod1(2);
  
}


void Lavalamp5() { 
  
  currentPalette = CRGBPalette16( 
  CHSV( 0, 255, 0 ), 
  CHSV( 0, 255, 255   ), 
  CHSV( 160, 255, 255   ),
  CHSV( 160, 255, 0)); 
 
  noisesmoothing = 50;
  //Pal();
  //PaletteRed();

  //x[0] = beatsin16(3, 200, 64000);
  y[0] += 1000;
  z[0] = 7000;
  scale_x[0] = beatsin16(3, 1000, 20000);;
  scale_y[0] = 6000;
  FillNoise(0);  

  //x[1] = beatsin16(4, 200, 64000);
  y[1] += 2000;
  z[1] = 3000;
  scale_x[1] = beatsin16(4, 1000, 20000);
  scale_y[1] = 8000;
  FillNoise(1);
  //CorrectBrightness();

  //x[2] += 2500;
  y[2] += 3000;
  z[2] = 6000;
  scale_x[2] = beatsin16(5, 1000, 20000);
  scale_y[2] = 8000;
  FillNoise(2);  
  
  //colorshift = beatsin8(1, 0, 255);
  
  //Show3Layers();
  MergeMethod2(3);
  //ShowPalette();
  
}

void Constrained1() { 
 
  noisesmoothing = 100;
  colorshift = 0;

  x[0] += 2000;
  //y[0] += 1000;
  //z[0] = 7000;
  scale_x[0] = 6000;
  scale_y[0] = 6000;
  FillNoise(0);  

  x[1] -= 2000;
  //y[1] -= 1000;
  //z[1] = 3000;
  scale_x[1] = 6000;
  scale_y[1] = 6000;
  FillNoise(1);
  
  CLS();
  
  // define a palette used for layer 0
  currentPalette = CRGBPalette16( 
  CHSV( 0, 255, 0   ), 
  CHSV( 0, 255, 0 ),
  CHSV( 0, 255, 255 ),
  CHSV( 160, 255, 0   ));

  // map layer 0 (red) for noise values between 100 and 200
  ConstrainedMapping( 0, 100, 200, 1);
  
  // palette for the second layer  
  currentPalette = CRGBPalette16( 
  CHSV( 0, 255, 0   ), 
  CHSV( 0, 255, 0 ),
  CHSV( 160, 255, 255 ),
  CHSV( 160, 255, 0   ));

  // map layer 1 (blue) for noise values between 100 and 200
  ConstrainedMapping( 1, 100, 200, 1);

}

void RelativeMotion1() {  
  
  currentPalette = CRGBPalette16( 
  CHSV( 0,   255, 0   ), 
  CHSV( 80,  255, 255 ),
  CHSV( 60,   255, 255 ),
  CHSV( 0, 255, 0   ));
  
  colorshift = beatsin8(10, 0, 100);
  noisesmoothing = 100;

  x[0] = 5 * beatsin16(2, 15000, 40000);
  y[0] = 5 * beatsin16(3, 15000, 40000);
  z[0] += 100;
  scale_x[0] = 6000 + beatsin16(30, 0, 4000);
  scale_y[0] = 8000 + beatsin16(27, 0, 4000);
  FillNoise(0);  
  
  x[1] = x[0] + (5 * beatsin16(30, 0, 10000)) - 25000;
  y[1] = y[0] + (5 * beatsin16(40, 0, 10000)) - 25000;;
  z[1] += 100;
  scale_x[1] = 6000 + beatsin16(30, 0, 3000);
  scale_y[1] = 8000 + beatsin16(27, 0, 3000);
  FillNoise(1);  
  
  //Show3Layers();
  
  MergeMethod3(1);
}

void RelativeMotion2() {  
  
  currentPalette = CRGBPalette16( 
  CHSV( 80,   255, 255   ), 
  CHSV( 160,  255, 255 ),
  CHSV( 160,   255, 255 ),
  CHSV( 80, 255, 255   ));
  
  colorshift = beatsin8(10, 0, 100);
  noisesmoothing = 100;

  x[0] = 5 * beatsin16(2, 15000, 40000);
  y[0] = 5 * beatsin16(3, 15000, 40000);
  z[0] += 100;
  scale_x[0] = 6000 + beatsin16(30, 0, 4000);
  scale_y[0] = 8000 + beatsin16(27, 0, 4000);
  FillNoise(0);  
  
  x[1] = x[0] + (5 * beatsin16(30, 0, 10000)) - 25000;
  y[1] = y[0] + (5 * beatsin16(40, 0, 10000)) - 25000;;
  z[1] += 100;
  scale_x[1] = 6000 + beatsin16(30, 0, 3000);
  scale_y[1] = 8000 + beatsin16(27, 0, 3000);
  FillNoise(1);  
  
  //Show3Layers();
  
  MergeMethod3(1);
}


