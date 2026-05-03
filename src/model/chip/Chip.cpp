#include "Chip.hpp"

Chip::Chip()
    : Value(0)
{
}

Chip::Chip(int value)
    : Value(value)
{
}

int Chip::GetValue() const
{
    return Value;
}

void Chip::SetValue(int value)
{
    Value = value;
}