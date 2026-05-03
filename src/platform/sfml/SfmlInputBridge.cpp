#include "SfmlInputBridge.hpp"


SfmlInputBridge::SfmlInputBridge(SfmlWindow& Window, InputSystem& Input)
    : Window(Window), Input(Input)
{
}

void SfmlInputBridge::Update()
{
    auto& NativeWindow = Window.GetNative();

    sf::Event Event;
    while (NativeWindow.pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed)
        {
            Window.Close();
            continue;
        }

        if (Event.type == sf::Event::MouseButtonPressed)
        {
            Input.OnTouch(TouchData{ 0, Point(Event.mouseButton.x, Event.mouseButton.y) });
        }

        if (Event.type == sf::Event::MouseMoved)
        {
            Input.OnMove(TouchData{ 0, Point(Event.mouseMove.x, Event.mouseMove.y) });
        }

        if (Event.type == sf::Event::MouseButtonReleased)
        {
            Input.OnRelease(TouchData{ 0, Point(Event.mouseButton.x, Event.mouseButton.y) });
        }
    }
}
