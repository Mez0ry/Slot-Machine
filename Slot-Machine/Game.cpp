#include "Game.hpp"

Game::Game()
{
	if (CSDLContext::instance().init() == EXIT_SUCCESS) {
		std::puts("SDL Context successfully initialized");
	}

	bGameLoop_ = true;
}

Game::~Game()
{

}

void Game::play()
{
	while (bGameLoop_) {

		SDL_RenderClear(CSDLContext::instance().get_renderer());

		render();
		input_handler();
		update();
		 

		SDL_RenderPresent(CSDLContext::instance().get_renderer());
	}
}

void Game::update()
{
}

void Game::render()
{
}

void Game::input_handler()
{
	if (SDL_PollEvent(&event_)) {
		switch (event_.type) {
		case SDL_QUIT: {
			bGameLoop_ = false;
			break;
		}
		}
	}
}
