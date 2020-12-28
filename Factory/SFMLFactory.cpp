//
// Created by nick on 28.12.20.
//

#include "SFMLFactory.h"

std::shared_ptr<Entity> SFMLFactory::createHiker(std::shared_ptr<sf::Texture>) {
    return std::shared_ptr<Entity>();
}

std::shared_ptr<Entity>  SFMLFactory::addLane(ColorLogic col, std::tuple<float, float> size,std::tuple<float, float> position) {
    Transformation *t = t->getInstance();
    std::tuple<int, int> s = t->logic_to_pixles(std::get<0>(size), std::get<1>(size));
    sf::Vector2f sfmlsize = sf::Vector2f(std::get<0>(s),std::get<1>(s));
    std::vector<int> colors = col.getColors();
    sf::Color color = sf::Color(colors[0], colors[1], colors[2]);

    std::tuple<int, int> p = t->logic_to_pixles(std::get<0>(position), std::get<1>(position));
    sf::Vector2f sfmlposition = sf::Vector2f(std::get<0>(p),std::get<1>(p));
    std::shared_ptr<Entity> entity = std::make_shared<LanesSFML>(LanesSFML(window, color, sfmlsize, sfmlposition));
    return entity;
}
