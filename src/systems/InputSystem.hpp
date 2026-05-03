#pragma once

#include "core/EventBus.hpp"
#include "input/TouchData.hpp"

class InputSystem
{
public:
    explicit InputSystem(EventBus& Bus);

    void OnTouch(const TouchData& Touch);
    void OnMove(const TouchData& Touch);
    void OnRelease(const TouchData& Touch);

private:
    EventBus& Bus;
};
