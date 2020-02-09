/*
** EPITECH PROJECT, 2020
** SFML++
** File description:
** Vector2Algebra.cpp
*/

#include <cmath>
//#include "SFML++/Vector2Algebra.hpp"

template<typename T>
T length(const sf::Vector2<T> &vector)
{
    return sqrt(sqrLength(vector));
}

template<typename T>
T sqrLength(const sf::Vector2<T> &vector)
{
    return vector.x * vector.x + vector.y * vector.y;
}

template<typename T>
Vector2<T> normalize(const Vector2<T> &vector)
{
    T length2 = sqrLength(vector);

    if (length2 > 0)
        return Vector2<T>(vector) / (T)sqrt(length2);
    return vector;
}

template<typename T>
T angleBetween(const Vector2<T> &from, const Vector2<T> &to)
{
    return acos((from.x * to.x + from.y * to.y) / length(from) * length(to));
}

template<typename T>
Vector2<T> &operator+(Vector2<T> &vector, Vector2<T> &vector2)
{
    vector.x += vector2.x;
    vector.y += vector2.y;
    return vector;
}

template<typename T>
Vector2<T> &operator-(Vector2<T> &vector, Vector2<T> &vector2)
{
    vector.x -= vector2.x;
    vector.y -= vector2.y;
    return vector;
}
