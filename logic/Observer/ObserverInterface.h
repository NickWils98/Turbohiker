//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_OBSERVERINTERFACE_H
#define TURBOHIKER_OBSERVERINTERFACE_H


class ObserverInterface {
public:

    virtual ~ObserverInterface() = default;

    virtual void update(int s) = 0;

    virtual int getScore() = 0;
};


#endif //TURBOHIKER_OBSERVERINTERFACE_H
