#pragma once

class Rect
{
public:
    Rect() = default;

    Rect(int x, int y, int w, int h)
        : X(x), Y(y), W(w), H(h)
    {
    }

    int X = 0;
    int Y = 0;
    int W = 0;
    int H = 0;
};











