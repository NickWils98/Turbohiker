//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <memory>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../logic/Singletons/Transformation.h"
#include "../logic/Singletons/RandomeNumber.h"
#include "../logic/Entity.h"
#include "../logic/World.h"
#include "HikerSFML.h"
#include "Factories/HikerFactories/PlayerFactory.h"
#include "../logic/Factories/HikerFactory.h"
#include "Factories/HikerFactories/EnemyFactory.h"
#include "Factories/HikerFactories/KnightFactory.h"
#include "Factories/LayoutFactories/LineFactory.h"
#include "Factories/HikerFactories/VerminFactory.h"
#include "Factories/LayoutFactories/SpeechBubbleFactory.h"
#include "Factories/LayoutFactories/ScoreFactory.h"

namespace turbohikerSFML {
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
        std::shared_ptr<turbohiker::Transformation> t;
        std::shared_ptr<turbohiker::RandomeNumber> r;

        std::shared_ptr<turbohiker::World> world;

        sf::RenderWindow window;
        sf::View view;

        std::vector<std::shared_ptr<sf::Texture>> textures = {};
        std::vector<sf::Sprite> backgrounds = {};
        std::vector<std::shared_ptr<sf::Font>> fonts = {};

        int playercount = 0;
        std::vector<int> scores;

        bool restartGame = false;
    };
}

#endif //TURBOHIKER_GAME_H
