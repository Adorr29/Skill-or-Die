/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** PlayerControl.hpp
*/

#include <iostream> // tmp
#include "PlayerControl.hpp"
#include "SFML++/Vector2Algebra.hpp"

PlayerControl::PlayerControl(Entity &_entity)
    : entity(_entity)
{
}

const Entity &PlayerControl::getEntity() const
{
    return entity;
}

bool PlayerControl::parseEvent(const Event &event)
{
    if (event.type == Event::JoystickMoved) {
        if (event.joystickMove.axis == Joystick::X)
            direction.x = event.joystickMove.position;
        else if (event.joystickMove.axis == Joystick::Y)
            direction.y = event.joystickMove.position;
    }
    else if (event.type == Event::JoystickButtonPressed) {
        // TODO
    }
    else
        return false;
    return true;
}

void PlayerControl::update()
{
    entity.move(normalize(direction));
}
