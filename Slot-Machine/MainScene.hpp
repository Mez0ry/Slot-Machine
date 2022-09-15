#ifndef SLOTMACHINE_MainScene_HPP
#define SLOTMACHINE_MainScene_HPP
#include "SDL.h"
#include "CSDLContext.hpp"
#include "Utils.hpp"
#include "GameStates.hpp"
#include "CShowResults.hpp"
#include "CInputWaiting.hpp"
#include "CDrumRotation.hpp"

class MainScene
{
public:
	MainScene();
	~MainScene();

	void setup();
	void update();
	void input_handler();
	void render();

private:
	SDL_Rect squareRect_;
	SDL_Rect starRect_;
	SDL_Rect circleRect_;

	SDL_Texture* squareTexture_;
	SDL_Texture* starTexture_;
	SDL_Texture* circleTexture_;
};

#endif // !SLOTMACHINE_MainScene_HPP