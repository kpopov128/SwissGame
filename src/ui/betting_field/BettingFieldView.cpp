#include "BettingFieldView.hpp"
#include "BettingFieldResources.hpp"
#include "graphics/Color.hpp"
#include "graphics/DrawLayer.hpp"

BettingFieldView::BettingFieldView(
    int fieldId,
    int imageId,
    Point position,
    Point size,
    int chipSize,
    std::vector<int> highlightFieldIds,
    bool drawable
)
    : FieldId(fieldId),
    ImageId(imageId),
    ChipSize(chipSize),
    Position(position),
    Size(size),
    Drawable(drawable),
    HighlightFieldIds(highlightFieldIds)
{
    if (Drawable)
    {
        Background.SetPosition(position);
        Background.SetImage(FieldBackgroundImage{ imageId });
        Background.SetBoxSize(size);
        Background.SetLayer(DrawLayer::Tapi);

        ActiveBackground.SetPosition(position);
        ActiveBackground.SetImage(FieldBackgroundImage{ GetActiveImageId(imageId) });
        ActiveBackground.SetBoxSize(size);
        ActiveBackground.SetLayer(DrawLayer::Tapi);
    }
}

int BettingFieldView::GetFieldId() const
{
    return FieldId;
}

int BettingFieldView::GetImageId() const
{
    return ImageId;
}

const std::vector<int>& BettingFieldView::GetHighlightFieldIds() const
{
    return HighlightFieldIds;
}

bool BettingFieldView::Contains(Point point) const
{
    return
        point.X >= Position.X &&
        point.X <= Position.X + Size.X &&
        point.Y >= Position.Y &&
        point.Y <= Position.Y + Size.Y;
}

bool BettingFieldView::IsDrawableField() const
{
    return Drawable;
}

void BettingFieldView::SetAmount(int amount)
{
    Chip.SetAmount(amount);
    Chip.SetPosition(GetChipPosition());
    Chip.SetSize(Point(ChipSize, ChipSize));
}

void BettingFieldView::SetHighlighted(bool highlighted)
{
    Highlighted = highlighted;
}

void BettingFieldView::Draw(DrawList& drawList) const
{
    if (Drawable)
    {
        if (Highlighted)
        {
            ActiveBackground.Draw(drawList);

            drawList.DrawRectangle(
                Position,
                Size.X,
                Size.Y,
                Color(255, 255, 255, 100),
                DrawLayer::Bets
            );
        }
        else
        {
            Background.Draw(drawList);
        }
    }

    Chip.Draw(drawList);
}

int BettingFieldView::GetActiveImageId(int imageId) const
{
    if (imageId == 0)
    {
        return -1000;
    }

    return -imageId;
}

Point BettingFieldView::GetChipPosition() const
{
    return Point(
        Position.X + (Size.X - ChipSize) / 2,
        Position.Y + (Size.Y - ChipSize) / 2
    );
}