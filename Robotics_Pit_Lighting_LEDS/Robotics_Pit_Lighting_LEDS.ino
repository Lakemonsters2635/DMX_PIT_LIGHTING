#include <Adafruit_NeoPixel.h>

//LED STRIP PINS
int strip1Pin = 22;
int strip2Pin = 24;
int strip3Pin = 26;
int strip4Pin = 28;
int strip5Pin = 30;
int strip6Pin = 32;
int strip7Pin = 34;
int strip8Pin = 36;

//LED ENABLE BOOLS
boolean strip1Enable = true;
boolean strip2Enable = true;
boolean strip3Enable = true;
boolean strip4Enable = true;
boolean strip5Enable = true;
boolean strip6Enable = true;
boolean strip7Enable = true;
boolean strip8Enable = true;

//VARIABLES & STUFF
int R;
int G;
int B;
String data;
boolean done;
int mode;

//STRIP SETUP
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(71, strip1Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(71, strip2Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(71, strip3Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(71, strip4Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(56, strip5Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(56, strip6Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(56, strip7Pin, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip8 = Adafruit_NeoPixel(56, strip8Pin, NEO_GRB + NEO_KHZ800);

void setup() 
{
  //Initialize neopixel strips
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  strip6.begin();
  strip7.begin();
  strip8.begin();

  //Start showing colors
  updateStrips();

  //Enable the serial port for communication with laptop
  Serial.begin(9600);
  Serial.println("Lights system uploaded. Please wait for diagnostics to finish.");
}

void loop() 
{
  if(done == false)
  {
    lmBlue();
    done = true; 
    mode = 1;
    data = "blue";
    Serial.println("Diagnostic process complete. You may enter instructions.");
  }

   while(Serial.available())
  {
    data = Serial.readString();
    data.trim();
  
    //Serial.println("RECEIVED: " + data);
    if(data == "blue")
    {
      mode = 1;
      Serial.println("Blue lights mode set!");
    }
    else if(data == "rainbow" or data == "gay")
    {
      mode = 2;
      Serial.println("Colors lights mode set!");
    }
    else if(data == "help")
    {
      mode = 3;
      Serial.println("Thank you for entering help. Here is the list of commands and what they do. blue : Sets the lights to the color blue. colors : Makes many colors pulsate. help : Brings up this help menu. usa : Starts a set of patriotically themed 'merican lights. enable : Enter this command, a space, and a number 1-8 to activate that particular set of lights.");
    }
    else if(data == "patriotic")
    {
      mode = 3;
      Serial.println("USA lights mode set!");
    }
    else if(data == "enable 1")
    {
      Serial.println("strip1Enable = true");
      strip1Enable = true;
    }
    else if(data == "disable 1")
    {
      Serial.println("strip1Enable = false");
      strip1Enable = false;
      for(uint16_t i=0; i<strip1.numPixels(); i++) 
      {
        strip1.setPixelColor(i, strip1.Color(0,0,0));
        
      }
      Serial.println("strip1.setPixelColor(i, strip1.Color(0,0,0))");
      strip1.show();
    }
    else if(data == "enable 2")
    {
      Serial.println("strip2Enable = true");
      strip2Enable = true;
    }
    else if(data == "disable 2")
    {
      strip2Enable = false;
      for(uint16_t i=0; i<strip2.numPixels(); i++) 
      {
        strip2.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip2.setPixelColor(i, strip1.Color(0,0,0))");
      strip2.show();
    }
    else if(data == "enable 3")
    {
      Serial.println("strip3Enable = true");
      strip3Enable = true;
    }
    else if(data == "disable 3")
    {
      strip3Enable = false;
      for(uint16_t i=0; i<strip3.numPixels(); i++) 
      {
        strip3.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip3.setPixelColor(i, strip1.Color(0,0,0))");
      strip3.show();
    }
    else if(data == "enable 4")
    {
      Serial.println("strip4Enable = true");
      strip4Enable = true;
    }
    else if(data == "disable 4")
    {
      strip4Enable = false;
      for(uint16_t i=0; i<strip4.numPixels(); i++) 
      {
        strip4.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip4.setPixelColor(i, strip1.Color(0,0,0))");
      strip4.show();
    }
    else if(data == "enable 5")
    {
      Serial.println("strip5Enable = true");
      strip5Enable = true;
    }
    else if(data == "disable 5")
    {
      strip5Enable = false;
      for(uint16_t i=0; i<strip5.numPixels(); i++) 
      {
        strip5.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip5.setPixelColor(i, strip1.Color(0,0,0))");
      strip5.show();
    }
    else if(data == "enable 6")
    {
      Serial.println("strip6Enable = true");
      strip6Enable = true;
    }
    else if(data == "disable 6")
    {
      strip6Enable = false;
      for(uint16_t i=0; i<strip6.numPixels(); i++) 
      {
        strip6.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip6.setPixelColor(i, strip1.Color(0,0,0))");
      strip6.show();
    }
    else if(data == "enable 7")
    {
      Serial.println("strip7Enable = true");
      strip7Enable = true;
    }
    else if(data == "disable 7")
    {
      strip7Enable = false;
      for(uint16_t i=0; i<strip7.numPixels(); i++) 
      {
        strip7.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip7.setPixelColor(i, strip1.Color(0,0,0))");
      strip7.show();
    }
    else if(data == "enable 8")
    {
      Serial.println("strip8Enable = true");
      strip8Enable = true;
    }
    else if(data == "disable 8")
    {
      strip8Enable = false;
      for(uint16_t i=0; i<strip8.numPixels(); i++) 
      {
        strip8.setPixelColor(i, strip1.Color(0,0,0));
      }
      Serial.println("strip8.setPixelColor(i, strip1.Color(0,0,0))");
      strip8.show();
    } 
  } 

  if(mode == 1)
  {
    lmBlue();
  }
  if(mode == 2)
  {
    rainbowCycle(5);
  }
  if(mode == 3)
  {
    marchRedWhiteBlue();
  }
}

/**
 * Lighting presets
 */
 
//LED Preset
void rainbowCycle(uint8_t wait) 
{
  uint16_t i, j;
    for(j=0; j<256; j++) // 5 cycles of all colors on wheel
    { 
      for(i=0; i< strip1.numPixels(); i++) 
      {
        strip1.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
        strip2.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
        strip3.setPixelColor(i, Wheel(((i * 256 / strip3.numPixels()) + j) & 255));
        strip4.setPixelColor(i, Wheel(((i * 256 / strip4.numPixels()) + j) & 255));
      }
      for(i=0; i< strip5.numPixels(); i++) 
      {
        strip5.setPixelColor(i, Wheel(((i * 256 / strip1.numPixels()) + j) & 255));
        strip6.setPixelColor(i, Wheel(((i * 256 / strip2.numPixels()) + j) & 255));
        strip7.setPixelColor(i, Wheel(((i * 256 / strip3.numPixels()) + j) & 255));
        strip8.setPixelColor(i, Wheel(((i * 256 / strip4.numPixels()) + j) & 255));
      }
      updateStrips();
      delay(wait);
    }
}

//LED Preset
void lmBlue()
{
  uint32_t colorLmBlue = strip1.Color(0, 255, 255);
  //Serial.println(strip1.numPixels());
  for(uint16_t i=0; i<strip1.numPixels(); i++)  
  {   
    //i<strip//1.numPixels()+1
      strip1.setPixelColor(i, colorLmBlue);   
      strip2.setPixelColor(i, colorLmBlue);  
      strip3.setPixelColor(i, colorLmBlue);  
      strip4.setPixelColor(i, colorLmBlue); 
      //Serial.println(i);    
  }
  for(uint16_t i=0; i<strip5.numPixels(); i++)  
  {   
      strip5.setPixelColor(i, colorLmBlue);
      strip6.setPixelColor(i, colorLmBlue);
      strip7.setPixelColor(i, colorLmBlue);
      strip8.setPixelColor(i, colorLmBlue);
  }
  updateStrips();
  strip1.show();
  
}

//LED Preset
void marchRedWhiteBlue()
{
  uint32_t colors[] = { strip1.Color(255,0,0), strip1.Color(0,0,255), strip1.Color(155,155,155) };
  int frame = 0;
  while( frame < 60 ) 
  {
    for (int index = 0;index<strip1.numPixels();index++)
    {
      //strip.setPixelColor((index  + (frame % 15)) % 60, colors[ ((index)/5 + frame) % 3 ]);
      strip1.setPixelColor((index + frame) % 60 , colors[ ((index)/5) % 3 ]);
      strip2.setPixelColor((index + frame) % 60 , colors[ ((index)/5) % 3 ]);
      strip3.setPixelColor((index + frame) % 60 , colors[ ((index)/5) % 3 ]);
      strip4.setPixelColor((index + frame) % 60 , colors[ ((index)/5) % 3 ]);
    }
    
    for (int index = 0;index<strip5.numPixels();index++)
    {
      //strip.setPixelColor((index  + (frame % 15)) % 60, colors[ ((index)/5 + frame) % 3 ]);
      strip5.setPixelColor((index + frame) % 71 , colors[ ((index)/5) % 3 ]);
      strip6.setPixelColor((index + frame) % 71 , colors[ ((index)/5) % 3 ]);
      strip7.setPixelColor((index + frame) % 71 , colors[ ((index)/5) % 3 ]);
      strip8.setPixelColor((index + frame) % 71 , colors[ ((index)/5) % 3 ]);
    }
    updateStrips();
    delay(50);
    frame++;
  }  
}

/**
 * Functional functions that function to perform frequently functioned functions.
 * Call them if you want, see if I care
 */

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip1.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip1.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip1.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void blackout()
{
  for(uint16_t i=0; i<strip1.numPixels(); i++) 
  {
      strip1.setPixelColor(i, strip1.Color(0,0,0));
      strip2.setPixelColor(i, strip1.Color(0,0,0));
      strip3.setPixelColor(i, strip1.Color(0,0,0));
      strip4.setPixelColor(i, strip1.Color(0,0,0));
      
   }
   for(uint16_t i=0; i<strip5.numPixels(); i++) 
  {
      strip5.setPixelColor(i, strip1.Color(0,0,0));
      strip6.setPixelColor(i, strip1.Color(0,0,0));
      strip7.setPixelColor(i, strip1.Color(0,0,0));
      strip8.setPixelColor(i, strip1.Color(0,0,0));
      
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  strip6.show();
  strip7.show();
  strip8.show();
}

void updateStrips()
{
  if(strip1Enable == true)
  {
    strip1.show();
  }
  if(strip2Enable == true)
  {
    strip2.show();
  }
  if(strip3Enable == true)
  {
    strip3.show();
  }
  if(strip4Enable == true)
  {
    strip4.show();
  }
  if(strip5Enable == true)
  {
    strip5.show();
  }
  if(strip6Enable == true)
  {
    strip6.show();
  }
  if(strip7Enable == true)
  {
    strip7.show();
  }
  if(strip8Enable == true)
  {
    strip8.show();
  }
}
