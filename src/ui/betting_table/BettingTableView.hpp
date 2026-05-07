#pragma once

#include <vector>

#include "graphics/DrawList.hpp"
#include "graphics/Point.hpp"
#include "graphics/Rect.hpp"
#include "ui/betting_field/BettingFieldView.hpp"


class BettingTableView
{
public:
    BettingTableView();

    void SetPosition(Point position);
    void SetCellSize(int size);

    int HitTest(Point position) const;

    void SetFieldAmount(int fieldId, int amount);

    void ClearHighlights();
    void HighlightField(int fieldId);

    void Draw(DrawList& drawList) const;

private:
    void BuildFields();

    int AddDrawableField(int imageId, Rect rect, std::vector<int> highlights);
    int AddInvisibleField(Rect rect, std::vector<int> highlights);

    void AddStraightBets();
    void AddOutsideBets();
    void AddZeroBets();
    void AddSplitBets();
    void AddCornerBets();
    void AddStreetBets();
    void AddSixLineBets();

    Point ToPosition(Rect rect) const;
    Point ToSize(Rect rect) const;

private:
    Point Position = Point(120, 120);

    int CellSize = 90;
    int UnitsPerCell = 4;

    std::vector<BettingFieldView> Fields;
};