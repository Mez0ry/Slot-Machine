#ifndef SLOTMACHINE_CInputWaiting_HPP
#define SLOTMACHINE_CInputWaiting_HPP
#include "GameStates.hpp"
#include "CDrumRotation.hpp"
#include "TextureManager.hpp"

class CInputWaiting : public GameStates
{
	TextureManager TextureManager_;
public:
	CInputWaiting() = default;
	CInputWaiting(TextureManager& Texture_Manager);
	~CInputWaiting();
 
	void input_handler() override;
 
private:
 
};

#endif // !SLOTMACHINE_CInputWaiting_HPP