#include "SpriteUtility.h"

SDL_Rect GetAnimatedSpriteRect(Directions direction, int walkCycleFrame)
{
	const int sheetClipSize = 64;

	SDL_Rect rect;
	rect.w = sheetClipSize;
	rect.h = sheetClipSize;

	rect.x = sheetClipSize * direction;
	rect.y = sheetClipSize * walkCycleFrame;

	return rect;
}