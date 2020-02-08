/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Player.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp> // ?
#include "Entity.hpp"

class Player
{
public:
    Player(Entity &_entity);
    bool parseEvent(const Event &event);
    void update();

private:
    //

private:
    Entity &entity;
    Vector2f direction;
};
