#include "raster.cuh"



// x and y signify the starting point.
// << grid, block>>
// TODO make code readable. this is a fuckin mess
void drawRectGPU(int x, int y, int width, int height, uint32_t colour, frameBuffer* fb){

	// update GPU framebuffer
	fb->updateDeviceColourbuffer();

	//compute
	drawRectKernel<<<height, width>>>(x, y, width, height, fb->height, fb->width, colour, fb->gpuColourBuffer);

	cudaDeviceSynchronize();
	// update main framebuffer
	fb->updateHostColourbuffer();

}

__global__ void drawRectKernel(int x_start, int y_start, int width, int height, int fbHeight, int fbWidth, uint32_t colour, uint32_t* cb){
	
	int y = blockIdx.x + y_start;
	int x = threadIdx.x + x_start;

	if (y >= 0 && y < fbHeight && x >= 0 && x < fbWidth) {

		cb[y * fbWidth + x] = colour;
	}

}