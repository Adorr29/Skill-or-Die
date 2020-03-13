/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** AControl.hpp
*/

#pragma once

#include <memory>
#include "GameObject.hpp"
#include "Entity/Entity.hpp" // ?

class AControl : public GameObject
{
public:
    AControl(Entity &_entity); // ?
    virtual ~AControl() = default;
    const Entity &getEntity() const; // TODO return a EntityPtr ??
    virtual void update() = 0; // ?

protected:
    Entity &entity;
};

typedef shared_ptr<AControl> AControlPtr;
