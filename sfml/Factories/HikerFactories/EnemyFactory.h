//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_ENEMYFACTORY_H
#define TURBOHIKER_ENEMYFACTORY_H


#include "../../../logic/Factories/HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../EnemySFML.h"
namespace turbohikerSFML {
    class EnemyFactory : public turbohiker::HikerFactory {
    public:
        EnemyFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v,
                     const std::shared_ptr<turbohiker::LayoutFactory> &f);

        std::shared_ptr<turbohiker::Hiker> createHiker(turbohiker::Coordinates size, turbohiker::Coordinates position) override;


    private:


        sf::RenderWindow &window;
        sf::View &view;
        std::shared_ptr<sf::Texture> texture;
    private:
        std::shared_ptr<turbohiker::LayoutFactory> fact = nullptr;

    };
}

#endif //TURBOHIKER_ENEMYFACTORY_H
