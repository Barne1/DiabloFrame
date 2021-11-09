#include "Player.h"

Player::Player(SDL_Texture* texture, const Vector2& screenCenter)
{
	this->texture = texture;
	transform.position = screenCenter;
	transform.size = Vector2(128,128);
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Rect srcRect = GetAnimatedSpriteRect(GetDirection(), GetWalkCycleFrame());

	SDL_Rect dstRect;
	dstRect.x = transform.position.x - transform.size.x*0.5f;
	dstRect.y = transform.position.y - transform.size.y*0.5f;
	dstRect.w = transform.size.x;
	dstRect.h = transform.size.y;

	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}

void Player::KeyChanged(SDL_Keycode key, bool down)
{
	switch (key)
	{
	default: break;
	case SDLK_LEFT: keyboardInput.set(KEY_LEFT, down); break;
	case SDLK_RIGHT: keyboardInput.set(KEY_RIGHT, down); break;
	case SDLK_UP: keyboardInput.set(KEY_UP, down); break;
	case SDLK_DOWN: keyboardInput.set(KEY_DOWN, down); break;
	}
}

void Player::Update(float deltatime)
{
	UpdateMovement(deltatime);
	UpdateWalkcycle(deltatime);
	transform.position += deltaPos.GetNormalized() * deltatime * walkSpeed;
	deltaPos = Vector2(0, 0);
}

void Player::UpdateMovement(float deltatime)
{
	if (keyboardInput.test(KEY_LEFT))
	{
		deltaPos += Vector2(-1, 0);
	}
	if (keyboardInput.test(KEY_RIGHT))
	{
		deltaPos += Vector2(1, 0);
	}
	if (keyboardInput.test(KEY_UP))
	{
		deltaPos += Vector2(0, -1);
	}
	if (keyboardInput.test(KEY_DOWN))
	{
		deltaPos += Vector2(0, 1);
	}
}

void Player::UpdateWalkcycle(float deltatime)
{
	if (deltaPos.GetLengthSqr() > 0.0001)
	{
		walkCycleTimer += deltatime;
		while (walkCycleTimer > timeBetweenWalkSteps)
		{
			IncrementWalkCycle();
			walkCycleTimer -= timeBetweenWalkSteps;
		}
	}

	Directions facing = deltaPos.GetDirectionVector();
	if (facing != DIR_MAX)
	{
		SetDirection(facing);
	}
}
