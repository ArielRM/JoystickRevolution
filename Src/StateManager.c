/*
 * StateControl.c
 *
 *  Created on: 6 de jun de 2019
 *      Author: Ariel
 */

#include "StateManager.h"
#include "stdlib.h"

static struct {
	int top;
	StateManagerInfo_t info;
	StateManagerState_t *stack[STATEMANAGER_STACKSIZE];
} StateManager;


void StateManagerInit(void *gameInfo) {
	StateManager.top = -1;
	StateManager.info.others = gameInfo;
}

int StateManagerPush(StateManagerState_t * state) {

	if (StateManager.top + 1 == STATEMANAGER_STACKSIZE)
		return 1;

	StateManager.top++;
	StateManager.stack[StateManager.top] = state;

	if (state->init != NULL)
		state->init(&StateManager.info);

	return 0;
}

int StateManagerPop(void) {
	const StateManagerState_t * const top = StateManagerTop();

	if (top == NULL)
		return 1;

	if (top->destroy != NULL)
		top->destroy(&StateManager.info);

	StateManager.stack[StateManager.top] = NULL;
	StateManager.top--;

	return 0;
}

const StateManagerState_t *StateManagerTop(void) {
	if (StateManager.top == -1)
		return NULL;

	return StateManager.stack[StateManager.top];
}

void StateManagerUpdate(StateManagerEvent_t ev) {
	const StateManagerState_t * const top = StateManagerTop();

	StateManager.info.ev = ev;

	if (top != NULL && top->update != NULL)
		top->update(&StateManager.info);
}

void StateManagerDraw(void) {
	const StateManagerState_t * const top = StateManagerTop();

	if (top != NULL && top->draw != NULL)
		top->draw(&StateManager.info);
}
