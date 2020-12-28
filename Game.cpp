//
// Created by nick on 27.12.20.
//

#include <iostream>
#include "Game.h"
#include "sfml/PlayerSFML.h"
#include "Factory/SFMLFactory.h"

Game::Game()
        :   m_window    (sf::VideoMode(300, 600), "Turbohiker",  sf::Style::Close | sf::Style::Resize){

    m_window.setFramerateLimit(60);
    world = std::make_shared<World>();
    t = Transformation::getInstance();
    t->changeWindow(300, 600);

}

Game::~Game() {

}

void Game::run() {

    init();
    //Main loop of the game
    while (m_window.isOpen()) {

        //Render
        m_window.clear(sf::Color(244, 69, 0, 255));
        //m_window.setView(view);

        world->render();
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
/*ini graphics TODO:move to world*/
    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    tex->loadFromFile("./../zombie.png");
    textures.push_back(tex);
    //TODO: fix pointer
    std::shared_ptr<Factory> factory = std::make_shared<SFMLFactory>(m_window);
    player = std::make_shared<PlayerSFML>(m_window, tex);
    //player = factory->createHiker(m_window, tex);
    world->add(player);
    world->addLane(factory, 5);
    std::cout<<"test";


}
std::vector<bool> Game::getInput() {
    std::vector<bool> input = {};

    //input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
    //input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
    input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
    //input.push_back(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    return input;
}