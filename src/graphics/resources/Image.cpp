#include "Image.hpp"

#include <fstream>

bool Image::LoadFromFile(const std::string& Path)
{
    this->Path = Path;
    std::ifstream File(Path.c_str());
    return File.good();
}

const std::string& Image::GetPath() const
{
    return Path;
}











