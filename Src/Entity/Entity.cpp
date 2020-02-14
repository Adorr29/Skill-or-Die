/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.hpp
*/

#include <list> // ?
#include "Entity/Entity.hpp"
#include "TimeFactor.hpp"
#include "SFML++/Vector2Algebra.hpp"
#include "SFML++/ConvexShapeIntersects.hpp"

const Uint32 &Entity::getHp() const
{
    return hp;
}

const Vector2f &Entity::getPosition() const
{
    return convexShape.getPosition();
}

const float &Entity::getSpeed() const
{
    return speed;
}

void Entity::setPosition(const Vector2f &position)
{
    convexShape.setPosition(position);
}

void Entity::move(const Vector2f &direction)
{
    Vector2f offset = direction;

    if (sqrLength(direction) > 1)
        offset = normalize(direction);
    offset *= speed;
    convexShape.move(offset * TimeFactorInstance.get());
    velocity = offset;
}

void Entity::takeDamage(const Uint32 &damage)
{
    if (damage >= hp)
        hp = 0;
    else
        hp -= damage;
}

void Entity::die()
{
    hp = 0;
}

void Entity::aff(RenderTarget &renderTarget) const
{
    renderTarget.draw(convexShape);

    // Tmp !!
    /*RectangleShape rectangleShape(Vector2f(25, 25));

    rectangleShape.setOrigin(rectangleShape.getSize() / (float)2);
    rectangleShape.setPosition(position);
    rectangleShape.setRotation(angle * 180.0 / M_PI);
    rectangleShape.setFillColor(Color(0, 110, 250));
    renderTarget.draw(rectangleShape);*/
}

bool Entity::collide(const Entity &entity) const
{
    if (!convexShape.getGlobalBounds().intersects(entity.convexShape.getGlobalBounds()))
        return false;
    return intersects(convexShape, entity.convexShape);
}
