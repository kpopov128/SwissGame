#include "Sprite.hpp"

void Sprite::SetBoxSize(Point size)
{
    BoxSize = size;
    HasCustomSize = true;
}

void Sprite::Draw(DrawList& drawList) const
{ 
    if (!IsVisible)
        return;

    drawList.DrawSprite(Image, Position, BoxSize, HasCustomSize, Layer);
}









