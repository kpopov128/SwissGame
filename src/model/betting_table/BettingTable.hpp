#pragma once

#include <vector>
#include "model/betting_field/BettingField.hpp"

class BettingTable
{
public:
    BettingTable();

    void PlaceBet(int fieldId, int chipValue);
    int GetBetAmount(int fieldId) const;

    const BettingField& GetField(int fieldId) const;
    BettingField& GetField(int fieldId);

    void Clear();

private:
    bool IsValidFieldNumber(int fieldId) const;

private:
    std::vector<BettingField> Fields;
};