#pragma once
#include "Shape.h"

class TriangularP : public Shape
{
public:
	TriangularP() : Shape() {
		pointNum = 5;
		vecticesNum = 8;
		points = {
		Point3D{50,-50,50},Point3D{50,-50,-50},Point3D{-50,-50,-50},Point3D{-50,-50,50}, // A, B, C, D
		Point3D{0,50,0} // E
		};

		vectices = {
			Vertex{0,1},Vertex{1,2},Vertex{2,3},Vertex{3,0}, // top face
			Vertex{0,4},Vertex{1,4},Vertex{2,4},Vertex{3,4}, // connect to E
		};
	}
	
};

