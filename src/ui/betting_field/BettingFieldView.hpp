#include "graphics/Sprite.hpp"
#include "ui/chip/ChipView.hpp"

class BettingFieldView
{
public:
    BettingFieldView(int fieldId, Point position, float fieldSize);

    int GetFieldId() const;
    bool Contains(Point position) const;

    void SetAmount(int amount);
    void Draw(DrawList& drawList) const;

private:
    Point GetChipPosition() const;

private:
    int FieldId = 0;
    Point Position;
    float FieldSize = 50.0f;

    Sprite Background;
    Sprite ActiveOverlay;
    ChipView Chip;
};