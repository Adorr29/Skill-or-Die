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
    const float &getSpeed() const;
    void setPosition(const Vector2f &position);
    virtual void move(const Vector2f &direction);
    void takeDamage(const Uint32 &damage);
    void die();
    void aff(RenderTarget &renderTarget) const;
    bool collide(const Entity &entity) const;

protected:
    Uint32 hp; // ?
    float speed;
    ConvexShape convexShape;

public:
    Vector2f velocity; // tmp
};

typedef shared_ptr<Entity> EntityPtr;
