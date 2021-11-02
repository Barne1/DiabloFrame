#pragma once
#include "SpriteUtility.h"

class IWalkingSprite
{
public:
	Directions GetDirection() { return direction; }
	int GetWalkCycleFrame() { return walkCycleFrame; }

protected:
	void IncrementWalkCycle(bool walkingBackwards = false);
	void Turn(bool clockwise);
	void SetDirection(Directions direction);

private:
	Directions direction;
	int walkCycleFrame;
};

