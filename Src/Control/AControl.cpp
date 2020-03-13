/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** AControl.cpp
*/

#include "Control/AControl.hpp"

AControl::AControl(Entity &_entity)
    : entity(_entity)
{
}

const Entity &AControl::getEntity() const
{
    return entity;
}
