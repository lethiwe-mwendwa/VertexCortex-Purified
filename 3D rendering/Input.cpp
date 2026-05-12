#include "input.h"
#include <iostream>

void keyboardInput(SDL_Event event) {

	switch (event.key.keysym.sym) {
		case SDLK_UP:

			break;
		case SDLK_DOWN:

			break;
		case SDLK_LEFT:

			break;
		case SDLK_RIGHT:

			break;


		case SDLK_w:

			break;
		case SDLK_s:

			break;
		case SDLK_a:

			break;
		case SDLK_d:

			break;

		default:
			std::cout << "Key Not Configured";
	}
		
}