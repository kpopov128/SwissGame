#include "BettingSystem.hpp"

BettingSystem::BettingSystem(EventBus& bus, GameState& state)
    : Bus(bus),
    State(state)
{
    Bus.Subscribe<OnTouchEvent>(
        [this](const OnTouchEvent& event)
        {
            OnTouch(event);
        }
    );

    Bus.Subscribe<OnMoveEvent>(
        [this](const OnMoveEvent& event)
        {
            OnMove(event);
        }
    );

    Bus.Subscribe<OnReleaseEvent>(
        [this](const OnReleaseEvent& event)
        {
            OnRelease(event);
        }
    );
}

void BettingSystem::OnTouch(const OnTouchEvent& event)
{
    IsTouching = true;
    LastFieldId = -1;

    HandleTouchPosition(event.Touch.Position);
}

void BettingSystem::OnMove(const OnMoveEvent& event)
{
    if (!IsTouching)
    {
        return;
    }

    HandleTouchPosition(event.Touch.Position);
}

void BettingSystem::OnRelease(const OnReleaseEvent& event)
{
    IsTouching = false;
    LastFieldId = -1;
}

void BettingSystem::HandleTouchPosition(Point position)
{
    const auto fieldId = State.TableView.HitTest(position);

    if (fieldId == -1)
    {
        LastFieldId = -1;
        return;
    }

    if (fieldId == LastFieldId)
    {
        return;
    }

    State.Table.PlaceBet(fieldId, State.SelectedChip);

    const auto amount = State.Table.GetBetAmount(fieldId);
    State.TableView.SetFieldAmount(fieldId, amount);

    LastFieldId = fieldId;
}