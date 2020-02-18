/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Player.hpp
*/

#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player();
    void update();

private:
    //
};

typedef shared_ptr<Player> PlayerPtr;
