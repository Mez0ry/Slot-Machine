#ifndef SLOTMACHINE_CInputWaiting_HPP
#define SLOTMACHINE_CInputWaiting_HPP
#include "GameStates.hpp"
#include "CDrumRotation.hpp"
#include "TextureManager.hpp"

class CInputWaiting : public GameStates
{
	TextureManager TextureManager_;
public:
	CInputWaiting() = default;
	CInputWaiting(const SDL_Rect& start_rect, const SDL_Rect& stop_rect,TextureManager& Texture_Manager);
	~CInputWaiting();
 
	void input_handler() override;
 
private:
	SDL_Rect rect_[2];
};

#endif // !SLOTMACHINE_CInputWaiting_HPP