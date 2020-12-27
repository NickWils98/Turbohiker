//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITYSFML_H
#define TURBOHIKER_ENTITYSFML_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class EntitySFML : public Entity {


public:
    EntitySFML(sf::RenderWindow& w, std::shared_ptr<sf::Texture> tex);

    ~EntitySFML() override;

    void render() override ;

    void update() override ;

private:
    sf::RectangleShape body;
    sf::RenderWindow& window;
};


#endif //TURBOHIKER_ENTITYSFML_H
