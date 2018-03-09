#include <Arduino.h>
#include <RA4067.h>

RA4067::RA4067(int s0, int s1, int s2, int s3) {
    m_s0 = s0;
    m_s1 = s1;
    m_s2 = s2;
    m_s3 = s3;
    pinMode(m_s0, OUTPUT);
    pinMode(m_s1, OUTPUT);
    pinMode(m_s2, OUTPUT);
    pinMode(m_s3, OUTPUT);
    m_currentPin = 0;
    m_eb = 0;
    m_re = 0;
}

RA4067::RA4067(int s0, int s1, int s2, int s3, int readPin) {
    m_s0 = s0;
    m_s1 = s1;
    m_s2 = s2;
    m_s3 = s3;
    m_readPin = readPin;
    pinMode(m_s0, OUTPUT);
    pinMode(m_s1, OUTPUT);
    pinMode(m_s2, OUTPUT);
    pinMode(m_s3, OUTPUT);
    pinMode(m_readPin, INPUT);
    m_currentPin = 0;
    m_eb = 0;
    m_re = 1;
}

void RA4067::setEnablePin(int enable) {
    m_e = enable;
    pinMode(m_e, OUTPUT);
    m_eb = 1;
}

int RA4067::RADigitalRead() {
    if (m_re == 1) {
        return digitalRead(m_readPin);
    } else {
        return 0;
    }
}

int RA4067::RAAnalogRead() {
    if (m_re == 1) {
        return analogRead(m_readPin);
    } else {
        return 0;
    }
}

void RA4067::setPin(int pinToSet) {
    if ((pinToSet >= 0) && (pinToSet < 16)) {
        m_currentPin = pinToSet;
        int m_r0 = bitRead(m_currentPin, 0);
        int m_r1 = bitRead(m_currentPin, 1);
        int m_r2 = bitRead(m_currentPin, 2);
        int m_r3 = bitRead(m_currentPin, 3);
        digitalWrite(m_s0, m_r0);
        digitalWrite(m_s1, m_r1);
        digitalWrite(m_s2, m_r2);
        digitalWrite(m_s3, m_r3);
    }
}

int RA4067::getCurrentPin() {
    return m_currentPin;
}

void RA4067::on() {
    if ((m_eb == 1) && (m_enableBit != LOW)) {
        digitalWrite(m_e, LOW);
        m_enableBit = LOW;
    }
}

void RA4067::off() {
    if ((m_eb == 1) && (m_enableBit != HIGH)) {
        digitalWrite(m_e, HIGH);
        m_enableBit = HIGH;
    }
}
