#pragma once

#include "model/betting_table/BettingTable.hpp"

class GameState
{
public:
    BettingTable Table;
    int SelectedChip = 10;
};