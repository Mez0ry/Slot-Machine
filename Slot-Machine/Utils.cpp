#include "Utils.hpp"

SDL_Texture* Utils::load_texture(SDL_Renderer* renderer, const char* path)
{
    SDL_Surface* tmp_surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    return texture ? texture : nullptr;
}

 

void Utils::Reset::reset_SlotPosition(SDL_Rect Rect_Arr[3][3])
{
	int rect_coord_x = 150;
	for (int i = 0; i < 3; i++) {
		int counter = 0;
		Rect_Arr[i][counter].x = SCREEN_WIDTH / 2 - rect_coord_x;
		Rect_Arr[i][counter].y = (SCREEN_HEIGHT / 2 - 200);
		Rect_Arr[i][counter++].w = Rect_Arr[i][counter].h = 90;

		Rect_Arr[i][counter].x = SCREEN_WIDTH / 2 - rect_coord_x;
		Rect_Arr[i][counter].y = (SCREEN_HEIGHT / 2 + 100);
		Rect_Arr[i][counter++].w = Rect_Arr[i][counter].h = 90;

		Rect_Arr[i][counter].x = SCREEN_WIDTH / 2 - rect_coord_x;
		Rect_Arr[i][counter].y = (SCREEN_HEIGHT / 2 - 50);
		Rect_Arr[i][counter++].w = Rect_Arr[i][counter].h = 90;

		rect_coord_x -= 150;
	}
}

void Utils::Reset::reset_SlotPosition(SDL_Rect& Rect_Arr, int row_index,  int col_index)
{
	int rect_coord_x = 0;
	switch (row_index) {
	case 0: {
		rect_coord_x = (SCREEN_WIDTH / 2 ) - 150;
		break;
	}
	case 1: {
		rect_coord_x = (SCREEN_WIDTH / 2) - 0;
		break;
	}
	case 2: {
		rect_coord_x = (SCREEN_WIDTH / 2) + 150;
		break;
	}
	}
	int rect_coord_y = 0;
 
	rect_coord_y = (SCREEN_HEIGHT / 2 - 350);
	Rect_Arr.x = rect_coord_x;
	Rect_Arr.y = rect_coord_y;
	Rect_Arr.w = Rect_Arr.h = 0;
}

int Utils::Random::random_num(int from, int to)
{
	std::random_device rd;    
	std::mt19937 gen(rd());   
	std::uniform_int_distribution<> dist(from, to);
	return dist(gen);
}

Utils::vec2 Utils::RectManager::rectClosestTo(SDL_Rect rect[3][3], const size_t row, int target)
{
	Utils::vec2 winnerSlotIndex_{};
	int closestToCenter = INT_MAX;
	 
	for (int x = 0; x < 3; x++) {
		int target = 350;
		int diff = rect[row][x].y - target;
		if (abs(diff) < closestToCenter) {
			winnerSlotIndex_.x = x;
			winnerSlotIndex_.y = row;

			closestToCenter = std::abs(diff);
		}
	}

	return winnerSlotIndex_;
}

void Utils::RectManager::draw_rectangle(const SDL_Rect& rect_, const SDL_Color& color)
{
	SDL_SetRenderDrawColor(CSDLContext::instance().get_renderer(), 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(CSDLContext::instance().get_renderer());

	SDL_SetRenderDrawColor(CSDLContext::instance().get_renderer(), color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(CSDLContext::instance().get_renderer(), &rect_);

}

TTF_Font* Utils::FontManager::open_font(const char* font_path, int font_size)
{
	TTF_Font* font = TTF_OpenFont(font_path, font_size);
	return font ? font : nullptr;
}

SDL_Surface* Utils::FontManager::get_FontSurface(TTF_Font* font, const char* text_to_render, SDL_Color color)
{

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text_to_render, color);
	return text_surface ? text_surface : nullptr;
}

SDL_Texture* Utils::FontManager::get_FontTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* text_surface)
{

	SDL_Texture* texture_text = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_FreeSurface(text_surface);

	return texture_text ? texture_text : nullptr;
}