#include "Utils.hpp"

SDL_Texture* Utils::load_texture(SDL_Renderer* renderer, const char* path)
{
    SDL_Surface* tmp_surface = IMG_Load(path);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    return texture ? texture : nullptr;
}
