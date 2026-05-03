#include "RenderSystem.hpp"

RenderSystem::RenderSystem(GameState& state)
    : State(state)
{
}

void RenderSystem::Render(DrawList& drawList)
{
    drawList.Clear();
    State.TableView.Draw(drawList);
}
