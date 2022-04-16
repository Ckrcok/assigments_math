#include "Plane.h"
#include "Vector.h"
#include "VMath.h"




//Constructors
// Set the member variables of the plane
Plane::Plane(float x_, float y_, float z_, float w_) {
	plane.x = x_;
	plane.y = y_;
	plane.z = z_;
	plane.w = w_;
}


// Define the plane using three points that are on the plane
Plane::Plane(const Vec3& v0, const Vec3& v1, const Vec3& v2) {
	Vec3 e1;
	Vec3 e2;
	Vec3  n;
	float d;

	e2 = v1 - v0; 
	e1 = v2 - v1;
	Vec3 crossE1E2 = VMath::cross(e1, e2);
	n = VMath::normalize(VMath::cross(e2, e1));
	
	d = VMath::dot(n, v0); 
}

Vec3 Plane::intersectionPoint(Ray ray)
{
	//t = - (D + N.S) / (N.V);
	Vec3 N = VMath::normalize(plane);
	float t = 0;
	float D = plane.w;
	Vec3 V = ray.GetDir();
	Vec3 S = ray.GetStart();

	float dot = N.Dot(V);
	if (abs(dot) <= 0.00001) {
		// we have two cases
		float dist = VMath::dot( N,S) + D;
		// if N.S + D = 0 line lies in plane;
		if (dist <= 0.00001) {
			cout << "lines lies in plane" << endl;
		}
		else {
			cout << "no intersection." << endl;
		}
	}
	else
	{
		t = -(D + VMath::dot(N,S)) / VMath::dot(N, V);
		return ray.currentPosition(t);
	}

	return Vec3(NULL, NULL, NULL);
}


