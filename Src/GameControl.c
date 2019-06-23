#include "StateManager.h"
#include "cmsis_os.h"
#include "States.h"
#include "defPrincipais.h"
#include "NOKIA5110_fb.h"
#include "GameControl.h"

static QueueHandle_t GameControlQueueHandle;

void GameControlTask(void *vParam) {
	GameControlQueueHandle = xQueueCreate(10, sizeof(StateManagerEvent_t));

	StateManagerEvent_t ev;

	GameInfo_t info;

	StateManagerInit((void*) &info);

	StateManagerPush(&StartScene);

	while (1) {
		BaseType_t r = xQueueReceive(GameControlQueueHandle, &ev, 0);
		if (r != pdTRUE) {
			ev = StateManagerEvent_TIME;
			StateManagerUpdate(ev);
			StateManagerDraw();
			imprime_LCD();
			vTaskDelay(MS(10));
		} else {
			StateManagerUpdate(ev);
			StateManagerDraw();
			imprime_LCD();
		}
	}
}

void GameControlSendEvent(StateManagerEvent_t ev) {
	while (xQueueSend(GameControlQueueHandle, &ev, 0) != pdTRUE)
		;
}
