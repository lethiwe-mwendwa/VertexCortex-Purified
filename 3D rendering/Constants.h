#pragma once
#include <vector>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern bool running;
extern int FOV;

struct Point3D {
	double x, y, z;
};

struct Point2D {
	double x, y;
};

struct Vertex {
	int point1, point2;
};