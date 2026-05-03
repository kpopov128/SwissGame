#include "InputSystem.hpp"

#include "events/InputEvents.hpp"

InputSystem::InputSystem(EventBus& Bus)
    : Bus(Bus)
{
}

void InputSystem::OnTouch(const TouchData& Touch)
{
    Bus.Emit(OnTouchEvent{ Touch });
}

void InputSystem::OnMove(const TouchData& Touch)
{
    Bus.Emit(OnMoveEvent{ Touch });
}

void InputSystem::OnRelease(const TouchData& Touch)
{
    Bus.Emit(OnReleaseEvent{ Touch });
}
