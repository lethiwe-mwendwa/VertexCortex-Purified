#pragma once
#include "Windows.h"
#include <iostream>

class Window
{

public:
	Window(const wchar_t* ClassName, const wchar_t* WindowText,HINSTANCE hInstance, int nCmdShow);
	bool isRunning = false;
	HWND handler;

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


class frameBuffer
{
public:
	frameBuffer(size_t width, size_t height);

	~frameBuffer();

	void clear(uint32_t);
	
	void setPixel(int x, int y, uint32_t);

	const uint32_t* getColourData();

private:

	size_t width;
	size_t height;

	uint32_t* colourBuffer;


};