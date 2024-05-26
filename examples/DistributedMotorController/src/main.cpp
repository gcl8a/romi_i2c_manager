#include <Arduino.h>
#include <Wire.h>

/**
 * Not really doing motor control, yet. Just testing
*/
void setup() 
{
  Serial.begin(115200);

  Wire.begin();
  Wire.setClock(400000UL);
}

void loop() 
{
  delay(500);

  uint8_t datum = millis() % 256;

  Serial.print("Writing: ");
  Serial.println(datum);

  Wire.beginTransmission(0x28);
  Wire.write(0x02);
  Wire.write(datum);
  Wire.endTransmission();

  delay(200);

  Serial.print("Reading: ");
  Wire.requestFrom(0x28, 1);
  if(!Wire.available()) Serial.println("Not available!");

  else
  {
    Serial.println(Wire.read());
  }

  Serial.println("Reading from 0x02: ");

  Wire.beginTransmission(0x28);
  Wire.write(0x00);
  Wire.endTransmission(false);

  Wire.requestFrom(0x28, 4);
  if(!Wire.available()) Serial.println("Not available!");
  else
  {
    Serial.println(Wire.read());
    Serial.println(Wire.read());
    Serial.println(Wire.read());
    Serial.println(Wire.read());
  } 
}
