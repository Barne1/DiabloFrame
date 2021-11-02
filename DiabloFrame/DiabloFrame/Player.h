#pragma once
#include "SDL.h"
#include "WalkingSprite.h"

class Player : public IWalkingSprite
{
public:
	Player(SDL_Texture* texture);
	void Render(SDL_Renderer* renderer);
	void KeyChanged(SDL_Keycode key, bool down);

private:
	SDL_Texture* texture;
};

