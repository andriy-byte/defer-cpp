

#ifndef DEFER_DEFER_HPP
#define DEFER_DEFER_HPP

#include <utility>
#include <functional>

namespace defer {

    template<typename T>
    class defer {
    public:
        explicit defer(T& type, T&& value);

        inline ~defer();

    private:
        T& type;
        T&& value;
    };

    class defer_call {
    public:
        template<typename Func, typename... Args>
        explicit defer_call(Func&& func, Args &&... args);

       inline ~defer_call();

    private:
        std::function<void()> function;
    };

    template<typename T>
    defer<T>::defer(T& type, T&& value) :type(type), value(std::move(value)) {}

    template<typename T>
    defer<T>::~defer() {
        this->type = std::move(this->value);
    }

    template<typename Func, typename ...Args>
    defer_call::defer_call(Func&& func, Args &&...args) :function(
        std::bind(std::forward<Func>(func), std::forward<Args>(args)...)) {}

    defer_call::~defer_call() { function(); }

}


#endif //DEFER_DEFER_HPP
