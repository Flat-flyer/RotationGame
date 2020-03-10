#ifndef TILE_H
#define TILE_H

#include "RotatableObject.h"
#include "Vector.h"
#include <SDL.h>

using namespace MATH;

class Tile : public RotatableObject
{
public:
	Tile();
	~Tile();
	Tile(Vec3 pos_, Vec3 vel_, Vec3 pivotPoint_, float RotationQuadrant_, int height_, int width_);
	void HandleEvents(const SDL_Event& event);
	SDL_Surface* image;
	float degree; // for rotation.

};
#endif // !MAPONE_H


