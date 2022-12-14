#ifndef SLOTMACHINE_UTILS_HPP
#define SLOTMACHINE_UTILS_HPP
#include "SDL.h" 
#include "SDL_image.h"
#include "CSDLContext.hpp"	
#include <random>

namespace Utils {

	struct vec2 { int x; int y; };
/**
* @brief Loading textures of different extensions
* @param  path[in] path to texture
* @returns texture on success otherwise will be returned nullptr;
*/
	[[nodiscard]] SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path);

	namespace Reset {
		void reset_SlotPosition(SDL_Rect Rect_Arr[3][3]);
		void reset_SlotPosition(SDL_Rect& Rect_Arr, int row_index, int col_index);
	}

	namespace RectManager {
		Utils::vec2 rectClosestTo(SDL_Rect rect[3][3], const size_t row, int target);
		void draw_rectangle(const SDL_Rect& rect_, const SDL_Color& color);
	}

	namespace Random {
		int random_num(int from, int to);
	}

	namespace FontManager {
		[[nodiscard]] TTF_Font* open_font(const char* font_path, int font_size);
		[[nodiscard]] SDL_Surface* get_FontSurface(TTF_Font* font, const char* text_to_render, SDL_Color color);
		[[nodiscard]] SDL_Texture* get_FontTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* text_surface);
	}// !FontManager
} // !Utils

#endif // !SLOTMACHINE_UTILS_HPP