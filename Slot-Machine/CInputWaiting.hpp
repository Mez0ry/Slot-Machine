#ifndef SLOTMACHINE_CInputWaiting_HPP
#define SLOTMACHINE_CInputWaiting_HPP
#include "GameStates.hpp"

class CInputWaiting : public GameStates
{
public:
	CInputWaiting();
	~CInputWaiting();
	void setup(const SDL_Rect& start_rect, const SDL_Rect& stop_rect);
	enum_GameStates input_handler() override;
 
private:
	SDL_Rect rect_[2];
};

#endif // !SLOTMACHINE_CInputWaiting_HPP