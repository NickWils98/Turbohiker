//
// Created by nick on 28.12.20.
//

#include "LineFactory.h"

LineFactory::LineFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v, bool m)
        : view(v), window(w), color(col), movable(m){

}

std::shared_ptr<Entity>  LineFactory::createProp(Coordinates size, Coordinates position) {
    std::shared_ptr<Transformation> t = t->getInstance();
    Coordinates s = t->logic_to_pixles(size.x, size.y);
    sf::Vector2f sfmlsize = sf::Vector2f(s.x,s.y);

    Coordinates p = t->logic_to_pixles(position.x, position.y);
    sf::Vector2f sfmlposition = sf::Vector2f(p.x,p.y);
    std::shared_ptr<LanesSFML> entity = std::make_shared<LanesSFML>(LanesSFML(window, color, sfmlsize, sfmlposition));
    entity->setToupdate(movable);
    return entity;
}