#include "CShowResults.hpp"
#include "CInputWaiting.hpp"

CShowResults::CShowResults()
{
 
}

CShowResults::CShowResults(const std::vector<Utils::vec2>& slot_win_indexes, TextureManager& texture_manager)
{
	this->SlotWinIndexes = slot_win_indexes;
	this->textureManager_ = textureManager_;
 
	font_ = Utils::FontManager::open_font("..\\Slot-Machine\\assets\\font\\HACKED.ttf", 30);  
}

CShowResults::~CShowResults()
{
	SlotWinIndexes.clear();
	TTF_CloseFont(font_);
}

void CShowResults::input_handler()
{
	if (SDL_PollEvent(&event_)) {
		mousePosition_.x = event_.motion.x;
		mousePosition_.y = event_.motion.y;
		switch (event_.type) {
		case SDL_QUIT: {

			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
		 
			if (event_.button.button == SDL_BUTTON_LEFT && mousePosition_.x >= TakePoints_.x && mousePosition_.x <= (TakePoints_.x + TakePoints_.w) && mousePosition_.y >= TakePoints_.y && mousePosition_.y <= TakePoints_.y + TakePoints_.h) {
				this->context_->ChangeStateTo(new CInputWaiting(textureManager_));
			}
			break;
		}
		} // !switch
	}
}

void CShowResults::update()
{
 
}

void CShowResults::render()
{
 
	std::string score_text = "Your winning: " + std::to_string(calculatePayOut());
	SDL_Color textColor = { 0xFF, 0xFF, 0 ,0xFF };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font_, score_text.c_str(), textColor);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(CSDLContext::instance().get_renderer(), textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = { 350, SCREEN_HEIGHT - 170, text_width, text_height };
	SDL_RenderCopy(CSDLContext::instance().get_renderer(), texture, NULL, &renderQuad);

	textColor = { 0XFF,0x0,0,0xFF };
	std::string take_points = "take your winnings";
	SDL_Surface* textSurface2 = TTF_RenderText_Solid(font_, take_points.c_str(), textColor);
	SDL_Texture* texture2 = SDL_CreateTextureFromSurface(CSDLContext::instance().get_renderer(), textSurface2);
	TakePoints_.w = textSurface2->w;
	TakePoints_.h = textSurface2->h;
	TakePoints_.x = 350;
	TakePoints_.y = SCREEN_HEIGHT - 120;

	SDL_RenderCopy(CSDLContext::instance().get_renderer(), texture2, NULL, &TakePoints_);

	SDL_DestroyTexture(texture);
}

int CShowResults::calculatePayOut()
{
	int counter = 0;
	int sum = 0;
	while (counter < 3) {
		int col_num = SlotWinIndexes[counter].x;
		 
		switch (col_num) {
		case static_cast<int>(ShapeType::SQUARE): {
			sum += 3;
			break;
		}
		case static_cast<int>(ShapeType::CIRCLE): {
			sum += 2;
			break;
		}
		case static_cast<int>(ShapeType::STAR): {
			sum += 5;
			break;
		}
		}
		counter++;
	}
	return sum;
}

 