#ifndef PHYSICS_H
#define PHYSICS_H
#include "Vector.h"
using namespace MATH;
class Physics
{
protected:
	Vec3 pos;
	Vec3 accel;
	Vec3 vel;
	Vec3 force;
	float mass;
public:
	Physics();
	Physics(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	~Physics();
	void Update(const float time);
	void ApplyForce(Vec3 force);
	Vec3 GetPosition();
	Vec3 GetVelocity();
	void SetPosition(float x_, float y_);
};
#endif
