//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_LANESSFML_H
#define TURBOHIKER_LANESSFML_H


#include "../logic/Lanes.h"
#include <SFML/Graphics.hpp>

namespace turbohikerSFML {
    class LanesSFML : public turbohiker::Lanes {
    public:
        LanesSFML(sf::RenderWindow &window, sf::Color col, sf::Vector2f size, sf::Vector2f position);

        ~LanesSFML() override = default;

        void render() override;

        void moveToView(double) override;

        void setToupdate(bool t);

    private:
        sf::RectangleShape body;
        sf::RenderWindow &window;
//    lines that divide lanes should move with the view but the enline does not
        bool toupdate = false;
    };
}

#endif //TURBOHIKER_LANESSFML_H
