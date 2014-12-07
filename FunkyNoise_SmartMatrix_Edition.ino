/*
         FunkyNoise 1.0
 ---------------              
 A Collection Of 
 Animations 
 And Helper Functions 
 
 for two dimensional led effects
 on the 32x32 SmartMatrix.
 
 Tested on PJRCs Teensy 3.1 @ 96Mhz.
 
 With explicit thanks to Daniel Garcia,
 Mark Kriegsmann and Louis Beavot.
 
 Written by Stefan Petrick 2014.
 hello(at) stefan-petrick . de
 
 ...
 
 Download the required software first:
 FastLED 3.0
 SmartMatrix
 Arduino IDE 1.0.6
 Teensyduino 1.2
 */

#include<SmartMatrix.h>
#include<FastLED.h>

// the size of your matrix
#define kMatrixWidth  32
#define kMatrixHeight 32

// used in FillNoise for central zooming
byte CentreX =  (kMatrixWidth / 2) - 1;
byte CentreY = (kMatrixHeight / 2) - 1;

// set up the framebuffer
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds[kMatrixWidth * kMatrixHeight];

// a place to store the color palette
CRGBPalette16 currentPalette;

// can be used for palette rotation
// "colorshift"
byte colorshift;

// The coordinates for 3 16-bit noise spaces.
#define NUM_LAYERS 3

uint32_t x[NUM_LAYERS];
uint32_t y[NUM_LAYERS];
uint32_t z[NUM_LAYERS];
uint32_t scale_x[NUM_LAYERS];
uint32_t scale_y[NUM_LAYERS];

// a 3dimensional array used to store the calculated 
// values of the different noise planes
uint8_t noise[NUM_LAYERS][kMatrixWidth][kMatrixHeight];


uint8_t noisesmoothing;


void setup() {

  Serial.begin(115200);
  LEDS.addLeds<SMART_MATRIX>(leds,NUM_LEDS);
  FastLED.setDither(0);
  pSmartMatrix->setColorCorrection(cc48);
  //LEDS.setBrightness(32);
  InitCoordinates();
}


void loop() {
  
  //ShowAll(500);

  RelativeMotion2();
  ShowFrame();

} 













