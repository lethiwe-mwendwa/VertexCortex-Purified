#include "SDL.h"
#include <iostream>
#include "TriangularP.h"
#include "Cube.h"
#include "Entities.h"
#include "Events.h"
#include "Window.h"
#include "Shape.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	//	Window and Renderer creation
	SDL_Window* window = SDL_CreateWindow("3D Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;

	// Create a shape
	Cube* BadabingBadaBoom = new Cube();

	// Render all the elements
	renderWindow(renderer);

	// Main loop
	while (running) {
		while (SDL_PollEvent(&event)) {
			appEvents(event, renderer);
		}
	}

	SDL_Delay(500);
	SDL_Quit();
	return 0;
	
}