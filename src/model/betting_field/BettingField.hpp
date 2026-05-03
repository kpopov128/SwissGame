#pragma once

#include "graphics/DrawList.hpp"
#include "graphics/Point.hpp"
#include "graphics/Sprite.hpp"
#include "model/chip/Chip.hpp"

class BettingField
{
public:
    BettingField(int id, Point position);

    void SetPosition(Point position);
    Point GetPosition() const;

    void SetActive(bool isActive);
    bool IsActive() const;

    void Draw(DrawList& drawList) const;

    void SetBet(int value);
    bool Contains(Point position) const;

    int Id = 0;

private:
    Point GetCenteredChipPosition() const;

private:
    Point Position;

    Sprite Background;
    Sprite ActiveOverlay;

    bool Active = false;
    bool HasChip = false;

    Chip FieldChip;
};