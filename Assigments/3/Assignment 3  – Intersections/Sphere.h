#pragma once
#include <iostream>
#include <math.h>
#include "Vector.h"

using namespace std;



class Sphere
{
	Vec3 position;
	float radius;
public:
	Sphere(Vec3 position_, float radius_);
		// Set position to the origin and radius = 1
	Sphere();

};

