#include "VertexCortex.cuh"
#include "window.h"
#include "raster.h"
#include <Windows.h>
#include "vertex.h"
#include "framebuffer.h"

#include "raster.cuh"

// not used for anything yet
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
//

void testCode(frameBuffer* fb, Window* window);

// MAIN FUNCTION[
VertexCortexApp
{
	// game init code
	setup();
	
	// initialise card
	cudaError_t cudaStatus;
	cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?");
		
	}

	// Create window
	wchar_t ClassName[] = L"MainWindow";
	wchar_t WindowText[] = L"VertexCortexApplication";

	Window MainWindow(ClassName,WindowText,hInstance, nCmdShow);

	if (MainWindow.handler == NULL) { return 0; }

	ShowWindow(MainWindow.handler, nCmdShow);

	// Program loop
	MSG msg = { };
	while (MainWindow.isRunning) {
		// 1. Process Windows Messages (Prevents freezing)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		
		MainWindow.timer.tick();

		// 2. Program Update Code  (TODO!!! only run this section if things have become "dirty"
		update(MainWindow.timer.dt);
		// I was gonna cap the framerate here but I'll be completely honest, I'm too lazy to and it won't affect anything much lmao.

		if (MainWindow.mainBuffer == nullptr) continue;

		// Clears the screen to avoid ghosting.
		MainWindow.mainBuffer->clear(packColourBGR(0,0,0));

		// Heres all the raster code stuff
		testCode(MainWindow.mainBuffer, &MainWindow);

		// 3. Render to framebuffer based on new world data 
		// //(INTERNAL THING I NEED TO DO. WITH THE WINDOW BITMAP) <---- I forgot what I was talking about here
		render(*MainWindow.mainBuffer);

		// Hands over to Win32 for displaying
		MainWindow.display();

	}

	// Program destroy code
	destroy();

	cudaStatus = cudaDeviceReset();
	if (cudaStatus != cudaSuccess) {
		fprintf(stderr, "cudaDeviceReset failed!");
		return 1;
	}

	return 0;

}


void testCode(frameBuffer* fb, Window* window) {

	//drawLine(20, 40, 70, 80, packColoruBGR(0, 0, 0), *MainWindow.mainBuffer);

	//drawRect(70, 100, 60, 60, packColourBGR(255, 255, 255), *window->mainBuffer);

	drawRectGPU(70, 100, 60, 60, packColourBGR(255, 255, 255), window->mainBuffer);

	// Test values!!
	Vec2 A = { 400, 500 };
	Vec2 B = { 600, 100 };
	Vec2 C = { 800, 500 };

	//drawTriangleWireframe(A, B, C, packColourBGR(255, 255, 255), *MainWindow.mainBuffer);

	Vertex2 Av = { Vec2(200, 500), Colour(255, 0, 0) };
	Vertex2 Bv = { Vec2(400, 100), Colour(0, 255, 0) };
	Vertex2 Cv = { Vec2(600, 500), Colour(0, 0, 255) };

	drawTriangle(Av, Bv, Cv, *fb);

	//drawRectKernel<<>>

}