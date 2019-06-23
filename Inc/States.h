/*
 * States.h
 *
 *  Created on: 6 de jun de 2019
 *      Author: Ariel
 */

#ifndef INC_STATES_H_
#define INC_STATES_H_

#include "StateManager.h"
#include "NOKIA5110_fb.h"

#define ARROW_WIDTH 21
#define ARROW_HEIGHT 21
#define ARROW_INITIAL_VELOCITY 50
#define ARROW_INITIAL_DISTANCE 10
#define ARROW_Y_POSITION 20
#define ARROW_X_SPOT 65
#define ARROW_X_MARGIN 10

#define ARROW_INITIAL_COUNTER 100

typedef struct {
	unsigned points;
	unsigned lifes;
	unsigned seed;
	unsigned min_dist;
	unsigned vel;
	unsigned counter;
} GameInfo_t;

extern StateManagerState_t StartScene;
extern StateManagerState_t GameScene;
extern StateManagerState_t PauseScene;
extern StateManagerState_t GameOverScene;

#define getGameInfo(info) ((GameInfo_t *)info->others)

extern const unsigned char GameBackgroundImage[];

extern const struct figura_t FiguraArrowRightAcesos;
extern const struct figura_t FiguraArrowRightApagados;

extern const struct figura_t FiguraArrowLeftAcesos;
extern const struct figura_t FiguraArrowLeftApagados;

extern const struct figura_t FiguraArrowUpAcesos;
extern const struct figura_t FiguraArrowUpApagados;

extern const struct figura_t FiguraArrowDownAcesos;
extern const struct figura_t FiguraArrowDownApagados;


void FigurasDrawLifes(GameInfo_t *gameInfo);
void FigurasDrawPoints(GameInfo_t *gameInfo);


#endif /* INC_STATES_H_ */
