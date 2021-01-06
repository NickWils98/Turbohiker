//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKERSFML_H
#define TURBOHIKER_HIKERSFML_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Transformation.h"

class HikerSFML {


public:
    HikerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );

    ~HikerSFML();

    void render() ;
    bool updateVisuals(std::tuple<int, int> s, double);;


private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> tex;
};


#endif //TURBOHIKER_HIKERSFML_H
