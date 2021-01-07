//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H


#include "Entity.h"
#include "Balloon.h"
#include "../Factory/LayoutFactory/LayoutFactory.h"


class Hiker : public Entity {
public:
    Hiker() = default;

    ~Hiker() override {
            scoretext = nullptr;
            fact = nullptr;
    };

    virtual void render() = 0;

    virtual void updateVisuals(Coordinates s) = 0;

    virtual Coordinates update() = 0;

    virtual void speedup(int, int) = 0;

    virtual std::shared_ptr<Entity> shout(double, double) = 0;

    virtual void removeBuff() = 0;

    void moveToView(double) override;

    std::shared_ptr<Entity> removeShout(bool force) override;

    int getLanes() const;

    void setLanes(int lanes);

    void setFact(const std::shared_ptr<LayoutFactory> &fact);

    const std::shared_ptr<LayoutFactory> &getFact() const;

    bool isShoutlock() const;

    void setShoutlock(bool shoutlock);

    void setLockedtimer(double lockedtimer);

    void setScoretext(const std::shared_ptr<Entity> &scoretext);

    const std::shared_ptr<Entity> &getScoretext() const;

private:
    int lanes = 0;
    double lockedtimer = 0;
    bool shoutlock = false;
    std::shared_ptr<LayoutFactory> fact = nullptr;
    std::shared_ptr<Entity> scoretext = nullptr;


};


#endif //TURBOHIKER_HIKER_H
