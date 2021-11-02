#pragma once
#include "SDL.h"

enum Directions //no enum class since we need to iterate over it
{
	DIR_SOUTH,
	DIR_SOUTHWEST,
	DIR_WEST,
	DIR_NORTHWEST,
	DIR_NORTH,
	DIR_NORTHEAST,
	DIR_EAST,
	DIR_SOUTHEAST,
	DIR_MAX
};

const int WalkCycleFrames = 4;

SDL_Rect GetAnimatedSpriteRect(Directions direction, int walkCycleFrame); //Only valid for 512 sheets of 64 each