#include "Player.h"

Player::Player(SDL_Texture* texture)
{
	this->texture = texture;
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Rect srcRect = GetAnimatedSpriteRect(GetDirection(), GetWalkCycleFrame());

	SDL_Rect dstRect;
	dstRect.x = 280;
	dstRect.y = 280;
	dstRect.w = 280;
	dstRect.h = 280;

	SDL_RenderCopy(renderer, texture, &srcRect, &dstRect);
}

void Player::KeyChanged(SDL_Keycode key, bool down)
{
	if (down)
	{
		switch (key)
		{
		default: break;
		case SDLK_LEFT: Turn(true); break;
		case SDLK_RIGHT: Turn(false); break;
		case SDLK_UP: IncrementWalkCycle(); break;
		case SDLK_DOWN: IncrementWalkCycle(true); break;
		}
	}
}
