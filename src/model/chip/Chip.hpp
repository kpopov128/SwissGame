#pragma once

class Chip
{
public:
    Chip();
    explicit Chip(int value);

    int GetValue() const;
    void SetValue(int value);

private:
    int Value = 0;
};