#include "BettingFieldView.hpp"
#include "model/betting_field/BettingFieldResources.hpp"

BettingFieldView::BettingFieldView(int fieldNumber, Point position, float fieldSize)
    : FieldId(fieldNumber),
      Position(position),
      FieldSize(fieldSize)
{
    Background.SetPosition(position);
    Background.SetImage(FieldBackgroundImage{ fieldNumber });
    Background.SetBoxSize(Point(fieldSize, fieldSize));
}

int BettingFieldView::GetFieldId() const
{
    return FieldId;
}

bool BettingFieldView::Contains(Point point) const
{
    return
        point.X >= Position.X &&
        point.X <= Position.X + FieldSize &&
        point.Y >= Position.Y &&
        point.Y <= Position.Y + FieldSize;
}

void BettingFieldView::SetAmount(int amount)
{
    Chip.SetAmount(amount);

    Point chipPos = GetChipPosition();
    float chipSize = FieldSize * 0.7f;

    Chip.SetPosition(chipPos);
    Chip.SetSize(Point(chipSize, chipSize));
}

void BettingFieldView::Draw(DrawList& drawList) const
{
    Background.Draw(drawList);
    Chip.Draw(drawList);
}

Point BettingFieldView::GetChipPosition() const
{
    float chipSize = FieldSize * 0.7f;

    return Point(
        Position.X + (FieldSize - chipSize) * 0.5f,
        Position.Y + (FieldSize - chipSize) * 0.5f
    );
}