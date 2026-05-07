#pragma once

#include "graphics/resources/FontRss.hpp"
#include "graphics/resources/ImageRss.hpp"

#include <string>

class SfmlResourceResolver
{
public:
    std::string ResolveImage(const ImageRss& resource) const;
    std::string ResolveFont(const FontRss& resource) const;

private:
    std::string ResolveFieldImage(int id) const;
};