#pragma once
#include "SDL.h"
#include "WalkingSprite.h"
#include "Updateable.h"
#include "Transform.h"
#include <bitset>

class Player : public WalkingSprite, public IUpdateable
{
public:
	Player(SDL_Texture* texture, const Vector2& screenCenter);

	Transform transform;

	void Render(SDL_Renderer* renderer);
	void KeyChanged(SDL_Keycode key, bool down);
	virtual void Update(float deltatime) override;

private:
	void UpdateMovement(float deltatime);
	void UpdateWalkcycle(float deltatime);


	SDL_Texture* texture;
	float walkCycleTimer = 0;
	const float timeBetweenWalkSteps = 0.075;

	Vector2 deltaPos = Vector2(0,0);
	const float walkSpeed = 250.f;

	enum KeyboardState
	{
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT,
		KEY_SHOOT,
		KEY_MAX
	};
	std::bitset<KEY_MAX> keyboardInput; //Bitmask
};