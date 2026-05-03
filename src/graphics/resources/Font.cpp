#include "Font.hpp"

#include <filesystem>

bool Font::LoadFromFile(const std::string& Path)
{
    this->Path = Path;
    return std::filesystem::exists(Path);
}

const std::string& Font::GetPath() const
{
    return Path;
}











