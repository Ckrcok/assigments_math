#include "Ray.h"
#include "Vec3.h"
#include "Vector.h"


//Member variables
// Starting position of ray
Vec3 start;
Vec3 pos;
// Direction of ray
Vec3 dir;

//Constructors
// Set the member variables of the ray
Ray::Ray(Vec3 start_, Vec3 dir_)
{
	start = start_;

	dir = dir_;
}


////Methods
//// Where are we along the Ray? 
//// Calculate position = start + dir * t
Vec3 Ray::currentPosition(float t)
{
	return pos = start + dir * t;
}

Vec3 Ray::GetDir() { return dir; }

Vec3 Ray::GetStart() { return start; }


