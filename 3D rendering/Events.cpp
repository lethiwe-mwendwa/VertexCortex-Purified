#include "events.h"
#include "Input.h"
#include "Constants.h"

void appEvents(SDL_Event event, SDL_Renderer* renderer) {
	if (event.type == SDL_QUIT) {
		running = false;
		SDL_Quit();
	}
	if (event.type == SDL_KEYDOWN) {
		keyboardInput(event);
	}
	//if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
	//	
	//}
}