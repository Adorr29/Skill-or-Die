/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Main.cpp
*/

#include <iostream> // ?
#include <list>
#include <SFML/Graphics.hpp>
#include "PlayerControl.hpp"
#include "EnemyAI/EnemyAIFire.hpp"
#include "Entity/Player.hpp"
#include "Entity/Enemy.hpp"
#include "TimeFactor.hpp"
#include "SFML++/Vector2Algebra.hpp" // tmp

using namespace sf;

void spawn(list<EntityPtr> &entityList, list<shared_ptr<Control>> &enemyAIList, const Entity &player)
{
    entityList.push_back(make_shared<Enemy>());
    enemyAIList.push_back(make_shared<EnemyAIFire>(*entityList.back(), player));
}

int main()
{
    srand(time(nullptr));
    const VideoMode desktopMode = VideoMode::getDesktopMode();
    const Vector2u desktopSize(desktopMode.width, desktopMode.height);
    ContextSettings settings;
    settings.antialiasingLevel = 8; // ?
    RenderWindow window(VideoMode(900, 900), "Skill or Die", Style::Close, settings);
    list<EntityPtr> entityList;
    list<ControlPtr> enemyAIList;
    entityList.push_back(make_shared<Player>());
    PlayerControl playerControl(*entityList.back());
    float wait = -3; // tmp
    float spawnDelay = 1.0; // tmp
    Clock clock; // tmp
    bool gameover = false;

    window.setPosition(Vector2i(desktopSize - window.getSize()) / 2);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        for (Event event; window.pollEvent(event);) {
            if (event.type == Event::Closed)
                window.close();
            else if (playerControl.parseEvent(event)) continue; // ??
        }
        wait += clock.restart().asSeconds() * TimeFactorInstance.get();
        if (wait >= spawnDelay) {
            spawn(entityList, enemyAIList, playerControl.getEntity());
            wait -= spawnDelay;
            spawnDelay -= 0.01 * spawnDelay;
            cerr << "spawnDelay : " << spawnDelay << "s" << endl;
        }
        if (!gameover) {
            playerControl.update();
            for (auto it = enemyAIList.begin(); it != enemyAIList.end(); it++) {
                ControlPtr enemyAI = *it;
                enemyAI->update();
                if (enemyAI->getEntity().collide(playerControl.getEntity())) {
                    cerr << "Collide !! " << endl;
                    gameover = true;
                    TimeFactorInstance.set(0.0);
                }
                if (enemyAI->toDestroy())
                    it = enemyAIList.erase(it);
            }
        }
        entityList.remove_if([&](const EntityPtr entity){return entity->getHp() == 0;});
        if (!gameover) {
            const Entity &playerEntity = playerControl.getEntity();
            float minDist = -1;

            for (const EntityPtr &entity : entityList)
                if (&(*entity) != &playerEntity) {
                    const float dist = length(playerEntity.getPosition() - entity->getPosition());
                    if (minDist < 0 || dist < minDist)
                        minDist = dist;
                }
            if (minDist > 0 && minDist - 15 * 2 < 120)
                TimeFactorInstance.set((minDist - 15 * 2) / 120);
            else
                TimeFactorInstance.set(1.0);
            //cerr << "TimeFactor : " << TimeFactorInstance.get() << endl;
        }
        window.clear();
        for (const EntityPtr &entity : entityList)
            entity->aff(window);
        window.display();
    }
    return 0;
}
