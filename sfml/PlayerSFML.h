//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_PLAYERSFML_H
#define TURBOHIKER_PLAYERSFML_H


#include "../logic/HikerPlayer.h"
#include "HikerSFML.h"

namespace turbohikerSFML {
    class PlayerSFML : public turbohiker::HikerPlayer {
    public:
        PlayerSFML(sf::RenderWindow &w, const std::shared_ptr<sf::Texture> &tex, sf::Vector2f size,
                   sf::Vector2f position,
                   sf::View &);

        void render() override { sfml->render(); };

        void updateVisuals(turbohiker::Coordinates s) override;

    private:
        std::shared_ptr<HikerSFML> sfml;
    };
}

#endif //TURBOHIKER_PLAYERSFML_H
