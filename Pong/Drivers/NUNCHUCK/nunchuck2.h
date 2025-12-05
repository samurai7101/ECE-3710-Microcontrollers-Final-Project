#ifndef __NUNCHUCK2_H
#define __NUNCHUCK2_H

#include "main.h"

// Nunchuck I2C Address (0x52 shifted left by 1 for STM32 HAL)
#define NUNCHUCK2_ADDR (0x52 << 1)

typedef struct {
    uint8_t joy_x;
    uint8_t joy_y;
    uint16_t accel_x;
    uint16_t accel_y;
    uint16_t accel_z;
    uint8_t z_btn; // 1 if pressed, 0 if released
    uint8_t c_btn; // 1 if pressed, 0 if released
} nunchuck2_t;

// Initializes I2C and sends the "Unlock" sequence (0x40, 0x00)
void nunchuck2_init(void);

// Reads data, applies (x ^ 0x17) + 0x17 decryption, and returns parsed struct
nunchuck2_t nunchuck2_read(void);

#endif // __NUNCHUCK2_H
