#ifndef SLOTMACHINE_MainScene_HPP
#define SLOTMACHINE_MainScene_HPP
#include "SDL.h"
#include "CSDLContext.hpp"
#include "Utils.hpp"
#include "GameStates.hpp"
#include "CShowResults.hpp"
#include "CInputWaiting.hpp"
#include "CDrumRotation.hpp"
#include "TextureManager.hpp"
#include <future>
class MainScene
{
private:
	CInputWaiting InputWaitingState_;
	CShowResults ShowResultsState_;
	CDrumRotation drumRotationState_;
	GameStateContext* StateContext_;
private:
	TextureManager TextureManager_;
public:
	MainScene();
	~MainScene();

	void setup();
	void update();
	void input_handler();
	void render();

private:

	enum_GameStates enumStates_;

	SDL_Rect startRect_;
	SDL_Rect stopRect_;

	SDL_Texture* startTexture_;
	SDL_Texture* stopTexture_;
 
	Utils::vec2 RectIndexies_;
};

#endif // !SLOTMACHINE_MainScene_HPP