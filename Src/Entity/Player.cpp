/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Player.cpp
*/

#include "Entity/Player.hpp"
#include "SFML++/Vector2Algebra.hpp"

Player::Player()
{
    setPosition(Vector2f(900 / 2, 900 / 2));
    hp = 1;
    speed = 5;
    convexShape.setFillColor(Color(0, 110, 250));
    /*convexShape.setPointCount(4);
    convexShape.setPoint(0, Vector2f(-12, -12));
    convexShape.setPoint(1, Vector2f(12, -12));
    convexShape.setPoint(2, Vector2f(12, 12));
    convexShape.setPoint(3, Vector2f(-12, 12));
    saveToFile("Resources/Shape/Square12");*/
    loadFromFile("Resources/Shape/Square12");
}

void Player::update()
{
    Entity::update();
    if (sqrLength(direction) > 0)
        convexShape.setRotation(atan2(direction.y, direction.x) * 180 / M_PI);
}
