//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_ENEMYSFML_H
#define TURBOHIKER_ENEMYSFML_H


#include "HikerSFML.h"
#include "../logic/HikerEnemy.h"

class EnemySFML : public HikerEnemy {
public:

    EnemySFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );

    void render() override{sfml->render();};

    void updateVisuals(Coordinates s) override;
private:
    std::shared_ptr<HikerSFML> sfml;
};


#endif //TURBOHIKER_ENEMYSFML_H
