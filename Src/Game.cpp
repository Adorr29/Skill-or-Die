/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Game.hpp
*/

#include <iostream> // tmp
#include "Game.hpp"
#include "TimeFactor.hpp" // move in hpp ?
#include "Entity/Player.hpp" // tmp
#include "Entity/Enemy.hpp" // tmp
#include "PlayerControl.hpp" // tmp
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
    player = make_shared<PlayerControl>(*this, *playerEntity);
    addEntity(playerEntity);
}

const RenderWindow &Game::getWindow() const
{
    return window;
}

void Game::addEntity(EntityPtr entity)
{
    entityList.push_back(entity);
}

void Game::run()
{
    while (window.isOpen()) {
        for (Event event; window.pollEvent(event);) {
            if (event.type == Event::Closed)
                window.close();
            else if (static_pointer_cast<PlayerControl>(player)->parseEvent(event))
                continue;
        }
        if (rand() % 30 == 0) // tmp
            spawn();
        update();
        if (playerCollide())
            cerr << "Collide !! " << endl;
        window.clear();
        for (EntityPtr &entity : entityList) {
            entity->update();
            entity->aff(window);
        }
        window.display();
        clearEntity();
    }
}

void Game::update()
{
    player->update();
    for (IControlPtr &control : controlList)
        control->update();
    updateTimeFactor();
}

void Game::updateTimeFactor()
{
    const Entity &playerEntity = player->getEntity();
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
        TimeFactorInstance.set(minDistance / maxDistance);
    else
        TimeFactorInstance.set(1.0);
}

bool Game::playerCollide()
{
    const Entity &playerEntity = player->getEntity();

    for (const EntityPtr entity : entityList)
        if (&playerEntity != &(*entity) && playerEntity.collide(*entity))
            return true;
    return false;
}

void Game::clearEntity()
{
    controlList.remove_if([&](const IControlPtr control){return control->toDestroy();});
    entityList.remove_if([&](const EntityPtr entity){return entity->getHp() == 0;});
}

void Game::spawn()
{
    EntityPtr enemy = make_shared<Enemy>();

    entityList.push_back(enemy);
    controlList.push_back(make_shared<EnemyAIFire>(*this, *enemy, player->getEntity()));
}

Vector2f Game::predictPosition(const Entity &entity, const float &time)
{
    return entity.getPosition() + entity.getVelocity() * time;
}
