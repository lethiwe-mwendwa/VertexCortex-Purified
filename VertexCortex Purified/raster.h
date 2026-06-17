#pragma once
#include "framebuffer.h"
#include <iostream>
#include "vertex.h"

void render(frameBuffer&);

// TODO!! Update to use math.h
void drawLine(int x0, int x1, int y0, int y1, uint32_t colour, frameBuffer&);

// TODO!! Update to use math.h
void drawRect(int x, int y, int width, int height, uint32_t colour, frameBuffer&);

void drawTriangleWireframe(Vec2,Vec2,Vec2, uint32_t colour, frameBuffer&);
