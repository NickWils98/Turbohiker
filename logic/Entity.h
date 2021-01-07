//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_ENTITY_H
#define TURBOHIKER_ENTITY_H

#include <memory>
#include <vector>
#include <algorithm>
#include "Coordinates.h"
#include "Singletons/Transformation.h"
#include "Singletons/RandomeNumber.h"
#include "Observer/SubjectInterface.h"
#include "Observer/Subject.h"
#include "Observer/Observer.h"

namespace turbohiker {
    class Entity {
    public:

        Entity();

        virtual ~Entity() = default;

        void deleteSubject();

        virtual void render() = 0;

        virtual Coordinates update() = 0;

        virtual void updateVisuals(Coordinates s) = 0;

        virtual void moveToView(double) = 0;

        virtual void speedup(int, int) = 0;

        virtual std::shared_ptr<Entity> shout(double, double) = 0;

        virtual void removeBuff() = 0;

        virtual std::shared_ptr<Entity> removeShout(bool force) = 0;

        const Coordinates &getPosition() const;

        void Move(double dx, double dy);

        void setPosition(double x, double y);

        void setPosition(const Coordinates &position);

        const Coordinates &getSize() const;

        void setSize(double x, double y);

        double getSpeedv() const;

        void setSpeedv(double speed);

        double getMaxSpeed() const;

        void setMaxspeed(double maxspeed);

        int getMyLane() const;

        void setMyLane(int mylane);

        Coordinates GetHalfSize() const;

        double getHeaviness() const;

        void setHeaviness(double h);

        bool isTransparant() const;

        void setTransparant(bool g);

        bool isSlowedDown() const;

        void setSlowedDown(bool s);

        bool isHasTextBubble() const;

        void setHasTextBubble(bool t);

        const std::shared_ptr<Entity> &getTextBubble() const;

        void setTextBubble(const std::shared_ptr<Entity> &t);

        bool isBuffed() const;

        void setBuffed(bool d);

        double getBuffedTimer() const;

        void setDebufftimer(double debufftimer);

        double getTimeLock() const;

        void setTimeLock(double lock);

        bool isTimeLocked() const;

        void setTimeLocked(bool locked);

        bool isWantToShout() const;

        void setWantToShout(bool wannashout);

        double getTimer() const;

        void setTimer(double timer);

        bool isObstacle() const;

        void setObstacle(bool isobstacle);

        double getDeltaTimer() const;

        void setDeltaTimer(double d);

        int getScore() const;

        void setScore(int score);

        const std::string &getScoreText() const;

        void setScoreText(const int &scoring);

        bool isEnemy() const;

        void setEnemy(bool enemy);

        int getSpeedh() const;

        void setSpeedh(int speedh);

    private:
        std::string scoreText;
        std::shared_ptr<SubjectInterface> subject;
        std::vector<std::shared_ptr<ObserverInterface>> observer;
        Coordinates position{0, 0};
        Coordinates size{0, 0};
        double maxspeed = 120;
        double speedv = 0;
        int speedh = 0;
        double timer = 0;
        double deltaTime = 0;
//    percentage of how much a hiker will move in collision
        double heaviness = 0;
//    true if it has no collision
        bool transparant = false;
//    true if hiker needs to slow down when touched
        bool slowedDown = false;
//    buff of a hiker
        bool buffed = false;
        double buffedTimer = 0;
//    text bubble if yelled
        bool hasTextBubble = false;
        std::shared_ptr<Entity> textBubble = nullptr;
//    lock on knight movement speed
        double timeLock = 0;
        bool timeLocked = false;
//    ai wants to shout
        bool wantToShout = false;
//    entity is an obstacle
        bool obstacle = false;
//    entity is an enemy
        bool enemy = false;
//    lane of the hiker
        int myLane = -1;
    };
}

#endif //TURBOHIKER_ENTITY_H
