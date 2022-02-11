#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN        6 
#define NUMPIXELS 49

int leftspec[7], rightspect[7];
int leftcount = 0, rightcount = 0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  pixels.begin();
  
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();
}

void loop() {

  leftspec[leftcount] = analogRead(A0);
  pintar(leftcount, leftspec[leftcount]);
    
  leftcount++;
  if(leftcount == 7){
   leftcount = 0;
  }
}

void pintar(int banda, int intensidad)
{
  pixels.fill(0, banda*7, (banda*7)+7);
  // SI LA BANDA DE FRECUENCIA ES PAR, ENCENDEMOS LOS LEDS CORRESPONDIENTES DE FORMA ASCENDENTE
  if(banda%2 == 0)
  { 
    if((intensidad > 0) && (intensidad < 147))
    {
      
      for(int i=0; i < 1; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));  
      }
    }
    
    else if((intensidad >= 147) && (intensidad < 294))
    {
      for(int i=0; i < 2; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else if((intensidad >= 294) && (intensidad < 441))
    {
      for(int i=0; i < 3; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else if((intensidad >= 441) && (intensidad < 588))
    {
      for(int i=0; i < 4; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else if((intensidad >= 588) && (intensidad < 735))
    {
      for(int i=0; i < 5; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else if((intensidad >= 735) && (intensidad < 882))
    {
      for(int i=0; i < 6; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else if((intensidad >= 882) && (intensidad <= 1024))
    {
      for(int i=0; i < 7; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0+(i*20), 120-(i*20), 0));
      }
    }
    
    else{
      for(int i=0; i < 7; i++)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0, 0, 0));
      }
    }
  } 
  // FIN DEL ENCENDIDO ASCENDENTE

  // SI LA BANDA DE FRECUENCIA ES IMPAR, ENCENDEMOS LOS LEDS CORRESPONDIENTES DE FORMA DESCENDENTE
  else
  {
    if((intensidad > 0) && (intensidad < 147))
    {
      for(int i=6; i >= 6; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 147) && (intensidad < 294))
    {
      for(int i=6; i >= 5; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 294) && (intensidad < 441))
    {
      for(int i=6; i >= 4; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 441) && (intensidad < 588))
    {
      for(int i=6; i >= 3; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 588) && (intensidad < 735))
    {
      for(int i=6; i >= 2; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 735) && (intensidad < 882))
    {
      for(int i=6; i >= 1; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else if((intensidad >= 882) && (intensidad <= 1024))
    {
      for(int i=6; i >= 0; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(120-(i*20), 0+(i*20), 0));
      }
    }
    
    else{
      for(int i=6; i >= 0; i--)
      {
        pixels.setPixelColor((banda*7) + i, pixels.Color(0, 0, 0));
      }
    }
  }
  // FIN DEL ENCENDIDO DESCENDENTE
  pixels.show();
}
