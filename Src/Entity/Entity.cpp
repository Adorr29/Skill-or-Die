/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Entity.cpp
*/

#include <list> // ?
#include <fstream>
#include "Entity/Entity.hpp"
#include "TimeFactor.hpp"
#include "SFML++/Vector2Algebra.hpp"
#include "SFML++/ConvexShapeIntersects.hpp"
#include "Error.hpp"

const Uint32 &Entity::getHp() const
{
    return hp;
}

const Vector2f &Entity::getPosition() const
{
    return convexShape.getPosition();
}

const Vector2f &Entity::getVelocity() const
{
    return velocity;
}

const float &Entity::getSpeed() const
{
    return speed;
}

void Entity::setPosition(const Vector2f &position)
{
    convexShape.setPosition(position);
}

void Entity::setDirection(const Vector2f &_direction)
{
    direction = _direction;
}

void Entity::takeDamage(const Uint32 &damage)
{
    if (damage >= hp)
        die();
    else
        hp -= damage;
}

void Entity::die()
{
    hp = 0;
    destroy();
}

void Entity::update()
{
    move();
}

void Entity::aff(RenderTarget &renderTarget) const
{
    renderTarget.draw(convexShape);
}

void Entity::draw(RenderTarget &renderTarget, RenderStates states) const
{
    renderTarget.draw(convexShape, states);
}

bool Entity::collide(const Entity &_entity) const
{
    const Entity &entity = static_cast<const Entity&>(_entity);

    if (!convexShape.getGlobalBounds().intersects(entity.convexShape.getGlobalBounds()))
        return false;
    return intersects(convexShape, entity.convexShape);
}

void Entity::loadFromFile(const string &fileName)
{
    ifstream file(fileName, ifstream::binary);
    size_t pointCount;
    Vector2f point;

    if (!file)
        throw ERROR(fileName + " can not be open");
    if (!file.read((char*)&pointCount, sizeof(size_t)))
        throw ERROR("Read pointCount failed");
    convexShape.setPointCount(pointCount);
    for (size_t i = 0; i < convexShape.getPointCount(); i++) {
        if (!file.read((char*)&point, sizeof(Vector2f)))
            throw ERROR("Read point failed");
        convexShape.setPoint(i, point);
    }
}

void Entity::saveToFile(const string &fileName) const
{
    ofstream file(fileName, ifstream::binary | ifstream::trunc);
    size_t pointCount;
    Vector2f point;

    if (!file)
        throw ERROR(fileName + " can not be open");
    pointCount = convexShape.getPointCount();
    if (!file.write((char*)&pointCount, sizeof(size_t)))
        throw ERROR("Write pointCount failed");
    for (size_t i = 0; i < convexShape.getPointCount(); i++) {
        point = convexShape.getPoint(i);
        if (!file.write((char*)&point, sizeof(Vector2f)))
            throw ERROR("Write point failed");
    }
}

void Entity::move()
{
    velocity = direction;
    if (sqrLength(direction) > 1)
        velocity = normalize(direction);
    velocity *= speed;
    convexShape.move(velocity * TimeFactor::get());
}
