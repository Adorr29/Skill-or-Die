/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** EnemyAIFire.hpp
*/

//#include <iostream>
#include "EnemyAI/EnemyAIFire.hpp"
#include "SFML++/Vector2Algebra.hpp"

EnemyAIFire::EnemyAIFire(Entity &_entity, const Entity &target)
    : Control(_entity)
{
    Vector2f position(rand() % 900, rand() % 900);

    if (rand() % 2)
        position.x = rand() % 2 ? -00 : 900 + 00;
    else
        position.y = rand() % 2 ? -00 : 900 + 00;
    entity.setPosition(position);
    direction = normalize(target.getPosition() - position);
}

void EnemyAIFire::update()
{
    entity.move(direction);
    /*if (entity.getPosition().x < -50 || entity.getPosition().x > 900 + 50)
        delete entity;
    else if (entity.getPosition().y < -50 || entity.getPosition().y > 900 + 50)
    delete entity;*/
}
