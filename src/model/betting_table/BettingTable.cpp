#include "BettingTable.hpp"

BettingTable::BettingTable()
{
    for (int i = 1; i <= 36; ++i)
    {
        Fields.push_back(BettingField(i));
    }
}

void BettingTable::PlaceBet(int fieldId, int chipValue)
{
    if (!IsValidFieldNumber(fieldId))
        return;

    Fields[fieldId - 1].AddChip(chipValue);
}

int BettingTable::GetBetAmount(int fieldId) const
{
    if (!IsValidFieldNumber(fieldId))
        return 0;

    return Fields[fieldId - 1].GetAmount();
}

const BettingField& BettingTable::GetField(int fieldId) const
{
    return Fields[fieldId - 1];
}

BettingField& BettingTable::GetField(int fieldId)
{
    return Fields[fieldId - 1];
}

void BettingTable::Clear()
{
    for (auto& field : Fields)
    {
        field.Clear();
    }
}

bool BettingTable::IsValidFieldNumber(int fieldId) const
{
    return fieldId >= 1 && fieldId <= 36;
}