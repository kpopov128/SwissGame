#pragma once

class Color
{
public:
    Color() = default;

    Color(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha = 255)
        : Red(Red), Green(Green), Blue(Blue), Alpha(Alpha)
    {
    }

    unsigned char Red = 255;
    unsigned char Green = 255;
    unsigned char Blue = 255;
    unsigned char Alpha = 255;
};











