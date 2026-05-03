#pragma once

#include "graphics/DrawList.hpp"
#include "graphics/Point.hpp"
#include "model/betting_field/BettingField.hpp"

#include <vector>

class BettingTable
{
public:
    BettingTable();

    void SetPosition(Point position);
    Point GetPosition() const;

    void Draw(DrawList& drawList) const;

    bool TryPlaceBet(Point position, int value);
    void SetActiveFieldAt(Point position);

private:
    void BuildFields();

private:
    Point Position;

    std::vector<BettingField> Fields;
};