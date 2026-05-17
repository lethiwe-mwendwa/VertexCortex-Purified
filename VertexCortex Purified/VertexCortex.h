#pragma once
#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

#define VertexCortexApp INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_  LPSTR lpCmdLine, _In_  INT nCmdShow)

void setup();

void update();

void render();

void destroy();

