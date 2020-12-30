//
// Created by nick on 27.12.20.
//

#include "HikerSFML.h"
HikerSFML::HikerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position)
        : window(w)
{
    body.setTexture(tex.get());
    body.setPosition(position);
    body.setSize(size);
    body.setOrigin(size/2.0f);

}



void HikerSFML::render() {
    window.draw(body);
}

void HikerSFML::updateVisuals(std::tuple<int, int> pos) {
    sf::Vector2f sfmlpos = sf::Vector2f(std::get<0>(pos),std::get<1>(pos));

    body.move(sfmlpos);
    sf::Vector2f fff = body.getPosition();


}


HikerSFML::~HikerSFML() = default;


