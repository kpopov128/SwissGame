#pragma once

class Window
{
public:
    virtual ~Window() = default;

    virtual void Clear() = 0;
    virtual void Display() = 0;
    virtual bool IsOpen() const = 0;
    virtual void Close() = 0;
};











