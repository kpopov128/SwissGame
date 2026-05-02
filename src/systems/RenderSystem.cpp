#include "RenderSystem.hpp"

RenderSystem::RenderSystem(sf::RenderWindow& Window, GameState& State)
    : Window(Window), State(State)
{}

void RenderSystem::Draw()
{
    State.Table.Draw(Window);
}