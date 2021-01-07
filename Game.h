//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <memory>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "logic/Singletons/Transformation.h"
#include "logic/Singletons/RandomeNumber.h"
#include "logic/Entity.h"
#include "logic/World.h"
#include "sfml/HikerSFML.h"
#include "Factory/HikerFactory/PlayerFactory.h"
#include "Factory/HikerFactory/HikerFactory.h"
#include "Factory/HikerFactory/EnemyFactory.h"
#include "Factory/HikerFactory/KnightFactory.h"
#include "Factory/LayoutFactory/LineFactory.h"
#include "Factory/HikerFactory/VerminFactory.h"
#include "Factory/LayoutFactory/SpeechBubbleFactory.h"
#include "Factory/LayoutFactory/ScoreFactory.h"

class Game {
public:
    Game();

    ~Game();

    bool run();

private:
    void handleEvent();

    static double handleFrames(std::clock_t beginRound, std::clock_t startTime);

    void init();

    void initBackground();

    void initStartPosition();

    void initObstacles();

    static std::vector<int> getInput();

    static bool restartInput();

    double moveView();

    int calculateViewAdjustment();

    void drawBackground();

    void endLoop(int finished, int player);

    std::vector<sf::Text> getScoreScreen(int placement, int score);

    void writeHighscore();

    void getHighscores();

private:
    std::shared_ptr<Transformation> t;
    std::shared_ptr<RandomeNumber> r;

    std::shared_ptr<World> world;

    sf::RenderWindow window;
    sf::View view;

    std::vector<std::shared_ptr<sf::Texture>> textures = {};
    std::vector<sf::Sprite> backgrounds = {};
    std::vector<std::shared_ptr<sf::Font>> fonts = {};

    int playercount = 0;
    std::vector<int> scores;

    bool restartGame = false;
};


#endif //TURBOHIKER_GAME_H
