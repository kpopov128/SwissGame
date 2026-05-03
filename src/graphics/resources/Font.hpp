#pragma once

#include <string>

class Font
{
public:
    bool LoadFromFile(const std::string& Path);

    const std::string& GetPath() const;

private:
    std::string Path;
};











