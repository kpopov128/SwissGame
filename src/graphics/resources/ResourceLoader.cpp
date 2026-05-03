#include "ResourceLoader.hpp"

#include <stdexcept>

std::shared_ptr<Image> ResourceLoader::LoadImage(const std::string& Path)
{
    auto It = Images.find(Path);

    if (It != Images.end())
    {
        return It->second;
    }

    auto NewImage = std::make_shared<Image>();

    if (!NewImage->LoadFromFile(Path))
    {
        throw std::runtime_error("Failed to load image: " + Path);
    }

    Images[Path] = NewImage;

    return NewImage;
}

std::shared_ptr<Font> ResourceLoader::LoadFont(const std::string& Path)
{
    auto It = Fonts.find(Path);

    if (It != Fonts.end())
    {
        return It->second;
    }

    auto NewFont = std::make_shared<Font>();

    if (!NewFont->LoadFromFile(Path))
    {
        throw std::runtime_error("Failed to load font: " + Path);
    }

    Fonts[Path] = NewFont;

    return NewFont;
}











