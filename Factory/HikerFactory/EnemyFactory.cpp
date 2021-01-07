//
// Created by nick on 31.12.20.
//

#include "EnemyFactory.h"

EnemyFactory::EnemyFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v, const std::shared_ptr<LayoutFactory> &f)
        : view(v), window(w){
    fact = f;
    texture=t;
}

std::shared_ptr<Hiker> EnemyFactory::createHiker(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);

    std::shared_ptr<Hiker> player = std::make_shared<EnemySFML>(EnemySFML(window, texture, sfmlsize, sfmlposition, view));
    player->setPosition(position.x, position.y);
    player->setSize(size.x+4, size.y+3);
    player->setHeaviness(0.5);
    player->setFact(fact);
    player->setMaxspeed(100);
    player->setEnemy(true);
    return player;
}
