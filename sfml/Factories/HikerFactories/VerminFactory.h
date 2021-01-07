//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_VERMINFACTORY_H
#define TURBOHIKER_VERMINFACTORY_H

#include "../../../logic/Factories/HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../PassingSFML.h"

namespace turbohikerSFML {
    class VerminFactory : public turbohiker::HikerFactory {
    public:
        VerminFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v);

        std::shared_ptr<turbohiker::Hiker>
        createHiker(turbohiker::Coordinates size, turbohiker::Coordinates position) override;

    private:
        sf::RenderWindow &window;
        sf::View &view;
        std::shared_ptr<sf::Texture> texture;
    };
}

#endif //TURBOHIKER_VERMINFACTORY_H
