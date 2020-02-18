/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** IControl.hpp
*/

#pragma once

#include <memory>
#include "Entity/Entity.hpp"
//#include "Game.hpp" // ?

class IControl
{
public:
    virtual ~IControl() = default;
    virtual const Entity &getEntity() const = 0;
    virtual bool toDestroy() const = 0;
    virtual void update() = 0;
};

typedef shared_ptr<IControl> IControlPtr;
