#include "TextureManager.h"

TextureManager::~TextureManager()
{
	for (SDL_Texture* texture : textures)
	{
		SDL_DestroyTexture(texture);
	}
}

bool TextureManager::LoadTextures(SDL_Renderer* renderer)
{
	bool allTexturesLoaded = true;
	for (int i = 0; i < TEXTURES_MAX; i++)
	{
		std::string path = textureDirectory + texturePaths[i];

		SDL_Surface* tempSurface = nullptr;
		tempSurface = IMG_Load(path.c_str());

		if (tempSurface == nullptr)
		{
			std::string errorMsg = "Could not load path: " + path;
			printError(errorMsg);
			allTexturesLoaded = false;
			continue;
		}
		//else
		//SDL_SetColorKey(tempSurface, true, SDL_MapRGB(tempSurface->format, 0, 255, 255)); //filter cyan

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);

		if (texture == nullptr)
		{
			std::string errorMsg = "Could not convert surface to texture: " + path;
			printError(errorMsg);
			allTexturesLoaded = false;
			continue;
		}
		textures[i] = texture;
	}
	SetUpTransparence();

	return allTexturesLoaded;
}

SDL_Texture* TextureManager::GetTexture(TextureTypes texture) const
{
    return textures[texture];
}

void TextureManager::SetUpTransparence()
{
	SDL_SetTextureBlendMode(textures[TEXTURE_PLAYER], SDL_BLENDMODE_BLEND);
}
