#include "nunchuck2.h"
#include <string.h> // For memset

extern I2C_HandleTypeDef hi2c1;

void nunchuck2_init(void) {
    // Standard "Unlock" command for encrypted Nunchucks
    // We send 0x40, 0x00 to address 0x52
    uint8_t unlock_seq[] = {0x40, 0x00};

    // Wait briefly for power stabilization
    HAL_Delay(10);

    // Transmit the unlock sequence
    HAL_I2C_Master_Transmit(&hi2c1, NUNCHUCK2_ADDR, unlock_seq, 2, HAL_MAX_DELAY);

    HAL_Delay(10);
}

nunchuck2_t nunchuck2_read(void) {
    nunchuck2_t state = {0};
    uint8_t data[6] = {0};
    uint8_t cmd = 0x00;

    // 1. Send 0x00 to request data
    if (HAL_I2C_Master_Transmit(&hi2c1, NUNCHUCK2_ADDR, &cmd, 1, 10) != HAL_OK) {
        return state; // Return empty state if I2C fails
    }

    // 2. Wait for conversion
    HAL_Delay(2);

    // 3. Receive 6 bytes of data
    if (HAL_I2C_Master_Receive(&hi2c1, NUNCHUCK2_ADDR, data, 6, 10) == HAL_OK) {

        // 4. Apply your specific Decryption Logic: (x ^ 0x17) + 0x17
        for (int i = 0; i < 6; i++) {
            data[i] = (data[i] ^ 0x17) + 0x17;
        }

        // 5. Parse decoded data
        state.joy_x = data[0];
        state.joy_y = data[1];
        
        // Accelerometer data is 10-bit (Upper 8 bits in bytes 2-4, Lower 2 bits in byte 5)
        state.accel_x = (data[2] << 2) | ((data[5] >> 2) & 0x03);
        state.accel_y = (data[3] << 2) | ((data[5] >> 4) & 0x03);
        state.accel_z = (data[4] << 2) | ((data[5] >> 6) & 0x03);

        // Buttons are active LOW (0 when pressed). We invert them to be 1 when pressed.
        // Bit 0 is Z, Bit 1 is C.
        state.z_btn = !((data[5] >> 0) & 0x01);
        state.c_btn = !((data[5] >> 1) & 0x01);
    }

    return state;
}
