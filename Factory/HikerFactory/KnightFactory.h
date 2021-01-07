//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_KNIGHTFACTORY_H
#define TURBOHIKER_KNIGHTFACTORY_H

#include "HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../sfml/PassingSFML.h"

class KnightFactory : public HikerFactory {
public:
    KnightFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v);

    std::shared_ptr<Hiker> createHiker(Coordinates size, Coordinates position) override;

private:
    sf::RenderWindow &window;
    sf::View &view;
    std::shared_ptr<sf::Texture> texture;
};


#endif //TURBOHIKER_KNIGHTFACTORY_H
