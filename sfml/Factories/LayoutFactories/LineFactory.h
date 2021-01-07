//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LINEFACTORY_H
#define TURBOHIKER_LINEFACTORY_H

#include "../../../logic/Factories/LayoutFactory.h"
#include "../../LanesSFML.h"
#include <SFML/Graphics.hpp>
namespace turbohikerSFML {
    class LineFactory : public turbohiker::LayoutFactory {
    public:
        LineFactory(sf::RenderWindow &w, sf::Color col, sf::View &v, bool m);

        std::shared_ptr<turbohiker::Entity> createProp(turbohiker::Coordinates size, turbohiker::Coordinates position) override;


    private:


        sf::RenderWindow &window;
        sf::View &view;
        const sf::Color color;
        bool movable;
    };
}

#endif //TURBOHIKER_LINEFACTORY_H
