#include "Shape.h"
#include "TetiMath.h"
#include "Entities.h"

Shape::Shape()
{
	Entities.push_back(this);
}

void Shape::drawShape(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	// if I dont change to arrays, maybe optimise?? beep beep
	for (int i = 0; i < this->vecticesNum; i++) {
		Vertex currentVertex = this->vectices[i];
		Point3D point1 = this->points[currentVertex.point1];
		Point3D point2 = this->points[currentVertex.point2];

		point1.x += this->x;
		point1.y += this->y;

		point2.x += this->x;
		point2.y += this->y;

		Point2D screenPoint1{
			((point1.x * FOV) / (point1.z + FOV)) + SCREEN_WIDTH / 2,
			((-point1.y * FOV) / (point1.z + FOV)) + SCREEN_HEIGHT / 2
		};
		Point2D screenPoint2{
			((point2.x * FOV) / (point2.z + FOV)) + SCREEN_WIDTH / 2,
			((-point2.y * FOV) / (point2.z + FOV)) + SCREEN_HEIGHT / 2
		};
		SDL_RenderDrawLine(
			renderer, screenPoint1.x, screenPoint1.y,
			screenPoint2.x, screenPoint2.y
		);

	}
};

void Shape::setRealPosition(){
	for (int i = 0; i < this->vecticesNum; i++) {
		Vertex currentVertex = this->vectices[i];
		Point3D point1 = this->points[currentVertex.point1];
		Point3D point2 = this->points[currentVertex.point2];

		point1.x += this->x;
		point1.y += this->y;

		point2.x += this->x;
		point2.y += this->y;


		this->realPoints[currentVertex.point1] = point1;
		this->realPoints[currentVertex.point2] = point2;

	}
}

void Shape::apply3DMatrix(double transMatrix[3][3]){
	for (int i = 0; i < this->pointNum; i++) {
		apply3DMatrixToPoint(transMatrix, this->points[i].x, this->points[i].y, this->points[i].z);
	}
};

void Shape::rotateShapeX(double theta) {
	double transMatrix[3][3] = {
		{1,0,0},
		{0,cos(theta),-sin(theta)},
		{0,sin(theta),cos(theta)}
	};
	this->apply3DMatrix(transMatrix);

}

void Shape::rotateShapeY(double theta) {
	double transMatrix[3][3] = {
		{cos(theta),0,sin(theta)},
		{0,1,0},
		{-sin(theta),0,cos(theta)}
	};
	this->apply3DMatrix(transMatrix);

}

void Shape::rotateShapeZ(double theta) {
	double transMatrix[3][3] = {
		{cos(theta),-sin(theta),0},
		{0,1,0},
		{-sin(theta),0,cos(theta)}
	};
	this->apply3DMatrix(transMatrix);
}

void Shape::moveShapeX(double x) {
	this->x += x;
}
void Shape::moveShapeY(double y) {
	this->y += y;
}
void Shape::moveShapeZ(double z) {
	this->z += z;
}

void Shape::reflectShapeYZ(double theta) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{-1,0,0},
		{0,1,0},
		{0,0,-1}
	};
	this->apply3DMatrix(transMatrix);

}

void Shape::reflectShapeXZ(double theta) {
	//theta = theta * (M_PI / 180.0);
	double transMatrix[3][3] = {
		{1,0,0},
		{0,-1,0},
		{0,0,1}
	};
	this->apply3DMatrix(transMatrix);

}

