//
// Created by nick on 30.12.20.
//

#ifndef TURBOHIKER_RANDOMENUMBER_H
#define TURBOHIKER_RANDOMENUMBER_H
#include <random>
#include<iostream>
#include<stdlib.h>

class RandomeNumber {
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
    static RandomeNumber *instance;

    // Private constructor so that no objects can be created.
    RandomeNumber(){
        std::mt19937 gen2(rd());
        gen = gen2;

        std::uniform_int_distribution<> distrib2(1,100);
        distrib = distrib2;



    };

public:
    static RandomeNumber *getInstance() {
        if (!instance)
            instance = new RandomeNumber();
        return instance;
    }
    int getintpercent(){return distrib(gen);};
};
#endif //TURBOHIKER_RANDOMENUMBER_H
