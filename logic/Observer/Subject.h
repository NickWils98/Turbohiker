//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_SUBJECT_H
#define TURBOHIKER_SUBJECT_H

#include "SubjectInterface.h"
#include "ObserverInterface.h"

/**
 * A concrete implementation of the SubjectInterface interface
 */
class Subject : public SubjectInterface {
    int value = 0;
public:
    ~Subject() override;

    std::vector<std::shared_ptr<ObserverInterface>> observers;

    void registerObserver(std::shared_ptr<ObserverInterface> &observer) override;

    void notifyObservers() override;

    void setScore(int s) override;

};

#endif //TURBOHIKER_SUBJECT_H
