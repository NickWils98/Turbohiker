//
// Created by nick on 27.12.20.
//

#include "Hiker.h"

void Hiker::moveToView(double moved) {
    Coordinates pos = getPosition();
    pos.y -= moved;
    setPosition(pos);
}

int Hiker::getLanes() const {
    return lanes;
}

void Hiker::setLanes(int l) {
    Hiker::lanes = l;
}


std::shared_ptr<Entity> Hiker::removeShout(bool force) {
    if (shoutlock) {
        if (getTimer() > lockedtimer or force) {
            shoutlock = false;
            std::shared_ptr<Entity> b = getTextBubble();
            setTextBubble(nullptr);
            setHasTextBubble(false);
            return b;
        }
    }
    return nullptr;
}

void Hiker::setFact(const std::shared_ptr<LayoutFactory> &f) {
    Hiker::fact = f;
}

const std::shared_ptr<LayoutFactory> &Hiker::getFact() const {
    return fact;
}

bool Hiker::isShoutlock() const {
    return shoutlock;
}

void Hiker::setShoutlock(bool s) {
    Hiker::shoutlock = s;
}

void Hiker::setLockedtimer(double l) {
    Hiker::lockedtimer = l;
}



void Hiker::setScoretext(const std::shared_ptr<Entity> &s) {
    Hiker::scoretext = s;
}

const std::shared_ptr<Entity> &Hiker::getScoretext() const {
    return scoretext;
}




