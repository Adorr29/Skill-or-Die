/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** PlayerControl.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp> // ?
#include "Control.hpp"

class PlayerControl : public Control
{
public:
    PlayerControl(Game &_game, Entity &_entity);
    bool parseEvent(const Event &event);
    void update();

private:
    //

private:
    Vector2f direction;
};
