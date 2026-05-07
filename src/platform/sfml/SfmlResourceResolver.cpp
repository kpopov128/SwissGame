#include "SfmlResourceResolver.hpp"

#include "ui/GameResources.hpp"

#include <cstdlib>
#include <stdexcept>
#include <string>

std::string SfmlResourceResolver::ResolveImage(const ImageRss& resource) const
{
    if (resource.Type == typeid(EChipImage))
    {
        const auto& image = resource.As<EChipImage>();

        switch (image)
        {
        case EChipImage::eRed:
            return "resources/chips/chip_red.png";

        case EChipImage::eGreen:
            return "resources/chips/chip_green.png";

        case EChipImage::eBlue:
            return "resources/chips/chip_blue.png";

        case EChipImage::eBlack:
            return "resources/chips/chip_black.png";

        case EChipImage::eWhite:
            return "resources/chips/chip_white.png";
        }

        throw std::runtime_error("Unknown EChipImage value");
    }

    if (resource.Type == typeid(FieldBackgroundImage))
    {
        const auto& image = resource.As<FieldBackgroundImage>();
        return ResolveFieldImage(image.Id);
    }

    throw std::runtime_error("Unknown image resource");
}

std::string SfmlResourceResolver::ResolveFieldImage(int id) const
{
    bool active = id < 0;
    int baseId = std::abs(id);

    if (id == -1000)
    {
        active = true;
        baseId = 0;
    }

    const std::string suffix = active ? "_active.png" : ".png";
    const std::string basePath = "resources/fields/";

    if (baseId == 0)
    {
        return basePath + "zero" + suffix;
    }

    if (baseId == 37)
    {
        return basePath + "double_zero" + suffix;
    }

    if (baseId >= 1 && baseId <= 36)
    {
        return basePath + "num_" + std::to_string(baseId) + suffix;
    }

    switch (baseId)
    {
    case 101: return basePath + "column_1st" + suffix;
    case 102: return basePath + "column_2nd" + suffix;
    case 103: return basePath + "column_3rd" + suffix;
    case 104: return basePath + "low_1_18" + suffix;
    case 105: return basePath + "high_19_36" + suffix;
    case 106: return basePath + "dozen_1_12" + suffix;
    case 107: return basePath + "dozen_13_24" + suffix;
    case 108: return basePath + "dozen_25_36" + suffix;
    case 109: return basePath + "even" + suffix;
    case 110: return basePath + "red" + suffix;
    case 111: return basePath + "black" + suffix;
    case 112: return basePath + "odd" + suffix;
    }

    throw std::runtime_error("Unknown FieldBackgroundImage id: " + std::to_string(id));
}

std::string SfmlResourceResolver::ResolveFont(const FontRss& resource) const
{
    return "";
}