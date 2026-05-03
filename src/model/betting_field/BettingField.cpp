#include "BettingField.hpp"
#include "BettingFieldResources.hpp"

namespace
{
    constexpr float FieldSize = 50.0f;
    constexpr float ChipSize = 30.0f;
}

BettingField::BettingField(int id, Point position)
    : Id(id),
    Position(position),
    Background(FieldBackgroundImage{ id }, position, DrawLayer::Tapi),
    FieldChip(0, Point(0.0f, 0.0f))
{
    Background.SetBoxSize(Point(FieldSize, FieldSize));
    ActiveOverlay.SetBoxSize(Point(FieldSize, FieldSize));

    FieldChip.SetPosition(GetCenteredChipPosition());
    FieldChip.SetSize(Point(ChipSize, ChipSize));
}

void BettingField::SetPosition(Point position)
{
    Position = position;

    Background.SetPosition(position);
    ActiveOverlay.SetPosition(position);

    if (HasChip)
    {
        FieldChip.SetPosition(GetCenteredChipPosition());
    }
}

Point BettingField::GetPosition() const
{
    return Position;
}

void BettingField::SetActive(bool isActive)
{
    Active = isActive;
}

bool BettingField::IsActive() const
{
    return Active;
}

void BettingField::Draw(DrawList& drawList) const
{
    Background.Draw(drawList);

    if (Active)
    {
        ActiveOverlay.Draw(drawList);
    }

    if (HasChip)
    {
        FieldChip.Draw(drawList);
    }
}

void BettingField::SetBet(int value)
{
    FieldChip.SetBet(value);
    HasChip = true;
}

bool BettingField::Contains(Point position) const
{
    return position.X >= Position.X &&
        position.X <= Position.X + FieldSize &&
        position.Y >= Position.Y &&
        position.Y <= Position.Y + FieldSize;
}

Point BettingField::GetCenteredChipPosition() const
{
    return Point( Position.X + (FieldSize - ChipSize) / 2.0f, 
                  Position.Y + (FieldSize - ChipSize) / 2.0f );
}