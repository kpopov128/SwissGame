#include "BettingField.hpp"

BettingField::BettingField()
{
    Shape.setSize(sf::Vector2f(60.f, 60.f));
    Shape.setFillColor(sf::Color(80, 80, 80));

  //  Font.loadFromFile("arial.ttf"); // сложи font в project folder

  //  Label.setFont(Font);
 //   Label.setCharacterSize(14);
 //   Label.setFillColor(sf::Color::White);
}

bool BettingField::Contains(sf::Vector2f Position) const
{
    return Shape.getGlobalBounds().contains(Position);
}

void BettingField::SetPosition(sf::Vector2f Position)
{
    Shape.setPosition(Position);
}

void BettingField::AddChip(int Value)
{
    sf::Vector2f Center = Shape.getPosition();
    Center += sf::Vector2f(20.f, 20.f);

    Chips.emplace_back(Value, Center);
}

void BettingField::Draw(sf::RenderWindow& Window)
{
    Window.draw(Shape);

   // Label.setString(std::to_string(Id));
   // Label.setPosition(Shape.getPosition());

   // Window.draw(Label);

    for (auto& ChipObj : Chips)
        ChipObj.Draw(Window);
}