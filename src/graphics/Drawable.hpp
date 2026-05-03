#pragma once

#include "DrawList.hpp"
#include "Point.hpp"
#include "Rect.hpp"

class Drawable
{
public:
    virtual ~Drawable() = default;

    virtual void SetPosition(Point Position) = 0;
    virtual Point GetPosition() const = 0;
    virtual Rect GetBoundingBox() const = 0;

    virtual void Draw(DrawList& DrawList) const = 0;
};











