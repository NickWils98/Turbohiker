//
// Created by nick on 28.12.20.
//

#include "LineFactory.h"

LineFactory::LineFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v, bool m)
        : view(v), window(w), color(col), movable(m){

}

std::shared_ptr<Entity>  LineFactory::createProp(std::tuple<double, double> size, std::tuple<double, double> position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    std::tuple<int, int> s = t->logic_to_pixles(std::get<0>(size), std::get<1>(size));
    sf::Vector2f sfmlsize = sf::Vector2f(std::get<0>(s), std::get<1>(s));


    std::tuple<int, int> p = t->logic_to_pixles(std::get<0>(position), std::get<1>(position));
    sf::Vector2f sfmlposition = sf::Vector2f(std::get<0>(p), std::get<1>(p));
    std::shared_ptr<LanesSFML> entity = std::make_shared<LanesSFML>(LanesSFML(window, color, sfmlsize, sfmlposition));
    entity->setToupdate(movable);
    return entity;
}