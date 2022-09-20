#include "CShowResults.hpp"

CShowResults::CShowResults()
{
}

CShowResults::~CShowResults()
{
}

void CShowResults::setup(TextureManager& texture_manager, SDL_Rect& stop_rect)
{
	this->textureManager_ = textureManager_;
	stopRect_ = stop_rect;
}
