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

	// For win32 use
	void present(HDC deviceContext);

private:

	size_t width;
	size_t height;

	// Use BGR storage
	uint32_t* colourBuffer;

	uint32_t packColor(uint8_t r, uint8_t g, uint8_t b);

};

class Window
{

public:
	Window(const wchar_t* ClassName, const wchar_t* WindowText,HINSTANCE hInstance, int nCmdShow);
	bool isRunning = false;
	HWND handler;
	frameBuffer* mainBuffer;

protected:
	const wchar_t* WindowText;
	const wchar_t* CLASS_NAME;

private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	int nCmdShow;
	WNDCLASS WindowClass = { };
	HINSTANCE hInstance;

	void registerWindowClass();

};

