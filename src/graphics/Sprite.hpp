#pragma once

#include "DrawList.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "resources/ImageRss.hpp"
#include "DrawLayer.hpp"

class Sprite
{
public:
    Sprite() = default;

    template<typename TImageEnum>
    Sprite(TImageEnum image, Point position, DrawLayer layer)
        : Image(ImageRss(image)), Position(position), Layer(layer) { }

    template<typename TImageEnum>
    void SetImage(TImageEnum image) { Image = ImageResource(image); }

    void SetPosition(Point position) { Position = position; }
    void SetLayer(DrawLayer layer) { Layer = layer;}

    void SetBoxSize(Point size);

    void Draw(DrawList& drawList) const;

private:
    ImageRss Image;
    Point Position;
    DrawLayer Layer = DrawLayer::UI;

    Point BoxSize = { 0, 0 };
    bool HasCustomSize = false;
};











