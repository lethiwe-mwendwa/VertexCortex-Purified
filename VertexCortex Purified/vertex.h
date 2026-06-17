#pragma once
#include <iostream>

struct Vertex {

	// for now, we're sticking to 2d. 3d will come when it comes.
	// 
	// NOTE THAT THIS IS WORLD POSITION. We will work on representing pos values differently later when we have
	// a projection system up and running
	int x = 0;
	int y = 0;

	uint32_t colour = (255) | (255 << 8) | (255 << 16); // Defaults to white.
};