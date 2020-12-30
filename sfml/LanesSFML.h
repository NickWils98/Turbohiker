//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANESSFML_H
#define TURBOHIKER_LANESSFML_H


#include "../logic/Lanes.h"
#include <SFML/Graphics.hpp>

class LanesSFML : public Lanes {
public:
    LanesSFML(sf::RenderWindow& window, sf::Color col, sf::Vector2f size, sf::Vector2f position);
    ~LanesSFML();

    void render();
    void movetoview(double) override;
private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
};


#endif //TURBOHIKER_LANESSFML_H
