#include "graphics/DrawList.hpp"
#include "ui/betting_field/BettingFieldView.hpp"

class BettingTableView
{
public:
    BettingTableView();

    void SetPosition(Point position);
    void SetFieldSize(float size);

    int HitTest(Point position) const;
    void SetFieldAmount(int fieldNumber, int amount);
    void Draw(DrawList& drawList) const;

private:
    void BuildFields();

private:
    Point Position = Point(660.0f, 465.0f);
    float FieldSize = 180.0f;
    int Columns = 12;
    int Rows = 3;

    std::vector<BettingFieldView> Fields;
};