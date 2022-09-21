#include "CInputWaiting.hpp"

CInputWaiting::CInputWaiting(TextureManager& Texture_Manager) : GameStates(0)
{
	this->TextureManager_ = Texture_Manager;
}

CInputWaiting::~CInputWaiting()
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
			for (size_t read_index = 0; read_index < 2; read_index++) {
				if (event_.button.button == SDL_BUTTON_LEFT && mousePosition_.x >= StartStopRect_[read_index].x && mousePosition_.x <= (StartStopRect_[read_index].x + StartStopRect_[read_index].w) && mousePosition_.y <= StartStopRect_[read_index].y + StartStopRect_[read_index].h) {
					if (read_index == 0) {
						this->context_->ChangeStateTo(new CDrumRotation(TextureManager_));
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
