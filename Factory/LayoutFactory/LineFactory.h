//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LINEFACTORY_H
#define TURBOHIKER_LINEFACTORY_H

#include "LayoutFactory.h"
#include "../../sfml/LanesSFML.h"
#include <SFML/Graphics.hpp>

class LineFactory : public LayoutFactory {
public:
    LineFactory(sf::RenderWindow& w, sf::Color col, sf::View& v, bool m);
    std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    const sf::Color color;
    bool movable;
};


#endif //TURBOHIKER_LINEFACTORY_H
