//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_OBSERVER_H
#define TURBOHIKER_OBSERVER_H


class Observer {
public:

    virtual ~Observer(){};
    virtual void update(int s) = 0;
    virtual int getScore() = 0;
};


#endif //TURBOHIKER_OBSERVER_H
