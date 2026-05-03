#include "SfmlWindow.hpp"

SfmlWindow::SfmlWindow(unsigned int Width, unsigned int Height, const char* Title)
    : NativeWindow(sf::VideoMode(Width, Height), Title)
{
}

void SfmlWindow::Clear()
{
    NativeWindow.clear(sf::Color::Black);
}

void SfmlWindow::Display()
{
    NativeWindow.display();
}

bool SfmlWindow::IsOpen() const
{
    return NativeWindow.isOpen();
}

void SfmlWindow::Close()
{
    NativeWindow.close();
}

sf::RenderWindow& SfmlWindow::GetNative()
{
    return NativeWindow;
}
