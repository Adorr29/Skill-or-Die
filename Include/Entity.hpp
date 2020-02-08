/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.hpp
*/

#pragma once

//#include <list>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Entity
{
public:
    Entity();
    const Uint32 &getHp() const;
    const Vector2f &getPosition() const;
    void move(const Vector2f &direction);
    void takeDamage(const Uint32 &damage);
    void aff(RenderTarget &renderTarget) const;

private:
    //

private:
    Uint32 hp;
    Vector2f position;
    float angle;
    float speed;
};
