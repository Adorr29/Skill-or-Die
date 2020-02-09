/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** PlayerControl.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp> // ?
#include "Entity/Entity.hpp"

class PlayerControl
{
public:
    PlayerControl(Entity &_entity);
    const Entity &getEntity() const;
    bool parseEvent(const Event &event);
    void update();

private:
    //

private:
    Entity &entity;
    Vector2f direction;
};
