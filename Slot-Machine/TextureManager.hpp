#ifndef SLOTMACHINE_TextureManager_HPP
#define SLOTMACHINE_TextureManager_HPP
#include "SDL.h"
#include "Utils.hpp"
#include <vector>
class TextureManager
{
private:
	size_t TargetRow_, TargetCol_;
public:
	TextureManager() {}
	~TextureManager() = default;

	SDL_Texture*& get_textureAt(size_t row, size_t col) { return pTexture_[row][col]; }
	SDL_Rect& get_rectAt(const size_t row, const size_t col) { return pRect_[row][col]; }
	SDL_Rect (&get_Rect())[3][3] { return pRect_; }
public:
	void set_Target(size_t row, size_t col);
	void set_Width(const int width);
	void set_Height(const int height);
	void set_Position(const Utils::vec2& pos);

public:
	SDL_Texture*& operator()(const size_t row, const size_t col) {
		
		return pTexture_[row][col];
	}
private:
 
	SDL_Texture* pTexture_[3][3];
	SDL_Rect pRect_[3][3];
};

#endif // !SLOTMACHINE_TextureManager_HPP