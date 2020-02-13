/*
** EPITECH PROJECT, 2020
** SFML++
** File description:
** ConvexShapeIntersects.cpp
*/

#include "SFML++/ConvexShapeIntersects.hpp"

list<Line> getLineList(const ConvexShape &convexShape)
{
    list<Line> lineList;
    const size_t nbPoint = convexShape.getPointCount();

    for (size_t i = 0; i < nbPoint; i++) {
        const Transform &transform = convexShape.getTransform();
        const Vector2f start = transform.transformPoint(convexShape.getPoint(i));
        const Vector2f end = transform.transformPoint(convexShape.getPoint((i + 1) % nbPoint));

        lineList.push_back(Line{start, end});
    }
    return lineList;
}

int getOrientation(const Vector2f &a, const Vector2f &b, const Vector2f &c)
{
     float value = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);

     if (value == 0)
         return 0;
     return value > 0 ? 1 : 2;
}


// https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
bool intersects(const Line &line1, const Line &line2)
{
    float orientation[4];

    orientation[0] = getOrientation(line1.start, line1.end, line2.start);
    orientation[1] = getOrientation(line1.start, line1.end, line2.end);
    orientation[2] = getOrientation(line2.start, line2.end, line1.start);
    orientation[3] = getOrientation(line2.start, line2.end, line1.end);
    if (orientation[0] != orientation[1] && orientation[2] != orientation[3])
        return true;
    // TODO if colinear
    return false;
}

bool intersects(const ConvexShape &convexShape1, const ConvexShape &convexShape2)
{
    if (!convexShape1.getGlobalBounds().intersects(convexShape2.getGlobalBounds()))
        return false;
    for (const Line &line1 : getLineList(convexShape1))
        for (const Line &line2 : getLineList(convexShape2))
            if (intersects(line1, line2))
                return true;
    return false;
}
