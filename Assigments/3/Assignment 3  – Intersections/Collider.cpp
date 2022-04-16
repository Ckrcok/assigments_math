#include "Collider.h"

Vec4 quaVec;


bool Collider::RayAABCollisionDetected(const Ray& ray, const ABB& box)
{
    // check collision with ray and sphere return false / true
    for (int i = 0; i < 6; i++) {
        Vec3 t;
        t.x = (box.box[i].plane.w - ray.start.x) / ray.dir.x;
        t.y = (box.box[i].plane.w - ray.start.y) / ray.dir.y;
        t.z = (box.box[i].plane.w - ray.start.z) / ray.dir.z;

        if (t > Vec3(0,0,0)) {
            return true;
        }
    }
    return false;
}


Vec3 Collider::RaySphereCollisionPoint(const Ray& ray, const Sphere& sphere){
    if (RayAABCollisionDetected(ray, sphere){
        float t;
            //t1= -B-sqrt(Discriminant)/2A
            float t1 = (-quaVec.y - sqrt(quaVec.w)) / 2 * quaVec.x;

            //t2= -B+sqrt(Discriminant)/2A
            float t2 = (-quaVec.y + sqrt(quaVec.w)) / 2 * quaVec.x;
            if (fminf(fabsf(t1), fabsf(t2)) == fabsf(t2) {
                t = t1;
            } else {
                t = t2;
            }
        return ray.currentPosition(t);
    }
}


bool Collider::quadraticEquation(const Ray& ray, const Sphere& sphere){
    quaVec.x = ray.dir.dot(ray.dir, ray.dir);

    quaVec.y = 2 * ray.start.dot((ray.start - sphere.position), ray.start);

    quaVec.z = ray.start.dot((ray.start - sphere.position), (ray.start - sphere.position) - pow(sphere.radius, 2);
    quaVec.w = quaVec.y quaVec.y - 4 * quaVec.x quavec.z;
}

bool Collider::RayAABCollisionPoint(const Ray& ray, const ABB& box){
    if (RayAABCollisionDetected(ray, box)){
        Vec3 px, py, pz;

        // x
        if (ray.dir.x == 0){
            px = Vec3(0, 0, 0);
        }
        else if (ray.dir.x > 0 ){
            float t;
            t = (box.box[0].plane.w - ray.start.x) / ray.dir.x;
            px = ray.currentPosition(t);

        }
        else if(ray.dir.x < 0 ){
            float t = (box.box[3].plane.w - ray.start.w) / ray.dir.x;
            px = ray.currentPosition(t);
        }

        if (Vec3 (0,0,0) <= px && px <= Vec3(box.box[3].plane.w, box.box[4].plane.w, box.box[5].plane.w)){
            return Vec3(px.x, px.y, px.z);
        }

        // y
        else if (ray.dir.y == 0 ) {
            py = Vec3(0, 0, 0);

        }
        else if (ray.dir.y > 0) {
            float t;
            t = (box.box[1].plane.w - ray.start.y) / ray.dir.y;
            py = ray.currentPosition(t);
        }
        else if (ray.dir.y < 0) {
            float t;
            t = (box.box[4].plane.w - ray.start.y) / ray.dir.y;
            py = ray.currentPosition(t);
        }

        if (Vec3(0, 0, 0) <= py && py <= Vec3(-box.box[3].plane.w, -box.box[4].plane.w, -box.box[5].plane.w)){
            return Vec3(py.x, py.y, py.z);

        }

        //z
        else if (ray.dir.z == 0) {
            pz = Vec3(0, 0, 0);
        }
        else if (ray.dir.z > 0) {
            float t;
            t = (box.box[2].plane.w - ray.start.z) / ray.dir.z;
            pz = ray.currentPosition(t);
        }
        else if (ray.dir.z < 0) {
            float t;
            t = (box.box[5].plane.w - ray.start.z) / ray.dir.z;
            pz = ray.currentPosition(t);
        }

        if (Vec3(0, 0, 0) <= py && py <= Vec3(-box.box[3].plane.w, -box.box[4].plane.w, -box.box[5].plane.w)) {
            return Vec3(py.x, py.y, py.z);

        }

    }

}

bool Collider::RaySphereCollisionDetected(const Ray& ray, const Sphere& sphere) {
    if (quadraticEquation(ray, sphere).w < 0) {
        return false;
    } else {
        return true;
    }

}