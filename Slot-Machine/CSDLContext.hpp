#ifndef SLOTMACHINE_CSDLContext_HPP
#define SLOTMACHINE_CSDLContext_HPP
#include <SDL.h>
#include "SDL_image.h"
#include <SDL_ttf.h>
#include <iostream>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class CSDLContext
{
private:
	SDL_Renderer* renderer_;
	SDL_Window* window_;
	SDL_Surface* windowSurface_;

public:
	CSDLContext() = default;
	~CSDLContext() = default;
public:/** Deleting copy constructor , Move Constructor, copy assignment operators  */
	CSDLContext(const CSDLContext&) = delete;
	CSDLContext(CSDLContext&&) = delete;
	CSDLContext operator=(const CSDLContext&) = delete;
	CSDLContext operator=(CSDLContext&) = delete;
public:

/**
* @brief Initialize SDL & TTF_Font & IMG
*\returns 0 on success or a positive error code on failure;
*/
	bool init();
/**
*  @brief needed to get instance of CSDLContext
*  @return instance
*/
	static CSDLContext& instance();
/**
* @brief release IMG, TTF, Renderer,Window, SDL
*/
	void release();
/**
* @return pointer on SDL_Window
*/
	[[nodiscard]] SDL_Window* get_window() const noexcept { return window_; }
/**
* @return pointer on SDL_Renderer
*/
	[[nodiscard]] SDL_Renderer* get_renderer() const noexcept { return renderer_; }
/**
* @return pointer on SDL_Surface which contains windowSurface_
*/
	[[nodiscard]] SDL_Surface* get_windowSurface() const noexcept { return windowSurface_; }
 };

#endif // !SLOTMACHINE_CSDLContext_HPP