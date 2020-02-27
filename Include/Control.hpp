/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.hpp
*/

#pragma once

#include <memory>
#include "Entity/Entity.hpp" // ?
#include "Game.hpp" // ?

class Control
{
public:
    Control(Game &_game, Entity &_entity);
    virtual ~Control() = default;
    const Entity &getEntity() const;
    bool toDestroy() const;
    virtual void update() = 0;

protected:
    Game &game;
    Entity &entity;
};
