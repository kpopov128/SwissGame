#pragma once

#include "graphics/Window.hpp"

#include <SFML/Graphics.hpp>

class SfmlWindow : public Window
{
public:
    SfmlWindow(unsigned int Width, unsigned int Height, const char* Title);

    void Clear() override;
    void Display() override;
    bool IsOpen() const override;
    void Close() override;

    sf::RenderWindow& GetNative();

private:
    sf::RenderWindow NativeWindow;
};
