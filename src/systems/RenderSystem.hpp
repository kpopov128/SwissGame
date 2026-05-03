#pragma once

#include "graphics/DrawList.hpp"
#include "model/game_state/GameState.hpp"

class RenderSystem
{
public:
    explicit RenderSystem(GameState& State);

    void Render(DrawList& DrawList);

private:
    GameState& State;
};
