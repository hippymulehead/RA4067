#include <Arduino.h>
#include <RA4067.h>

RA4067::RA4067(int s0, int s1, int s2, int s3) {
    _s0 = s0;
    _s1 = s1;
    _s2 = s2;
    _s3 = s3;
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_s3, OUTPUT);
    _currentPin = 0;
    _eb = 0;
}

RA4067::RA4067(int s0, int s1, int s2, int s3, int enable) {
    _s0 = s0;
    _s1 = s1;
    _s2 = s2;
    _s3 = s3;
    _e = enable;
    pinMode(_s0, OUTPUT);
    pinMode(_s1, OUTPUT);
    pinMode(_s2, OUTPUT);
    pinMode(_s3, OUTPUT);
    pinMode(_e, OUTPUT);
    _currentPin = 0;
    _eb = 1;
}

void RA4067::setPin(int pinToSet) {
    if ((pinToSet >= 0) && (pinToSet < 16)) {
        _currentPin = pinToSet;
        int _r0 = bitRead(_currentPin, 0);
        int _r1 = bitRead(_currentPin, 1);
        int _r2 = bitRead(_currentPin, 2);
        int _r3 = bitRead(_currentPin, 3);
        digitalWrite(_s0, _r0);
        digitalWrite(_s1, _r1);
        digitalWrite(_s2, _r2);
        digitalWrite(_s3, _r3);
    }
}

int RA4067::getCurrentPin() {
    return _currentPin;
}

void RA4067::on() {
    if ((_eb == 1) && (_enableBit != LOW)) {
        digitalWrite(_e, LOW);
        _enableBit = LOW;
    }
}

void RA4067::off() {
    if ((_eb == 1) && (_enableBit != HIGH)) {
        digitalWrite(_e, HIGH);
        _enableBit = HIGH;
    }
}