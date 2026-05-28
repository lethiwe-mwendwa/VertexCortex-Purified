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
	MSG msg = { };
	while (MainWindow.isRunning) {
		// 1. Process Windows Messages (Prevents freezing)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		MainWindow.timer.tick();

		// 2. Game Update Code
		update(MainWindow.timer.dt);
		// I was gonna cap the framerate here but I'll be completely honest, I'm too lazy to and it won't affect anything much lmao.

		if (MainWindow.mainBuffer == nullptr) continue;

		// Clears the screen to avoid ghosting.
		MainWindow.mainBuffer->clear(packColorBGR(255,80,200));


		// 3. Render to framebuffer based on new world data 
		// //(INTERNAL THING I NEED TO DO. WITH THE WINDOW BITMAP) 
		render(*MainWindow.mainBuffer);

		// Hands over to Win32 for displaying
		MainWindow.display();

	}

	// game destroy code
	destroy();

	return 0;

}