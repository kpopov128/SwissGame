#pragma once

#include "model/betting_table/BettingTable.hpp"
#include "ui/betting_table/BettingTableView.hpp"

class GameState
{
public:
    BettingTable Table;
    BettingTableView TableView;

    int SelectedChip = 10;
};