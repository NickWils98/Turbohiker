//
// Created by nick on 04.01.21.
//

#include "ScoreFactory.h"

ScoreFactory::ScoreFactory(sf::RenderWindow &w, const sf::Color col, sf::View &v, std::string s,
                           std::shared_ptr<sf::Font> &f, bool u)
        : view(v), window(w), color(col) {
    text = std::move(s);
    font = f;
    toupdate = u;
}

std::shared_ptr<Entity> ScoreFactory::createProp(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(static_cast<float>(p.x), static_cast<float>(p.y));

    std::shared_ptr<Entity> enitity = std::make_shared<TextFieldSFML>(
            TextFieldSFML(window, color, sfmlposition, text, font, toupdate));
    enitity->setPosition(position.x, position.y);
    enitity->setSize(size.x + 4, size.y + 3);
    enitity->setHeaviness(1);
    enitity->setTransparant(true);
    return enitity;
}