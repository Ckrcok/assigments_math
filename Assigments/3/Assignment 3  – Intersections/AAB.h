#pragma once
#include "Plane.h"

class AAB
{
	// Width, height, and depth of box
	float rx, ry, rz;
	Plane box[6];



	void AAB(float width_, float height_, float depth_);
		// Create a box with width, height, depth = 1
	 void AAB();


};

