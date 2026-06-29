#pragma once
#include "framebuffer.h"
#include <iostream>

struct Vertex2;
struct Vec2; // Forward declare so that I avoid circular include dependency. vertex.h is included in raster.cpp

struct Colour {
	int r;
	int g;
	int b;

};

// This might benefit being in the engine folder
void render(frameBuffer&);

// TODO!! Update to use math.h
void drawLine(int x0, int x1, int y0, int y1, uint32_t colour, frameBuffer&);

// TODO!! Update to use math.h
void drawRect(int x, int y, int width, int height, uint32_t colour, frameBuffer&);

// (uses clockwise order)
void drawTriangleWireframe(Vec2,Vec2,Vec2, uint32_t colour, frameBuffer&);

// This is blends the colours from the vertexes
void drawTriangle(Vertex2, Vertex2, Vertex2, frameBuffer&);

// To figure out if a point (x,y) is inside a given triangle.
// Inside corresponds to positive edge values for our vertex order and screen coordinate system.
float edgeFunction(Vec2 A, Vec2 B, Vec2 P);
