/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** EnemyAIFire.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp> // ?
#include "Control/Control.hpp"

class EnemyAIFire : public Control
{
public:
    EnemyAIFire(Game &_game, Entity &_entity, const Entity &target);
    void update();

private:
    //

private:
    //
};
