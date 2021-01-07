//
// Created by nick on 02.01.21.
//

#include "SpeechBubbleFactory.h"

SpeechBubbleFactory::SpeechBubbleFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v)
        : view(v), window(w){

    texture=t;
}

std::shared_ptr<Entity> SpeechBubbleFactory::createProp(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);

    std::shared_ptr<Entity> player = std::make_shared<SpeechBubbleSFML>(SpeechBubbleSFML(window, texture, sfmlsize, sfmlposition, view));
    player->setPosition(position.x, position.y);
    player->setSize(size.x+4, size.y+3);
    player->setHeaviness(1);
    player->setTransparant(true);
    return player;
}