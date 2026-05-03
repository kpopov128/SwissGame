#include "Sprite.hpp"

void Sprite::SetBoxSize(Point size)
{
    BoxSize = size;
    HasCustomSize = true;
}

void Sprite::Draw(DrawList& drawList) const
{ 
    drawList.DrawSprite(Image, Position, BoxSize, HasCustomSize, Layer);
}









