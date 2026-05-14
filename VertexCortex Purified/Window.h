#pragma once
#include "Windows.h"
#include <iostream>
extern bool applicationState;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{

public:
	Window(const wchar_t* ClassName, const wchar_t* WindowText,HINSTANCE hInstance, int nCmdShow);

	HWND handler;

protected:
	const wchar_t* WindowText;
	const wchar_t* CLASS_NAME;

private:

	int nCmdShow;
	WNDCLASS WindowClass = { };
	HINSTANCE* hInstance;

	void registerWindowClass();

};


