#include "CShowResults.hpp"

CShowResults::CShowResults()
{
 
}

CShowResults::CShowResults(const std::vector<Utils::vec2>& slot_win_indexes, TextureManager& texture_manager, SDL_Rect& stop_rect)
{
	this->SlotWinIndexes = slot_win_indexes;
	this->textureManager_ = textureManager_;
	stopRect_ = stop_rect;
	font_ = Utils::FontManager::open_font("..\\Slot-Machine\\assets\\font\\HACKED.ttf", 30);  
}

CShowResults::~CShowResults()
{
	TTF_CloseFont(font_);
}

void CShowResults::input_handler()
{
	if (SDL_PollEvent(&event_)) {
		switch (event_.type) {
		case SDL_QUIT: {

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
	std::string score_text = "You're gain: " + std::to_string(calculatePayOut());
	SDL_Color textColor = { 0xFF, 0xFF, 0 ,0xFF };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font_, score_text.c_str(), textColor);
	SDL_Texture* text = SDL_CreateTextureFromSurface(CSDLContext::instance().get_renderer(), textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	SDL_Rect renderQuad = { 350, SCREEN_HEIGHT - 170, text_width, text_height };
	
	SDL_RenderCopy(CSDLContext::instance().get_renderer(), text, NULL, &renderQuad);
	
	 

	SDL_DestroyTexture(text);
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

 