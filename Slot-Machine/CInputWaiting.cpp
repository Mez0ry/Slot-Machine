#include "CInputWaiting.hpp"

CInputWaiting::CInputWaiting()
{
}

CInputWaiting::~CInputWaiting()
{
}

void CInputWaiting::setup()
{
}

void CInputWaiting::input_handler()
{
	if (SDL_PollEvent(&event_)) {
		mousePosition_.x = event_.motion.x;
		mousePosition_.y = event_.motion.y;
		switch (event_.type) {
		case SDL_QUIT: {
			
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {

			break;
		}
		} // !switch
	}
}
