#pragma once
#include "SpriteUtility.h"

class WalkingSprite
{
public:
	const Directions GetDirection() const { return direction; }
	const int GetWalkCycleFrame() const { return walkCycleFrame; }

protected:
	void IncrementWalkCycle(const bool walkingBackwards = false);
	void Turn(const bool clockwise);
	void SetDirection(const Directions direction);
	void SetWalkCycleFrame(const int walkCycleFrame);

private:
	Directions direction;
	int walkCycleFrame;
};

