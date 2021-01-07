//
// Created by nick on 02.01.21.
//

#include "VerminFactory.h"
VerminFactory::VerminFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v)
        : view(v), window(w){

    texture=t;
}

std::shared_ptr<Hiker> VerminFactory::createHiker(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);

    std::shared_ptr<Hiker> player = std::make_shared<PassingSFML>(PassingSFML(window, texture, sfmlsize, sfmlposition, view));
    player->setPosition(position.x, position.y);
    player->setSize(size.x+4, size.y+3);
    player->setHeavynes(0);
    player->setGottrough(true);
    player->setSlowdown(true);
    player->setSpeed(70);
    player->setMaxspeed(70);
    player->setIsobstacle(true);
    return player;

}

