#pragma once

#include "BettingTable.hpp"

class GameState
{
public:
    BettingTable Table;
    int SelectedChip = 10;
};