/*
 * Start.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */

#include "States.h"
#include "StateManager.h"
#include "NOKIA5110_fb.h"
#include "PRNG_LFSR.h"
#include "sound.h"

static void StartSceneInit(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);

	gameInfo->lifes = 5;
	gameInfo->points = 0;
	gameInfo->seed = 1;


}

static void StartSceneUpdate(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);
	StateManagerEvent_t event = info->ev;
	note_t n;

	if (event == StateManagerEvent_TIME) {
		gameInfo->seed++;
	} else if (event == StateManagerEvent_JOYSTICK_DOWN) {
		n.duration = 1000;
		n.tone = NOTE_A1;
		//SoundPlay(&n);
		StateManagerPush(&GameScene);
	}

	switch (event)
	{
	case StateManagerEvent_JOYSTICK_NORTH:
		n.duration = 500;
		n.tone = NOTE_B4;
		//SoundPlay(&n);
		break;
	case StateManagerEvent_JOYSTICK_EAST:
		n.duration = 500;
		n.tone = NOTE_C4;
		//SoundPlay(&n);
		break;
	case StateManagerEvent_JOYSTICK_SOUTH:
		n.duration = 500;
		n.tone = NOTE_D4;
		//SoundPlay(&n);
		break;
	case StateManagerEvent_JOYSTICK_WEST:
		n.duration = 500;
		n.tone = NOTE_E4;
		//SoundPlay(&n);
		break;
	}
}

static void StartSceneDraw(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);
	escreve2fb(GameBackgroundImage);

	FigurasDrawLifes(gameInfo);
	FigurasDrawPoints(gameInfo);

	goto_XY(14, 3);
	string_LCD("Start");
}

StateManagerState_t StartScene = { init: StartSceneInit, update: StartSceneUpdate, draw : StartSceneDraw, };
