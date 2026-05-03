#include "SfmlInputBridge.hpp"

#include <optional>

SfmlInputBridge::SfmlInputBridge(SfmlWindow& Window, InputSystem& Input)
    : Window(Window), Input(Input)
{
}

void SfmlInputBridge::Update()
{
    auto& NativeWindow = Window.GetNative();

    while (const std::optional Event = NativeWindow.pollEvent())
    {
        if (Event->is<sf::Event::Closed>())
        {
            Window.Close();
            continue;
        }

        if (const auto* MouseDown = Event->getIf<sf::Event::MouseButtonPressed>())
        {
            Input.OnTouch(TouchData{ 0, Point(static_cast<float>(MouseDown->position.x), static_cast<float>(MouseDown->position.y)) });
        }

        if (const auto* MouseMove = Event->getIf<sf::Event::MouseMoved>())
        {
            Input.OnMove(TouchData{ 0, Point(static_cast<float>(MouseMove->position.x), static_cast<float>(MouseMove->position.y)) });
        }

        if (const auto* MouseUp = Event->getIf<sf::Event::MouseButtonReleased>())
        {
            Input.OnRelease(TouchData{ 0, Point(static_cast<float>(MouseUp->position.x), static_cast<float>(MouseUp->position.y)) });
        }
    }
}
