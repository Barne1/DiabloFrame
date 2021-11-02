#include "WalkingSprite.h"

void IWalkingSprite::IncrementWalkCycle(bool walkingBackwards)
{
	if (!walkingBackwards)
	{
		++walkCycleFrame;
		if (walkCycleFrame >= WalkCycleFrames)
		{
			walkCycleFrame = 0;
		}
	}
	else
	{
		--walkCycleFrame;
		if (walkCycleFrame < 0) 
		{
			walkCycleFrame = WalkCycleFrames - 1;
		}
	}
}

void IWalkingSprite::Turn(bool clockwise)
{
	if (clockwise)
	{
		switch (direction)
		{
		default: return;
		case DIR_SOUTH:		direction = DIR_SOUTHWEST; return;
		case DIR_SOUTHWEST: direction = DIR_WEST; return;
		case DIR_WEST:		direction = DIR_NORTHWEST; return;
		case DIR_NORTHWEST: direction = DIR_NORTH; return;
		case DIR_NORTH:		direction = DIR_NORTHEAST; return;
		case DIR_NORTHEAST:	direction = DIR_EAST; return;
		case DIR_EAST:		direction = DIR_SOUTHEAST; return;
		case DIR_SOUTHEAST: direction = DIR_SOUTH; return;
		}
	}
	else
	{
		switch (direction)
		{
		default: return;
		case DIR_SOUTH:		direction = DIR_SOUTHEAST; return;
		case DIR_SOUTHWEST: direction = DIR_SOUTH; return;
		case DIR_WEST:		direction = DIR_SOUTHWEST; return;
		case DIR_NORTHWEST: direction = DIR_WEST; return;
		case DIR_NORTH:		direction = DIR_NORTHWEST; return;
		case DIR_NORTHEAST:	direction = DIR_NORTH; return;
		case DIR_EAST:		direction = DIR_NORTHEAST; return;
		case DIR_SOUTHEAST: direction = DIR_EAST; return;
		}
	}
}

void IWalkingSprite::SetDirection(Directions direction)
{
	this->direction = direction;
}
