/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.hpp
*/

#include "Entity.hpp"
#include "SFML++/Vector2Algebra.hpp"

Entity::Entity()
    : position(900 / 2, 900 / 2),
      speed(5)
{
}

const Uint32 &Entity::getHp() const
{
    return hp;
}

const Vector2f &Entity::getPosition() const
{
    return position;
}

void Entity::move(const Vector2f &direction)
{
    if (sqrLength(direction) > 0) {
        position += direction * speed;
        angle = atan2(direction.y, direction.x);
    }
}

void Entity::takeDamage(const Uint32 &damage)
{
    if (damage >= hp)
        hp = 0;
    else
        hp -= damage;
}

void Entity::aff(RenderTarget &renderTarget) const
{
    // Tmp !!
    RectangleShape rectangleShape(Vector2f(25, 25));

    rectangleShape.setOrigin(rectangleShape.getSize() / (float)2);
    rectangleShape.setPosition(position);
    rectangleShape.setRotation(angle * 180.0 / M_PI);
    rectangleShape.setFillColor(Color(0, 110, 250));
    renderTarget.draw(rectangleShape);
}
