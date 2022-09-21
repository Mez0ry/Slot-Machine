#include "Game.hpp"

Game::Game()
{
	if (CSDLContext::instance().init() == EXIT_SUCCESS) {
		std::puts("SDL Context successfully initialized");
	}

	mainScene_.setup();
	bGameLoop_ = true;
}

Game::~Game()
{

}

void Game::play()	
{
	while (bGameLoop_) {
		SDL_SetRenderDrawColor(CSDLContext::instance().get_renderer(), 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(CSDLContext::instance().get_renderer());

		update();
		render();
		input_handler();

		SDL_RenderPresent(CSDLContext::instance().get_renderer());
	}
}

void Game::update()
{
	mainScene_.update();
}

void Game::render()
{
	mainScene_.render();
}

void Game::input_handler()
{
	mainScene_.input_handler();
	if (SDL_PollEvent(&event_)) {
		switch (event_.type) {
		case SDL_QUIT: {
			bGameLoop_ = false;
			break;
		}
		}
	}
}
