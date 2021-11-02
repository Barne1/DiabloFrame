#pragma once
#include <string>
#include "SDL.h"

inline void printError(std::string error)
{
	error.append(" SDL Error: %s\n");
	printf(error.c_str(), SDL_GetError());
}