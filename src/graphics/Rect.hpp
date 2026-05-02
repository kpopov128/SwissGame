#pragma once
#include "Drawable.hpp"

class Rect : public Drawable
{
public:
    Rect(sf::Vector2f Size);

    void SetPosition(sf::Vector2f Position) override;
    sf::Vector2f GetPosition() const override;

    void SetColor(sf::Color Color);

    bool Contains(sf::Vector2f Point) const;

    sf::Vector2f GetSize() const;

    void Draw(sf::RenderWindow& Window) override;

private:
    sf::RectangleShape Shape;
};