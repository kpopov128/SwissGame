#include "Font.hpp"

#include <fstream>

bool Font::LoadFromFile(const std::string& Path)
{
    this->Path = Path;
    std::ifstream File(Path.c_str());
    return File.good();
}

const std::string& Font::GetPath() const
{
    return Path;
}











