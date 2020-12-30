//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKERSFML_H
#define TURBOHIKER_HIKERSFML_H

#include <SFML/Graphics.hpp>
#include "../logic/Hiker.h"

class HikerSFML : public Hiker {


public:
    HikerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position);

    ~HikerSFML() override;

    void render() override ;
    void updateVisuals(std::tuple<int, int> s)override;
    double helpcout(){return body.getPosition().y;};



private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
};


#endif //TURBOHIKER_HIKERSFML_H
