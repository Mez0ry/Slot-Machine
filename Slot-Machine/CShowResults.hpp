#ifndef SLOTMACHINE_CShowResults_HPP
#define SLOTMACHINE_CShowResults_HPP
#include "GameStates.hpp"
#include "TextureManager.hpp"
class CShowResults : public GameStates
{
public:
	CShowResults();
	~CShowResults();

	void setup(TextureManager& texture_manager, SDL_Rect& stop_rect);

private:
	TextureManager textureManager_;
	SDL_Rect stopRect_;
};

#endif // !SLOTMACHINE_CShowResults_HPP