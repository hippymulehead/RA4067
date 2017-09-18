#include <Arduino.h>
#include <RA4067.h>

/*
Simple demo.  +5v in then an LED and a r220 to ground from each output.
Demo simply walks through the outputs switching the +5v to each of the 
outs lighting the LED.
*/

RA4067 aswitch(12,11,10,9);

void setup() {
    aswitch.setPin(0);
    aswitch.setEnablePin(8);
    aswitch.on();
}

void loop() {
    for (size_t i = 0; i < 8; i++) {
        aswitch.setPin(i);
        delay(300);
    }
    aswitch.off();
    delay(300);
    aswitch.on();
}