#pragma once

#include "DrawLayer.hpp"
#include "Point.hpp"
#include "Color.hpp"

#include "resources/ImageRss.hpp"
#include "resources/FontRss.hpp"

#include <array>
#include <memory>
#include <string>
#include <vector>


struct DrawSpriteCommand
{
    ImageRss Image;
    Point Position;
    Point BoxSize;
    bool HasCustomSize;
    DrawLayer Layer;
};

struct DrawTextCommand
{
    FontRss Font;
    std::string Text;
    Point Position;
};

struct DrawRectangleCommand
{
    Point Position;
    int Width = 0;
    int Height = 0;
    Color FillColor;
};

struct DrawCircleCommand
{
    Point Position;
    int Radius = 0;
    Color FillColor;
};

struct DrawCommand
{
    enum class Type
    {
        Sprite,
        Text,
        Rectangle,
        Circle
    };

    DrawCommand(const DrawSpriteCommand& Command)
        : CommandType(Type::Sprite), Sprite(Command)
    {
    }

    DrawCommand(const DrawTextCommand& Command)
        : CommandType(Type::Text), Text(Command)
    {
    }

    DrawCommand(const DrawRectangleCommand& Command)
        : CommandType(Type::Rectangle), Rectangle(Command)
    {
    }

    DrawCommand(const DrawCircleCommand& Command)
        : CommandType(Type::Circle), Circle(Command)
    {
    }

    Type CommandType;
    DrawSpriteCommand Sprite;
    DrawTextCommand Text;
    DrawRectangleCommand Rectangle;
    DrawCircleCommand Circle;
};

class DrawList
{
public:
    void Clear()
    {
        for (auto& Layer : Layers)
        {
            Layer.clear();
        }
    }

    void DrawSprite(ImageRss image, Point position, Point size, bool hasCustomSize, DrawLayer layer)
    {
        Push(layer, DrawSpriteCommand{image, position, size, hasCustomSize, layer});
    }

    void DrawText(FontRss Font, const std::string& Text, Point Position, DrawLayer Layer)
    {
        Push(Layer, DrawTextCommand{ Font, Text, Position });
    }


    void DrawRectangle(Point position, int width, int height, Color fillColor, DrawLayer layer = DrawLayer::UI)
    {
        Push(layer, DrawRectangleCommand{position, width, height, fillColor});
    }

    void DrawCircle(Point position, int radius, Color fillColor, DrawLayer layer = DrawLayer::UI)
    {
        Push(layer, DrawCircleCommand{position, radius, fillColor});
    }

    const std::array<
        std::vector<DrawCommand>,
        static_cast<size_t>(DrawLayer::Count)
    >& GetLayers() const
    {
        return Layers;
    }

private:
    void Push(DrawLayer Layer, DrawCommand Command)
    {
        Layers[static_cast<size_t>(Layer)].push_back(std::move(Command));
    }

private:
    std::array<
        std::vector<DrawCommand>,
        static_cast<size_t>(DrawLayer::Count)
    > Layers;
};










