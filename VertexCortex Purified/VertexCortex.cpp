#include "VertexCortex.h"
#include "Window.h"


// MAIN FUNCTION
VertexCortexApp
{
	// game init code
	setup();

	// Create window
	wchar_t ClassName[] = L"MainWindow";
	wchar_t WindowText[] = L"VertexCortexApplication";
	Window MainWindow(ClassName,WindowText,hInstance, nCmdShow);
	if (MainWindow.handler == NULL) { return 0; }
	ShowWindow(MainWindow.handler, nCmdShow);

	// game loop

	while (applicationState) {
		MSG msg = { };
		// 1. Process Windows Messages (Prevents freezing)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) applicationState = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// 2. Game Update Code
		update();
		
		// 3. Game Render Code
		render();
	}

	// game destroy code

	return 0;

}