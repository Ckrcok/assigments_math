#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <math.h>

using namespace std;

class Vec3
{
public:
	Vec3();
	Vec3(float x_, float y_, float z_);

	void Add(Vec3 b);

	void Subtract(Vec3 b);

	void ScalarMultiplication(float s);

	float Mag();

	float Normalize();

	float Dot(Vec3 b);

	Vec3 Cross(Vec3 b);

	void Lerp(Vec3 b, float t);


	void RotateZ(float angle);

	float x;
	float y;
	float z;


	/// Multiply a Vec3 by a scalar
	inline const Vec3  operator * (const float s) const {
		return Vec3(s * x, s * y, s * z);
	}

	/// Add two Vec3s
	inline const Vec3 operator + (const Vec3& v) const {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}




};

#endif
