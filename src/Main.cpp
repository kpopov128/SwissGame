#include <SFML/Graphics.hpp>

#include "core/EventBus.hpp"
#include "model/GameState.hpp"
#include "model/BettingTable.hpp"

#include "systems/InputSystem.hpp"
#include "systems/BettingSystem.hpp"
#include "systems/RenderSystem.hpp"

int main()
{
    sf::RenderWindow Window(sf::VideoMode(sf::Vector2u(800, 600)), "casino");

    EventBus Bus;
    GameState State;
    State.Table.Initialize();
    State.Table.SetPosition(sf::Vector2f(100.f, 100.f));

    sf::Vector2u windowSize = Window.getSize();

    Window.setView(Window.getDefaultView());

    InputSystem Input(Bus, Window);
    BettingSystem Betting(Bus, State);
    RenderSystem Renderer(Window, State);

    while (Window.isOpen())
    {
        Input.Update();

        Window.clear(sf::Color::Black);
        Renderer.Draw();
        Window.display();
    }
}