//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_SFMLFACTORY_H
#define TURBOHIKER_SFMLFACTORY_H


#include "Factory.h"
#include "../sfml/LanesSFML.h"
#include "../sfml/HikerSFML.h"
#include "../sfml/HikerPlayerSFML.h"
#include "../sfml/HikerEnemySFML.h"
#include <vector>
class SFMLFactory : public Factory {
public:
    SFMLFactory(sf::RenderWindow& w, sf::View& v) : window(w), view(v){};
    std::shared_ptr<Hiker>  createHikerPlayer(std::tuple<double, double> size, std::tuple<double, double> position) override;
    std::shared_ptr<Hiker>  createHikerEnemy(std::tuple<double, double> size, std::tuple<double, double> position) override;
    std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<double, double> size, std::tuple<double, double> position) override;


    void setPlayertext(const shared_ptr<sf::Texture> &playertext);

    void setTextures(const std::shared_ptr<sf::Texture> &textures);

private:
    sf::RenderWindow& window;
    std::shared_ptr<sf::Texture> tex;
    sf::View& view;
    std::shared_ptr<sf::Texture> playertext;
    std::vector<std::shared_ptr<sf::Texture>> textures;
};


#endif //TURBOHIKER_SFMLFACTORY_H
