#ifndef SLOTMACHINE_GameStates_HPP
#define SLOTMACHINE_GameStates_HPP
#include "CSDLContext.hpp"
#include "Utils.hpp"

class GameStates
{
public:
	GameStates() = default;
	virtual ~GameStates() = default;

	virtual void setup() = 0;
	virtual void input_handler() = 0;
protected:
	SDL_Event event_;
private:
};

#endif // !SLOTMACHINE_GameStates_HPP