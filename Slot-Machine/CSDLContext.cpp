#include "CSDLContext.hpp"

bool CSDLContext::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != EXIT_SUCCESS) {
		std::cout << "Unable to initialize SDL: " << SDL_GetError() << '\n';
		return EXIT_FAILURE;
	}

	uint32_t WindowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;

	window_ = SDL_CreateWindow("Slot-Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, WindowFlags);
	if (window_ == NULL) {
		std::cout << "Window can't be created. Error: " << SDL_GetError() << '\n';
		return EXIT_FAILURE;
	}

	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	if (renderer_ == NULL) {
		std::cout << "Renderer can't be created. Error: " << SDL_GetError() << '\n';
		return EXIT_FAILURE;
	}

	windowSurface_ = SDL_GetWindowSurface(window_);
	if (windowSurface_ == 0) {
		std::cout << "Failed to get window surface, Error: " << SDL_GetError() << '\n';
	}
	puts("SDL successfully initialized");

	if (TTF_Init() == EXIT_SUCCESS) {
		std::cout << "TTF successfully intialized " << '\n';
	}
	else {
		std::cout << "Failed to init TTF: " << TTF_GetError() << '\n';
	}
	int initialized = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	if (initialized == NULL) {
		std::cout << "IMG_Init: Failed to init required jpg and png support! \n IMG_Error:" << IMG_GetError();
	}

	return EXIT_SUCCESS;
}

CSDLContext& CSDLContext::instance()
{
	static CSDLContext instance_;
	return instance_;
}

void CSDLContext::release()
{
	IMG_Quit();
	TTF_Quit();

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}
