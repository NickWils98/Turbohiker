//
// Created by nick on 27.12.20.
//

#ifndef TURBOHIKER_HIKER_H
#define TURBOHIKER_HIKER_H


#include "Entity.h"
#include "Balloon.h"
#include "Factories/LayoutFactory.h"

namespace turbohiker {
    class Hiker : public Entity {
    public:
        Hiker() = default;

        ~Hiker() override {
            scoretext = nullptr;
            bubbleFact = nullptr;
        };

        void moveToView(double) override;

        std::shared_ptr<Entity> removeShout(bool force) override;

        int getAllLaneCount() const;

        void setAllLaneCount(int lanes);

        void setBubbleFact(const std::shared_ptr<LayoutFactory> &fact);

        const std::shared_ptr<LayoutFactory> &getBubbleFact() const;

        bool isShoutlock() const;

        void setShoutlock(bool shoutlock);

        void setShoutLockedtimer(double lockedtimer);

        void setScoretext(const std::shared_ptr<Entity> &scoretext);

        const std::shared_ptr<Entity> &getScoretext() const;

    private:
        int allLaneCount = 0;
//    lock shout for a time so you cant keep shouting
        double shoutLockTimer = 0;
        bool shoutlock = false;
//    factory to make a speech bubble
        std::shared_ptr<LayoutFactory> bubbleFact = nullptr;
//    link the score to a hiker
        std::shared_ptr<Entity> scoretext = nullptr;
    };
}

#endif //TURBOHIKER_HIKER_H
