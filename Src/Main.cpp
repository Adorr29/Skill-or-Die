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
#include "Entity/Player.hpp"
#include "Entity/Enemy.hpp"
#include "TimeFactor.hpp"
#include "SFML++/Vector2Algebra.hpp" // tmp

using namespace sf;

int main()
{
    srand(time(nullptr));
    const VideoMode desktopMode = VideoMode::getDesktopMode();
    const Vector2u desktopSize(desktopMode.width, desktopMode.height);
    ContextSettings settings;
    settings.antialiasingLevel = 8; // ?
    RenderWindow window(VideoMode(900, 900), "Skill or Die", Style::Close, settings);
    list<EntityPtr> EntityList;
    EntityList.push_back(make_unique<Player>());
    PlayerControl playerControl(*EntityList.back());
    for (size_t i = 0; i < 4; i++)
        EntityList.push_back(make_unique<Enemy>());

    window.setPosition(Vector2i(desktopSize - window.getSize()) / 2);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        for (Event event; window.pollEvent(event);) {
            if (event.type == Event::Closed)
                window.close();
            else if (playerControl.parseEvent(event)) continue; // ??
            //else if (enemy.parseEvent(event)) continue;

            // GLOBAL stock event
        }
        playerControl.update();
        {
            const Entity &playerEntity = playerControl.getEntity();
            float minDist = -1;

            for (const EntityPtr &entity : EntityList)
                if (&(*entity) != &playerEntity) {
                    const float dist = length(playerEntity.getPosition() - entity->getPosition());
                    if (minDist < 0 || dist < minDist)
                        minDist = dist;
                }
            if (minDist > 0 && minDist - 15 * 2 < 120)
                TimeFactorInstance.set((minDist - 15 * 2) / 120);
            else
                TimeFactorInstance.set(1.0);
            cerr << "TimeFactor : " << TimeFactorInstance.get() << endl;
        }
        window.clear();
        for (const EntityPtr &entity : EntityList)
            entity->aff(window);
        window.display();
    }
    return 0;
}
