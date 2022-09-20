#include "CInputWaiting.hpp"

CInputWaiting::CInputWaiting()
{

}

CInputWaiting::~CInputWaiting()
{

}

void CInputWaiting::setup(const SDL_Rect& start_rect, const SDL_Rect& stop_rect)
{
	rect_[0] = start_rect;
	rect_[1] = stop_rect;
}

enum_GameStates CInputWaiting::input_handler()
{
	if (SDL_PollEvent(&event_)) {
		mousePosition_.x = event_.motion.x;
		mousePosition_.y = event_.motion.y;
		switch (event_.type) {
		case SDL_QUIT: {
			
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			for (size_t read_index = 0; read_index < 2; read_index++) {
				if (event_.button.button == SDL_BUTTON_LEFT && mousePosition_.x >= rect_[read_index].x && mousePosition_.x <= (rect_[read_index].x + rect_[read_index].w) && mousePosition_.y >= rect_[read_index].y && mousePosition_.y <= rect_[read_index].y + rect_[read_index].h) {
					if (read_index == 0) {
						return enum_GameStates::RotatingDrums;
					}
					if (read_index == 1) {
						std::cout << "Stop" << '\n';
					}
				}
			 }
			break;
		}
		} // !switch
	}
}
