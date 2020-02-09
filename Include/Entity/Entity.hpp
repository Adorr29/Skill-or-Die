/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.hpp
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{
public:
    virtual ~Entity() = default;
    const Uint32 &getHp() const;
    const Vector2f &getPosition() const;
    virtual void move(const Vector2f &direction);
    void takeDamage(const Uint32 &damage);
    void aff(RenderTarget &renderTarget) const;

protected:
    void setPosition(const Vector2f &position);

protected:
    Uint32 hp;
    float speed;
    ConvexShape convexShape;
};

typedef unique_ptr<Entity> EntityPtr;
