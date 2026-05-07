#include "BettingTableView.hpp"

namespace
{
    const int C = 4;

    Rect Cell(int x, int y, int w = 1, int h = 1)
    {
        return Rect{ x * C, y * C, w * C, h * C };
    }

    std::vector<int> Range(int from, int to)
    {
        std::vector<int> result;

        for (int i = from; i <= to; ++i)
        {
            result.push_back(i);
        }

        return result;
    }

    std::vector<int> RedNumbers()
    {
        return { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
    }

    std::vector<int> BlackNumbers()
    {
        return { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };
    }

    std::vector<int> EvenNumbers()
    {
        return { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36 };
    }

    std::vector<int> OddNumbers()
    {
        return { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35 };
    }

    int NumberRow(int number)
    {
        if (number % 3 == 0)
        {
            return 1;
        }

        if (number % 3 == 2)
        {
            return 2;
        }

        return 3;
    }

    int NumberColumn(int number)
    {
        return 1 + (number - 1) / 3;
    }

    Rect NumberRect(int number)
    {
        return Cell(NumberColumn(number), NumberRow(number));
    }

    int Numbers[3][12] =
    {
        { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 },
        { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 },
        { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 }
    };
}

BettingTableView::BettingTableView()
{
    BuildFields();
}

void BettingTableView::SetPosition(Point position)
{
    Position = position;
    BuildFields();
}

void BettingTableView::SetCellSize(int size)
{
    CellSize = size;
    BuildFields();
}

void BettingTableView::BuildFields()
{
    Fields.clear();

    AddStraightBets();
    AddOutsideBets();
    AddZeroBets();
    AddSplitBets();
    AddCornerBets();
    AddStreetBets();
    AddSixLineBets();
}

void BettingTableView::AddStraightBets()
{
    // Fields[0]  = straight 0
    // Fields[1]  = straight 1
    // ...
    // Fields[36] = straight 36

    AddDrawableField(0, Cell(0, 1, 1, 3), { 0 });

    for (int number = 1; number <= 36; ++number)
    {
        AddDrawableField(number, NumberRect(number), { number });
    }
}

void BettingTableView::AddOutsideBets()
{
    AddDrawableField(101, Cell(13, 3), { 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34 });
    AddDrawableField(102, Cell(13, 2), { 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35 });
    AddDrawableField(103, Cell(13, 1), { 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36 });

    AddDrawableField(104, Cell(1, 0, 6, 1), Range(1, 18));
    AddDrawableField(105, Cell(7, 0, 6, 1), Range(19, 36));

    AddDrawableField(106, Cell(1, 4, 4, 1), Range(1, 12));
    AddDrawableField(107, Cell(5, 4, 4, 1), Range(13, 24));
    AddDrawableField(108, Cell(9, 4, 4, 1), Range(25, 36));

    AddDrawableField(109, Cell(1, 5, 3, 1), EvenNumbers());
    AddDrawableField(110, Cell(4, 5, 3, 1), RedNumbers());
    AddDrawableField(111, Cell(7, 5, 3, 1), BlackNumbers());
    AddDrawableField(112, Cell(10, 5, 3, 1), OddNumbers());
}

void BettingTableView::AddZeroBets()
{
    AddInvisibleField(Rect{ 1 * C - 1, 1 * C + 1, 2, 2 }, { 0, 3 });
    AddInvisibleField(Rect{ 1 * C - 1, 2 * C + 1, 2, 2 }, { 0, 2 });
    AddInvisibleField(Rect{ 1 * C - 1, 3 * C + 1, 2, 2 }, { 0, 1 });

    AddInvisibleField(Rect{ 1 * C - 1, 2 * C - 1, 2, 2 }, { 0, 2, 3 });
    AddInvisibleField(Rect{ 1 * C - 1, 3 * C - 1, 2, 2 }, { 0, 1, 2 });
}

void BettingTableView::AddSplitBets()
{
    for (int col = 0; col < 12; ++col)
    {
        AddInvisibleField(Rect{ (1 + col) * C + 1, 2 * C - 1, 2, 2 }, { Numbers[0][col], Numbers[1][col] });
        AddInvisibleField(Rect{ (1 + col) * C + 1, 3 * C - 1, 2, 2 }, { Numbers[1][col], Numbers[2][col] });
    }

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 11; ++col)
        {
            AddInvisibleField(Rect{ (2 + col) * C - 1, (1 + row) * C + 1, 2, 2 }, { Numbers[row][col], Numbers[row][col + 1] });
        }
    }
}

void BettingTableView::AddCornerBets()
{
    for (int row = 0; row < 2; ++row)
    {
        for (int col = 0; col < 11; ++col)
        {
            AddInvisibleField(Rect{ (2 + col) * C - 1, (2 + row) * C - 1, 2, 2 },
                { Numbers[row][col], Numbers[row][col + 1], Numbers[row + 1][col], Numbers[row + 1][col + 1] });
        }
    }
}

void BettingTableView::AddStreetBets()
{
    for (int col = 0; col < 12; ++col)
    {
        AddInvisibleField(Rect{ (1 + col) * C, 4 * C - 1, C, 2 }, { Numbers[0][col], Numbers[1][col], Numbers[2][col] });
    }
}

void BettingTableView::AddSixLineBets()
{
    for (int col = 0; col < 11; ++col)
    {
        AddInvisibleField(Rect{ (2 + col) * C - 1, 4 * C - 1, 2, 2 },
            { Numbers[0][col], Numbers[1][col], Numbers[2][col], Numbers[0][col + 1], Numbers[1][col + 1], Numbers[2][col + 1] });
    }
}

int BettingTableView::AddDrawableField(int imageId, Rect rect, std::vector<int> highlights)
{
    const int fieldId = static_cast<int>(Fields.size());

    highlights.push_back(fieldId);

    const int chipSize = CellSize * 70 / 100;

    Fields.emplace_back(fieldId, imageId, ToPosition(rect), ToSize(rect), chipSize, highlights, true);

    return fieldId;
}

int BettingTableView::AddInvisibleField(Rect rect, std::vector<int> highlights)
{
    const int fieldId = static_cast<int>(Fields.size());
    const int chipSize = CellSize * 55 / 100;

    Fields.emplace_back(fieldId, 0, ToPosition(rect), ToSize(rect), chipSize, highlights, false);

    return fieldId;
}

Point BettingTableView::ToPosition(Rect rect) const
{
    const int unitSize = CellSize / UnitsPerCell;

    return Point(Position.X + rect.X * unitSize, Position.Y + rect.Y * unitSize);
}

Point BettingTableView::ToSize(Rect rect) const
{
    const int unitSize = CellSize / UnitsPerCell;

    return Point(rect.W * unitSize, rect.H * unitSize);
}

int BettingTableView::HitTest(Point position) const
{
    for (auto it = Fields.rbegin(); it != Fields.rend(); ++it)
    {
        if (it->Contains(position))
        {
            return it->GetFieldId();
        }
    }

    return -1;
}

void BettingTableView::SetFieldAmount(int fieldId, int amount)
{
    if (fieldId < 0 || fieldId >= static_cast<int>(Fields.size()))
    {
        return;
    }

    Fields[fieldId].SetAmount(amount);
}

void BettingTableView::ClearHighlights()
{
    for (auto& field : Fields)
    {
        field.SetHighlighted(false);
    }
}

void BettingTableView::HighlightField(int fieldId)
{
    ClearHighlights();

    if (fieldId < 0 || fieldId >= static_cast<int>(Fields.size()))
    {
        return;
    }

    const auto& highlights = Fields[fieldId].GetHighlightFieldIds();

    for (int highlightId : highlights)
    {
        if (highlightId < 0 || highlightId >= static_cast<int>(Fields.size()))
        {
            continue;
        }

        if (Fields[highlightId].IsDrawableField())
        {
            Fields[highlightId].SetHighlighted(true);
        }
    }
}

void BettingTableView::Draw(DrawList& drawList) const
{
    for (const auto& field : Fields)
    {
        field.Draw(drawList);
    }
}