/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Input.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Input
{
public:
    static bool getJoystickButton(const Uint32 &joystickId, const Uint32 &button);
    static bool getJoystickButtonDown(const Uint32 &joystickId, const Uint32 &button);
    static bool getJoystickButtonUp(const Uint32 &joystickId, const Uint32 &button);
    static float getJoystickPosition(const Uint32 &joystickId, const Joystick::Axis &axis);
    static void update(Window &window);

private:
    Input(); // default ?
    ~Input() = default;
    Input(const Input &input) = delete;
    void reset(); // ??

private:
    static Input instance;
    array<array<bool, Joystick::ButtonCount>, Joystick::Count> joystickButtonList;
    array<array<bool, Joystick::ButtonCount>, Joystick::Count> joystickButtonDownList;
    array<array<bool, Joystick::ButtonCount>, Joystick::Count> joystickButtonUpList;
    array<array<float, Joystick::AxisCount>, Joystick::Count> joystickPositionList;
};
