#ifndef PLAYER_H
#define PLAYER_H
#include "Physics.h"
#include "GameObject.h"
#include <SDL.h>

class Player:public GameObject, public Physics 
{
public:
	Player();
	~Player();
	Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	bool OnCreate();
	void OnDestroy();
	void Update(const float deltaTime);
	void Render()const;
	void HandleEvents(const SDL_Event& event);
	bool RotateLevelLeft;
	bool RotateLevelRight;

	SDL_Surface* thePlayer;
	SDL_Event Event;

private:
	float MoveState;
};
#endif

