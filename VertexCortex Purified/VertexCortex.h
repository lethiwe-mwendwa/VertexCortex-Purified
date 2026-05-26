#pragma once
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

#define VertexCortexApp INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  INT nCmdShow)

void setup();

void update(float deltaTime);

void destroy();


//void onResize(int width, int height);

//void onClose();

//void onKeyDown(WPARAM key);

//void onKeyUp(WPARAM key);