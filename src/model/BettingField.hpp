#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Chip.hpp"

class BettingField
{
public:
    BettingField();

    void SetPosition(sf::Vector2f Position);
    void Draw(sf::RenderWindow& Window);

    void AddChip(int Value);
    bool Contains(sf::Vector2f Position) const;

    int Id;

private:
    sf::RectangleShape Shape;
  //  sf::Text Label;
 //   sf::Font Font;
    std::vector<Chip> Chips;
};