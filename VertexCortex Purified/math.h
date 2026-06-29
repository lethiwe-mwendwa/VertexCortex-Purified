#pragma once


struct Vec2 {
	float x;
	float y;
};

//Potentially later available
struct Vec3{
	float x;
	float y;
	float z;

};

float crossProduct(Vec2, Vec2);

Vec3 crossProduct(Vec3, Vec3);

