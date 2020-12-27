//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_GAME_H
#define TURBOHIKER_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>


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

};


#endif //TURBOHIKER_GAME_H
