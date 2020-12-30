//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_SFMLFACTORY_H
#define TURBOHIKER_SFMLFACTORY_H


#include "Factory.h"
#include "../sfml/LanesSFML.h"
#include <vector>
class SFMLFactory : public Factory {
public:
    SFMLFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture>& t) : window(w), tex(t){};
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;
    std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<double, double> size, std::tuple<double, double> position) override;

private:
    sf::RenderWindow& window;
    std::shared_ptr<sf::Texture> tex;
};


#endif //TURBOHIKER_SFMLFACTORY_H
