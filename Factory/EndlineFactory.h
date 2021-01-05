//
// Created by nick on 05.01.21.
//

#ifndef TURBOHIKER_ENDLINEFACTORY_H
#define TURBOHIKER_ENDLINEFACTORY_H


#include "FactoryLines.h"
#include "../sfml/LanesSFML.h"
#include <vector>

class EndlineFactory : public FactoryLines {
public:
    EndlineFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v);
    std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    const sf::Color color;
};

#endif //TURBOHIKER_ENDLINEFACTORY_H
