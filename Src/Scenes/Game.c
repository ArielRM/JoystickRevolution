/*
 * Game.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */

#include "States.h"
#include "StateManager.h"
#include "NOKIA5110_fb.h"
#include "PRNG_LFSR.h"
#include "ArrowQueue.h"

static void GameSceneInit(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);

	gameInfo->lifes = 5;
	gameInfo->points = 0;
	gameInfo->min_dist = ARROW_INITIAL_DISTANCE;
	gameInfo->vel = ARROW_INITIAL_VELOCITY;
	gameInfo->counter = 0;

	init_LFSR(gameInfo->seed);
	arrowQueueInit();
}

void GameSceneUpdateCallback(arrow_t *arrow)
{
	arrow->x++;
}

static void GameSceneError(GameInfo_t *gameInfo)
{
	gameInfo->lifes--;
}

static void GameSceneOK(GameInfo_t *gameInfo, unsigned percent)
{
	if (gameInfo->vel < gameInfo->points)
		gameInfo->vel *= 2;
//	else if (gameInfo->min_dist > ARROW_WIDTH)
//		 gameInfo->min_dist--;
	gameInfo->points += percent/10;
	arrowQueueDequeue();
}

static void GameSceneCreateArrow(void)
{
	arrow_t a;
	a.x = 0;
	switch (prng_LFSR() % 4)
	{
	case 0:
		a.dir = ARROW_DIRECTION_EAST;
		break;
	case 1:
		a.dir = ARROW_DIRECTION_NORTH;
		break;
	case 2:
		a.dir = ARROW_DIRECTION_SOUTH;
		break;
	case 3:
		a.dir = ARROW_DIRECTION_WEST;
	}

	arrowQueueEnqueue(&a);
}

static void GameSceneJoystickEvent(StateManagerInfo_t *info)
{
	unsigned percent;
	GameInfo_t *gameInfo = getGameInfo(info);
	StateManagerEvent_t event = info->ev;

	arrow_t last;

	if (arrowQueuePeekTail(&last) == 0)
	{
		GameSceneError(gameInfo);
		return;
	}

	if (last.x > ARROW_X_SPOT  && last.x < 84 + ARROW_WIDTH)
	{
		if (last.x <= 84)
		{
			percent = (last.x - ARROW_X_SPOT);
		}
		else
		{
			percent = (84 + ARROW_WIDTH - last.x);
		}
		percent *= 100;
		percent /= ARROW_WIDTH;
	} else {
		percent = 0;
	}

	if (	(event == StateManagerEvent_JOYSTICK_NORTH && last.dir != ARROW_DIRECTION_NORTH) ||
			(event == StateManagerEvent_JOYSTICK_SOUTH && last.dir != ARROW_DIRECTION_SOUTH) ||
			(event == StateManagerEvent_JOYSTICK_WEST && last.dir != ARROW_DIRECTION_WEST) ||
			(event == StateManagerEvent_JOYSTICK_EAST && last.dir != ARROW_DIRECTION_EAST))
		GameSceneError(gameInfo);
	else if (percent != 0)
		GameSceneOK(gameInfo, percent);
	else
		GameSceneError(gameInfo);
}

static void GameSceneUpdate(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);
	StateManagerEvent_t event = info->ev;

	arrow_t last;

	if (arrowQueuePeekTail(&last) == 0)
	{
		GameSceneCreateArrow();
	}
	else if (last.x > 84 + ARROW_WIDTH)
	{
		GameSceneError(gameInfo);
		arrowQueueDequeue();
	}

	if (arrowQueuePeekHead(&last))
	{
		if (last.x > ARROW_WIDTH + gameInfo->min_dist)
			GameSceneCreateArrow();
	}


	if (event == StateManagerEvent_TIME)
	{
		if (gameInfo->counter + gameInfo->vel >= ARROW_INITIAL_COUNTER)
		{
			gameInfo->counter = 0;
			arrowQueueForEach(GameSceneUpdateCallback);
		} else {
			gameInfo->counter += gameInfo->vel;
		}
	}
	else if (event == StateManagerEvent_JOYSTICK_DOWN)
	{
		StateManagerPush(&PauseScene);
	}
	else
		GameSceneJoystickEvent(info);

	if (gameInfo->lifes == 0)
	{
		StateManagerPop();
		StateManagerPush(&GameOverScene);
	}
}

static void GameSceneDrawCallback(arrow_t *arrow)
{
	if (arrow->x == 0)
		return;

	struct pontos_t p = {0};
	p.y1 = ARROW_Y_POSITION;

	if (arrow->x < ARROW_WIDTH)
	{
		p.x1 = 0;
		p.x3 = arrow->x;
		p.y3 = ARROW_HEIGHT;
	}
	else
		p.x1 = arrow->x - ARROW_WIDTH;

	switch(arrow->dir)
	{
	case ARROW_DIRECTION_NORTH:
		desenha_fig_transparente(&p, &FiguraArrowUpAcesos, &FiguraArrowUpApagados);
		break;
	case ARROW_DIRECTION_SOUTH:
		desenha_fig_transparente(&p, &FiguraArrowDownAcesos, &FiguraArrowDownApagados);
		break;
	case ARROW_DIRECTION_EAST:
		desenha_fig_transparente(&p, &FiguraArrowRightAcesos, &FiguraArrowRightApagados);
		break;
	case ARROW_DIRECTION_WEST:
		desenha_fig_transparente(&p, &FiguraArrowLeftAcesos, &FiguraArrowLeftApagados);
		break;
	}
}

static void GameSceneDraw(StateManagerInfo_t *info) {
	GameInfo_t *gameInfo = getGameInfo(info);

	escreve2fb(GameBackgroundImage);

	FigurasDrawLifes(gameInfo);
	FigurasDrawPoints(gameInfo);

	arrowQueueForEach(GameSceneDrawCallback);
}

StateManagerState_t GameScene= { init: GameSceneInit, update: GameSceneUpdate, draw: GameSceneDraw, };
