#pragma once

#include <vector>

#include "graphics/DrawList.hpp"
#include "graphics/Point.hpp"
#include "graphics/Sprite.hpp"
#include "ui/chip/ChipView.hpp"

class BettingFieldView
{
public:
    BettingFieldView(int fieldId, int imageId, Point position, Point size,
                     int chipSize, std::vector<int> highlightFieldIds, bool drawable = true);

    int GetFieldId() const;
    int GetImageId() const;

    const std::vector<int>& GetHighlightFieldIds() const;

    bool Contains(Point position) const;
    bool IsDrawableField() const;

    void SetAmount(int amount);
    void SetHighlighted(bool highlighted);

    void Draw(DrawList& drawList) const;

private:
    int GetActiveImageId(int imageId) const;
    Point GetChipPosition() const;

private:
    int FieldId = 0;
    int ImageId = 0;
    int ChipSize = 0;

    Point Position;
    Point Size;

    bool Drawable = true;
    bool Highlighted = false;

    std::vector<int> HighlightFieldIds;

    Sprite Background;
    Sprite ActiveBackground;
    ChipView Chip;
};