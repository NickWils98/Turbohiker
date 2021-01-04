//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_SFMLWANDERERFACTORY_H
#define TURBOHIKER_SFMLWANDERERFACTORY_H

#include "SFMLFactory.h"
#include "../sfml/LanesSFML.h"
#include <vector>

class SFMLWandererFactory : public SFMLFactory {
public:
    SFMLWandererFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};


#endif //TURBOHIKER_SFMLWANDERERFACTORY_H
