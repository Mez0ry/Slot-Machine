#include "CDrumRotation.hpp"

CDrumRotation::CDrumRotation(TextureManager& texture_manager, SDL_Rect& stop_rect) : GameStates(0)
{
	TextureManager_ = texture_manager;
	this->StopRect_ = stop_rect;

	MaxTime_ = Utils::Random::random_num(200, 5000);
	SlotIsReady = -1;
	Finished_ = false;
	SlotWinnerIndexes_.clear();
}

CDrumRotation::~CDrumRotation()
{

}

void CDrumRotation::update(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes)
{

	if (Finished_)
		return;

	if (indexes.x >= 3)
		indexes.x = 0;

	if (indexes.y >= 3) {
		indexes.y = 0;
	} 

	timer_++;

	if (Rect_Arr[indexes.y][indexes.x].y > 200 && Rect_Arr[indexes.y][indexes.x].w != 100 && Rect_Arr[indexes.y][indexes.x].h != 100) {
		Rect_Arr[indexes.y][indexes.x].w = Rect_Arr[indexes.y][indexes.x].h = 100;
	}

		if (Rect_Arr[indexes.y][indexes.x].y < 500) {
			Rect_Arr[indexes.y][indexes.x].y += 5;
		}

		else {
			if (timer_ >= MaxTime_ || bStopPressed_) {

				int y = indexes.y;
				Utils::vec2 winnter_slot_indexies;

				const int Center = 350;
				winnter_slot_indexies = Utils::RectManager::rectClosestTo(Rect_Arr, y, Center);

				SlotWinnerIndexes_.push_back(winnter_slot_indexies);

				while (Rect_Arr[winnter_slot_indexies.y][winnter_slot_indexies.x].y > Center) {
					Rect_Arr[winnter_slot_indexies.y][winnter_slot_indexies.x].y -= 1;
				}

				while (Rect_Arr[winnter_slot_indexies.y][winnter_slot_indexies.x].y < Center) {
					Rect_Arr[winnter_slot_indexies.y][winnter_slot_indexies.x].y += 1;
				}

				for (int j = 0; j < 3; j++) {
					if (Rect_Arr[indexes.y][j].y < 202)
						Rect_Arr[indexes.y][j].y += 1;

					if (Rect_Arr[indexes.y][j].w != 100 || Rect_Arr[indexes.y][j].h != 100) {
						Rect_Arr[indexes.y][j].w = Rect_Arr[indexes.y][j].h = 100;
					}

				}

				timer_ = 0;
				MaxTime_ = Utils::Random::random_num(200, 5000);
				SlotIsReady = indexes.y + 1;
				indexes.y++;
				 
				if (SlotIsReady == 3) {
					Finished_ = true;
				}
				if (bStopPressed_) 
					bStopPressed_ = false;
			}
			 
			Rect_Arr[indexes.y][indexes.x].y += 5;

			if (Rect_Arr[indexes.y][indexes.x].y >= 500) {
				Rect_Arr[indexes.y][indexes.x].h -= 2;
				Utils::Reset::reset_SlotPosition(Rect_Arr[indexes.y][indexes.x], indexes.y, indexes.x);
			}

		}
	 
}

void CDrumRotation::input_handler()
{
	if (Finished_) {
		this->context_->ChangeStateTo(new CShowResults(SlotWinnerIndexes_, TextureManager_, StopRect_));
	}

	if (SDL_PollEvent(&event_)) {
		mousePosition_.x = event_.motion.x;
		mousePosition_.y = event_.motion.y;
		switch (event_.type) {
		case SDL_QUIT: {

			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			if (event_.button.button == SDL_BUTTON_LEFT && mousePosition_.x >= StopRect_.x && mousePosition_.x <= (StopRect_.x + StopRect_.w) && mousePosition_.y >= StopRect_.y && mousePosition_.y <= StopRect_.y + StopRect_.h) {
				bStopPressed_ = true;
			}
			 
			break;
		}
		} // !switch
	}
	 
}
