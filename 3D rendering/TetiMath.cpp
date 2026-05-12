#include "TetiMath.h"

//apply a 2D matrix to a point
void apply2DMatrixToPoint(double transMatrix[2][2], double& x, double& y) {
	x = (transMatrix[0][0] * x) + (transMatrix[0][1] * y);
	y = (transMatrix[1][0] * x) + (transMatrix[1][1] * y);
}

//apply a 3D matrix to a point
void apply3DMatrixToPoint(double transMatrix[3][3], double& x, double& y, double& z) {
	x = (transMatrix[0][0] * x) + (transMatrix[0][1] * y) + (transMatrix[0][2] * z);
	y = (transMatrix[1][0] * x) + (transMatrix[1][1] * y) + (transMatrix[1][2] * z);
	z = (transMatrix[2][0] * x) + (transMatrix[2][1] * y) + (transMatrix[2][2] * z);
}
