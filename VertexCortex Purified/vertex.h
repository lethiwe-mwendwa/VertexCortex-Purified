#pragma once
#include "math.h"
#include <iostream>

struct Vertex {

	// for now, we're sticking to 2d for simplicity. 3d will come when it comes.
	Vec2 position;

	uint32_t colour = (255) | (255 << 8) | (255 << 16); // Defaults to white.
};

