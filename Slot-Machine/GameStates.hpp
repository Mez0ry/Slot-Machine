#ifndef SLOTMACHINE_GameStates_HPP
#define SLOTMACHINE_GameStates_HPP
#include "CSDLContext.hpp"
#include "Utils.hpp"
enum class enum_GameStates {
	WaitingInput, RotatingDrums, ShowingResults, START, STOP, UNKNOWN
};
class GameStateContext;

class GameStates
{
protected:
	GameStateContext* context_;
public:
	GameStates() = default;
	virtual ~GameStates() = default;

	virtual void set_state(GameStateContext* context) {
		this->context_ = context;
	}

	virtual void update(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes){}
	
	virtual void input_handler() { };
 
protected:
	SDL_Event event_;
	int timer_;
	Utils::vec2 mousePosition_;
	GameStates(int timer) : timer_(timer) {}

private:
};

class GameStateContext {
private:
	GameStates* state_;
	 
public:
	GameStateContext(GameStates* state) : state_(nullptr) {
		this->ChangeStateTo(state);
	}

	void ChangeStateTo(GameStates* state) {
		if (this->state_ != nullptr)
			delete this->state_;

		this->state_ = state;
		this->state_->set_state(this);
	}

	void updateRequest(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes) {
		this->state_->update(Rect_Arr, indexes);
	}

	void HandleInputRequest() {
		this->state_->input_handler();
	}

private:
};
#endif // !SLOTMACHINE_GameStates_HPP