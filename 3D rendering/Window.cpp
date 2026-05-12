#include "Window.h"
#include "Entities.h"
#include <SDL.h>

void renderWindow(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	renderEntities(renderer);
	SDL_RenderPresent(renderer);
}