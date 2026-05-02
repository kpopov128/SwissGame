#include "BettingSystem.hpp"

BettingSystem::BettingSystem(EventBus& Bus, GameState& State)
    : Bus(Bus), State(State)
{
    Bus.Subscribe<MouseUpEvent>(
        [this](const MouseUpEvent& Event)
        {
            OnMouseUp(Event);
        }
    );
}

void BettingSystem::OnMouseUp(const MouseUpEvent& Event)
{
    State.Table.TryPlaceBet(Event.Position, State.SelectedChip);
}