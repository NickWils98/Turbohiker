//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_PASSINGSFML_H
#define TURBOHIKER_PASSINGSFML_H


#include "../logic/HikerPassing.h"
#include "HikerSFML.h"

class PassingSFML : public HikerPassing  {
public:
    PassingSFML(sf::RenderWindow& w, const std::shared_ptr<sf::Texture>& tex, sf::Vector2f size, sf::Vector2f position, sf::View& );

    void render() override{sfml->render();};

    bool updateVisuals(std::tuple<int, int> s) override;
private:
    std::shared_ptr<HikerSFML> sfml;
};


#endif //TURBOHIKER_PASSINGSFML_H
