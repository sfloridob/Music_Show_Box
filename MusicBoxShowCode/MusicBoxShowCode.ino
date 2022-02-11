#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define STROBE     5
#define RESET      6

#define PIN        7 
#define NUMPIXELS 98

int leftspec[7], rightspec[7];
int count = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.
  
  pixels.begin();
  
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();

  pinMode(RESET, OUTPUT); 
  pinMode(STROBE, OUTPUT); 

  digitalWrite(RESET, LOW); 
  delayMicroseconds(1);
  digitalWrite(STROBE, HIGH); // Change frequency band when LOW
  delayMicroseconds(1);
 
}

void loop() {

  digitalWrite(STROBE, LOW);
  delayMicroseconds(30);
  leftspec[count] = analogRead(A1);
  rightspec[count] = analogRead(A2);
  draw(count, leftspec[count]); // Switch neopixels on depending on the intensity of the frequency band selected on the left
  draw(count+7, rightspec[count]); // Same for the right
  digitalWrite(STROBE, HIGH);
    
  count++;
  if(count == 7){ // When it has finished reading every frequency band, it resets both MSGEQ7 and starts all over again from the first frequency band 
   count = 0;
   digitalWrite(RESET, HIGH);
   digitalWrite(RESET, LOW); 
  }

}

void draw(int band, int intensity)
{
    pixels.fill(0, band*7, (band*7)+7);
    // IF THE CHANNEL SELECTED FOR A SPECIFIC FREQUENCY BAND IS EVEN FOR THE LEFT INPUT OR IF IT IS ODD FOR THE RIGHT INPUT, THIS FUNCTION SWITCHES ON THE CORRESPONDING NEOPIXELS IN A ASCENDING WAY
    if(((band%2 == 0) && (band < 7)) || ((band%2 != 0) && (band >= 7)))
    { 
      if((intensity > 70) && (intensity < 200))
      {
       
       for(int i=0; i < 1; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));  
       }
      }
    
     else if((intensity >= 200) && (intensity < 330))
     {
       for(int i=0; i < 2; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
     
     else if((intensity >= 330) && (intensity < 460))
     {
       for(int i=0; i < 3; i++)
       {
          pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
     
     else if((intensity >= 460) && (intensity < 590))
     {
       for(int i=0; i < 4; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
     
     else if((intensity >= 590) && (intensity < 720))
     {
       for(int i=0; i < 5; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
    
     else if((intensity >= 720) && (intensity < 850))
     {
       for(int i=0; i < 6; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
     
     else if((intensity >= 850) && (intensity <= 1024))
     {
       for(int i=0; i < 7; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
       }
     }
     
     else{
       for(int i=0; i < 7; i++)
       {
         pixels.setPixelColor((band*7) + i, pixels.Color(0, 0, 0));
       }
     }
   } 
   // END OF ASCENDING SWITCHING ON

  // IF THE CHANNEL SELECTED FOR A SPECIFIC FREQUENCY BAND IS ODD FOR THE LEFT INPUT OR IF IT IS EVEN FOR THE RIGHT INPUT, THIS FUNCTION SWITCHES ON THE CORRESPONDING NEOPIXELS IN A DESCENDING WAY
  else if(((band%2 != 0) && (band < 7)) || ((band%2 == 0) && (band >= 7)))
  {
    if((intensity > 70) && (intensity < 200))
    {
      for(int i=6; i >= 6; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 200) && (intensity < 330))
    {
      for(int i=6; i >= 5; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 330) && (intensity < 460))
    {
      for(int i=6; i >= 4; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 460) && (intensity < 590))
    {
      for(int i=6; i >= 3; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 590) && (intensity < 720))
    {
      for(int i=6; i >= 2; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 720) && (intensity < 850))
    {
      for(int i=6; i >= 1; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensity >= 850) && (intensity <= 1024))
    {
      for(int i=6; i >= 0; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else{
      for(int i=6; i >= 0; i--)
      {
        pixels.setPixelColor((band*7) + i, pixels.Color(0, 0, 0));
      }
    }
  }
  // END OF DESCENDING SWITCHING ON
  pixels.show();
}
