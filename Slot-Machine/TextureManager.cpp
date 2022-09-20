#include "TextureManager.hpp"

 

void TextureManager::set_Target(const size_t row, const size_t col){
	this->TargetRow_ = row;
	this->TargetCol_ = col;

}

void TextureManager::set_Width(const int width)
{
	pRect_[this->TargetRow_][this->TargetCol_].w = width;
}

void TextureManager::set_Height(const int height)
{
	pRect_[this->TargetRow_][this->TargetCol_].h = height;
}

void TextureManager::set_Position(const Utils::vec2& pos)
{
	pRect_[this->TargetRow_][this->TargetCol_].x = pos.x;
	pRect_[this->TargetRow_][this->TargetCol_].y = pos.y;
}

 