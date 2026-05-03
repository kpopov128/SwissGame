#pragma once

#include "graphics/resources/ImageRss.hpp"
#include "graphics/resources/FontRss.hpp"

#include <string>

class SfmlResourceResolver
{
public:
    std::string ResolveImage(const ImageRss& resource) const;
    std::string ResolveFont(const FontRss& resource) const;
};