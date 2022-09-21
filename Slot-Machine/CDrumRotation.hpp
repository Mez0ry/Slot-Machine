#ifndef SLOTMACHINE_CDrumRotation_HPP
#define SLOTMACHINE_CDrumRotation_HPP
#include "GameStates.hpp"
#include "Utils.hpp"
#include "TextureManager.hpp"
#include "CShowResults.hpp"

class CDrumRotation : public GameStates
{
private:
	TextureManager TextureManager_;
	SDL_Rect* pRect[3][3];
public:
	CDrumRotation() = default;
	CDrumRotation(TextureManager& texture_manager);
	~CDrumRotation();

	void update(SDL_Rect Rect_Arr[3][3], Utils::vec2& indexes);
 
	void input_handler() override;

private:
	bool bStopPressed_;
 
	int SlotIsReady;
	int MaxTime_;

	bool Finished_ = false;
	std::vector<Utils::vec2> SlotWinnerIndexes_;
	
};

#endif // !SLOTMACHINE_CDrumRotation_HPP