//
// Created by nick on 27.12.20.
//

#include "EntitySFML.h"
EntitySFML::EntitySFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex)
        : window(w)
{
    body.setTexture(tex.get());
    body.setPosition(200,300);
    sf::Vector2f s = sf::Vector2f(20,35);
    body.setSize(s);
    body.setOrigin(s/2.0f);

}



void EntitySFML::render() {
    window.draw(body);
}

void EntitySFML::update() {

}

EntitySFML::~EntitySFML() = default;

