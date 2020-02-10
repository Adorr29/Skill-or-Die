/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.hpp
*/

#include <iostream> // tmp
#include "Control.hpp"
#include "SFML++/Vector2Algebra.hpp"

Control::Control(Entity &_entity)
    : entity(_entity)
{
}

const Entity &Control::getEntity() const
{
    return entity;
}
