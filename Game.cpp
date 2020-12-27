//
// Created by nick on 27.12.20.
//

#include "Game.h"
Game::Game()
        :   m_window    (sf::VideoMode(514, 431), "Turbohiker",  sf::Style::Close | sf::Style::Resize),
            view(m_window.getDefaultView()) {

    m_window.setFramerateLimit(60);
}

Game::~Game() {

}

void Game::run() {

    //init();
    //Main loop of the game
    while (m_window.isOpen()) {

        //Render
        m_window.clear();
        m_window.setView(view);
        m_window.display();

        //Handle window events
        handleEvent();
    }
}


void Game::handleEvent() {
    sf::Event evnt;

    while (m_window.pollEvent(evnt)) {
        switch (evnt.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                break;
            default:
                break;

        }
    }
}

void Game::init() {
/*ini graphics*/
}
