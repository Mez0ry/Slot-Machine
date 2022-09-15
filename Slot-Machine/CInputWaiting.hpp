#ifndef SLOTMACHINE_CInputWaiting_HPP
#define SLOTMACHINE_CInputWaiting_HPP
#include "GameStates.hpp"

class CInputWaiting : public GameStates
{
public:
	CInputWaiting();
	~CInputWaiting();
	void setup();
	void input_handler();
private:
	Utils::vec2 mousePosition_;
};

#endif // !SLOTMACHINE_CInputWaiting_HPP