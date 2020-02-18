/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.hpp
*/

#include <iostream> // tmp
#include "Control.hpp"
#include "SFML++/Vector2Algebra.hpp"

Control::Control(Game &_game, Entity &_entity)
    : game(_game),
      entity(_entity)
{
}

bool Control::toDestroy() const
{
    return entity.getHp() == 0;
}

const Entity &Control::getEntity() const
{
    return entity;
}
