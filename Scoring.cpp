//
// Created by nick on 04.01.21.
//

#include "Scoring.h"

void Scoring::registerObserver(std::shared_ptr<Observer> observer) {
    observers.push_back(observer);
}

void Scoring::removeObserver(std::shared_ptr<Observer> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer));

}

void Scoring::notifyObservers() {
    for(auto o : observers){
        o->update(value);
    }
}

void Scoring::setScore(int s) {
    value = s;
    notifyObservers();
}
