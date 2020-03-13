/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.hpp
*/

#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

using namespace std;
using namespace sf;

class Entity : public GameObject, public Drawable
{
public:
    virtual ~Entity() = default;
    const Uint32 &getHp() const;
    const Vector2f &getPosition() const;
    const Vector2f &getVelocity() const;
    const float &getSpeed() const; // ?
    void setPosition(const Vector2f &position);
    void setDirection(const Vector2f &_direction);
    void takeDamage(const Uint32 &damage);
    void die();
    virtual void update();
    void aff(RenderTarget &renderTarget) const; // TODO supr
    void draw(RenderTarget &renderTarget, RenderStates states) const;
    bool collide(const Entity &_entity) const;
    void loadFromFile(const string &fileName);
    void saveToFile(const string &fileName) const;

private:
    void move();

protected:
    Uint32 hp; // ?
    float speed;
    Vector2f direction;
    ConvexShape convexShape;

private:
    Vector2f velocity;
};

typedef shared_ptr<Entity> EntityPtr;
