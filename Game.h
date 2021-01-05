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
#include "Factory/SFMLFactory.h"
#include <iostream>
#include <fstream>

class Game {
public:
    Game();

    virtual ~Game();

    bool run();

    void init();

    void handleEvent();

    std::vector<int> getInput();

    double moveView(double, double);


    void DrawBackground(double);
    void desperate (int finished, int player);
    bool restart();
    void writeHighscore();
    void getHighscores();
private:
    std::shared_ptr<Transformation> t;
    sf::RenderWindow m_window;
    sf::View view;
    std::shared_ptr<World> world;
    std::vector<std::shared_ptr<sf::Texture>> textures = {};
    std::vector<sf::Sprite>backgrounds = {};
    std::vector<std::shared_ptr<sf::Font>> fonts = {};


    double deltaTime = 0;
    std::shared_ptr<RandomeNumber> r;
    int playercount = 0;
    bool goagain = false;
    std::vector<int> scores;

};


#endif //TURBOHIKER_GAME_H
