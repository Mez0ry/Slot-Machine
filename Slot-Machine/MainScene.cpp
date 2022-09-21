#include "MainScene.hpp"

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

	RectIndexies_.x = 0;
	RectIndexies_.y = 0;

	StateContext_ = new GameStateContext(new CInputWaiting(startRect_, stopRect_, TextureManager_));
}

void MainScene::update()
{
	for (RectIndexies_.x = 0; RectIndexies_.x < 3; RectIndexies_.x++) {
		StateContext_->updateRequest(TextureManager_.get_Rect(), RectIndexies_);
	}
}	

void MainScene::input_handler()
{
	 StateContext_->HandleInputRequest();
}

void MainScene::render()
{
	SDL_Rect rect2 = { 50,200,700, 400 };
	SDL_Color color1 = { 255,0,0,255 };
	Utils::RectManager::draw_rectangle(rect2, color1);

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
