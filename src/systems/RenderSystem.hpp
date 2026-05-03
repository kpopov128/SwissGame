#pragma once

#include "graphics/DrawList.hpp"
#include "model/game_state/GameState.hpp"

class RenderSystem
{
public:
    explicit RenderSystem(GameState& state);

    void Render(DrawList& drawList);

private:
    GameState& State;
};
