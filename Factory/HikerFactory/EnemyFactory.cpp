//
// Created by nick on 31.12.20.
//

#include "EnemyFactory.h"

EnemyFactory::EnemyFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v,
                           const std::shared_ptr<LayoutFactory> &f)
        : view(v), window(w) {
    fact = f;
    texture = t;
}

std::shared_ptr<Hiker> EnemyFactory::createHiker(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(static_cast<float>(s.x), static_cast<float>(s.y));

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(static_cast<float>(p.x), static_cast<float>(p.y));

    std::shared_ptr<Hiker> hiker = std::make_shared<EnemySFML>(
            EnemySFML(window, texture, sfmlsize, sfmlposition, view));
    hiker->setPosition(position.x, position.y);
    hiker->setSize(size.x + 4, size.y + 3);
    hiker->setHeaviness(0.5);
    hiker->setBubbleFact(fact);
    hiker->setMaxspeed(100);
    hiker->setEnemy(true);
    return hiker;
}
