/*
 * GameOver.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */
#include "States.h"
#include "StateManager.h"
#include "NOKIA5110_fb.h"

static void GameOverSceneInit(StateManagerInfo_t *info)
{
	GameInfo_t *gameInfo = getGameInfo(info);

	escreve2fb(GameBackgroundImage);

	FigurasDrawLifes(gameInfo);
	FigurasDrawPoints(gameInfo);

	goto_XY(6, 3);
	string_LCD("Game Over");
}

static void GameOverSceneUpdate(StateManagerInfo_t *info)
{
	//GameInfo_t *gameInfo = getGameInfo(info);
	StateManagerEvent_t event = info->ev;

	if (event == StateManagerEvent_JOYSTICK_DOWN) {
			StateManagerPop();
	}
}

static void GameOverSceneDraw(StateManagerInfo_t *info) {
}

static void GameOverSceneDestroy(StateManagerInfo_t *info) {
	GameInfo_t *gameinfo = getGameInfo(info);
	gameinfo->lifes = 5;
}

StateManagerState_t GameOverScene = { init: GameOverSceneInit, update: GameOverSceneUpdate, draw: GameOverSceneDraw, destroy: GameOverSceneDestroy};
