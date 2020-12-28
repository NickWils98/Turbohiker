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
    SFMLFactory(sf::RenderWindow& w) : window(w){};
    std::shared_ptr<Entity>  createHiker(std::shared_ptr<sf::Texture>) override;
    std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<float, float> size, std::tuple<float, float> position) override;

private:
    sf::RenderWindow& window;
};


#endif //TURBOHIKER_SFMLFACTORY_H
