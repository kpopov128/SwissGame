#pragma once

#include <typeindex>

#pragma once

#include <memory>
#include <stdexcept>
#include <typeindex>

class ImageRss
{
public:
    ImageRss()
        : Type(typeid(void))
    {
    }

    template<typename T>
    ImageRss(const T& value)
        : Type(typeid(T)),
        Value(std::make_shared<Holder<T>>(value))
    {
    }

    template<typename T>
    const T& As() const
    {
        if (Type != typeid(T))
        {
            throw std::runtime_error("Bad ImageResource cast");
        }

        return static_cast<Holder<T>*>(Value.get())->Data;
    }

    std::type_index Type;

private:
    struct IHolder
    {
        virtual ~IHolder() = default;
    };

    template<typename T>
    struct Holder : IHolder
    {
        explicit Holder(const T& value)
            : Data(value)
        {
        }

        T Data;
    };

    std::shared_ptr<IHolder> Value;
};










