//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_SPEECHBUBBLEFACTORY_H
#define TURBOHIKER_SPEECHBUBBLEFACTORY_H

#include "LayoutFactory.h"
#include "../../sfml/SpeechBubbleSFML.h"
#include <SFML/Graphics.hpp>

class SpeechBubbleFactory : public LayoutFactory {
public:
    SpeechBubbleFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Entity>  createProp(Coordinates size, Coordinates position) override;

private:
    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};



#endif //TURBOHIKER_SPEECHBUBBLEFACTORY_H
