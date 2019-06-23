/*
 * Pause.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */
#include "States.h"
#include "StateManager.h"
#include "NOKIA5110_fb.h"

static void PauseSceneInit(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);

	escreve2fb(GameBackgroundImage);

	FigurasDrawLifes(gameInfo);
	FigurasDrawPoints(gameInfo);

	goto_XY(14, 3);
	string_LCD("Resume");
}

static void PauseSceneUpdate(StateManagerInfo_t *info) {
	//GameInfo_t *gameInfo = getGameInfo(info);
	StateManagerEvent_t event = info->ev;

	if (event == StateManagerEvent_JOYSTICK_DOWN)
		StateManagerPop();
}

static void PauseSceneDraw(StateManagerInfo_t *info) {

}

StateManagerState_t PauseScene = { init: PauseSceneInit, update: PauseSceneUpdate, draw: PauseSceneDraw };
