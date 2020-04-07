#include "RotatableObject.h"

RotatableObject::RotatableObject()
{

}

RotatableObject::~RotatableObject()
{
}

RotatableObject::RotatableObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, Vec3 pivotPoint_, float RotationQuadrant_, int width_, int height_)
{
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;

	PivotPoint.x = pivotPoint_.x;
	PivotPoint.y = pivotPoint_.y;
	PivotPoint.z = pivotPoint_.z;

	RotationQuadrant = RotationQuadrant_;
	width = width_;
	height = height_;
}

bool RotatableObject::OnCreate()
{
	return false;
}

void RotatableObject::OnDestroy()
{
}

void RotatableObject::Update(const float deltaTime)
{
	if (RotateObjectRight == true) {
		if (RotationQuadrant == 4) {
			pos.y = pos.y - PivotPoint.y;
			RotationQuadrant = 1;
		}
		else if (RotationQuadrant == 3) {
			pos.x = pos.x - PivotPoint.x;
			RotationQuadrant = 4;
		}
		else if (RotationQuadrant == 2) {
			pos.y = pos.y + PivotPoint.y;
			RotationQuadrant = 3;
		}
		else {
			pos.x = pos.x + PivotPoint.x;
			RotationQuadrant = 2;
		}
		RotateObjectRight = false;
	}

	if (RotateObjectLeft == true) {
		if (RotationQuadrant == 1) {
			pos.y = pos.y + PivotPoint.y;
			RotationQuadrant = 4;
		}
		else if (RotationQuadrant == 2) {
			pos.x = pos.x - PivotPoint.x;
			RotationQuadrant = 1;
		}
		else if (RotationQuadrant == 3) {
			pos.y = pos.y - PivotPoint.y;
			RotationQuadrant = 2;
		}
		else {
			pos.x = pos.x + PivotPoint.x;
			RotationQuadrant = 3;
		}
		RotateObjectLeft = false;
	}
}

void RotatableObject::Render() const
{
}

void RotatableObject::HandleEvents(const SDL_Event& event)
{
	
}

void RotatableObject::Rotate(float rotationAmount)
{

	float xRotated = ((pos.x - PivotPoint.x) * cos(rotationAmount)) - ((PivotPoint.y - pos.y) * sin(rotationAmount)) + PivotPoint.x;
	float yRotated = ((PivotPoint.y - pos.y) * cos(rotationAmount)) - ((pos.x - PivotPoint.x) * sin(rotationAmount)) + PivotPoint.y;
	pos.x = xRotated;
	pos.y = yRotated;
}
