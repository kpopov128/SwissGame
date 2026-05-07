#include "core/EventBus.hpp"
#include "graphics/DrawList.hpp"
#include "graphics/Point.hpp"
#include "model/game_state/GameState.hpp"

#include "platform/sfml/SfmlInputBridge.hpp"
#include "platform/sfml/SfmlRenderer.hpp"
#include "platform/sfml/SfmlResourceManager.hpp"
#include "platform/sfml/SfmlWindow.hpp"

#include "systems/BettingSystem.hpp"
#include "systems/InputSystem.hpp"
#include "systems/RenderSystem.hpp"

int main()
{
    SfmlWindow Window(1920, 1080, "casino");
    SfmlResourceManager Resources;
    SfmlRenderer RendererBackend(Window.GetNative(), Resources);
    DrawList drawList;

    EventBus Bus;
    GameState State;
    State.TableView.SetPosition(Point(230, 265));
   // State.TableView.SetFieldSize(120);

    InputSystem Input(Bus);
    SfmlInputBridge InputBridge(Window, Input);
    BettingSystem Betting(Bus, State);
    RenderSystem Renderer(State);

    while (Window.IsOpen())
    {
        InputBridge.Update();

        Renderer.Render(drawList);

        Window.Clear();
        RendererBackend.Render(drawList);
        Window.Display();
    }

    return 0;
}
