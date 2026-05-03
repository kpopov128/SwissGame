#pragma once

#include "DrawLayer.hpp"
#include "Point.hpp"
#include "Color.hpp"

#include "resources/ImageRss.hpp"
#include "resources/FontRss.hpp"

#include <array>
#include <memory>
#include <string>
#include <variant>
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

using DrawCommand = std::variant<
    DrawSpriteCommand,
    DrawTextCommand,
    DrawRectangleCommand,
    DrawCircleCommand
>;

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

    const auto& GetLayers() const
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










