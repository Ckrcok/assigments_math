#pragma once
#include "Vector.h"
#include "Ray.h"
using namespace  MATH;

class Plane
{

	Vec4 plane;
	Plane(float x_, float y_, float z_, float w_);
	Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2);
	Vec3 intersectionPoint(Ray ray);

};


