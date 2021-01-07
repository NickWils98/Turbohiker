//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_SPEECHBUBBLEFACTORY_H
#define TURBOHIKER_SPEECHBUBBLEFACTORY_H

#include "../../../logic/Factories/LayoutFactory.h"
#include "../../SpeechBubbleSFML.h"
#include <SFML/Graphics.hpp>
namespace turbohikerSFML {
    class SpeechBubbleFactory : public turbohiker::LayoutFactory {
    public:
        SpeechBubbleFactory(sf::RenderWindow &w, std::shared_ptr<sf::Texture> &t, sf::View &v);

        std::shared_ptr<turbohiker::Entity> createProp(turbohiker::Coordinates size, turbohiker::Coordinates position) override;

    private:
        sf::RenderWindow &window;
        sf::View &view;
        std::shared_ptr<sf::Texture> texture;
    };
}

#endif //TURBOHIKER_SPEECHBUBBLEFACTORY_H
