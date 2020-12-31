//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "logic/Entity.h"
#include "logic/World.h"
#include "Factory/PlayerFactory.h"
#include "Factory/Factory.h"
#include "Transformation.h"
#include "RandomeNumber.h"


class Game {
public:
    Game();

    virtual ~Game();

    void run();

    void init();

    void handleEvent();

    std::vector<int> getInput();

    double moveView(double, double);


    void DrawBackground(double);
private:
    Transformation *t;
    sf::RenderWindow m_window;
    sf::View view;
    std::shared_ptr<World> world;
    std::vector<std::shared_ptr<sf::Texture>> textures = {};
    std::vector<sf::Sprite>backgrounds = {};

    double deltaTime = 0;
    RandomeNumber *r;

};


#endif //TURBOHIKER_GAME_H
