#include <i2c_t3.h>
#include "i2c_driver.h"

#define ADDRESS (0x00)

bool i2c_driver_begin(void (*request)(void), void (*receive)(size_t len))
{
  bool status = false;
  if ((request != NULL) && (receive != NULL))
  {
    // Setup for Slave mode, address, pins 18/19, internal pullups
    Wire.begin(I2C_SLAVE, ADDRESS, I2C_PINS_18_19, I2C_PULLUP_INT);

    // Register events
    Wire.onReceive(receive);
    Wire.onRequest(request);
    status = true;
  }

  return status;
}

bool i2c_driver_write(const uint8_t *data, size_t size)
{
  bool status = false;
  if ((data != NULL) && (size > 0))
  {
    status = (size == Wire.write(data, size));
  }
  return status;
}

bool i2c_driver_read(uint8_t *data, size_t size)
{
  bool status = false;
  if ((data != NULL) && (size > 0))
  {
    status = (size == Wire.read(data, size));
  }
  return status;
}