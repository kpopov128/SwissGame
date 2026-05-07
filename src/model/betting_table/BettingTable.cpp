#include "BettingTable.hpp"

BettingTable::BettingTable()
{
}

void BettingTable::PlaceBet(int fieldId, int chipValue)
{
    if (fieldId < 0 || chipValue <= 0)
    {
        return;
    }

    Bets[fieldId] += chipValue;
}

int BettingTable::GetBetAmount(int fieldId) const
{
    const auto it = Bets.find(fieldId);

    if (it == Bets.end())
    {
        return 0;
    }

    return it->second;
}

void BettingTable::Clear()
{
    Bets.clear();
}