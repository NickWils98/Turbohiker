//
// Created by nick on 31.12.20.
//

#include "SFMLEnemyFactory.h"

SFMLEnemyFactory::SFMLEnemyFactory(sf::RenderWindow& w, shared_ptr<sf::Texture> &t, sf::View& v)
        : view(v), window(w){

    texture=t;
}

std::shared_ptr<Hiker> SFMLEnemyFactory::createHiker(std::tuple<double, double> size, std::tuple<double, double> position) {
    Transformation *t = t->getInstance();
    std::tuple<int, int> s = t->logic_to_pixles(std::get<0>(size), std::get<1>(size));
    sf::Vector2f sfmlsize = sf::Vector2f(std::get<0>(s),std::get<1>(s));

    std::tuple<int, int> p = t->logic_to_pixles(std::get<0>(position), std::get<1>(position));
    sf::Vector2f sfmlposition = sf::Vector2f(std::get<0>(p),std::get<1>(p));

    std::shared_ptr<Hiker> player = std::make_shared<HikerEnemySFML>(HikerEnemySFML(window, texture, sfmlsize, sfmlposition, view));
    player->setPosition(std::get<0>(position), std::get<1>(position));
    player->setSize(std::get<0>(size), std::get<1>(size));
    player->setHeavynes(0.5);
    return player;
}
