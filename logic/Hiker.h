//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H


#include "Entity.h"
#include "Balloon.h"
#include "../Factory/LayoutFactory/LayoutFactory.h"
#include "Lanes.h"

class Hiker : public Entity {
public:
    Hiker()= default;

    virtual ~Hiker() = default;

    virtual void render() = 0;
    virtual bool updateVisuals(std::tuple<int, int> s) = 0;
    void updatePlayerv(int);
    void updatePlayerh(int);
    virtual std::tuple<double, double> update() = 0;
    void movetoview(double) override;
    virtual double helpcout(){return 0;};

    int getLanes() const;

    void setLanes(int lanes);

    virtual void speedup(int, int) = 0;

    virtual std::shared_ptr<Entity> shout(double, double, double) =0;
    std::shared_ptr<Entity> remove_shout(double timer) override;


    void setFact(const std::shared_ptr<LayoutFactory> &fact);

    const std::shared_ptr<LayoutFactory> &getFact() const;

    bool isShoutlock() const;

    void setShoutlock(bool shoutlock);

    double getLockedtimer() const;

    void setLockedtimer(double lockedtimer);

    bool isHorizontal() const;

    void setHorizontal(bool horizontal);
    virtual void fixdebuff(double) = 0;

    void setScoretext(const std::shared_ptr<Entity> &scoretext);

    const std::shared_ptr<Entity> &getScoretext() const;

private:
    int lanes;
    bool shoutlock = false;
    double lockedtimer;
    std::shared_ptr<LayoutFactory> fact = nullptr;
    bool horizontal = false;
    std::shared_ptr<Entity> scoretext = nullptr;


};


#endif //TURBOHIKER_HIKER_H
