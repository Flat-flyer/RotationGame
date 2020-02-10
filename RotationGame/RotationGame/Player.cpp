#include "Player.h"
Player::Player() :Physics(Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f)
{
}
Player::~Player()
{

}
Player::Player(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_) {
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;

	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;

	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;

	mass = mass_;
}

bool Player::OnCreate()
{
	return false;
}

void Player::OnDestroy()
{

}

void Player::Update(const float deltaTime)
{
	Physics::Update(deltaTime);
	if (MoveState == 1) {
		this->vel = Vec3(10.0f, 0.0f, 0.0f);
	}
	if (MoveState == 2) {
		this->vel = Vec3(-10.0f, 0.0f, 0.0f);
	}
	if (MoveState == 0) {
		this->vel = Vec3(0.0f, 0.0f, 0.0f);
	}
	if (MoveState == 3) {
		this->vel = Vec3(0.0f, 20.0f, 0.0f);
	}
	if (MoveState == 4) {
		this->vel = Vec3(10.0f, 20.0f, 0.0f);
	}
	if (MoveState == 5) {
		this->vel = Vec3(-10.0f, 20.0f, 0.0f);
	}
}

void Player::Render() const
{

}
void Player::HandleEvents(const SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_d) {
			MoveState = 1;
		}
		if (event.key.keysym.sym == SDLK_a) {
			MoveState = 2;
		}
		if (event.key.keysym.sym == SDLK_w) {
			MoveState = 3;
			if (event.key.keysym.sym == SDLK_d) {
				MoveState = 4;
			}
			if (event.key.keysym.sym == SDLK_a) {
				MoveState = 5;
			}
		}
		if (event.key.keysym.sym == SDLK_q) {
			RotateLevelLeft = true;
		}
		if (event.key.keysym.sym == SDLK_e) {
			RotateLevelRight = true;
		}

	}
	if (event.type == SDL_KEYUP) {
		MoveState = 0;
	}

}