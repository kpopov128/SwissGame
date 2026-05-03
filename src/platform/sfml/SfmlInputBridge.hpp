#pragma once

#include "SfmlWindow.hpp"
#include "systems/InputSystem.hpp"

class SfmlInputBridge
{
public:
    SfmlInputBridge(SfmlWindow& Window, InputSystem& Input);

    void Update();

private:
    SfmlWindow& Window;
    InputSystem& Input;
};
