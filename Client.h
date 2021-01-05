//
// Created by nick on 04.01.21.
//

#ifndef TURBOHIKER_CLIENT_H
#define TURBOHIKER_CLIENT_H


#include "Observer.h"
#include "Subject.h"

/**
 * a client that implements the Observer interface
 */
class Client : public Observer {
    double score = 0;
public:

    Client(){};

    virtual void update(int s) override;

    int getScore() override;

};


#endif //TURBOHIKER_CLIENT_H
