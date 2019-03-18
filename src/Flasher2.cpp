/**
 * This is a copy of source code you can find here:
 * https://learn.adafruit.com/multi-tasking-the-arduino-part-1/a-classy-solution and here 
 * https://learn.adafruit.com/multi-tasking-the-arduino-part-2/timers
 */

#include "Flasher2.h"

Flasher2::Flasher2(int pin, long on, long off)
{
  ledPin = pin;
  pinMode(ledPin, OUTPUT);
    
  OnTime = on;
  OffTime = off;

  ledState = LOW; 
  previousMillis = 0;
}

void Flasher2::Update()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
    
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);	  // Update the actual LED
  }
}

void Flasher2::Update(unsigned long currentMillis) 
{
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
    	ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);	  // Update the actual LED
    }
}