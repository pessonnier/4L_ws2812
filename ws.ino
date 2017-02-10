// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            8

// les PIN des 2 bouttons
#define INTLONG  7
#define INTMODE  6

// How many NeoPixels are attached to the Arduino?
// 2 longueure possible pour le ruban
#define NUMPIXELSCOURT      30
#define NUMPIXELSLONG      90
int nbpixels = NUMPIXELSCOURT;

// 2 luminosités
#define LUMMOY 128
#define LUMFORT 200
int luminosite = LUMFORT;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(nbpixels, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50;

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("alu");

  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INTLONG, INPUT);
  pinMode(INTMODE, INPUT);
  Serial.println("go");
}

void blanc() {

  for(int i=0;i<nbpixels;i++){
    pixels.setPixelColor(i, pixels.Color(luminosite,luminosite,luminosite));

    pixels.show(); // This sends the updated pixel color to the hardware.
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayval); // Delay for a period of time (in milliseconds).
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayval);
  }
}

void eteindre() {
  for(int i=0;i<nbpixels;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
  }
  pixels.show();
}

void k2000() {
  for(int i=0;i<nbpixels;i++){


    pixels.setPixelColor(i-5, pixels.Color(0,0,0));
    pixels.setPixelColor(i-4, pixels.Color(10,0,0));
    pixels.setPixelColor(i-3, pixels.Color(25,0,0));
    pixels.setPixelColor(i-2, pixels.Color(50,0,0));
    pixels.setPixelColor(i-1, pixels.Color(100,0,0));
    pixels.setPixelColor(i, pixels.Color(200,0,0));
    pixels.setPixelColor(i+1, pixels.Color(100,0,0));
    pixels.setPixelColor(i+2, pixels.Color(50,0,0));
    pixels.setPixelColor(i+3, pixels.Color(25,0,0));
    pixels.setPixelColor(i+4, pixels.Color(10,0,0));
    pixels.setPixelColor(i+5, pixels.Color(0,0,0));

    pixels.show(); // This sends the updated pixel color to the hardware.
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayval); // Delay for a period of time (in milliseconds).
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayval);
  }

  for(int i=nbpixels;i>=0;i--){

    pixels.setPixelColor(i-5, pixels.Color(0,0,0)); 
    pixels.setPixelColor(i-4, pixels.Color(10,0,0));
    pixels.setPixelColor(i-3, pixels.Color(25,0,0)); 
    pixels.setPixelColor(i-2, pixels.Color(50,0,0));
    pixels.setPixelColor(i-1, pixels.Color(100,0,0)); 
    pixels.setPixelColor(i, pixels.Color(200,0,0));
    pixels.setPixelColor(i+1, pixels.Color(100,0,0));
    pixels.setPixelColor(i+2, pixels.Color(50,0,0));
    pixels.setPixelColor(i+3, pixels.Color(25,0,0));
    pixels.setPixelColor(i+4, pixels.Color(10,0,0));
    pixels.setPixelColor(i+5, pixels.Color(0,0,0));

    pixels.show(); // This sends the updated pixel color to the hardware.
    digitalWrite(LED_BUILTIN, HIGH);
    delay(delayval); // Delay for a period of time (in milliseconds).
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayval);
  }  
}

void loop() {
  int intmodeState = digitalRead(INTMODE);
  int intlongState = digitalRead(INTLONG);
  
  if ((intlongState == HIGH) && (nbpixels == NUMPIXELSCOURT)) {
    Serial.println("long = HIGH");
    eteindre();
    nbpixels = NUMPIXELSLONG;
    luminosite = LUMMOY;
    pixels = Adafruit_NeoPixel(nbpixels, PIN, NEO_GRB + NEO_KHZ800);
    pixels.begin();
  }
  if ((intlongState == LOW) && (nbpixels == NUMPIXELSLONG)) {
    Serial.println("long = LOW");
    eteindre();
    nbpixels = NUMPIXELSCOURT;
    luminosite = LUMFORT;
    pixels = Adafruit_NeoPixel(nbpixels, PIN, NEO_GRB + NEO_KHZ800);
    pixels.begin();
  }
  if (intmodeState == HIGH) {
    Serial.println("mode = k2000");
    k2000();
  }
  if (intmodeState == LOW) {
    Serial.println("mode = eclairage");
    blanc();
  }

  Serial.println("youou");
}
