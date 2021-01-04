//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_TEXTBALLOON_H
#define TURBOHIKER_TEXTBALLOON_H

#include "FactoryLines.h"
#include "../sfml/BalloonSFML.h"
#include <vector>

class TextBalloon : public FactoryLines {
public:
    TextBalloon(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;
};



#endif //TURBOHIKER_TEXTBALLOON_H
