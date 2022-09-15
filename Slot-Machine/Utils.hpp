#ifndef SLOTMACHINE_UTILS_HPP
#define SLOTMACHINE_UTILS_HPP
#include "SDL.h" 
#include "SDL_image.h"
namespace Utils {

	struct vec2 { int x; int y; };
/**
* @brief Loading textures of different extensions
* @param  path[in] path to texture
* @returns texture on success otherwise will be returned nullptr;
*/
	[[nodiscard]] SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path);
} // !Utils

#endif // !SLOTMACHINE_UTILS_HPP