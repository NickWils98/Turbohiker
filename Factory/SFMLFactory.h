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
#include "../sfml/HikerPassingSFML.h"
#include <vector>
class SFMLFactory : public Factory {
public:
    SFMLFactory(){};
    virtual std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) = 0;


};


#endif //TURBOHIKER_SFMLFACTORY_H
