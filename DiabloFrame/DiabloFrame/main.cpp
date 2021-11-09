#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "ErrorPrinter.h"
#include "TextureManager.h"
#include "Player.h"

struct CoreData
{
	const int width = 1280;
	const int height = 720;
	const int windowFlags = 0;
	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
};

//forward declarations
bool InitSDL(CoreData* outCoreData);
void QuitSDL(CoreData* outCoreData);

const char* windowTitle = "DiabloFrame";

int main(int argc, char* argv[])
{
	CoreData coreData;
	InitSDL(&coreData);

	TextureManager textureManager;
	textureManager.LoadTextures(coreData.renderer);

	SDL_Event event;
	bool quit = false;

	Player p(textureManager.GetTexture(TEXTURE_PLAYER), Vector2(coreData.width * 0.5f, coreData.height * 0.5f));

	int previousTicks = 0;
	while (!quit)
	{
		int currentTicks = SDL_GetTicks();
		float deltaTime = (currentTicks- previousTicks) * 0.001; //divide to get in seconds
		previousTicks = currentTicks;

		//Event polling
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			default: break;
			case SDL_QUIT: quit = true; break;
			case SDL_KEYDOWN: p.KeyChanged(event.key.keysym.sym, true); break;
			case SDL_KEYUP: p.KeyChanged(event.key.keysym.sym, false); break;
			}
		}

		p.Update(deltaTime);

		SDL_RenderClear(coreData.renderer);
		p.Render(coreData.renderer);
		SDL_RenderPresent(coreData.renderer);
	}

	QuitSDL(&coreData);
	return 0;
}

bool InitSDL(CoreData* outCoreData)
{
	//Main sdl init
	Uint32 initFlags = SDL_INIT_VIDEO;
	if (SDL_Init(initFlags) != 0) //SDL_Init returns 0 if successful
	{
		printError("Could not initialize SDL.");
		return false;
	}
	
	//img init
	initFlags = IMG_INIT_PNG;
	if (IMG_Init(initFlags) != initFlags)
	{
		printError("Could not initialize IMG.");
		return false;
	}

	SDL_Window* tempWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, outCoreData->width, outCoreData->height, outCoreData->windowFlags);
	if (tempWindow == nullptr)
	{
		printError("Could not create window.");
		return false;
	}
	outCoreData->window = tempWindow;

	initFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC; //using hardware acceleration and Vsync
	SDL_Renderer* tempRenderer = SDL_CreateRenderer(tempWindow, -1, initFlags);
	if (tempRenderer == nullptr)
	{
		printError("Could not create renderer.");
		return false;
	}
	SDL_SetRenderDrawColor(tempRenderer, 0,0,0,255); //black
	outCoreData->renderer = tempRenderer;

	return true;
}

void QuitSDL(CoreData* outCoreData)
{
	SDL_DestroyRenderer(outCoreData->renderer);
	outCoreData->renderer = nullptr;
	SDL_DestroyWindow(outCoreData->window);
	outCoreData->window = nullptr;

	IMG_Quit();
	SDL_Quit();
}
