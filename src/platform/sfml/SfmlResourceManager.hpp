#pragma once

#include "SfmlResourceResolver.hpp"
#include "graphics/resources/ImageRss.hpp"
#include "graphics/resources/FontRss.hpp"

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

class SfmlResourceManager
{
public:
    const sf::Texture& GetTexture(const ImageRss& Resource);
    const sf::Font& GetFont(const FontRss& Resource);

private:
    SfmlResourceResolver Resolver;

    std::unordered_map<std::string, sf::Texture> Textures;
    std::unordered_map<std::string, sf::Font> Fonts;
};