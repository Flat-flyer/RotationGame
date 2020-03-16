#include "RotatableObject.h"

RotatableObject::RotatableObject()
{

}

RotatableObject::~RotatableObject()
{
}

RotatableObject::RotatableObject(Vec3 pos_, Vec3 vel_, Vec3 accel_, Vec3 pivotPoint_, float RotationQuadrant_, int height_, int width_)
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

	height = height_;
	width = width_;
	FirstRotation = true;
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
	if (RotateObject == true) {
		if (FirstRotation == false) {
			if (RotationQuadrant == 4) {
				pos.y = pos.y - height;
			}
			else if (RotationQuadrant == 3) {
				pos.y = pos.y + height;
			}
			else if (RotationQuadrant == 2) {
				pos.x = pos.x + width;
				pos.y = pos.y + height;
			}
			else {
				pos.x = pos.x + width;
			}
		}
		Rotate(90.0f);
		if (RotationQuadrant == 4) {
			pos.y = pos.y + height;
			RotationQuadrant = 1;
		}
		else if (RotationQuadrant == 3) {
			pos.y = pos.y - height;
			RotationQuadrant = 4;
		}
		else if (RotationQuadrant == 2) {
			pos.x = pos.x - width;
			pos.y = pos.y - height;
			RotationQuadrant = 3;
		}
		else {
			pos.x = pos.x - width;
			RotationQuadrant = 2;
		}
		if (FirstRotation == true) {
			FirstRotation = false;
		}
		RotateObject = false;
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
