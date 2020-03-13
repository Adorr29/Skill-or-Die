/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Game.cpp
*/

#include <iostream> // tmp
#include "Game.hpp"
#include "Input.hpp" // move in hpp ?
#include "TimeFactor.hpp" // move in hpp ?
#include "Entity/Player.hpp" // tmp
#include "Entity/Enemy.hpp" // tmp
#include "Control/PlayerControl.hpp" // tmp
#include "EnemyAI/EnemyAIFire.hpp" // tmp
#include "SFML++/Vector2Algebra.hpp" // ?

Game::Game()
{
    const VideoMode desktopMode = VideoMode::getDesktopMode();
    const Vector2u desktopSize(desktopMode.width, desktopMode.height);
    ContextSettings settings;

    settings.antialiasingLevel = 8; // ?
    window.create(VideoMode(900, 900), "Skill or Die", Style::Close, settings);
    window.setPosition(Vector2i(desktopSize - window.getSize()) / 2);
    window.setFramerateLimit(Framerate);

    // tmp
    PlayerPtr playerEntity = make_shared<Player>();
    playerControl = make_shared<PlayerControl>(*this, *playerEntity);
    addEntity(playerEntity);
    controlList.push_back(playerControl);

    // tmp
    wait = -3.0;
    spawnDelay = 1.0;
}

const RenderWindow &Game::getWindow() const
{
    return window;
}

void Game::addEntity(EntityPtr entity)
{
    entityList.push_back(entity);
}

void Game::addControl(AControlPtr control)
{
    controlList.push_back(control);
}

void Game::run()
{
    while (window.isOpen()) {
        Input::update(window);
        spawn(); // tmp
        update();
        if (playerCollide())
            cerr << "Collide !! " << endl;
        window.clear();
        for (EntityPtr &entity : entityList) {
            entity->update();
            window.draw(*entity);
        }
        window.display();
        clearEntity();
    }
}

void Game::update()
{
    for (AControlPtr &control : controlList)
        control->update();
    updateTimeFactor();
}

void Game::updateTimeFactor()
{
    const Entity &playerEntity = playerControl->getEntity();
    float minDistance = -1;
    const float maxDistance = 120;
    const float time = Framerate / 8.0;
    const Vector2f predictPlayerPosition = predictPosition(playerEntity, time);

    for (const EntityPtr &entity : entityList)
        if (&playerEntity != &(*entity)) {
            const Vector2f predictEntityPosition = predictPosition(*entity, time);
            const float distance = length(predictEntityPosition - predictPlayerPosition);

            if (minDistance < 0 || distance < minDistance)
                minDistance = distance;
        }
    if (minDistance > 0 && minDistance < maxDistance)
        TimeFactor::set(minDistance / maxDistance);
    else
        TimeFactor::set(1.0);
}

bool Game::playerCollide()
{
    const Entity &playerEntity = playerControl->getEntity();

    for (const EntityPtr entity : entityList)
        if (&playerEntity != &(*entity) && playerEntity.collide(*entity))
            return true;
    return false;
}

void Game::clearEntity()
{
    controlList.remove_if([&](const AControlPtr control){return control->toDestroy();});
    entityList.remove_if([&](const GameObjectPtr entity){return entity->toDestroy();});
}

void Game::spawn()
{
    wait += clock.restart().asSeconds() * TimeFactor::get();
    if (wait >= spawnDelay) {
        wait -= spawnDelay;
        spawnDelay -= 0.01 * spawnDelay;
        EntityPtr enemy = make_shared<Enemy>();

        entityList.push_back(enemy);
        controlList.push_back(make_shared<EnemyAIFire>(*this, *enemy, playerControl->getEntity()));
    }
}

Vector2f Game::predictPosition(const Entity &entity, const float &time)
{
    return entity.getPosition() + entity.getVelocity() * time;
}
