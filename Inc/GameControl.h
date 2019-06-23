/*
 * GameCntrol.h
 *
 *  Created on: 6 de jun de 2019
 *      Author: Ariel
 */


#ifndef INC_GAMECONTROL_H_
#define INC_GAMECONTROL_H_

#include "StateManager.h"

void GameControlTask(void *vParam);
void GameControlSendEvent(StateManagerEvent_t ev);

#endif /* INC_GAMECONTROL_H_ */
