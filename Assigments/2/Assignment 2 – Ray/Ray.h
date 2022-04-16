#pragma once
#include <iostream>
#include <math.h>
#include "Vector.h"
using namespace std;


class Ray
{

public:

	Ray(Vec3 start_, Vec3 dir_);
	Vec3 currentPosition(float t);
	Vec3 GetDir();
	Vec3 GetStart();

};

