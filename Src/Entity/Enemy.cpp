/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Enemy.hpp
*/

#include "Entity/Enemy.hpp"
#include "SFML++/Vector2Algebra.hpp" // tmp

Enemy::Enemy()
{
    // tmp
    hp = 2;
    speed = 11;
    convexShape.setPointCount(3);
    convexShape.setPoint(0, Vector2f(-15, -10));
    convexShape.setPoint(1, Vector2f(30, 0));
    convexShape.setPoint(2, Vector2f(-15, 10));
    convexShape.setFillColor(Color(250, 50, 50));
}

void Enemy::move(const Vector2f &direction)
{
    Entity::move(direction);
    if (sqrLength(direction) > 0)
        convexShape.setRotation(atan2(direction.y, direction.x) * 180 / M_PI);
}
