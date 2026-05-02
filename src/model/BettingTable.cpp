#include "BettingTable.hpp"

void BettingTable::Initialize()
{
    Fields.clear();
    Fields.reserve(36);

    for (int i = 0; i < 36; i++)
    {
        BettingField Field;
        Field.Id = i;
        Fields.push_back(Field);
    }
}

void BettingTable::SetPosition(sf::Vector2f Position)
{
    StartPosition = Position;

    for (int i = 0; i < Fields.size(); i++)
    {
        float x = StartPosition.x + (i % 12) * Spacing;
        float y = StartPosition.y + (i / 12) * Spacing;

        Fields[i].SetPosition(sf::Vector2f(x, y));
    }
}

bool BettingTable::TryPlaceBet(sf::Vector2f Position, int ChipValue)
{
    for (size_t i = 0; i < Fields.size(); i++)
    {
        if (Fields[i].Contains(Position))
        {
            Fields[i].AddChip(ChipValue);
            return true;
        }
    }

    return false;
}

void BettingTable::Draw(sf::RenderWindow& Window)
{
    for (auto& Field : Fields)
        Field.Draw(Window);
}

BettingField& BettingTable::GetField(int Index)
{
    return Fields[Index];
}