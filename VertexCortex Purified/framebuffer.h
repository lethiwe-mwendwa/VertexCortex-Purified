#pragma once
#include "Windows.h"
#include <iostream>

class frameBuffer
{

public:

	frameBuffer(size_t width, size_t height);

	~frameBuffer();

	void clear(uint32_t); 
	
	void setPixel(size_t, size_t, uint32_t);

	const uint32_t* getColourData();

	BITMAPINFO bitmapInfo;

	// For win32 use. TODO!!!! REMOVE EVERYTHING RELATED TO WIN32 HERE
	void present(HDC deviceContext);

	size_t width;
	size_t height;

	// Use BGR storage
	uint32_t* colourBuffer;

private:


};

uint32_t packColorBGR(uint8_t r, uint8_t g, uint8_t b);

