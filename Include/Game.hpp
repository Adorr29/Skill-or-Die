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
//#include "Control.hpp" // ??
//#include "PlayerControl.hpp" // ?

using namespace std;
using namespace sf;

#define Framerate 60 // ?


// ----- tmp -----
class Entity;
class Control;
class PlayerControl;

typedef shared_ptr<Entity> EntityPtr;
typedef shared_ptr<Control> ControlPtr;
typedef shared_ptr<PlayerControl> PlayerControlPtr;
// ----- !tmp -----


class Game
{
public:
    Game();
    const RenderWindow &getWindow() const;
    void addEntity(EntityPtr entity);
    void addControl(ControlPtr control);
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
    list<ControlPtr> controlList;
    PlayerControlPtr player; // use PlayerControl

private:
    float wait; // tmp
    float spawnDelay; // tmp
    Clock clock; // tmp
};
