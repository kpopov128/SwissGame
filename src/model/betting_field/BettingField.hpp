#pragma once

#include "model/chip/Chip.hpp"

class BettingField
{
public:
    explicit BettingField(int number);

    int GetNumber() const;

    bool HasChip() const;
    int GetAmount() const;

    void AddChip(int value);
    void Clear();

private:
    int Number = 0;
    Chip FieldChip;
};