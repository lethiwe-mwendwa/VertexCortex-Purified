#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include "framebuffer.h"
#include "Window.h"
#include <iostream>


// first kernel to work on!
void drawRectGPU(int x, int y, int width, int height, uint32_t colour, frameBuffer*);

__global__ void drawRectKernel(int x_start, int y_start, int width, int height, int fbHeight, int fbWidth, uint32_t colour, uint32_t* cb);