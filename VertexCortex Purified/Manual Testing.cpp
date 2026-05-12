// VertexCortex Purified Testing

#include "VertexCortex.h"
#include "Window.h"
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

VertexCortexApp
{
	wchar_t ClassName[] = L"MainWindow";
	wchar_t WindowText[] = L"VertexCortexApplication";

	Window MainWindow(ClassName,WindowText,hInstance, nCmdShow);

	if (MainWindow.handler == NULL)
	{
		return 0;
	}

	ShowWindow(MainWindow.handler, nCmdShow);

	// game init code
	MSG msg = { };
	while (applicationState) {
		// 1. Process Windows Messages (Prevents freezing)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) applicationState = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		// 2. Game Update Code
		// 
		// 3. Game Render Code
	}

	// game destroy code

	return 0;
	
}