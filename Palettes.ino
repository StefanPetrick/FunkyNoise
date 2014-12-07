/*
Some color palettes. 
Includes the predifined FastLED palettes and custom ones.

PaletteRed()
Pal()
-----------------------------------------------------------------
*/


// A red-black palette.

void PaletteRed() {
  currentPalette = CRGBPalette16( 
  CHSV( 0, 255, 255 ), 
  CHSV( 0, 255, 0   ), 
  CHSV( 0, 255, 0   ),
  CHSV( 0, 255, 255)); 
}

void PaletteCustom() {
  currentPalette = CRGBPalette16( 
  CHSV( 40, 255, 255 ), 
  CHSV( 40, 255, 255   ), 
  CHSV( 0, 255, 0   ),
  CHSV( 0, 255, 255)); 
}

// Hopefully uses by any animation. Set here
// a global color palette.
// All the the predifined FastLED palettes:

void Pal() {
  //PaletteRed();
  //PaletteCustom();
  //currentPalette = CloudColors_p;
  //currentPalette = LavaColors_p;
  //currentPalette = OceanColors_p;
  currentPalette = ForestColors_p;
  //currentPalette = RainbowColors_p;
  //currentPalette = RainbowStripeColors_p;
  //currentPalette = PartyColors_p;
  //currentPalette = HeatColors_p;
}
  
  
