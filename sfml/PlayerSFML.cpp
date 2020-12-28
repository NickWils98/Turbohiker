//
// Created by nick on 27.12.20.
//

#include "PlayerSFML.h"
PlayerSFML::PlayerSFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex)
        : window(w)
{
    body.setTexture(tex.get());
    body.setPosition(150,300);
    sf::Vector2f s = sf::Vector2f(20,35);
    body.setSize(s);
    body.setOrigin(s/2.0f);

}



void PlayerSFML::render() {
    window.draw(body);
}

void PlayerSFML::update() {

}

PlayerSFML::~PlayerSFML() = default;


