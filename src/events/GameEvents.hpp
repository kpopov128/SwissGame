#pragma once

#include <SFML/Graphics.hpp>

struct MouseDownEvent
{
    sf::Vector2f Position;
};

struct MouseUpEvent
{
    sf::Vector2f Position;
};

struct PlaceBetEvent
{
    int FieldId;
    int ChipValue;
};