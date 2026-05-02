#include "Rect.hpp"

Rect::Rect(sf::Vector2f Size)
{
    Shape.setSize(Size);
}

void Rect::SetPosition(sf::Vector2f Position)
{
    Shape.setPosition(Position);
}

sf::Vector2f Rect::GetPosition() const
{
    return Shape.getPosition();
}

void Rect::SetColor(sf::Color Color)
{
    Shape.setFillColor(Color);
}

bool Rect::Contains(sf::Vector2f Point) const
{
    return Shape.getGlobalBounds().contains(Point);
}

sf::Vector2f Rect::GetSize() const
{
    return Shape.getSize();
}

void Rect::Draw(sf::RenderWindow& Window)
{
    Window.draw(Shape);
}