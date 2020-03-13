/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.cpp
*/

#include "Control/Control.hpp"

Control::Control(Game &_game, Entity &_entity)
    : AControl(_entity),
      game(_game)
{
}
