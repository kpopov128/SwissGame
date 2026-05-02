#pragma once

#include "../core/EventBus.hpp"
#include "../events/GameEvents.hpp"
#include "../model/GameState.hpp"

class BettingSystem
{
public:
    BettingSystem(EventBus& Bus, GameState& State);

private:
    void OnMouseUp(const MouseUpEvent& Event);

    EventBus& Bus;
    GameState& State;
};