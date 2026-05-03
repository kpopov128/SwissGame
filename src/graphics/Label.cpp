#include "Label.hpp"


void Label::SetText(const std::string& Text)
{
    this->Text = Text;
}

void Label::SetPosition(Point Position)
{
    this->Position = Position;
}

Point Label::GetPosition() const
{
    return Position;
}

Rect Label::GetBoundingBox() const
{
    return Rect(Position.X, Position.Y, 0, 0);
}

void Label::Draw(DrawList& DrawList) const
{
    //DrawList.DrawText(FontResource, Text, Position, 14.0f);
}











