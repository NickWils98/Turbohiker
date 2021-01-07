//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_KNIGHTFACTORY_H
#define TURBOHIKER_KNIGHTFACTORY_H

#include "../../../logic/Factories/HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../PassingSFML.h"

namespace turbohikerSFML {
    class KnightFactory : public turbohiker::HikerFactory {
    public:
        KnightFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v);

        std::shared_ptr<turbohiker::Hiker>
        createHiker(turbohiker::Coordinates size, turbohiker::Coordinates position) override;

    private:
        sf::RenderWindow &window;
        sf::View &view;
        std::shared_ptr<sf::Texture> texture;
    };
}

#endif //TURBOHIKER_KNIGHTFACTORY_H
