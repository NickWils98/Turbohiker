//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_PLAYERSFML_H
#define TURBOHIKER_PLAYERSFML_H

#include <SFML/Graphics.hpp>
#include "../logic/player.h"

class PlayerSFML : public player {


public:
    PlayerSFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex);

    ~PlayerSFML() override;

    void render() override ;

    void update() override ;


private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
};


#endif //TURBOHIKER_PLAYERSFML_H
