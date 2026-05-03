#pragma once

#include "core/EventBus.hpp"
#include "events/InputEvents.hpp"
#include "model/game_state/GameState.hpp"

class BettingSystem
{
public:
    BettingSystem(EventBus& Bus, GameState& State);

private:
    void OnRelease(const OnReleaseEvent& Event);

    EventBus& Bus;
    GameState& State;
};
