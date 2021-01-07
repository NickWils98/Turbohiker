//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SUBJECTINTERFACE_H
#define TURBOHIKER_SUBJECTINTERFACE_H

#include "ObserverInterface.h"
#include <memory>
#include <vector>
#include <algorithm>


class SubjectInterface {

public:

    virtual ~SubjectInterface() = default;

    virtual void registerObserver(std::shared_ptr<ObserverInterface> &observer) = 0;

    virtual void notifyObservers() = 0;

    virtual void setScore(int) = 0;

};


#endif //TURBOHIKER_SUBJECTINTERFACE_H
