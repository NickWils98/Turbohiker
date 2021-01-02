//
// Created by nick on 28.12.20.
//

#ifndef TURBOHIKER_FACTORY_H
#define TURBOHIKER_FACTORY_H

#include <memory>
#include "../logic/Entity.h"
#include "../logic/ColorLogic.h"
#include "../Transformation.h"
#include "../logic/Hiker.h"


class Factory {
public:
//    virtual std::shared_ptr<Hiker>  createHiker(std::tuple<double, double> size, std::tuple<double, double> position) = 0;
    virtual std::shared_ptr<Entity>  addLane(ColorLogic col, std::tuple<double, double> size, std::tuple<double, double> position) = 0;
    virtual std::shared_ptr<Hiker>  createHikerPlayer(std::tuple<double, double> size, std::tuple<double, double> position) = 0;
    virtual std::shared_ptr<Hiker>  createHikerEnemy(std::tuple<double, double> size, std::tuple<double, double> position) = 0;
    virtual std::shared_ptr<Hiker>  createHikerPassing(std::tuple<double, double> size, std::tuple<double, double> position) =0;

};


#endif //TURBOHIKER_FACTORY_H
