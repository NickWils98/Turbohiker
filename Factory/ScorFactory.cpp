//
// Created by nick on 04.01.21.
//

#include "ScorFactory.h"

ScorFactory::ScorFactory(sf::RenderWindow& w, const sf::Color col,sf::View& v, std::string s, std::shared_ptr<sf::Font>& f)
        : view(v), window(w), color(col){
    text = s;
    font = f;
}

std::shared_ptr<Entity> ScorFactory::createProp(std::tuple<double, double> size, std::tuple<double, double> position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    std::tuple<int, int> s = t->logic_to_pixles(std::get<0>(size), std::get<1>(size));
    sf::Vector2f sfmlsize = sf::Vector2f(std::get<0>(s),std::get<1>(s));

    std::tuple<int, int> p = t->logic_to_pixles(std::get<0>(position), std::get<1>(position));
    sf::Vector2f sfmlposition = sf::Vector2f(std::get<0>(p),std::get<1>(p));

    std::shared_ptr<Entity> player = std::make_shared<TextFieldSFML>(TextFieldSFML(window, color, sfmlsize, sfmlposition, text, font));
    player->setPosition(std::get<0>(position), std::get<1>(position));
    player->setSize(std::get<0>(size)+4, std::get<1>(size)+3);
    player->setHeavynes(1);
    player->setGottrough(true);
    return player;
}