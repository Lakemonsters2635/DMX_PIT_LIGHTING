#include <DmxSimple.h>
boolean done;
String data;
int scene;

void setup() 
{
  //Set the DMX Output Pin. Is 3 by default, but just to be sure
  DmxSimple.usePin(3);

  //Max Number of DMX Channels. If not set, will be set by the highest .write(). 
  //Using 4 lights with 1-8 each, so using 35 for wiggle room
  DmxSimple.maxChannel(35);

  pinMode(2,INPUT);

   //Enable the serial port for communication with laptop
  Serial.begin(9600);
  Serial.println("Setup Executed!"); //Debug
}

void loop() 
{
  //Run the default scene, blue mood lighting
  if(done == false)
  {
    moodLighting();
    done = true; 
    Serial.println("Done!");
  }

  while(Serial.available())
  {
    data = Serial.readString();
    data.trim();
    //Serial.println("RECEIVED: " + data);
    if(data == "mood")
    {
      scene = 1;
      //moodLighting();
      Serial.println("Mood lighting set");
    }
    if(data == "work")
    {
      scene = 2;
      //workLighting();
      Serial.println("Work Lighting set");
    }
    if(data == "rainbow")
    {
      scene = 3;
      //rainbow();
      Serial.println("Rainbow mode set");
      //Serial.println("You do not have permissions. This event will be reported.");
    }
    if(data == "pink")
    {
      scene = 4;
      Serial.println("Annoying Nick Abbott...");
      //Serial.println("You do not have permissions. This event will be reported.");
    }
  }

  if(scene == 1)
  {
    moodLighting();
  }
  if(scene == 2)
  {
    workLighting();
  }
  if(scene == 3)
  {
    rainbow();
  }
  if(scene == 4)
  {
    pink();
  }
}


/**
 * Lighting presets
 */
void moodLighting()
{
  //Mode 1
  setColor(1, 0, 200, 200, 0);
  setColor(5, 0, 200, 200, 0);
  setColor(9, 0, 200, 200, 0);
  setColor(13, 0, 200, 200, 0);
}

void workLighting()
{
  setColor(1, 255, 255, 255, 0);
  setColor(5, 255, 255, 255, 0);
  setColor(9, 255, 255, 255, 0);
  setColor(13, 255, 255, 255, 0);
}

void pink()
{
  setColor(1, 255, 192, 203, 0);
  setColor(5, 255, 192, 203, 0);
  setColor(9, 255, 192, 203, 0);
  setColor(13, 255, 192, 203, 0);
}

void rainbow()
{
  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) 
  {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) 
    {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColor(1, rgbColour[0], rgbColour[1], rgbColour[2], 0);
      setColor(5, rgbColour[0], rgbColour[1], rgbColour[2], 0);
      setColor(9, rgbColour[0], rgbColour[1], rgbColour[2], 0);
      setColor(13, rgbColour[0], rgbColour[1], rgbColour[2], 0);
      delay(5);
    }
  }
}


/*
 * Functional functions that function to perform frequently functioned functions.
 * Call them if you want, see if I care
 */
 
void setColor(int f, int r, int g, int b, int u)
{
  DmxSimple.write(f, r);
  DmxSimple.write(f+1, g);
  DmxSimple.write(f+2, b);
  DmxSimple.write(f+3, u);
}
