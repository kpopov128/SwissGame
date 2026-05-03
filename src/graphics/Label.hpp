#pragma once

#include "Drawable.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "resources/Font.hpp"

#pragma once

#include "DrawList.hpp"
#include "Point.hpp"
#include "Rect.hpp"
#include "resources/FontRss.hpp"

#include <string>

class Label
{
public:
    template <typename TFontEnum>
    void SetFont(TFontEnum NewFont)
    {
        Font = FontResource(NewFont);
    }

    void SetText(const std::string& Text);
    void SetPosition(Point Position);

    Point GetPosition() const;
    Rect GetBoundingBox() const;

    void Draw(DrawList& DrawList) const;

private:
    FontRss Font;
    std::string Text;
    Point Position;
};











