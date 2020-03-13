/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** GameObject.cpp
*/

#include "GameObject.hpp"

GameObject::GameObject()
    : toDelete(false)
{
}

void GameObject::destroy()
{
    toDelete = true;
}

const bool &GameObject::toDestroy() const
{
    return toDelete;
}
