#include "Sphere.h"
#include "Vec3.h"

Sphere::Sphere(Vec3 position_, float radius_)
{
	position = position_;
	radius = radius_;
}

Sphere::Sphere()
{
	Vec3 position (0, 0, 0);
	float radius = 1;

}
