#ifndef SLOTMACHINE_GameStates_HPP
#define SLOTMACHINE_GameStates_HPP
#include "CSDLContext.hpp"
#include "Utils.hpp"
enum class enum_GameStates {
	WaitingInput, RotatingDrums, ShowingResults, START, STOP, UNKNOWN
};

class GameStates
{
private:
public:
	GameStates() = default;
	virtual ~GameStates() = default;
	virtual void update(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes){}
	virtual enum_GameStates input_handler() { return enum_GameStates::UNKNOWN; };
 
protected:
	SDL_Event event_;
	int timer_;
	Utils::vec2 mousePosition_;
	GameStates(int timer) : timer_(timer) {}
	SDL_Texture* resultTextures_[3];
	int points_[3];

private:
};

#endif // !SLOTMACHINE_GameStates_HPP