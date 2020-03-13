/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Game.hpp
*/

#pragma once

class Game;

#include <list>
#include <memory> // tmp
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp> // tmp ?
#include "Control/AControl.hpp" // ?
#include "Entity/Entity.hpp" // ?

using namespace std;
using namespace sf;

#define Framerate 60 // ?

class Game
{
public:
    Game();
    const RenderWindow &getWindow() const;
    void addEntity(EntityPtr entity);
    void addControl(AControlPtr control);
    void run();

private:
    void update();
    void updateTimeFactor();
    bool playerCollide();
    void clearEntity();
    void spawn(); // tmp
    inline Vector2f predictPosition(const Entity &entity, const float &time); // ?

private:
    RenderWindow window;
    list<EntityPtr> entityList;
    list<AControlPtr> controlList;
    AControlPtr playerControl;

private:
    float wait; // tmp
    float spawnDelay; // tmp
    Clock clock; // tmp
};
