#include "MainScene.hpp"

MainScene::MainScene()
{

}

MainScene::~MainScene()
{
	SDL_DestroyTexture(squareTexture_);
	SDL_DestroyTexture(circleTexture_);
	SDL_DestroyTexture(starTexture_);
}

void MainScene::setup()
{
	squareTexture_ = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\square.png");
	starTexture_ = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\star.png");
	circleTexture_ = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\circle.png");
}

void MainScene::update()
{

}

void MainScene::input_handler()
{

}

void MainScene::render()
{

}
