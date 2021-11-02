#pragma once
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "ErrorPrinter.h"

const std::string textureDirectory = "Textures\\";

#pragma region Texture_enums_paths
enum TextureTypes //no enum class since we need to iterate over it
{
	TEXTURE_PLAYER,
	TEXTURES_MAX
};
const std::string texturePaths[TEXTURES_MAX] = {
	"player.png"
};
#pragma endregion

class TextureManager
{
public:
	~TextureManager();
	bool LoadTextures(SDL_Renderer* renderer);
	SDL_Texture* GetTexture(TextureTypes texture) const;
private:
	void SetUpTransparence();
	SDL_Texture* textures[TEXTURES_MAX];
};

