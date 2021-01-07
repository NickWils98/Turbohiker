//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SCOREFACTORY_H
#define TURBOHIKER_SCOREFACTORY_H

#include "../../../logic/Factories/LayoutFactory.h"
#include "../../TextFieldSFML.h"
#include <SFML/Graphics.hpp>

namespace turbohikerSFML {
    class ScoreFactory : public turbohiker::LayoutFactory {
    public:
        ScoreFactory(sf::RenderWindow &w, sf::Color col, sf::View &v, std::string s, std::shared_ptr<sf::Font> &f,
                     bool);

        std::shared_ptr<turbohiker::Entity>
        createProp(turbohiker::Coordinates size, turbohiker::Coordinates position) override;


    private:


        sf::RenderWindow &window;
        sf::View &view;
        const sf::Color color;
        std::string text;
        std::shared_ptr<sf::Font> font;
        bool toupdate = false;

    };
}

#endif //TURBOHIKER_SCOREFACTORY_H
