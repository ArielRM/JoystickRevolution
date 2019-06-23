/*
 * StateManager.h
 *
 *  Created on: 6 de jun de 2019
 *      Author: Ariel
 */

#ifndef INC_STATEMANAGER_H_
#define INC_STATEMANAGER_H_

typedef enum {
	StateManagerEvent_NONE = 0,
	StateManagerEvent_JOYSTICK_NORTH,
	StateManagerEvent_JOYSTICK_EAST,
	StateManagerEvent_JOYSTICK_SOUTH,
	StateManagerEvent_JOYSTICK_WEST,
	StateManagerEvent_JOYSTICK_DOWN,
	StateManagerEvent_TIME,
} StateManagerEvent_t;

typedef struct {
	StateManagerEvent_t ev;
	void *others;
} StateManagerInfo_t;

typedef struct {
	void (* const init)(StateManagerInfo_t *info);
	void (* const update)(StateManagerInfo_t *info);
	void (* const draw)(StateManagerInfo_t *info);
	void (* const destroy)(StateManagerInfo_t *info);
} StateManagerState_t;

const StateManagerState_t *StateManagerTop(void);

void StateManagerInit(void *gameInfo);
void StateManagerUpdate(StateManagerEvent_t ev);
void StateManagerDraw(void);

int StateManagerPush(StateManagerState_t * state);
int StateManagerPop();

#define STATEMANAGER_STACKSIZE 3

#endif /* INC_STATEMANAGER_H_ */
