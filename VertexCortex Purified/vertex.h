#pragma once
#include "math.h"
#include "raster.h"
#include <iostream>

struct Vertex3 {

	Vec3 pos;

	//uint32_t colour = (255) | (255 << 8) | (255 << 16); // Defaults to white.

	Colour colour;
};

struct Vertex2 {

	// for now, we're sticking to 2d for simplicity. 3d will come when it comes. preemtively the Vertex3 is defined up there.
	Vec2 pos;

	//uint32_t colour = (255) | (255 << 8) | (255 << 16); // Defaults to white.

	Colour colour;
};


