#pragma once

#include <vector>
#include "BettingField.hpp"

class BettingTable
{
public:
    void Initialize();
    void SetPosition(sf::Vector2f Position);
    void Draw(sf::RenderWindow& Window);

    bool TryPlaceBet(sf::Vector2f Position, int ChipValue);

    BettingField& GetField(int Index);

private:
    std::vector<BettingField> Fields;

    sf::Vector2f StartPosition;
    float Spacing = 70.f;
};