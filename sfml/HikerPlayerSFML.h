//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_HIKERPLAYERSFML_H
#define TURBOHIKER_HIKERPLAYERSFML_H


#include "../logic/HikerPlayer.h"
#include "HikerSFML.h"

class HikerPlayerSFML : public HikerPlayer  {
public:
    HikerPlayerSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );

    void render() override{sfml->render();};

    bool updateVisuals(std::tuple<int, int> s) override {
        coordinats pos = getPosition();
        return sfml->updateVisuals(s, pos.y);};
private:
    std::shared_ptr<HikerSFML> sfml;
};


#endif //TURBOHIKER_HIKERPLAYERSFML_H
