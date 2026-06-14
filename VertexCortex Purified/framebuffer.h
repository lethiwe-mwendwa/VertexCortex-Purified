#pragma once
#include "Windows.h"
#include <iostream>

class frameBuffer
{

public:

	frameBuffer(size_t width, size_t height);

	~frameBuffer();

	void clear(uint32_t); void setPixel(size_t, size_t, uint32_t);
	void drawLine(int x0, int x1, int y0, int y1, uint32_t colour);
	void drawRect(int x, int y, int width, int height, uint32_t colour); void drawCircle(int x, int y, int radius, uint32_t colour);

	const uint32_t* getColourData();

	BITMAPINFO bitmapInfo;

	// For win32 use
	void present(HDC deviceContext);

private:

	size_t width;
	size_t height;

	// Use BGR storage
	uint32_t* colourBuffer;

};

class Clock
{

public:
	Clock();

	float dt;

	// Updates dt
	void tick();

private:

	LARGE_INTEGER lastTime;
	LARGE_INTEGER counterFrequency;

};

uint32_t packColorBGR(uint8_t r, uint8_t g, uint8_t b);

void render(frameBuffer&);