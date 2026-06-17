#pragma once
#include "Windows.h"
#include "framebuffer.h"
#include "time.h"

class Window
{

public:
	Window(const wchar_t* ClassName, const wchar_t* WindowText,HINSTANCE hInstance, int nCmdShow);
	~Window();
	
	bool isRunning = false;
	HWND handler;
	frameBuffer* mainBuffer;
	Clock timer;

	void display();

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

