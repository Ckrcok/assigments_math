#include <iostream>

#include "Mat3.h"

using namespace std;

int main()
{

	Vec3	V(2, 2, 1);
	Vec3	U(4, 2, 1);

	//printf("\n  The magnitute of V Vec is %f",V.Mag());
	//V.Normalize();
	//printf("\n  The Dot of V Vec is %g", V.Dot(U));
	 U.Cross(V);
	return 0;




	
}