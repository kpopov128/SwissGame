#include "InputSystem.hpp"

InputSystem::InputSystem(EventBus& Bus, sf::RenderWindow& Window)
    : Bus(Bus), Window(Window)
{}

void InputSystem::Update()
{
    while (const std::optional<sf::Event> Event = Window.pollEvent())
    {
        if (Event->is<sf::Event::Closed>())
            Window.close();

        if (const auto* MouseDown = Event->getIf<sf::Event::MouseButtonPressed>())
        {
            Bus.Emit(MouseDownEvent{
                sf::Vector2f((float)MouseDown->position.x,
                             (float)MouseDown->position.y)
                });
        }

        if (const auto* MouseUp = Event->getIf<sf::Event::MouseButtonReleased>())
        {
            Bus.Emit(MouseUpEvent{
                sf::Vector2f((float)MouseUp->position.x,
                             (float)MouseUp->position.y)
                });
        }
    }
}