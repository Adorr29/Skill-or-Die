/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** GameObject.hpp
*/

#pragma once

#include <memory>

using namespace std;

class GameObject // ??
{
public:
    GameObject();
    virtual ~GameObject() = default;
    void destroy();
    const bool &toDestroy() const;
    virtual void update() = 0;

private:
    bool toDelete;
};

typedef shared_ptr<GameObject> GameObjectPtr; // ?
