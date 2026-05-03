#pragma once

#include "SfmlResourceManager.hpp"
#include "graphics/DrawList.hpp"

#include <SFML/Graphics.hpp>

class SfmlRenderer
{
public:
    SfmlRenderer(sf::RenderWindow& Window, SfmlResourceManager& Resources);

    void Render(const DrawList& DrawList);

private:
    void RenderCommand(const DrawSpriteCommand& Command);
    void RenderCommand(const DrawTextCommand& Command);
    void RenderCommand(const DrawRectangleCommand& Command);
    void RenderCommand(const DrawCircleCommand& Command);

private:
    sf::RenderWindow& Window;
    SfmlResourceManager& Resources;
};