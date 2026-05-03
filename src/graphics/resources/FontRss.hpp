#pragma once

#include <typeindex>

class FontRss
{
public:
    FontRss()
        : Type(typeid(void)), Value(0)
    {
    }

    template <typename TEnum>
    FontRss(TEnum EnumValue)
        : Type(typeid(TEnum)),
          Value(static_cast<int>(EnumValue))
    {
    }

    std::type_index Type;
    int Value;
};










