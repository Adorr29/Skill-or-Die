/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.hpp
*/

#pragma once

#include "Entity/Entity.hpp"

class Control
{
public:
    Control(Entity &_entity);
    const Entity &getEntity() const;
    bool toDestroy() const;
    virtual void update() = 0;

protected:
    Entity &entity;
};

typedef shared_ptr<Control> ControlPtr;
