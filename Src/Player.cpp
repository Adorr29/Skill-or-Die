/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Player.hpp
*/

#include <iostream> // tmp
#include "Player.hpp"
#include "SFML++/Vector2Algebra.hpp"

Player::Player(Entity &_entity)
    : entity(_entity)
{
}

bool Player::parseEvent(const Event &event)
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

void Player::update()
{
    entity.move(normalize(direction));
}
