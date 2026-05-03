#include "BettingField.hpp"

BettingField::BettingField(int number)
    : Number(number)
{
}

int BettingField::GetNumber() const
{
    return Number;
}

bool BettingField::HasChip() const
{
    return FieldChip.GetValue() > 0;
}

int BettingField::GetAmount() const
{
    return FieldChip.GetValue();
}

void BettingField::AddChip(int value)
{
    FieldChip.SetValue(FieldChip.GetValue() + value);
}

void BettingField::Clear()
{
    FieldChip.SetValue(0);
}