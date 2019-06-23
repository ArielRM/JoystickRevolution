/*
 * sound.c
 *
 *  Created on: 5 de jun de 2019
 *      Author: Ariel
 */
#include "sound.h"
#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "defPrincipais.h"

static QueueHandle_t SoundQueue;

static void SoundSetTone(SoundCfg_t *cfg, tone_t t)
{

}

static void SoundSetVolume(SoundCfg_t * cfg, uint16_t value)
{
	HAL_TIM_PWM_Stop(cfg->htimx, cfg->channel);

    TIM_OC_InitTypeDef sConfigOC;

    sConfigOC.OCMode = TIM_OCMODE_PWM1;
    sConfigOC.Pulse = value;
    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
    HAL_TIM_PWM_ConfigChannel(cfg->htimx, &sConfigOC, cfg->channel);
    HAL_TIM_PWM_Start(cfg->htimx, cfg->channel);
}

void SoundTask(void *param)
{
	SoundCfg_t *cfg = (SoundCfg_t *)param;
	SoundQueue = cfg->note_t_queue;

	SoundSetVolume(cfg, 100);

	note_t n;
	unsigned i = 31;
	while(1)
	{
//		SoundSetVolume(cfg, 0);
//		BaseType_t r = xQueueReceive(SoundQueue, &n, portMAX_DELAY);
//
//		if (r == pdTRUE)
//		{
//			SoundSetVolume(cfg, 100);
//			SoundSetTone(cfg, n.tone);
//			vTaskDelay(MS(n.duration));
//		}
	}
}


void SoundPlay(note_t *n)
{
	while(xQueueSend(SoundQueue,n, 0) != pdTRUE);
}
