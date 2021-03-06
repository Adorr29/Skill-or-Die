/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Control.hpp
*/

#pragma once

#include <memory>
#include "AControl.hpp"
//#include "Entity/Entity.hpp" // ?
#include "Game.hpp" // ?

class Control : public AControl
{
public:
    Control(Game &_game, Entity &_entity);
    virtual ~Control() = default;
    //const Entity &getEntity() const;
    virtual void update() = 0;

protected:
    Game &game;
    //Entity &entity;
};

typedef shared_ptr<Control> ControlPtr;
