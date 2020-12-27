//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Entity.h"
#include "World.h"


class Game {
public:
    Game();

    virtual ~Game();

    void run();

    void init();

    void handleEvent();

private:
    sf::RenderWindow m_window;
    sf::View view;
    std::shared_ptr<World> world;
    std::shared_ptr<Entity> player;
    std::vector<std::shared_ptr<sf::Texture>> textures = {};

};


#endif //TURBOHIKER_GAME_H
