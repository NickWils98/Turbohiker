//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_SFMLPASSINGFACTORY_H
#define TURBOHIKER_SFMLPASSINGFACTORY_H

#include "SFMLFactory.h"
#include "../sfml/LanesSFML.h"
#include <vector>

class SFMLPassingFactory : public SFMLFactory {
public:
    SFMLPassingFactory(sf::RenderWindow& w, shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};



#endif //TURBOHIKER_SFMLPASSINGFACTORY_H
