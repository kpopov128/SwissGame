#include "SfmlResourceResolver.hpp"

#include "model/GameResources.hpp"

#include <stdexcept>

std::string SfmlResourceResolver::ResolveImage(const ImageRss& resource) const
{
    if (resource.Type == typeid(EChipImage))
    {
        const auto& image = resource.As<EChipImage>();

        switch (image)
        {
        case EChipImage::eRed:
            return "resources/chips/chip_red.png";
            /*
        case ChipImage::Blue:
            return "resources/images/chip_blue.png";
        case ChipImage::Green:
            return "resources/images/chip_green.png";
       */
        }
        throw std::runtime_error("Unknown EChipImage value");
    }
    else if (resource.Type == typeid(FieldBackgroundImage))
    {
        const auto& image = resource.As<FieldBackgroundImage>();

        return "resources/fields/" +
            std::to_string(image.Id) +
            ".png";
    }
    else if (resource.Type == typeid(EBettingTableImage))
    {
      //  switch (static_cast<EBettingTableImage>(Resource.Value))
      /*  {
        case BettingTableImage::Background:
            return "resources/images/betting_table.png";
        case BettingTableImage::RedField:
            return "resources/images/bet_field_red.png";
        case BettingTableImage::BlackField:
            return "resources/images/bet_field_black.png";
        case BettingTableImage::GreenField:
            return "resources/images/bet_field_green.png";
       
        } */
    }

    throw std::runtime_error("Unknown image resource");
}

std::string SfmlResourceResolver::ResolveFont(const FontRss& Resource) const
{
    return "";
    /*
    if (Resource.Type == typeid(ChipFont))
    {
        switch (static_cast<ChipFont>(Resource.Value))
        {
        case ChipFont::Value:
            return "resources/fonts/chip_value.ttf";
        }
    }

    if (Resource.Type == typeid(BettingTableFont))
    {
        switch (static_cast<BettingTableFont>(Resource.Value))
        {
        case BettingTableFont::Number:
            return "resources/fonts/main.ttf";
        }
    }

    throw std::runtime_error("Unknown font resource");
    */
}