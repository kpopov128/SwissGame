#pragma once

#include "core/EventBus.hpp"
#include "events/InputEvents.hpp"
#include "model/game_state/GameState.hpp"
#include "graphics/Point.hpp"

class BettingSystem
{
public:
    BettingSystem(EventBus& bus, GameState& state);

private:
    void OnTouch(const OnTouchEvent& event);
    void OnMove(const OnMoveEvent& event);
    void OnRelease(const OnReleaseEvent& event);

    void HandleTouchPosition(Point position);

private:
    EventBus& Bus;
    GameState& State;

    bool IsTouching = false;
    int LastFieldId = -1;
};