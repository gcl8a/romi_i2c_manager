#include <romi_i2c_manager.h>

#define ADDR_SPEED_LEFT 0X00
#define ADDR_SPEED_RIGHT 0X02
#define ADDR_ENC_LEFT 0x04
#define ADDR_ENC_RIGHT 0x06

#define ADDR_ROMI 0x20

void SetEfforts(int16_t effortLeft, int16_t effortRight)
{
  uint8_t spdBuffer[4];

  //copy using memcpy to keep endian-ness???
  memcpy(spdBuffer, &effortLeft, 2);
  memcpy(&spdBuffer[2], &effortRight, 2);
  
  Wire.beginTransmission(ADDR_ROMI);
  
  Wire.write(ADDR_SPEED_LEFT); //submask
  for(int i = 0; i < 4; i++) Wire.write(spdBuffer[i]);
  
  Wire.endTransmission();     // stop transmitting
}

uint8_t ReadSpeeds(int16_t& speedLeft, int16_t& speedRight)
{
  Wire.beginTransmission(ADDR_ROMI); // 
  Wire.write(ADDR_ENC_LEFT);             // sends address byte  
  Wire.endTransmission();     // stop transmitting

  uint8_t byte_count = Wire.requestFrom(ADDR_ROMI, 4);
  
  speedLeft = Wire.read();
  speedLeft += Wire.read() << 8;

  speedRight = Wire.read();
  speedRight += Wire.read() << 8;

  return byte_count;
}
