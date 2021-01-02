//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_FACTORYLINES_H
#define TURBOHIKER_FACTORYLINES_H

#include <memory>
#include "../logic/Entity.h"
#include "../logic/ColorLogic.h"
#include "../Transformation.h"
#include "../logic/Hiker.h"
class FactoryLines {
public:
    virtual std::shared_ptr<Entity>  createLane(std::tuple<double, double> size, std::tuple<double, double> position) = 0;

};


#endif //TURBOHIKER_FACTORYLINES_H
