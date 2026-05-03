#pragma once

#include "Image.hpp"
#include "Font.hpp"

#include <memory>
#include <string>
#include <unordered_map>

class ResourceLoader
{
public:
    std::shared_ptr<Image> LoadImage(const std::string& Path);
    std::shared_ptr<Font> LoadFont(const std::string& Path);

private:
    std::unordered_map<std::string, std::shared_ptr<Image>> Images;
    std::unordered_map<std::string, std::shared_ptr<Font>> Fonts;
};











