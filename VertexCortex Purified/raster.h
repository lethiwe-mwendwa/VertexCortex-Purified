#pragma once
#include "framebuffer.h"
#include <iostream>

void render(frameBuffer&);

void drawLine(int x0, int x1, int y0, int y1, uint32_t colour, frameBuffer*);

void drawRect(int x, int y, int width, int height, uint32_t colour, frameBuffer*);

void drawTriangle(int x, int y, int z, uint32_t colour, frameBuffer*);
