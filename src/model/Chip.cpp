#include "Chip.hpp"

Chip::Chip(int Value, sf::Vector2f Position)
{
    this->Value = Value;

    Shape.setRadius(10.f);
    Shape.setFillColor(sf::Color::Red);
    Shape.setOrigin(sf::Vector2f(10.f, 10.f));
    Shape.setPosition(Position);
}

void Chip::Draw(sf::RenderWindow& Window)
{
    Window.draw(Shape);
}