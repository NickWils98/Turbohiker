//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SCORFACTORY_H
#define TURBOHIKER_SCORFACTORY_H

#include "FactoryLines.h"
#include "../sfml/TextFieldSFML.h"
#include <vector>

class ScorFactory : public FactoryLines {
public:
    ScorFactory(sf::RenderWindow& w, const sf::Color col, sf::View& v, std::string s, std::shared_ptr<sf::Font>& f);
    std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    const sf::Color color;
    std::string text;
    std::shared_ptr<sf::Font> font;

};




#endif //TURBOHIKER_SCORFACTORY_H
