#include "SfmlRenderer.hpp"

SfmlRenderer::SfmlRenderer(sf::RenderWindow& Window, SfmlResourceManager& Resources)
    : Window(Window), Resources(Resources)
{
}

void SfmlRenderer::Render(const DrawList& DrawList)
{
    for (const auto& Layer : DrawList.GetLayers())
    {
        for (const auto& Command : Layer)
        {
            switch (Command.CommandType)
            {
            case DrawCommand::Type::Sprite:
                RenderCommand(Command.Sprite);
                break;
            case DrawCommand::Type::Text:
                RenderCommand(Command.Text);
                break;
            case DrawCommand::Type::Rectangle:
                RenderCommand(Command.Rectangle);
                break;
            case DrawCommand::Type::Circle:
                RenderCommand(Command.Circle);
                break;
            }
        }
    }
}

void SfmlRenderer::RenderCommand(const DrawSpriteCommand& command)
{
    const sf::Texture& texture = Resources.GetTexture(command.Image);

    sf::Sprite sprite(texture);
    sprite.setPosition({ static_cast<float>(command.Position.X), static_cast<float>(command.Position.Y) });

    if (command.HasCustomSize)
    {
        auto textureSize = texture.getSize();

        if (textureSize.x > 0 && textureSize.y > 0)
        {
            float scaleX = command.BoxSize.X / static_cast<float>(textureSize.x);
            float scaleY = command.BoxSize.Y / static_cast<float>(textureSize.y);

            sprite.setScale({ scaleX, scaleY });
        }
    }

    Window.draw(sprite);
}

void SfmlRenderer::RenderCommand(const DrawTextCommand& Command)
{
    const sf::Font& Font = Resources.GetFont(Command.Font);

    sf::Text Text;
    Text.setFont(Font);
    Text.setString(Command.Text);
    Text.setPosition({ static_cast<float>(Command.Position.X), static_cast<float>(Command.Position.Y) });

    Window.draw(Text);
}

void SfmlRenderer::RenderCommand(const DrawRectangleCommand& Command)
{
    sf::RectangleShape Rectangle;
    Rectangle.setPosition({ static_cast<float>(Command.Position.X), static_cast<float>(Command.Position.Y) });
    Rectangle.setSize({ static_cast<float>(Command.Width), static_cast<float>(Command.Height) });
    Rectangle.setFillColor(sf::Color(
        Command.FillColor.Red,
        Command.FillColor.Green,
        Command.FillColor.Blue,
        Command.FillColor.Alpha
    ));

    Window.draw(Rectangle);
}

void SfmlRenderer::RenderCommand(const DrawCircleCommand& Command)
{
    sf::CircleShape Circle;
    Circle.setPosition({ static_cast<float>(Command.Position.X), static_cast<float>(Command.Position.Y) });
    Circle.setRadius(Command.Radius);
    Circle.setFillColor(sf::Color(
        Command.FillColor.Red,
        Command.FillColor.Green,
        Command.FillColor.Blue,
        Command.FillColor.Alpha
    ));

    Window.draw(Circle);
}