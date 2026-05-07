#pragma once

#include <unordered_map>

class BettingTable
{
public:
    BettingTable();

    void PlaceBet(int fieldId, int chipValue);
    int GetBetAmount(int fieldId) const;

    void Clear();

private:
    std::unordered_map<int, int> Bets;
};