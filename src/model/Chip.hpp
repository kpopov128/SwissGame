#pragma once
#include <SFML/Graphics.hpp>

class Chip
{
public:
    Chip(int Value, sf::Vector2f Position);

    void Draw(sf::RenderWindow& Window);

private:
    int Value;
    sf::CircleShape Shape;
};