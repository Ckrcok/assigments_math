#include <iostream>
#include "Mat3.h"
#include "Ray.h"


using namespace std;

int main()
{

	Vec3 dir(2, 3, 1);

	Vec3 start(1, 1, 0);

	Ray rayOne(start, dir);

	float t = 0.2;

	Vec3 ptAt = rayOne.currentPosition(t);

	return 0;

}