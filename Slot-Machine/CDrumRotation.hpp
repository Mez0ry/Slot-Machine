#ifndef SLOTMACHINE_CDrumRotation_HPP
#define SLOTMACHINE_CDrumRotation_HPP
#include "GameStates.hpp"
#include "Utils.hpp"
#include "TextureManager.hpp"

class CDrumRotation : public GameStates
{
private:
	TextureManager TextureManager_;
public:
	CDrumRotation();
	~CDrumRotation();

	void setup(TextureManager& texture_manager,SDL_Rect& stop_rect);
	void update(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes);
 
	enum_GameStates input_handler() override;

private:
	bool bStopPressed_;
	SDL_Rect StopRect_;
	int SlotIsReady;
	int MaxTime_;

	bool Finished_ = false;
	std::vector<Utils::vec2> SlotWinnerIndexies_;
};

#endif // !SLOTMACHINE_CDrumRotation_HPP