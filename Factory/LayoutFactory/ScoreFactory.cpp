//
// Created by nick on 04.01.21.
//

#include "ScoreFactory.h"

#include <utility>

ScoreFactory::ScoreFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v, std::string s, std::shared_ptr<sf::Font>& f, bool u)
        : view(v), window(w), color(col){
    text = std::move(s);
    font = f;
    toupdate = u;
}

std::shared_ptr<Entity> ScoreFactory::createProp(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);

    std::shared_ptr<Entity> player = std::make_shared<TextFieldSFML>(TextFieldSFML(window, color, sfmlposition, text, font, toupdate));
    player->setPosition(position.x, position.y);
    player->setSize(size.x+4, size.y+3);
    player->setHeaviness(1);
    player->setTransparant(true);
    return player;
}