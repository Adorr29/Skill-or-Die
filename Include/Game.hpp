/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Game.hpp
*/

#pragma once

#include <list>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp> // tmp
#include "Entity/Entity.hpp"
#include "IControl.hpp"
//#include "PlayerControl.hpp" // ??

using namespace std;
using namespace sf;

#define Framerate 60 // ?

class Game
{
public:
    Game();
    const RenderWindow &getWindow() const;
    void addEntity(EntityPtr entity);
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
    list<IControlPtr> controlList;
    IControlPtr player; // use PlayerControl
};
