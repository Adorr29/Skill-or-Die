/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** EnemyAIFire.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp> // ?
#include "Control.hpp"

class EnemyAIFire : public Control
{
public:
    EnemyAIFire(Entity &_entity, const Entity &target);
    void update();

private:
    //

private:
    Vector2f direction;
};
