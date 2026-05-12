#pragma once
#include <vector>
#include <iostream>
#include "Constants.h"
#include "SDL.h"

class Shape
{
public:
	Shape();
	int x = 0;
	int y = 0;
	int z = 0;
	int pointNum = 0;
	int vecticesNum = 0;

	//Sets the value of the points in real space
	void setRealPosition();

	//Draws the Shape
	void drawShape(SDL_Renderer* renderer);

	//Applies a given 3D matrix to the points of a shape
	void apply3DMatrix(double transMatrix[3][3]);

	//Rotates a Shape by the X axis by theta degrees
	void rotateShapeX(double theta);

	//Rotates a Shape by the Y axis by theta degrees
	void rotateShapeY(double theta);

	//Rotates a Shape by the Z axis by theta degrees
	void rotateShapeZ(double theta);

	//Increases a Shape's x value by the given value
	void moveShapeX(double x);

	//Increases a Shape's y value by the given value
	void moveShapeY(double y);

	//Increases a Shape's z value by the given value
	void moveShapeZ(double z);

	//I fogor what this does to be honest. like, xy?? uhhh
	void reflectShapeYZ(double theta);

	//I fogor what this does to be honest. like, xz?? uhhh
	void reflectShapeXZ(double theta);

	std::vector<Point3D> points{};
	std::vector<Point3D> realPoints{};
	std::vector<Vertex> vectices{};

protected:

};
