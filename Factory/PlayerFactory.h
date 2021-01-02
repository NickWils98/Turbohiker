//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_PLAYERFACTORY_H
#define TURBOHIKER_PLAYERFACTORY_H

#include "SFMLFactory.h"

class PlayerFactory : public SFMLFactory {
public:
    PlayerFactory(sf::RenderWindow& w, shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};


#endif //TURBOHIKER_PLAYERFACTORY_H
