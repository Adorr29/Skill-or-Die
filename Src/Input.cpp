/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Input.cpp
*/

#include "Input.hpp"

Input Input::instance;

bool Input::getJoystickButton(const Uint32 &joystickId, const Uint32 &button)
{
    return instance.joystickButtonList[joystickId][button];
}

bool Input::getJoystickButtonDown(const Uint32 &joystickId, const Uint32 &button)
{
    return instance.joystickButtonDownList[joystickId][button];
}

bool Input::getJoystickButtonUp(const Uint32 &joystickId, const Uint32 &button)
{
    return instance.joystickButtonUpList[joystickId][button];
}

float Input::getJoystickPosition(const Uint32 &joystickId, const Joystick::Axis &axis)
{
    return instance.joystickPositionList[joystickId][axis];
}

void Input::update(Window &window)
{
    instance.reset();
    for (Event event; window.pollEvent(event);) {
        if (event.type == Event::Closed)
            window.close();
        else if (event.type == Event::JoystickButtonPressed) {
            instance.joystickButtonList[event.joystickButton.joystickId][event.joystickButton.button] = true;
            instance.joystickButtonDownList[event.joystickButton.joystickId][event.joystickButton.button] = true;
        }
        else if (event.type == Event::JoystickButtonReleased) {
            instance.joystickButtonList[event.joystickButton.joystickId][event.joystickButton.button] = false;
            instance.joystickButtonUpList[event.joystickButton.joystickId][event.joystickButton.button] = true;
        }
        else if (event.type == Event::JoystickMoved)
            instance.joystickPositionList[event.joystickMove.joystickId][event.joystickMove.axis] = event.joystickMove.position / 100.0;
    }
}

Input::Input()
{
    //
}

void Input::reset()
{
    for (size_t i = 0; i < joystickButtonDownList.size(); i++)
        for (size_t j = 0; j < joystickButtonDownList[i].size(); j++)
            joystickButtonDownList[i][j] = false;
    for (size_t i = 0; i < joystickButtonUpList.size(); i++)
        for (size_t j = 0; j < joystickButtonUpList[i].size(); j++)
            joystickButtonUpList[i][j] = false;
}
