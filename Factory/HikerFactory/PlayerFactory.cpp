//
// Created by nick on 28.12.20.
//

#include "PlayerFactory.h"

PlayerFactory::PlayerFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v, const std::shared_ptr<LayoutFactory> &f)
        : view(v), window(w){

    texture=t;
    fact = f;
}

std::shared_ptr<Hiker> PlayerFactory::createHiker(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);
    std::shared_ptr<Hiker> player = std::make_shared<PlayerSFML>(PlayerSFML(window, texture, sfmlsize, sfmlposition, view));
    player->setPosition(position.x, position.y);
    player->setSize(size.x+4, size.y+3);

    player->setHeavynes(0.5);
    player->setFact(fact);
    return player;
}

