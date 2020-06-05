#include <Arduino.h>
#include <FastLED.h>
//#include <string>
//#include "5x5_font.h"
#include "Dots5x5font.h"


#include <Tone32.h>
#define BUZZER_PIN BUZZER
#define BUZZER_CHANNEL 0


//using namespace std;
#define DEBUG true

// LED Matrix Definition
#define DATA_PIN 4  // ESP2866 D4 = PIN 4
#define NUM_ROWS 5
#define NUM_COLUMNS 5  // If this is odd, you might flip the text upside-down due to the 'snaking' LED handling
#define START_ROW 0
#define NUM_LEDS (NUM_ROWS * NUM_COLUMNS)
#define BRIGHTNESS 32
#define ORIENTATION 0  // 0 = pixel 0 at bottom-right, 1 = pixel 0 at top-right, 2 = pixel 0 at top-left, 3 = pixel 0 at bottom-left

// Font Definition (note: font data must be 8-bits wide even if the glyphs are narrower than this)
#define FONT_WIDTH 5
#define FONT_HEIGHT 5
#define LSB_FONT false  // Set to true if the font data has the left-most display pixel in the least-significant (right-most) bit

// Scroller Parameters
//#define WAVY false           // 'true' applies the wave distortion to the scroll, 'false' means a simple straight-line scroller
//#define DISTORT_FACTOR 3     // Additional wave step per display column -- larger means more compressed waveform, 0 for a 'bouncing straight-line' scroller
//#define WAVE_START_INDEX 0   // Position to start in wave function (0-255)
//#define WAVE_SPEED_FACTOR 8  // Increment for the wave, larger means faster bounces
//#define SCROLL_STEP 1        // Positive scrolls 'normally', negative scrolls 'backwards'
#define LOOP_DELAY 10        // Milliseconds to wait between full matrix updates
#define INITIAL_HUE 0        // Hue to set scroller to on start
#define HUE_INCREMENT 1      // 0 for single colour, higher numbers cycle colours faster

// Define the array of leds
CRGB leds[NUM_LEDS];
static const String sMessage = "0123456789 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz +-x/!@#$%^&*(!";

//Original matrix positions
int mapLED[] ={
     0, 1, 2, 3, 4,
     5, 6, 7, 8, 9,
    10,11,12,13,14,
    15,16,17,18,19,
    20,21,22,23,24
    };
//Rotated left 90 degree    
int mapLED_Left90[] ={
    20,15,10, 5, 0,
    21,16,11, 6, 1,
    22,17,12, 7, 2,
    23,18,13, 8, 3,
    24,19,14, 9, 4
    };

/*
static const string scrollyMessage =
    "      "
    "   DEMO OF BASIC SCROLLY TEXT MESSAGES"
    "   THIS RUNS COMFORTABLY ON A NODE MCU AND CAN SUPPORT 50+ FPS ON A 512-PIXEL LED MATRIX DISPLAY."
    "   8x8 AND 6x6 FONTS ARE INCLUDED, with lower-case text, as well as various punctuation characters!"
    "   $ % ^ & * ( ) - = _ + [ ] { } ' @ # ~ / ? | \\"
    "   No non-English support... sorry!"
    "          ";
*/
static uint8_t _hue = INITIAL_HUE;
//uint8_t yPosIndex = WAVE_START_INDEX;
int matrixBufferWidth;
int bufferCharacterWidth;
int scrollLengthInPixels;
int currentScrollPosition = 0;

// This function translates from x/y coordinates to an index in the LED array.
// It assumes 'snaking' pixel arrangement
int getPixelStripPosition(int x, int y) {
    int index;
    if (x < 0 || x > NUM_COLUMNS || y < 0 || y > NUM_ROWS) {
        index = -1;
    } else {
        if (ORIENTATION == 0) {  // Pixel 0 at bottom-right
            if (x % 2 == 0) {    // Even rows
                index = (x + 1) * NUM_ROWS - y - 1;
            } else {
                index = x * NUM_ROWS + y;  // Odd rows
            }
            index = NUM_LEDS - 1 - index;
        } else if (ORIENTATION == 1) {  // Pixel 0 at top-right
            if (y % 2 == 0) {           // Even rows
                index = ((y + 1) * NUM_COLUMNS) - x - 1;
            } else {
                index = y * NUM_COLUMNS + x;  // Odd rows
            }
        } else if (ORIENTATION == 2) {  // Pixel 0 at top-left
            if (x % 2 == 0) {           // Even columns
                index = x * NUM_ROWS + y;
            } else {  // Odd columns
                index = (x + 1) * NUM_ROWS - y - 1;
            }
        } else if (ORIENTATION == 3) {  // Pixel 0 at bottom-left
            if (y % 2 == 0) {           // Even rows
                index = y * NUM_COLUMNS + x;
            } else {
                index = (y + 1) * NUM_COLUMNS - x - 1;  // Odd rows
            }
            index = NUM_LEDS - 1 - index;
        }
        if (index < 0 || index >= NUM_LEDS) {
            index = -1;
        }
    }
    return index;
}

// Fill the strip line-by-line to test orientation and pixel operation
void testMatrix(CRGB colour) {
    memset(leds, 0, NUM_LEDS * 3);
    FastLED.show();
    for (int y = 0; y < NUM_ROWS; y++) {
        for (int x = 0; x < NUM_COLUMNS; x += 2) {
            int pixelPos = getPixelStripPosition(x, y);
            leds[pixelPos] = colour;
            pixelPos = getPixelStripPosition(x + 1, y);
            leds[pixelPos] = colour;
            FastLED.show();
            }
            FastLED.delay(10);
        }
}

// Draw font glyphs into a rectangular matrix buffer.
// This simplifies the glyph-rendering process, as distortions can be applied late.
// It does, however, require a little extra memory and means that we effectively
//  draw the character data twice (once into this buffer, then again into the LED array).
void plotMatrixChar(CRGB (*matrix)[FONT_HEIGHT], int x, char character, int width, int height) {
    int y = 0;
    if (width > 0 && height > 0) {
        int charIndex = (int)character - 32;
        int xBitsToProcess = width;

        for (int i = 0; i < height; i++) {
            byte fontLine = FontData[charIndex][i]; //Accquire fontline data from font.h
                     
            for (int bitCount = 0; bitCount < xBitsToProcess; bitCount++) {
                CRGB pixelColour = CRGB(0, 0, 0);

                if (LSB_FONT == true) {
                    if (fontLine & 0b00000001) {
                        pixelColour = CHSV(_hue, 255, 55);  // When using reverse-mapped binary character data (left-most pixel is LSB)
                    }
                    fontLine = fontLine >> 1;
                } else {
                    if (fontLine & 0b10000000) {  // When using direct-mapped binary character data (left-most pixel is HSB)
                        pixelColour = CHSV(_hue, 255, 55);
                    }
                    fontLine = fontLine << 1;
                }
                int xpos = x + bitCount;
                int ypos = y + i;
                if (xpos < 0 || xpos > matrixBufferWidth || ypos < 0 || ypos > FONT_HEIGHT) {
                    Serial.printf("***Err:x=%d,y=%d\n", xpos, ypos);
                } else {
                    matrix[xpos][ypos] = pixelColour;
                    Serial.print(pixelColour);  
                }     
            }
            Serial.println();
        }
    }
}

void playNotes() {
    tone(BUZZER_PIN, NOTE_C5, 300, BUZZER_CHANNEL);
    //noTone(BUZZER_PIN, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_E5, 300, BUZZER_CHANNEL);
    //noTone(BUZZER_PIN, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_G5, 300, BUZZER_CHANNEL);
    //noTone(BUZZER_PIN, BUZZER_CHANNEL);
    tone(BUZZER_PIN, NOTE_C6, 1000, BUZZER_CHANNEL);
    noTone(BUZZER_PIN, BUZZER_CHANNEL);
}

void setup() {
    Serial.begin(115200);
    Serial.println("Setup method begins.");
    pinMode(DATA_PIN, OUTPUT);
    LEDS.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
    LEDS.setBrightness(BRIGHTNESS);

    float maxDisplayedCharacters = (float)NUM_COLUMNS / (float)FONT_WIDTH;
    bufferCharacterWidth = (int)(maxDisplayedCharacters + 0.5) + 1;
    matrixBufferWidth = bufferCharacterWidth * FONT_WIDTH;

    // Bit of a hack to cope with some situations where matrix buffer isn't wide enough
    // Seems to occur when font width isn't a factor of matrix width -- needs some more investigation!

    if (matrixBufferWidth < NUM_COLUMNS + FONT_WIDTH - 1) {
        bufferCharacterWidth++;
        matrixBufferWidth = bufferCharacterWidth * FONT_WIDTH;
    }

    scrollLengthInPixels = sMessage.length() * FONT_WIDTH;

    Serial.println(bufferCharacterWidth);
    Serial.println(matrixBufferWidth);
    Serial.println("Setup method complete.");


    Serial.println("Short pause...");
    Serial.println("Main loop begins.");
    for (int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Blue;
        FastLED.show();
        FastLED.delay(10);
        }
    playNotes();    
}

void loop()
{
     CRGB matrixColor[matrixBufferWidth][FONT_HEIGHT];

     currentScrollPosition = 0;
     int messageLength = sMessage.length();

     //Get char from sMessage one by one...
     for (int x=0; x<messageLength; x++) {
        //select char from message 
        char myChar = sMessage[x];
        Serial.printf("Char:%c\n", myChar);
        //plot glyph into matrixColor 
        _hue+=3;
               
        plotMatrixChar(matrixColor, 0 * FONT_WIDTH, myChar, FONT_WIDTH, FONT_HEIGHT);

        for (int sft=0;sft<5;sft++) { //Play simple left shift 
            //update FastLED with colors
            for (int x = 0; x < NUM_COLUMNS; x++) {
                for (int y = 0; y < FONT_HEIGHT; y++) {
                    int stripIdx = mapLED_Left90[y*5+x];
                    //leds[stripIdx] = matrixColor[x][y];
                    if (x+sft<5)
                        leds[stripIdx] = matrixColor[x+sft][y]; //Shift by one column left
                    else
                        leds[stripIdx] = CRGB(0,0,0);
                    }
                }    
            //Show    
            FastLED.show();
            if (sft==0)
               FastLED.delay(200);       //Pause more for the first one
            else
               FastLED.delay(30);   
            }
        }
        
    //Show a color ramp
    for (int x = 0; x < NUM_COLUMNS; x++) {
        for (int y = 0; y < FONT_HEIGHT; y++) {
            int stripIdx = mapLED_Left90[y*5+x];
            leds[stripIdx] = CHSV(_hue, 255, 55);
            }
        _hue += 51;    
        FastLED.show();
        FastLED.delay(100); 
        }
    FastLED.delay(3000);     
}


