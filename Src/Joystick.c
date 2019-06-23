/*
 * Joystick.c
 *
 *  Created on: 11 de jun de 2019
 *      Author: Ariel
 */
#include "Joystick.h"
#include "GameControl.h"
#include "StateManager.h"
#include "defPrincipais.h"
#include "cmsis_os.h"

unsigned *JoystickXBuffer;
unsigned *JoystickYBuffer;

void JoystickTask(void *vParam)
{
	unsigned current_status =JOYSTICK_BUTTON_READ();
	unsigned last_status = current_status;

	unsigned current_e =JoystickGetPosition();
	unsigned last_e = current_e;

	do {

		current_status = JOYSTICK_BUTTON_READ();
		if (current_status == 0 && last_status == 1)
		{
			GameControlSendEvent(StateManagerEvent_JOYSTICK_DOWN);
			vTaskDelay(MS(20));
		}
		last_status = current_status;

		current_e = JoystickGetPosition();
		if (current_e != last_e)
		{
			switch (JoystickGetPosition())
			{
					case JoystickPosition_NORTH:
						GameControlSendEvent(StateManagerEvent_JOYSTICK_NORTH);
						break;
					case JoystickPosition_EAST:
						GameControlSendEvent(StateManagerEvent_JOYSTICK_EAST);
						break;
					case JoystickPosition_SOUTH:
						GameControlSendEvent(StateManagerEvent_JOYSTICK_SOUTH);
						break;
					case JoystickPosition_WEST:
						GameControlSendEvent(StateManagerEvent_JOYSTICK_WEST);
						break;
					default:
						break;
			}
						vTaskDelay(MS(20));
		}
		last_e = current_e;


	} while(1);
}

void JoystickInit(unsigned *x_buffer, unsigned *y_buffer)
{
	JoystickXBuffer = x_buffer;
	JoystickYBuffer = y_buffer;
}

#define DEAD_ZONE 600

JoystickPosition_t JoystickGetPosition(void)
{

	int x = *JoystickXBuffer - 2047;
	int y = *JoystickYBuffer - 2047;

	if (x < -DEAD_ZONE)
	{
		return JoystickPosition_WEST;
	}

	if (x > DEAD_ZONE)
	{
		return JoystickPosition_EAST;
	}

	if (y < -DEAD_ZONE)
	{
		return JoystickPosition_SOUTH;
	}

	if (y > DEAD_ZONE)
	{
		return JoystickPosition_NORTH;
	}

	return JoystickPosition_NONE;
}

