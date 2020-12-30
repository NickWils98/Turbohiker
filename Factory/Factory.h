//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_FACTORY_H
#define TURBOHIKER_FACTORY_H

#include <memory>
#include "../logic/Entity.h"
#include "../sfml/HikerSFML.h"
#include "../logic/ColorLogic.h"
#include "../Transformation.h"


class Factory {
public:
    virtual std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) = 0;
    virtual std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<double, double> size, std::tuple<double, double> position) = 0;

};


#endif //TURBOHIKER_FACTORY_H
