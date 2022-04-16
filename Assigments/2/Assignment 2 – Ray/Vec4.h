#pragma once
#include <iostream>

using namespace std;

class Vec4
{
public:	
	Vec4();
	Vec4(float x_, float y_, float z_, float d_);

	float Mag();

	float Normalize();

	float x;
	float y;
	float z;
	float w;
};

