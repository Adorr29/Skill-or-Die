/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Enemy.hpp
*/

#include "Entity/Enemy.hpp"
#include "SFML++/Vector2Algebra.hpp"

Enemy::Enemy()
{
    Vector2f position(rand() % 900, rand() % 900);

    /*if (rand() % 2)
        position.x = rand() % 2 ? -50 : 900 + 50;
    else
    position.y = rand() % 2 ? -50 : 900 + 50;*/
    setPosition(position);
    speed = 4;
    convexShape.setPointCount(4);
    convexShape.setPoint(0, Vector2f(-15, -15));
    convexShape.setPoint(1, Vector2f(15, -15));
    convexShape.setPoint(2, Vector2f(15, 15));
    convexShape.setPoint(3, Vector2f(-15, 15));
    convexShape.setFillColor(Color(250, 50, 50));
}
