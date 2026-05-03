#pragma once

class Rect
{
public:
    Rect() = default;

    Rect(int Left, int Top, int Width, int Height)
        : Left(Left), Top(Top), Width(Width), Height(Height)
    {
    }

    int Left = 0;
    int Top = 0;
    int Width = 0;
    int Height = 0;
};











