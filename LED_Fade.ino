/*
	This is a remix of the "Fade" example that extends it to 
	have multiple LEDs fading in an offset manner

	The analogWrite() function uses PWM, so if you want to change the pin you're
	using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
	are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

	For a standard 5V source I used 220ohm resistors with the 
	the 3V (fv) LEDs.  
*/

int led[5] = {5,6,9,10,11};   					// 5 leds to light up based on PWM pins
int brightness[5] = {0, 55, 100, 155, 240};   	// how bright the LED starts (make sure these are nice multipels of the fade amount)
int fadeAmount[5] = {5, 5, 5, 5, 5};    		// how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() 
{
  for(int i = 0; i < 5; ++i)
  {
    pinMode(led[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() 
{
  // set the brightness of all pins:
  for (int i = 0; i < 5; ++i)
  {
    analogWrite(led[i], brightness[i]);
      
    // change the brightness for next time through the loop:
    brightness[i] = brightness[i] + fadeAmount[i];
  
    // reverse the direction of the fading at the ends of the fade:
    if (brightness[i] <= 0 || brightness[i] >= 255) 
	{
      fadeAmount[i] = -fadeAmount[i];
    }
  }
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
