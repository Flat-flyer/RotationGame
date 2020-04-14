#include "Tile.h"

Tile::Tile()
{
	degree = 0;
}

Tile::~Tile()
{

}

Tile::Tile(Vec3 pos_, Vec3 vel_, Vec3 pivotPoint_, float RotationQuadrant_, int height_, int width_)
{
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	PivotPoint.x = pivotPoint_.x;
	PivotPoint.y = pivotPoint_.y;
	PivotPoint.z = pivotPoint_.z;

	RotationQuadrant = RotationQuadrant_;
	height = height_;
	width = width_;
}

void Tile::HandleEvents(const SDL_Event& event)
{
	RotatableObject::HandleEvents(event);
}
