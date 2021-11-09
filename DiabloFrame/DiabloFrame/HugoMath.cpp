#include "HugoMath.h"

Directions Vector2::GetDirectionVector()
{
	Vector2 normal = GetNormalized();
	int x = GetRounded(normal.x);
	int y = GetRounded(normal.y);

	switch (x)
	{
	default:
		printf("Error in conversion GetDirection x"); break;
	case -1: //to the west
		switch (y)
		{
		default:
			printf("Error in conversion GetDirection y"); break;
		case -1: return DIR_NORTHWEST;
		case 0: return DIR_WEST;
		case 1: return DIR_SOUTHWEST;
		}; break;
	case 0: //Straight up or down
		switch (y)
		{
		default:
			printf("Error in conversion GetDirection y"); break;
		case -1: return DIR_NORTH;
		case 0: return DIR_MAX;
		case 1: return DIR_SOUTH;
		}; break;
	case 1: //to the east
		switch (y)
		{
		default:
			printf("Error in conversion GetDirection y"); break;
		case -1: return DIR_NORTHEAST;
		case 0: return DIR_EAST;
		case 1: return DIR_SOUTHEAST;
		}; break;
	};

	return DIR_MAX;
}

int GetRounded(float x)
{
	if (x > 0)
		x += 0.5f;
	else if (x < 0)
		x -= 0.5f;

	return (int) x;
}
