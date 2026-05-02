#pragma once

#include <SFML/Graphics.hpp>
#include "../model/GameState.hpp"

class RenderSystem
{
public:
    RenderSystem(sf::RenderWindow& Window, GameState& State);

    void Draw();

private:
    sf::RenderWindow& Window;
    GameState& State;
};