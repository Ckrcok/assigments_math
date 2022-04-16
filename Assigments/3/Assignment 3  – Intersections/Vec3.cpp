#include "Vec3.h"
#include "Vector.h"

Vec3::Vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vec3::Vec3(float x_, float y_, float z_)
{
	x = x_;
	y = y_;
	z = z_;
}

void Vec3::Add(Vec3 b)
{
	x += b.x;
	y += b.y;
	z += b.z;
}

void Vec3::Subtract(Vec3 b)
{
	x -= b.x;
	y -= b.y;
	z -= b.z;
}

void Vec3::ScalarMultiplication(float s)
{
	x *= s;
	y *= s;
	z *= s;
}

float Vec3::Mag()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float  Vec3::Normalize() {
	float temp = Mag();
	x = x / temp;
	y = y / temp;
	z = z / temp;

	printf("\n  The Normalized of V Vec is(% f, % f, % f) \n \n", x, y, z);
	return x, y, z;
}

float Vec3::Dot(Vec3 b) {

	return x * b.x + y * b.y + b.z * z;
}

Vec3 Vec3::Cross(Vec3 b) {
	Vec3 results;
	results.x = y * b.z - z * b.y;
	results.y = z * b.x - x * b.z;
	results.z = x * b.y - y * b.x;
	printf("\n  The Cross product of U Vec is(% g, % g, % g) \n \n", results.x, results.y, results.z);
	return results;
}

void Vec3::Lerp(Vec3 b, float t) {
	x = (1 - t) * x + (t * b.x);
	y = (1 - t) * y + (t * b.y);
	z = (1 - t) * z + (t * b.z);
}

void Vec3::RotateZ(float angle) {
	float temp = x;
	x = temp * cos(angle) - y * sin(angle);
	y = temp * sin(angle) + y * cos(angle);
}
