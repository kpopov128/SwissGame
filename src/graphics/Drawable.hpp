#pragma once
#include <SFML/Graphics.hpp>

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void SetPosition(sf::Vector2f Position) = 0;
    virtual sf::Vector2f GetPosition() const = 0;

    virtual void Draw(sf::RenderWindow& Window) = 0;
};