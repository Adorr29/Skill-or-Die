/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** PlayerControl.cpp
*/

#include <iostream> // tmp
#include "Control/PlayerControl.hpp"
//#include "SFML++/Vector2Algebra.hpp"
#include "Input.hpp" // tmp

PlayerControl::PlayerControl(Game &_game, Entity &_entity)
    : Control(_game, _entity)
{
}

bool PlayerControl::parseEvent(const Event &event)
{
    if (event.type == Event::JoystickMoved) {
        if (event.joystickMove.axis == Joystick::X)
            direction.x = event.joystickMove.position / 100.0;
        else if (event.joystickMove.axis == Joystick::Y)
            direction.y = event.joystickMove.position / 100.0;
    }
    else if (event.type == Event::JoystickButtonPressed) {
        // TODO
    }
    else if (event.type == Event::JoystickButtonReleased) {
        //
    }
    /*else if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up)
            direction.y = -1;
        else if (event.key.code == Keyboard::Down)
            direction.y = 1;
        else if (event.key.code == Keyboard::Left)
            direction.x = -1;
        else if (event.key.code == Keyboard::Right)
            direction.x = 1;
        else
            return false;
    }
    else if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Up || event.key.code == Keyboard::Down)
            direction.y = 0;
        else if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Right)
            direction.x = 0;
        else
            return false;
            }*/
    /*else if (event.type == Event::MouseMoved) {
        const Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);

        direction = mousePosition - entity.getPosition();
        if (length(direction) < 1)
            direction = Vector2f();
            }*/
    else
        return false;
    return true;
}

void PlayerControl::update()
{
    direction.x = Input::getJoystickPosition(0, Joystick::X);
    direction.y = Input::getJoystickPosition(0, Joystick::Y);
    if (Input::getJoystickButtonDown(0, 0)) // tmp
        cout << "Press" << endl;
    else if (Input::getJoystickButtonUp(0, 0)) // tmp
        cout << "Release" << endl;
    entity.setDirection(direction);
}
