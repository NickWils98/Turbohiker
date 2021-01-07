//
// Created by nick on 02.01.21.
//

#include "VerminFactory.h"

VerminFactory::VerminFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v)
        : view(v), window(w) {

    texture = t;
}

std::shared_ptr<Hiker> VerminFactory::createHiker(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y));

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(static_cast<float>(p.x), static_cast<float>(p.y));

    std::shared_ptr<Hiker> hiker = std::make_shared<PassingSFML>(
            PassingSFML(window, texture, sfmlsize, sfmlposition, view));
    hiker->setPosition(position.x, position.y);
    hiker->setSize(size.x + 4, size.y + 3);
    hiker->setHeaviness(0);
    hiker->setTransparant(true);
    hiker->setSlowedDown(true);
    hiker->setSpeedv(70);
    hiker->setMaxspeed(70);
    hiker->setObstacle(true);
    return hiker;

}

