#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Initiates the I2C communication from the slave (Teensy).
 *
 * @param request Function pointer to a request event.
 * @param recieve Function pointer to a recieve event.
 * @return status Returns false if error, else true.
 */
bool i2c_driver_begin(void (*request)(void), void (*recieve)(size_t len));

/**
 *
 * @brief Writes data from a slave device in response to a request from a master.
 *
 * @param data An array of data to send as bytes.
 * @param size size of the array.
 * @return status Returns false if error, else true.
 */
bool i2c_driver_write(const uint8_t *data, size_t size);

/**
 * @brief Reads data sent by a master device.
 *
 * @param data An array of data to read as bytes.
 * @param size size of the array.
 * @return status Returns false if error, else true.
 */
bool i2c_driver_read(uint8_t *data, size_t size);

#endif /* I2C_DRIVER_H */
