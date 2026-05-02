#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

#include "../core/EventBus.hpp"
#include "../events/GameEvents.hpp"

class InputSystem
{
public:
    InputSystem(EventBus& Bus, sf::RenderWindow& Window);

    void Update();

private:
    EventBus& Bus;
    sf::RenderWindow& Window;
};