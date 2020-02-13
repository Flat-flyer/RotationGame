#ifndef MAPONE_H
#define MAPONE_H

#include "Vector.h"
#include <SDL.h>

using namespace MATH;

class MapOne
{
public:
	MapOne();
	~MapOne();
	Vec3 position;
	SDL_Surface* image;
	float degree; // for rotation.
};
#endif // !MAPONE_H


