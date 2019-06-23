/*
 * Joystick.h
 *
 *  Created on: 11 de jun de 2019
 *      Author: Ariel
 */

#ifndef INC_JOYSTICK_H_
#define INC_JOYSTICK_H_

#include "stdint.h"
#include "main.h"
#include "stm32f1xx_hal.h"

//extern ADC_HandleTypeDef hadc1;
//extern DMA_HandleTypeDef hdma_adc1;

#define JOYSTICK_BUTTON_PORT (GPIOC)
#define JOYSTICK_BUTTON_PIN (GPIO_PIN_15)

#define JOYSTICK_BUTTON_READ() (HAL_GPIO_ReadPin(JOYSTICK_BUTTON_PORT, JOYSTICK_BUTTON_PIN))

typedef enum {
	JoystickPosition_NONE = 0,
	JoystickPosition_NORTH,
	JoystickPosition_EAST,
	JoystickPosition_SOUTH,
	JoystickPosition_WEST,
	JoystickPosition_DOWN,
	JoystickPosition_ERROR,
} JoystickPosition_t;

void JoystickInit(unsigned *x_buffer, unsigned *y_buffer);
JoystickPosition_t JoystickGetPosition(void);
void JoystickTask(void *vParam);


extern unsigned *JoystickXBuffer;
extern unsigned *JoystickYBuffer;


#endif /* INC_JOYSTICK_H_ */
