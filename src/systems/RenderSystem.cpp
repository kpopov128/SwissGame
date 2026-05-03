#include "RenderSystem.hpp"

RenderSystem::RenderSystem(GameState& State)
    : State(State)
{
}

void RenderSystem::Render(DrawList& DrawList)
{
    DrawList.Clear();
    State.Table.Draw(DrawList);
}
