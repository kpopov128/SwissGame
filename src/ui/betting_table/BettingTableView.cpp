#include "BettingTableView.hpp"

BettingTableView::BettingTableView()
{
    BuildFields();
}

void BettingTableView::SetPosition(Point position)
{
    Position = position;
    BuildFields();
}

void BettingTableView::SetFieldSize(float size)
{
    FieldSize = size;
    BuildFields();
}

void BettingTableView::BuildFields()
{
    Fields.clear();

    int fieldNumber = 1;

    for (int row = 0; row < Rows; ++row)
    {
        for (int col = 0; col < Columns; ++col)
        {
            Point pos(
                Position.X + col * FieldSize,
                Position.Y + row * FieldSize
            );

            Fields.emplace_back(fieldNumber, pos, FieldSize);
            fieldNumber++;
        }
    }
}

int BettingTableView::HitTest(Point position) const
{
    for (const auto& field : Fields)
    {
        if (field.Contains(position))
        {
            return field.GetFieldId();
        }
    }

    return -1;
}

void BettingTableView::SetFieldAmount(int fieldId, int amount)
{
    if (fieldId < 1 || fieldId > static_cast<int>(Fields.size()))
    {
        return;
    }

    Fields[fieldId - 1].SetAmount(amount);
}

void BettingTableView::Draw(DrawList& drawList) const
{
    for (const auto& field : Fields)
    {
        field.Draw(drawList);
    }
}