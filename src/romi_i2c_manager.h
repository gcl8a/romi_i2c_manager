#include <Arduino.h>
#include <Wire.h>

void SetEfforts(int16_t effortLeft, int16_t effortRight);
uint8_t ReadSpeeds(int16_t& speedLeft, int16_t& speedRight);
