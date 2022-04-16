#include "AAB.h"

void AAB::AAB(float width_, float height_, float depth_)
{
	rx = width_;
	ry = height_;
	rz = depth_;

	box[0] = Plane(1, 0, 0, 0);
	box[1] = Plane(0, 1, 0, 0);
	box[2] = Plane(0, 0, 1, 0);

	box[3] = Plane(1, 0, 0, -rx);
	box[4] = Plane(1, 1, 0, -ry);
	box[5] = Plane(1, 0, 1, -rz);
}

void AAB::AAB()
{

	box[0] = Plane(1, 0, 0, 0);
	box[1] = Plane(0, 1, 0, 0);
	box[2] = Plane(0, 0, 1, 0);

	box[3] = Plane(1, 0, 0, -rx);
	box[4] = Plane(1, 1, 0, -ry);
	box[5] = Plane(1, 0, 1, -rz);
}
