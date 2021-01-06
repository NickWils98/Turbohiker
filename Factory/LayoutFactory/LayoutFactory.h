//
// Created by nick on 02.01.21.
//

#ifndef TURBOHIKER_LAYOUTFACTORY_H
#define TURBOHIKER_LAYOUTFACTORY_H

#include <memory>
#include <vector>
#include "../../logic/Entity.h"
#include "../../Transformation.h"
class LayoutFactory {
public:
    virtual std::shared_ptr<Entity>  createProp(std::tuple<double, double> size, std::tuple<double, double> position) = 0;

};


#endif //TURBOHIKER_LAYOUTFACTORY_H
