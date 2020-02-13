/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** EnemyAIFire.hpp
*/

//#include <iostream> // ?
#include "EnemyAI/EnemyAIFire.hpp"
#include "SFML++/Vector2Algebra.hpp"

EnemyAIFire::EnemyAIFire(Entity &_entity, const Entity &target)
    : Control(_entity)
{
    Vector2f position(rand() % 900, rand() % 900);
    Vector2f targetPosition(target.getPosition());

    if (rand() % 2)
        position.x = rand() % 2 ? -50 : 900 + 50;
    else
        position.y = rand() % 2 ? -50 : 900 + 50;
    //position = Vector2f(450, 0); // tmp
    entity.setPosition(position);
    targetPosition += target.velocity * length(targetPosition - position) / entity.getSpeed();
    direction = targetPosition - position;
}

void EnemyAIFire::update()
{
    entity.move(direction);
    if (entity.getPosition().x < -70 || entity.getPosition().x > 900 + 70)
        entity.die();
    else if (entity.getPosition().y < -70 || entity.getPosition().y > 900 + 70)
        entity.die();
}
