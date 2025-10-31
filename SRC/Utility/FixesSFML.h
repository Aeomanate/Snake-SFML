#ifndef SNAKE_FIXESSFML_H
#define SNAKE_FIXESSFML_H
#include <type_traits>

#include "SFML/System/Vector2.hpp"

template<class T>
class Vector2Caster
{
public:
    Vector2Caster(T x, T y)
    : x(x)
    , y(y)
    { }

    template<class U>
    operator sf::Vector2<U>()
    {
        return sf::Vector2<U>
        (
            static_cast<U>(x),
            static_cast<U>(y)
        );
    }

    T x, y;
};

template<class T, class U, class Common = std::common_type_t<T, U>>
Vector2Caster<Common> operator*(sf::Vector2<T> target, U value)
{
    return {
        target.x * value,
        target.y * value
    };
}

template<class T, class U, class Common = std::common_type_t<T, U>>
Vector2Caster<U> operator/(sf::Vector2<T> target, U value)
{
    return {
        target.x / value,
        target.y / value
    };
}

#endif //SNAKE_FIXESSFML_H
