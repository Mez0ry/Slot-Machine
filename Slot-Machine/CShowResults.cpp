#include "CShowResults.hpp"

CShowResults::CShowResults()
{

}

CShowResults::CShowResults(const std::vector<Utils::vec2>& slot_win_indexes, TextureManager& texture_manager, SDL_Rect& stop_rect)
{
	this->SlotWinIndexes = slot_win_indexes;
	this->textureManager_ = textureManager_;
	stopRect_ = stop_rect;
}

CShowResults::~CShowResults()
{

}

 