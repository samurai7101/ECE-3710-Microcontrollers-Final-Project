#ifndef PONG_H
#define PONG_H

#include "stm32l476xx.h"
#include <stdbool.h>
#include <stdint.h>

// Game state
extern bool game_over;
extern bool win;

// Scores
extern uint8_t player_score;
extern uint8_t mcu_score;

// Ball state
extern uint8_t ball_x;
extern uint8_t ball_y;
extern int8_t ball_dir_x;
extern int8_t ball_dir_y;

// Timing
extern uint32_t last_ball_update;
extern uint32_t last_paddle_update;

// Paddle positions
extern const uint8_t MCU_X;
extern uint8_t mcu_y;
extern const uint8_t PLAYER_X;
extern uint8_t player_y;

// Function prototypes
void delay_ms(uint32_t ms);
void drawCourt(void);
void drawGame(void);
void resetGame(void);
void pong_setup(void);
void pong_loop(void);

#endif
