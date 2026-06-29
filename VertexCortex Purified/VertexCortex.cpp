#include "VertexCortex.h"
#include "window.h"
#include "raster.h"
#include <Windows.h>

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
		MainWindow.mainBuffer->clear(packColorBGR(0,0,0));
			
		//drawLine(20, 40, 70, 80, packColorBGR(0, 0, 0), *MainWindow.mainBuffer);
			
		//drawRect(70, 100, 60, 60, packColorBGR(255, 255, 255), *MainWindow.mainBuffer);

		

		// Test values!!
		Vec2 A = { 400, 500 };
		Vec2 B = { 600, 100 };
		Vec2 C = { 800, 500 };

		drawTriangleWireframe(A, B, C, packColorBGR(255, 255, 255), *MainWindow.mainBuffer);

		Vertex2 Av = {Vec2(400, 500), packColorBGR(255, 255, 255) };
		Vertex2 Bv = {Vec2(600, 100), packColorBGR(255, 255, 255) };
		Vertex2 Cv = {Vec2(800, 500), packColorBGR(255, 255, 255) };

		drawTriangle(Av, Bv, Cv, *MainWindow.mainBuffer);

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