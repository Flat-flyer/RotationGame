#include "Player.h"
#include "MapOne.h"
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

	if (MoveState == 0) {
		this->vel = Vec3(0.0f, 0.0f, 0.0f);
	}
	if (MoveState == 1) {
		this->vel = Vec3(10.0f, 0.0f, 0.0f);
	}
	if (MoveState == 2) {
		this->vel = Vec3(-10.0f, 0.0f, 0.0f);
	}
	if (MoveState == 3) {
		this->vel = Vec3(0.0f, 10.0f, 0.0f);
	}
	if (MoveState == 4) {
		this->vel = Vec3(0.0f, -10.0f, 0.0f);
	}
	if (MoveState == 5) {
		this->vel = Vec3(-10.0f, 20.0f, 0.0f);
	}
	if (MoveState == 8) {
		degrees1 += 10;
	}
	if (MoveState == 9) {
		degrees1 -= 10;
	}
}

void Player::Render() const
{

}
void Player::HandleEvents(const SDL_Event& event)
{
switch (event.type) {
		/* Look for a keypress */
	case SDL_KEYDOWN:
		/* Check the SDLKey values and move change the coords */
		switch (event.key.keysym.sym) {
		case SDLK_d:
			MoveState = 1;
			break;
		case SDLK_a:
			MoveState = 2;
			break;
		case SDLK_w:
			MoveState = 3;
			break;
		case SDLK_s:
			MoveState = 4;
			break;
		case SDLK_q:
			MoveState = 8;
			std::cout << SDL_GetKeyName(event.key.keysym.sym) << " is pressed." << std::endl;
			break;
		case SDLK_e:
			MoveState = 9;
			std::cout << SDL_GetKeyName(event.key.keysym.sym) << " is pressed." << std::endl;
		default:
			break;
		}
	//reverts velocity when you let go of key.
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_d:
			if (this->vel.x > 0)
				MoveState = 0;
			break;
		case SDLK_a:
			if (this->vel.x < 0)
				MoveState = 0;
			break;
		case SDLK_w:
			if (this->vel.y > 0)
				MoveState = 0;
			break;
		case SDLK_s:
			if (this->vel.y < 0)
				MoveState = 0;
			break;
		default:
			break;
		}
		break;

		default:
			break;
	}
}