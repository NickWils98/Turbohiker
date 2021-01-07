//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_OBSERVER_H
#define TURBOHIKER_OBSERVER_H


#include "ObserverInterface.h"
#include "SubjectInterface.h"

namespace turbohiker {
/**
 * a client that implements the ObserverInterface interface
 */
    class Observer : public ObserverInterface {
        double score = 0;
    public:

        Observer() = default;

        void update(int s) override;

        int getScore() override;

    };
}

#endif //TURBOHIKER_OBSERVER_H
