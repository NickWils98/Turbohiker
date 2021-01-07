//
// Created by nick on 30.12.20.
//

#ifndef TURBOHIKER_RANDOMENUMBER_H
#define TURBOHIKER_RANDOMENUMBER_H

#include <random>
#include<iostream>
#include<cstdlib>
#include <memory>
namespace turbohiker {
    class RandomeNumber {
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<> distrib;
        static std::shared_ptr<RandomeNumber> instance;

        // Private constructor so that no objects can be created.
        RandomeNumber() {
//        seed random
            std::mt19937 gen2(rd());
            gen = gen2;
            std::uniform_int_distribution<int> distrib2(1, 100);
            distrib = distrib2;
        };

    public:
        static std::shared_ptr<RandomeNumber> getInstance() {
            if (!instance) {
                instance.reset(new RandomeNumber());
            }
            return instance;
        }

        int getintpercent() { return distrib(gen); };

        double getint(int maxInt) {
            std::uniform_real_distribution<double> distrib3(1, maxInt);
            return distrib3(gen);
        };
    };
}

#endif //TURBOHIKER_RANDOMENUMBER_H
