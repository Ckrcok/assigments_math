#include "Vec4.h"


Vec4::Vec4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Vec4::Vec4(float x_, float y_, float z_, float w_)
{
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

float Vec4::Mag()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w,2));
}

float  Vec4::Normalize() {
	float temp = Mag();
	x = x / temp;
	y = y / temp;
	z = z / temp;
	w = w / temp;

	printf("\n  The Normalized of V Vec is(% f, % f, % f) \n \n", x, y, z);
	return x, y, z;
}