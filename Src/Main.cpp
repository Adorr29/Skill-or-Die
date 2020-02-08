/*
** EPITECH PROJECT, 2020
** Skill or Die
** File description:
** Main.cpp
*/

#include <list>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Entity.hpp"

using namespace sf;

int main()
{
    const VideoMode desktopMode = VideoMode::getDesktopMode();
    const Vector2u desktopSize(desktopMode.width, desktopMode.height);
    RenderWindow window(VideoMode(900, 900), "Skill or Die", Style::Close);
    list<Entity> EntityList(1);
    Player player(EntityList.front());

    window.setPosition(Vector2i(desktopSize - window.getSize()) / 2);
    window.setFramerateLimit(60);
    while (window.isOpen()) {
        for (Event event; window.pollEvent(event);) {
            if (event.type == Event::Closed)
                window.close();
            else if (player.parseEvent(event)) continue; // ??
            //else if (enemy.parseEvent(event)) continue;

            // GLOBAL stock event
        }
        player.update();
        window.clear();
        for (const Entity &entity : EntityList)
            entity.aff(window);
        window.display();
    }
    return 0;
}
