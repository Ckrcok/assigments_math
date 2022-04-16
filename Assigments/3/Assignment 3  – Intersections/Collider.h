#pragma once
#include "Vec3.h"
#include "Sphere.h"
#include "Ray.h"
#include "Vec4.h"
#include "AAB.h"

class Collider
{
public:
	static Vec3 RaySphereCollisionPoint(const Ray& ray, const Sphere& sphere);

	static bool quadraticEquation(const Ray& ray, const Sphere& sphere);
	// Collision detection methods:
	static bool RaySphereCollisionDetected(const Ray& ray, const Sphere& sphere);
	// The next methods return the first intersection point if there is one (closest to Ray’s starting point)

	static bool RayAABCollisionDetected(const Ray& ray, const ABB& box);

	static bool RayAABCollisionPoint(const Ray& ray, const ABB& box);


};

