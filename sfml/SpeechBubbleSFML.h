//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_SPEECHBUBBLESFML_H
#define TURBOHIKER_SPEECHBUBBLESFML_H

#include "HikerSFML.h"
#include "../logic/Balloon.h"
class SpeechBubbleSFML : public Balloon {


public:
    SpeechBubbleSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );
    void render() override;
    bool updateVisuals(std::tuple<int, int> s) override;


private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> tex;
};


#endif //TURBOHIKER_SPEECHBUBBLESFML_H
