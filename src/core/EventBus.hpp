#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include <typeindex>

class EventBus
{
public:
    template <typename T>
    using Handler = std::function<void(const T&)>;

    template <typename T>
    void Subscribe(Handler<T> HandlerFunc)
    {
        Listeners[typeid(T)].push_back(
            [HandlerFunc](const void* Event)
            {
                HandlerFunc(*static_cast<const T*>(Event));
            }
        );
    }

    template <typename T>
    void Emit(const T& Event)
    {
        auto it = Listeners.find(typeid(T));
        if (it == Listeners.end()) return;

        for (auto& Func : it->second)
            Func(&Event);
    }

private:
    std::unordered_map<
        std::type_index,
        std::vector<std::function<void(const void*)>>
    > Listeners;
};