//
// Created by nick on 31.12.20.
//

#include "HikerPlayerSFML.h"
HikerPlayerSFML::HikerPlayerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position,sf::View& v)
        : sfml(std::make_shared<HikerSFML>(w, tex, size, position, v))
{


}