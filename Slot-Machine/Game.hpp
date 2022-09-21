#ifndef SLOTMACHINE_GAME_HPP
#define SLOTMACHINE_GAME_HPP
#include "CSDLContext.hpp"
#include "MainScene.hpp"
class Game
{
private:
	uint32_t fps_ = 60;
	uint32_t frameDelay_ = 3000 / fps_;
	uint32_t frameStart_;
	uint32_t frameTime_;

	bool bGameLoop_;
private:
	SDL_Event event_;
public:
	Game();
	~Game();

	void play();
private:
	void update();
	void render();
	void input_handler();

private:
	MainScene mainScene_;
};

#endif // !SLOTMACHINE_GAME_HPP