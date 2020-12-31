//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_SFMLWANDERERFACTORY_H
#define TURBOHIKER_SFMLWANDERERFACTORY_H

#include "Factory.h"
#include "../sfml/LanesSFML.h"
#include <vector>

/*class SFMLWandererFactory : public Factory {
public:
    SFMLWandererFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture>& t, sf::View& v) : window(w), tex(t), view(v){};
    std::shared_ptr<Hiker>  createHikerPlayer(std::tuple<double, double> size, std::tuple<double, double> position) override;
    std::shared_ptr<Hiker>  createHikerEnemy(std::tuple<double, double> size, std::tuple<double, double> position) override;
    std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<double, double> size, std::tuple<double, double> position) override;

private:
    sf::RenderWindow& window;
    std::shared_ptr<sf::Texture> tex;
    sf::View& view;
};*/


#endif //TURBOHIKER_SFMLWANDERERFACTORY_H
