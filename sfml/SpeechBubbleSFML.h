//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_SPEECHBUBBLESFML_H
#define TURBOHIKER_SPEECHBUBBLESFML_H

#include <SFML/Graphics.hpp>
#include "../logic/Balloon.h"
namespace turbohikerSFML {
    class SpeechBubbleSFML : public turbohiker::Balloon {
    public:
        SpeechBubbleSFML(sf::RenderWindow &w, const std::shared_ptr<sf::Texture> &tex, sf::Vector2f size,
                         sf::Vector2f position, sf::View &);

        void render() override;

        void updateVisuals(turbohiker::Coordinates s) override;


    private:
        sf::RectangleShape body;
        sf::RenderWindow &window;
        sf::View &view;
    };
}

#endif //TURBOHIKER_SPEECHBUBBLESFML_H
