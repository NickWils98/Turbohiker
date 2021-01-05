//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SUBJECT_H
#define TURBOHIKER_SUBJECT_H

#include "Observer.h"
#include <memory>


class Subject {

public:

    virtual ~Subject(){};
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;


    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;


    virtual void notifyObservers() = 0;
    virtual void setScore(int ) = 0;

};



#endif //TURBOHIKER_SUBJECT_H
