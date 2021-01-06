//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_VERMINFACTORY_H
#define TURBOHIKER_VERMINFACTORY_H

#include "HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../sfml/PassingSFML.h"

class VerminFactory : public HikerFactory {
public:
    VerminFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};



#endif //TURBOHIKER_VERMINFACTORY_H
