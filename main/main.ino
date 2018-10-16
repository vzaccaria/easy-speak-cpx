// Talkie library
// Copyright 2011 Peter Knight

#include "speech.h"
#include <Adafruit_CircuitPlayground.h>
#include <SPI.h>
#include <Wire.h>

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.speaker.say(spONE);
  // Calling speaker.end() after playing a sound is optional -- this
  // will turn off the pin 13 LED (it's connected to a microcontroller
  // pin that's also related to the speaker), but there's a small
  // audible click when it turns off.  Tradeoffs!
  CircuitPlayground.speaker.end();
}

void loop() {}
