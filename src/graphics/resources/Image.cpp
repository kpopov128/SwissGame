#include "Image.hpp"

#include <filesystem>

bool Image::LoadFromFile(const std::string& Path)
{
    this->Path = Path;
    return std::filesystem::exists(Path);
}

const std::string& Image::GetPath() const
{
    return Path;
}











