#ifndef SLOTMACHINE_CShowResults_HPP
#define SLOTMACHINE_CShowResults_HPP
#include "GameStates.hpp"
#include "TextureManager.hpp"
class CShowResults : public GameStates
{
public:
	CShowResults();
	CShowResults(const std::vector<Utils::vec2>& slot_win_indexes, TextureManager& texture_manager, SDL_Rect& stop_rect);
	~CShowResults();

	void update() {}
private:
	TextureManager textureManager_;
	SDL_Rect stopRect_;

	std::vector<Utils::vec2> SlotWinIndexes;
};

#endif // !SLOTMACHINE_CShowResults_HPP