//
// Created by nick on 31.12.20.
//

#ifndef TURBOHIKER_SFMLENEMYFACTORY_H
#define TURBOHIKER_SFMLENEMYFACTORY_H


#include "SFMLFactory.h"

class SFMLEnemyFactory : public SFMLFactory {
public:
    SFMLEnemyFactory(sf::RenderWindow& w, std::shared_ptr<sf::Texture> &t, sf::View& v);
    std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) override;

    void setFact(const std::shared_ptr<FactoryLines> &fact);

private:


    sf::RenderWindow& window;
    sf::View& view;
    std::shared_ptr<sf::Texture> texture;private:
    std::shared_ptr<FactoryLines> fact = nullptr;

};


#endif //TURBOHIKER_SFMLENEMYFACTORY_H
