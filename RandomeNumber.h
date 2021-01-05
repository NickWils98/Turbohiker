//
// Created by nick on 30.12.20.
//

#ifndef TURBOHIKER_RANDOMENUMBER_H
#define TURBOHIKER_RANDOMENUMBER_H
#include <random>
#include<iostream>
#include<stdlib.h>
#include <memory>

class RandomeNumber {
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
    static std::shared_ptr<RandomeNumber> instance;

    // Private constructor so that no objects can be created.
    RandomeNumber(){
        std::mt19937 gen2(rd());
        gen = gen2;

        std::uniform_int_distribution<int> distrib2(1,100);
        distrib = distrib2;



    };

public:
    static std::shared_ptr<RandomeNumber> getInstance() {
        if (!instance) {
            instance.reset(new RandomeNumber());
        }
//            instance = std::make_shared<Transformation>();
        return instance;
    }
    int getintpercent(){return distrib(gen);};
    double getint(int i){
        std::uniform_real_distribution<double> distrib3(1,i);

        return distrib3(gen);
    };
};
#endif //TURBOHIKER_RANDOMENUMBER_H
