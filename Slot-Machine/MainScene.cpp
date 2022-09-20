#include "MainScene.hpp"
#define _GLIBCXX_USE_NANOSLEEP
#include <iostream>
#include <string>
#include <thread>
MainScene::MainScene()
{

}

MainScene::~MainScene()
{
 
}

void MainScene::setup()
{
 
	for (int i = 0; i < 3; i++) {
		int counter = 0;
		TextureManager_.get_textureAt(i, counter++) = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\square.png");

		TextureManager_.get_textureAt(i, counter++) = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\circle.png");
		TextureManager_.get_textureAt(i, counter++) = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\star.png");
	}
	startTexture_ = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\start.png");
	stopTexture_ = Utils::load_texture(CSDLContext::instance().get_renderer(), "..\\Slot-Machine\\assets\\stop.png");
 

	Utils::Reset::reset_SlotPosition(TextureManager_.get_Rect());
	 
		startRect_.x = SCREEN_WIDTH / 2 + 200;
		startRect_.y = (SCREEN_HEIGHT / 2 - 400);
		startRect_.w = startRect_.h = 100;

		stopRect_.x = SCREEN_WIDTH / 2 - 200;
		stopRect_.y = (SCREEN_HEIGHT / 2 - 400);
		stopRect_.w = stopRect_.h = 100;
	
	InputWaitingState_.setup(startRect_, stopRect_);
	drumRotationState_.setup(TextureManager_, stopRect_);
	ShowResultsState_.setup(TextureManager_, stopRect_);
	State_ = &InputWaitingState_;

	RectIndexies_.x = 0;
	RectIndexies_.y = 0;
}

void MainScene::update()
{
	 
	for (RectIndexies_.x = 0; RectIndexies_.x < 3; RectIndexies_.x++) {
			State_->update(TextureManager_.get_Rect(), RectIndexies_);
	}
	 
}

void MainScene::input_handler()
{
	enumStates_ = State_->input_handler();

	switch (enumStates_) {	
	case enum_GameStates::RotatingDrums: {
		State_ = &drumRotationState_;
		break;
	}
	case enum_GameStates::ShowingResults: {
		drumRotationState_.setup(TextureManager_, stopRect_);
		State_ = &ShowResultsState_;
		break;
	}
	}
}

void MainScene::render()
{
	SDL_Rect rect2 = { 50,200,700, 400 };
 
	SDL_SetRenderDrawColor(CSDLContext::instance().get_renderer(), 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(CSDLContext::instance().get_renderer());
	SDL_SetRenderDrawColor(CSDLContext::instance().get_renderer(), 255, 0, 0, 255);

	SDL_RenderDrawRect(CSDLContext::instance().get_renderer(), &rect2);

	SDL_Rect rect3 = { 50,350,700,100 };
	SDL_RenderDrawRect(CSDLContext::instance().get_renderer(), &rect3);
	 
	for (int i = 0; i < 3; i++) {
		int counter = 0;
		SDL_RenderCopy(CSDLContext::instance().get_renderer(), TextureManager_.get_textureAt(i, counter++), NULL, &TextureManager_.get_rectAt(i, counter));
		SDL_RenderCopy(CSDLContext::instance().get_renderer(), TextureManager_.get_textureAt(i, counter++), NULL, &TextureManager_.get_rectAt(i, counter));
		SDL_RenderCopy(CSDLContext::instance().get_renderer(), TextureManager_.get_textureAt(i, counter++), NULL, &TextureManager_.get_rectAt(i, counter));
	}
	SDL_Delay(6);
	 
	startRect_.x = SCREEN_WIDTH / 2 + 200;
	startRect_.y = (SCREEN_HEIGHT / 2 - 400);
	startRect_.w = startRect_.h = 100;

	stopRect_.x = SCREEN_WIDTH / 2 - 200;
	stopRect_.y = (SCREEN_HEIGHT / 2 - 400);
	stopRect_.w = stopRect_.h = 100;


	SDL_RenderCopy(CSDLContext::instance().get_renderer(), startTexture_, NULL, &startRect_);
	SDL_RenderCopy(CSDLContext::instance().get_renderer(), stopTexture_, NULL, &stopRect_);

}
