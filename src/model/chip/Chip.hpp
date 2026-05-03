#pragma once

#include "graphics/DrawLayer.hpp"
#include "graphics/DrawList.hpp"
#include "graphics/Sprite.hpp"

#include "ChipResources.hpp"

class Chip
{
public:
    Chip(int bet, Point position)
        : Bet(bet), Position(position), Background(EChipImage::eRed, position, DrawLayer::Chips)
    {
    }

    void SetBet(int bet) { Bet = bet; }

    void Draw(DrawList& DrawList) const;

    void SetSize(Point size) { Background.SetBoxSize(size); }

    void SetPosition(Point position) { Background.SetPosition(position); }

private:
    int Bet = 0;
    Point Position;
    Sprite Background;
};
