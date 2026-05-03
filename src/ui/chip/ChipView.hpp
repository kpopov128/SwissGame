#pragma once

#include "graphics/Sprite.hpp"
#include "graphics/Point.hpp"
#include "graphics/DrawList.hpp"
#include "model/chip/ChipResources.hpp"

class ChipView
{
public:
    ChipView();

    void SetAmount(int amount);
    void SetPosition(Point position);
    void SetSize(Point size);

    int GetAmount() const;

    void Draw(DrawList& drawList) const;

private:
    EChipImage ResolveImage(int amount) const;

private:
    int Amount = 0;
    Sprite Background;
};