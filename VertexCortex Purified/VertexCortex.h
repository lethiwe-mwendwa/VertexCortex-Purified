#pragma once
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

#define VertexCortexApp int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);



