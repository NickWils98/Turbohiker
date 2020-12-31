//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERENEMYSFML_H
#define TURBOHIKER_HIKERENEMYSFML_H


#include "HikerSFML.h"
#include "../logic/HikerPlayer.h"

class HikerEnemySFML : public HikerPlayer {
public:

    HikerEnemySFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );

    void render() override{sfml->render();};

    void updateVisuals(std::tuple<int, int> s) override {
        coordinats pos = getPosition();
        sfml->updateVisuals(s, pos.y);};
private:
    std::shared_ptr<HikerSFML> sfml;
};


#endif //TURBOHIKER_HIKERENEMYSFML_H
