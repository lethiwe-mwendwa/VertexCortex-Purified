#include "math.h"

// 2d cross product (used in triangle rasterisation)
float crossProduct(Vec2 AB, Vec2 AP) {

	return AB.x * AP.y - AB.y * AP.x;

}

// 3d cross product
Vec3 crossProduct(Vec3 AB , Vec3 AP) {

	int x = AB.y * AP.z - AB.z * AP.y;

	int y = AB.z * AP.x - AB.x * AP.z;

	int z = AB.x * AP.y - AB.y * AP.x;

	return Vec3(x, y, z);
}