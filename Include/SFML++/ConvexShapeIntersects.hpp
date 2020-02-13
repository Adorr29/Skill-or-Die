/*
** EPITECH PROJECT, 2020
** SFML++
** File description:
** ConvexShapeIntersects.hpp
*/

#pragma once

#include <list>
#include <SFML/Graphics/ConvexShape.hpp> // ?

using namespace std;
using namespace sf;

struct Line
{
    Vector2f start;
    Vector2f end;
};

list<Line> getLineList(const ConvexShape &convexShape);

//Int8 getOrientation(const Vector2f &a, const Vector2f &b, const Vector2f &c);

bool intersects(const Line &line1, const Line &line2);

bool intersects(const ConvexShape &convexShape1, const ConvexShape &convexShape2);
