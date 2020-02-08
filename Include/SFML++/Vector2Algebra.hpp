/*
** EPITECH PROJECT, 2020
** SFML++
** File description:
** Vector2Algebra.hpp
*/

#pragma once

#include <SFML/System/Vector2.hpp> // ?

using namespace sf;

template<typename T>
T length(const sf::Vector2<T> &vector);

template<typename T>
T sqrLength(const sf::Vector2<T> &vector);

template<typename T>
Vector2<T> normalize(const Vector2<T> &vector);

template<typename T>
T angleBetween(const Vector2<T> &from, const Vector2<T> &to); // TODO replace be signedAgnle

/*template<typename T>
  Vector2<T> operator+(Vector2<T> &vector, Vector2<T> &vector2);*/

#include "../../Src/SFML++/Vector2Algebra.cpp"
