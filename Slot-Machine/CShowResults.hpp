#ifndef SLOTMACHINE_CShowResults_HPP
#define SLOTMACHINE_CShowResults_HPP
#include "GameStates.hpp"
#include "TextureManager.hpp"
#include "CSDLContext.hpp"
#include <string>

class CShowResults : public GameStates
{
private:
	enum class ShapeType {
		SQUARE, CIRCLE, STAR
	};
public:
	CShowResults();
	CShowResults(const std::vector<Utils::vec2>& slot_win_indexes, TextureManager& texture_manager);
	~CShowResults();

	void input_handler();
	void update();
	void render() override; 

private:
	SDL_Texture* background_;

	int calculatePayOut();
	TextureManager textureManager_;

	TTF_Font* font_;
	std::vector<Utils::vec2> SlotWinIndexes;
 
	SDL_Rect TakePoints_;
};

#endif // !SLOTMACHINE_CShowResults_HPP