#include "ChipView.hpp"

ChipView::ChipView()
{
}

void ChipView::SetAmount(int amount)
{
    if (Amount == amount)
    {
        return;
    }

    Amount = amount;

    if (Amount <= 0)
    {
        Background.SetVisible(false);
        return;
    }

    Background.SetVisible(true);
    Background.SetImage(ResolveImage(Amount));
}

void ChipView::SetPosition(Point position)
{
    Background.SetPosition(position);
}

void ChipView::SetSize(Point size)
{
    Background.SetBoxSize(size);
}

int ChipView::GetAmount() const
{
    return Amount;
}

void ChipView::Draw(DrawList& drawList) const
{
    if (Amount <= 0)
    {
        return;
    }

    Background.Draw(drawList);
}

EChipImage ChipView::ResolveImage(int amount) const
{
    if      (amount <= 0) return EChipImage::eUnknown;
    else if (amount < 11) return EChipImage::eRed;
    else if (amount < 26) return EChipImage::eGreen;
    else if (amount < 51) return EChipImage::eBlue;
    else if (amount < 100) return EChipImage::eBlack;

    return EChipImage::eWhite;
}