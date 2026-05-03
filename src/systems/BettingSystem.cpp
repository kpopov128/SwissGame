#include "BettingSystem.hpp"

BettingSystem::BettingSystem(EventBus& Bus, GameState& State)
    : Bus(Bus), State(State)
{
    Bus.Subscribe<OnReleaseEvent>(
        [this](const OnReleaseEvent& Event)
        {
            OnRelease(Event);
        }
    );
}

void BettingSystem::OnRelease(const OnReleaseEvent& Event)
{
    State.Table.TryPlaceBet(Event.Touch.Position, State.SelectedChip);
}
