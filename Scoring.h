//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SCORING_H
#define TURBOHIKER_SCORING_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "Subject.h"
#include "Observer.h"

/**
 * A concrete implementation of the Subject interface
 */
class Scoring : public Subject {
    std::vector<std::shared_ptr<Observer>> observers;

    int value = 0;

public:

    void registerObserver(std::shared_ptr<Observer> observer) override;

    void removeObserver(std::shared_ptr<Observer> observer) override;

    void notifyObservers() override;

    void setScore(int s) override;

};

#endif //TURBOHIKER_SCORING_H
