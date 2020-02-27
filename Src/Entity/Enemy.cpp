/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Enemy.cpp
*/

#include <cmath> // tmp
#include "Entity/Enemy.hpp"
#include "SFML++/Vector2Algebra.hpp" // tmp

Enemy::Enemy()
{
    // tmp
    hp = 2;
    speed = 11;
    convexShape.setFillColor(Color(250, 50, 50));
    /*convexShape.setPointCount(3);
    convexShape.setPoint(0, Vector2f(-15, -10));
    convexShape.setPoint(1, Vector2f(30, 0));
    convexShape.setPoint(2, Vector2f(-15, 10));
    saveToFile("Resources/Shape/Spike");*/
    loadFromFile("Resources/Shape/Spike");

    /*convexShape.setPointCount(8);
    float angle = 0;
    float radius = 120;
    //angle = M_PI / convexShape.getPointCount();
    for (size_t i = 0; i < convexShape.getPointCount(); i++) {
        Vector2f point(cos(angle) * radius, sin(angle) * radius);

        convexShape.setPoint(i, point);
        angle += 2 * M_PI / convexShape.getPointCount();
    }
    saveToFile("Resources/Shape/Octagon" + to_string((int)radius));*/
}

void Enemy::update()
{
    Entity::update();
    if (sqrLength(direction) > 0)
        convexShape.setRotation(atan2(direction.y, direction.x) * 180 / M_PI);
}
