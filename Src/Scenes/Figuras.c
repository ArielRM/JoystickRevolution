/*
 * Figuras.c
 *
 *  Created on: 17 de jun de 2019
 *      Author: Ariel
 */
#include "NOKIA5110_fb.h"
#include "States.h"

const unsigned char GameBackgroundImage[] = {
		0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x01, 0x01, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
		};


const struct figura_t FiguraArrowDownAcesos = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0xF8, 	0xFC, 	0x06, 	0x03, 	0xF3, 	0xFB, 	0xF3, 	0x03, 	0x06, 	0xFC, 	0xF8, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
0x0C, 	0x1E, 	0x33, 	0x63, 	0xCB, 	0x9B, 	0x39, 	0x7C, 	0xFE, 	0xFF, 	0xFF, 	0xFF, 	0xFE, 	0x7C, 	0x39, 	0x9B, 	0xCB, 	0x63, 	0x33, 	0x1E, 	0x0C,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x01, 	0x03, 	0x06, 	0x0C, 	0x19, 	0x1B, 	0x19, 	0x0C, 	0x06, 	0x03, 	0x01, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

const struct figura_t FiguraArrowDownApagados = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0xF8, 	0xFC, 	0x0C, 	0x04, 	0x0C, 	0xFC, 	0xF8, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
0x00, 	0x00, 	0x0C, 	0x1C, 	0x34, 	0x64, 	0xC6, 	0x83, 	0x01, 	0x00, 	0x00, 	0x00, 	0x01, 	0x83, 	0xC6, 	0x64, 	0x34, 	0x1C, 	0x0C, 	0x00, 	0x00,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x01, 	0x03, 	0x06, 	0x04, 	0x06, 	0x03, 	0x01, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

/*************************************************************************************************************************************************************************/

const struct figura_t FiguraArrowUpAcesos = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x80, 	0xC0, 	0x60, 	0x30, 	0x98, 	0xCC, 	0xE6, 	0xF3, 	0xFB, 	0xF3, 	0xE6, 	0xCC, 	0x98, 	0x30, 	0x60, 	0xC0, 	0x80, 	0x00, 	0x00,
0x06, 	0x0F, 	0x19, 	0x18, 	0x1A, 	0xFB, 	0xF3, 	0x07, 	0x0F, 	0xFF, 	0xFF, 	0xFF, 	0x0F, 	0x07, 	0xF3, 	0xFB, 	0x1A, 	0x18, 	0x19, 	0x0F, 	0x06,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x03, 	0x07, 	0x0C, 	0x18, 	0x19, 	0x1B, 	0x19, 	0x18, 	0x0C, 	0x07, 	0x03, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

const struct figura_t FiguraArrowUpApagados = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x00, 	0x00, 	0x80, 	0xC0, 	0x60, 	0x30, 	0x18, 	0x0C, 	0x04, 	0x0C, 	0x18, 	0x30, 	0x60, 	0xC0, 	0x80, 	0x00, 	0x00, 	0x00, 	0x00,
0x00, 	0x00, 	0x06, 	0x07, 	0x05, 	0x04, 	0x0C, 	0xF8, 	0xF0, 	0x00, 	0x00, 	0x00, 	0xF0, 	0xF8, 	0x0C, 	0x04, 	0x05, 	0x07, 	0x06, 	0x00, 	0x00,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x03, 	0x07, 	0x06, 	0x04, 	0x06, 	0x07, 	0x03, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

/*************************************************************************************************************************************************************************/

const struct figura_t FiguraArrowLeftAcesos = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x80, 	0xC0, 	0x60, 	0x30, 	0x98, 	0xCC, 	0xE6, 	0xF3, 	0x83, 	0x3E, 	0x7C, 	0x60, 	0x60, 	0x60, 	0x60, 	0x60, 	0xC0, 	0x80, 	0x00,
0x0E, 	0x1F, 	0x31, 	0x64, 	0xCE, 	0x9F, 	0x3F, 	0x7F, 	0xFF, 	0xFF, 	0x3F, 	0x9F, 	0xCE, 	0xCE, 	0xCE, 	0xCE, 	0xCE, 	0xC4, 	0x60, 	0x3F, 	0x1F,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x01, 	0x03, 	0x06, 	0x0C, 	0x19, 	0x18, 	0x0F, 	0x07, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

const struct figura_t FiguraArrowLeftApagados = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x00, 	0x00, 	0x80, 	0xC0, 	0x60, 	0x30, 	0x18, 	0x0C, 	0x7C, 	0xC0, 	0x80, 	0x80, 	0x80, 	0x80, 	0x80, 	0x80, 	0x00, 	0x00, 	0x00,
0x00, 	0x00, 	0x0E, 	0x1B, 	0x31, 	0x60, 	0xC0, 	0x80, 	0x00, 	0x00, 	0xC0, 	0x60, 	0x31, 	0x31, 	0x31, 	0x31, 	0x31, 	0x3B, 	0x1F, 	0x00, 	0x00,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x01, 	0x03, 	0x06, 	0x07, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

/*************************************************************************************************************************************************************************/

const struct figura_t FiguraArrowRightAcesos = { largura: 21, altura: 21, pixels: {
0x00, 	0x80, 	0xC0, 	0x60, 	0x60, 	0x60, 	0x60, 	0x60, 	0x7C, 	0x3E, 	0x83, 	0xF3, 	0xE6, 	0xCC, 	0x98, 	0x30, 	0x60, 	0xC0, 	0x80, 	0x00, 	0x00,
0x1F, 	0x3F, 	0x60, 	0xC4, 	0xCE, 	0xCE, 	0xCE, 	0xCE, 	0xCE, 	0x9F, 	0x3F, 	0xFF, 	0xFF, 	0x7F, 	0x3F, 	0x9F, 	0xCE, 	0x64, 	0x31, 	0x1F, 	0x0E,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x07, 	0x0F, 	0x18, 	0x19, 	0x0C, 	0x06, 	0x03, 	0x01, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

const struct figura_t FiguraArrowRightApagados = { largura: 21, altura: 21, pixels: {
0x00, 	0x00, 	0x00, 	0x80, 	0x80, 	0x80, 	0x80, 	0x80, 	0x80, 	0xC0, 	0x7C, 	0x0C, 	0x18, 	0x30, 	0x60, 	0xC0, 	0x80, 	0x00, 	0x00, 	0x00, 	0x00,
0x00, 	0x00, 	0x1F, 	0x3B, 	0x31, 	0x31, 	0x31, 	0x31, 	0x31, 	0x60, 	0xC0, 	0x00, 	0x00, 	0x80, 	0xC0, 	0x60, 	0x31, 	0x1B, 	0x0E, 	0x00, 	0x00,
0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x07, 	0x06, 	0x03, 	0x01, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00, 	0x00,
}};

/*************************************************************************************************************************************************************************/

const struct figura_t StatesHeartFig = { largura: 7, altura: 5, pixels: { 0x02,
		0x07, 0x0F, 0x1E, 0x0F, 0x07, 0x02 } };


void FigurasDrawLifes(GameInfo_t *gameInfo)
{
	unsigned i;
	struct pontos_t p;
	p.x1 = 10;
	p.y1 = 2;
	for (i = 0; i < gameInfo->lifes; i++, p.x1+=10)
	{
		desenha_fig(&p, &StatesHeartFig);
	}
}

void FigurasDrawPoints(GameInfo_t *gameInfo)
{
	escreve_Nr_Peq(67, 2, gameInfo->points, 4);
}


