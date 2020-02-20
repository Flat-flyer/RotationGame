#ifndef TILE_H
#define TILE_H

#include "Vector.h"
#include <SDL.h>

using namespace MATH;

class Tile
{
public:
	Tile();
	~Tile();
	Vec3 position;
	SDL_Surface* image;
	float degree; // for rotation.
};
#endif // !MAPONE_H


