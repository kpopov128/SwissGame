#include "SfmlResourceManager.hpp"

#include <SFML/System.hpp>

#include <stdexcept>
#include <utility>
#include <iostream>

const sf::Texture& SfmlResourceManager::GetTexture(const ImageRss& Resource)
{
    const std::string Path = Resolver.ResolveImage(Resource);

    auto It = Textures.find(Path);
    if (It != Textures.end())
    {
        return It->second;
    }

    sf::Texture Texture;
    if (!Texture.loadFromFile(Path))
    {
        throw std::runtime_error("Failed to load texture: " + Path);
    }

    auto Result = Textures.emplace(Path, std::move(Texture));
    return Result.first->second;
}

const sf::Font& SfmlResourceManager::GetFont(const FontRss& Resource)
{
    const std::string Path = Resolver.ResolveFont(Resource);

    auto It = Fonts.find(Path);
    if (It != Fonts.end())
    {
        return It->second;
    }

    sf::Font Font;
    if (!Font.loadFromFile(Path))
    {
        throw std::runtime_error("Failed to load font: " + Path);
    }

    auto Result = Fonts.emplace(Path, std::move(Font));
    return Result.first->second;
}