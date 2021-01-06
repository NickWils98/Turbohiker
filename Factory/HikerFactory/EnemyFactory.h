//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_ENEMYFACTORY_H
#define TURBOHIKER_ENEMYFACTORY_H


#include "HikerFactory.h"
#include <SFML/Graphics.hpp>
#include "../../sfml/EnemySFML.h"

class EnemyFactory : public HikerFactory {
public:
    EnemyFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v, const std::shared_ptr<LayoutFactory> &f);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;


private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;private:
    std::shared_ptr<LayoutFactory> fact = nullptr;

};


#endif //TURBOHIKER_ENEMYFACTORY_H
