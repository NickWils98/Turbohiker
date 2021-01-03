//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANEFACTORY_H
#define TURBOHIKER_LANEFACTORY_H

#include "FactoryLines.h"
#include "../sfml/LanesSFML.h"
#include <vector>

class LaneFactory : public FactoryLines {
public:
    LaneFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v);
    std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    const sf::Color color;
};


#endif //TURBOHIKER_LANEFACTORY_H
