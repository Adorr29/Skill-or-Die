/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Enemy.hpp
*/

#pragma once

#include "Entity.hpp"

class Enemy : public Entity
{
public:
    Enemy();
    void move(const Vector2f &direction);

private:
    //
};
