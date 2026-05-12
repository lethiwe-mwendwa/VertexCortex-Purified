#pragma once
#include "Shape.h"

class Cube : public Shape
{
public:
	Cube(): Shape() {
		pointNum = 8;
		vecticesNum = 12;
		points = {
		Point3D{50,50,50},Point3D{50,50,-50},Point3D{-50,50,-50},Point3D{-50,50,50}, // A, B, C, D
		Point3D{50,-50,50}, Point3D{50,-50,-50}, Point3D{-50,-50,-50}, Point3D{-50,-50,50}  // E, F, G, H
		};

		
		vectices = {
		Vertex{0,1},Vertex{1,2},Vertex{2,3},Vertex{3,0}, // top face
		Vertex{4,5},Vertex{5,6},Vertex{6,7},Vertex{7,4}, // bottom face
		Vertex{0,4},Vertex{1,5},Vertex{2,6},Vertex{3,7} // connecting parts
		};
	}
	
};

