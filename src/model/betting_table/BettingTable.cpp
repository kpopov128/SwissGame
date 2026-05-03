#include "BettingTable.hpp"

namespace
{
    constexpr float FieldSize = 50.0f;
    constexpr int Columns = 12;
    constexpr int Rows = 3;
}

BettingTable::BettingTable()
    : Position(660.0f, 465.0f)
{
    BuildFields();
}

void BettingTable::BuildFields()
{
    Fields.clear();
    Fields.reserve(Columns * Rows);

    for (int i = 0; i < Columns * Rows; ++i)
    {
        int id = i + 1;
        int row = i / Columns;
        int column = i % Columns;

        Point fieldPosition(Position.X + column * FieldSize,  Position.Y + row * FieldSize);
        Fields.emplace_back(id, fieldPosition);
    }
}

void BettingTable::SetPosition(Point position)
{
    Position = position;
    BuildFields();
}

Point BettingTable::GetPosition() const
{
    return Position;
}

void BettingTable::Draw(DrawList& drawList) const
{
    for (const auto& field : Fields)
    {
        field.Draw(drawList);
    }
}

bool BettingTable::TryPlaceBet(Point position, int value)
{
    for (auto& field : Fields)
    {
        if (field.Contains(position))
        {
            field.SetBet(value);
            return true;
        }
    }

    return false;
}

void BettingTable::SetActiveFieldAt(Point position)
{
    for (auto& field : Fields)
    {
        field.SetActive(field.Contains(position));
    }
}