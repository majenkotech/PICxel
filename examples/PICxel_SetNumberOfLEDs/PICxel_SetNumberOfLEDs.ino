/************************************************************************
 *  PICxel_SetNumberOfLEDso - PIC32 Neopixel Library Demo
 *
 *  This sketch shows how to use the setNumberOfLEDs() function
 *
 *  supported boards:
 *    - all chipKIT boards
 *
 *  This library is protected under the GNU GPL v3.0 license
 *  http://www.gnu.org/licenses/
 *
 *  Even thought this sketch shows setNumberOfLEDs() with just one
 *  parameter, it is possible to pass in four, See PICxel.cpp
 *  and PICxel.h for paramter info. When you only use on paraemter,
 *  the other paramters defult to NULL. But if you send them in,
 *  you can control the arrays (if you initalized the PICxel object
 *  with a memory mode of noalloc)
 ************************************************************************/

#include <PICxel.h>

#define MAXIMUM_NUMBER_OF_LEDS      15
#define LED_PIN                      0
#define MILLISECOND_DELAY           50

// PICxel constructor(uint8_t # of LEDs, uint8_t pin #);
PICxel strip(MAXIMUM_NUMBER_OF_LEDS, LED_PIN);

uint8_t CurrentNumberOfLEDs = MAXIMUM_NUMBER_OF_LEDS;

void setup()
{
  strip.begin();
  strip.setBrightness(30);
  strip.clear();
}

void loop()
{
  for (int i = 0; i < strip.getNumberOfLEDs(); i++)
  {
    strip.GRBsetLEDColor(i, 255, 0, 0);
    strip.refreshLEDs();
    delay(MILLISECOND_DELAY);
  }

  for (int i = strip.getNumberOfLEDs(); i >= 0; i--)
  {
    strip.GRBsetLEDColor(i, 0, 255, 0);
    strip.refreshLEDs();
    delay(MILLISECOND_DELAY);
  }
  CurrentNumberOfLEDs--;
  if (CurrentNumberOfLEDs == 0)
  {
    CurrentNumberOfLEDs = MAXIMUM_NUMBER_OF_LEDS;
  }
  /* Reconfigure the PICxel object to have a different number of LEDs.
   *  Note that you can't ask for more memory here than you have heap space for, 
   *  and eventually the heap may get fragmented, so be careful how many times
   *  you reset the number of LEDs.
   */
  strip.setNumberOfLEDs(CurrentNumberOfLEDs);
}
