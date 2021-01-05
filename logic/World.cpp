//
// Created by nick on 27.12.20.
//

#include "World.h"

World::World() {
    entityList = {};
    lanelist = {};
}
void World::remove(std::shared_ptr<Entity> toDel) {
    entityList.erase(std::remove(entityList.begin(), entityList.end(), toDel));
    if(std::find(obstacles.begin(), obstacles.end(), toDel)!=obstacles.end()){

        obstacles.erase(std::remove(obstacles.begin(), obstacles.end(), toDel));
    }
}

void World::render() {
    player->getScoretext()->setScoring(player->getScore());
    for(auto obj: entityList) {
        obj->render();
    }
}

std::tuple<double, double> World::update() {
    for (int i = 0; i < entityList.size(); i++){
        auto obj = entityList[i];
        std::tuple<double, double> changed = obj->update();
        //double moved = Collision(i);
        coordinats pos = obj->getPosition();
        std::shared_ptr<Transformation> t = t->getInstance();
        std::tuple<int, int> oldp = t->logic_to_pixles(0,0);
        std::tuple<int, int> newp = t->logic_to_pixles(std::get<0>(changed)*lanelength, std::get<1>(changed));
        std::tuple<int, int> updatep = std::make_tuple(std::get<0>(oldp)- std::get<0>(newp), std::get<1>(oldp)- std::get<1>(newp));

        bool tried = obj->updateVisuals(updatep);
        if(obj->isHasballoon()){
            obj->getBalloon()->setPosition(obj->getPosition().x, obj->getPosition().y-obj->getSize().y);
            obj->getBalloon()->updateVisuals(updatep);
        }
        if (tried == false){
            obj->setPosition(obj->getPosition().x, 3);
        }

    }
    return std::make_tuple(0,0);
}

void World::add(std::shared_ptr<Entity> obj) {
    entityList.push_back(obj);
    std::cout<<entityList.size();
}

void World::addLane(std::vector<std::shared_ptr<Factory>> f, std::vector<std::shared_ptr<FactoryLines>> l, const int amount) {
    double extra = 8.0/amount;
    double start = -4 + extra;
//    double original =start-extra/2;
    RandomeNumber* r = RandomeNumber::getInstance();
    int chance = r->getintpercent();
    int ance = (chance*amount)/100.0;

    lanes = amount-1;


    lanelength = extra;
    firstlane = (start-extra/2)-((extra/1.1-4)-(extra-4))/2;
    for(int count = 0; count<amount;count++){
        if(count<amount-1) {
            std::shared_ptr<Entity> entity = l[0]->createProp(std::tuple<double, double>(-3.9f, 3.0f),
                                                           std::tuple<double, double>(start, -3.0f));
            entityList.push_back(entity);
        }
        std::shared_ptr<Hiker> hiker;
        bool playerbool = false;
        if(!player){

            if( ance == count){
                playerbool = true;
                hiker = f[0]->createHiker(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 2.5f));
            }
            else{
                hiker = f[1]->createHiker(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 2.5f));
            }
        } else{
            hiker = f[1]->createHiker(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 2.5f));
        }
        //std::shared_ptr<Hiker> hiker = f->createHikerPlayer(std::tuple<double, double>(extra-4, -2.5f), std::tuple<double, double>(start-extra/2, 0.0f));
//        hiker->setPosition(firstlane+lanelength*count, 2.5f);
//        hiker->setSize(extra, 0.5f);
//        hiker->setHeavynes(0.5);

        hiker->setLanes(amount-1);
        hiker->setMylane(count);


        entityList.push_back(hiker);
        if(playerbool){
            playerbool = false;
            player = hiker;
        }
        start += extra;
    }

    std::shared_ptr<Entity> text = l[1]->createProp(std::tuple<double, double>(-2.0f, -2.0f),
                                                   std::tuple<double, double>(7.5, -3.0f));
    player->setScoretext(text);
    entityList.push_back(text);
}
void World::speedup(int speedv, int speedh) {
    speedh = speedupPlayer(speedh);
    //player->updatePlayerv(speedv);
    for(auto obj: entityList) {
        if(obj!= player){
            std::vector<int> speed = ai(obj);

            obj->speedup(speed[0], speed[1]);
        } else {
            obj->speedup(speedv, speedh);
        }
    }
}



int World::speedupPlayer(int speedh) {
    int usedspeedh = 0;
    Collider c = Collider();
    if(speedh != 0){
        bool left = (speedh<0) ? true : false;
        bool isgoed = true;
        for(auto entity : entityList) {
            if (entity != player) {
                if (not c.checklaneswitch(player, entity, left)) {
                    isgoed = false;
                }
                if (c.CheckCollision(player, entity)) {
                    isgoed = false;
                }

            }
        }
        if(not player->isLocked() and isgoed) {
            usedspeedh = speedh;
            //player->updatePlayerh(speedh);
            player->setLock(timer + 200000);
            player->setLocked(true);
        } else{
            //std::cout<<"     "<<lock<<"    "<<timer<<std::endl;
        }
    }
    return usedspeedh;

}

double World::getplayerposy() {
    return player->getPosition().y;
}

double World::getplayerspeed() {
    return player->getSpeed();
}
double World::getplayermaxspeed() {
    return player->getMaxSpeed();
}

void World::movetoview(double moved) {
    for(auto obj: entityList) {

        obj->movetoview(moved);
    }
}

void World::setTimer(double timer, double delta) {
    World::timer = timer;
    for(auto e : entityList){
        e->setOldtimer(delta);
        e->setTimer(timer);
    }
}

void World::removeLock() {
    for(auto e : entityList){
        if(e->isLocked() and e->getLock() <timer){
             e->setLocked(false);
        }
    }

}

double World::Collision(int i) {
    std::vector<double> moved = {0,0};
    /*
    for (int j = 0; j < entityList.size(); j++) {
        if (i != j) {
            Collider col = Collider();
            moved+= col.CheckCollision(entityList[i],entityList[j], 1.0f);

        }
    }
    return moved;

    */if(!entityList.empty()) {
        for (int i = 0; i < entityList.size() - 1; i++) {
            for (int j = i; j < entityList.size(); j++) {
                if (i != j) {
                    if(!entityList[i]->isIsobstacle() or !entityList[j]->isIsobstacle()) {
                        Collider col = Collider();
                        moved = col.CollisionDetection(entityList[i], entityList[j], timer);
                        if (moved[0] != 0 or moved[1] != 0) {
                            if(entityList[i] == player or entityList[j] == player){
                                player->setScore(-1);
                            }
                            std::shared_ptr<Transformation> t = t->getInstance();
                            std::tuple<int, int> oldp = t->logic_to_pixles(0, 0);
                            std::tuple<int, int> newp = t->logic_to_pixles(0, -moved[0]);
                            std::tuple<int, int> updatep = std::make_tuple(std::get<0>(oldp) - std::get<0>(newp),
                                                                 std::get<1>(oldp) - std::get<1>(newp));
                            std::tuple<int, int> newp2 = t->logic_to_pixles(0, -moved[1]);
                            std::tuple<int, int> updatep2 = std::make_tuple(std::get<0>(oldp) - std::get<0>(newp2),
                                                                  std::get<1>(oldp) - std::get<1>(newp2));
                            //tuple<int, int> updatepNeg = make_tuple(- std::get<0>(updatep), - std::get<1>(updatep));


                            entityList[i]->updateVisuals(updatep);
                            entityList[j]->updateVisuals(updatep2);
                        }
                    }
                }
            }
        }
    }

}

void World::generateObstacle(std::vector<std::shared_ptr<Factory>> f, int times) {
    std::shared_ptr<Hiker> hiker3;
    hiker3 = f[0]->createHiker(std::tuple<double, double>(lanelength / 1.1 - 4, -2.5f),
                               std::tuple<double, double>(firstlane + lanelength * 3, -3.0f+1));

    hiker3->setLanes(player->getLanes());
    hiker3->setMylane(3);
    entityList.push_back(hiker3);
    obstacles.push_back(hiker3);


    times *= player->getLanes();
    RandomeNumber* r = r->getInstance();
    for(int i=1; i<times;i++){
        int fact = r->getintpercent()%2;
        double percent = r->getint(tracklength-2);
        int percent2 = r->getintpercent();
        int lane = percent2 % (player->getLanes()+1);
        std::shared_ptr<Hiker> hiker3;
        hiker3 = f[fact]->createHiker(std::tuple<double, double>(lanelength / 1.1 - 4, -2.5f),
                                       std::tuple<double, double>(firstlane + lanelength * lane, -3.0f-percent));

        //std::shared_ptr<Hiker> hiker = f->createHikerPlayer(std::tuple<double, double>(extra-4, -2.5f), std::tuple<double, double>(start-extra/2, 0.0f));
//        hiker3->setPosition(firstlane + lanelength * lane, -3.0f-percent);
        hiker3->setLanes(player->getLanes());
        hiker3->setMylane(lane);
//        hiker3->setSize(lanelength, 0.5f);
//        hiker3->setHeavynes(0);
//        hiker3->setGottrough(true);
        bool push = true;
        if(!obstacles.empty()) {
            for (auto o : obstacles) {
                if (o != hiker3) {
                    Collider c = Collider();
                    if (c.CheckCollision(o, hiker3)) {
                        i--;
                        push = false;

                    }
                }
            }
        }
        if (push) {
            entityList.push_back(hiker3);
            obstacles.push_back(hiker3);
        }


    }

//    std::shared_ptr<Hiker> hiker3;
//
//    hiker3 = f->createHiker(std::tuple<double, double>(lanelength / 1.1 - 4, -2.5f),
//                            std::tuple<double, double>(firstlane + lanelength * 4, -3));
//
//    //std::shared_ptr<Hiker> hiker = f->createHikerPlayer(std::tuple<double, double>(extra-4, -2.5f), std::tuple<double, double>(start-extra/2, 0.0f));
//    hiker3->setPosition(firstlane + lanelength * 4, -3.0f);
//    hiker3->setLanes(player->getLanes());
//    hiker3->setMylane(4);
//    hiker3->setSize(lanelength, 0.5f);
//    hiker3->setHeavynes(0);
//    entityList.push_back(hiker3);
//    obstacles.push_back(hiker3);


}

void World::generateObstacle2(std::shared_ptr<Factory> f, int times) {
    bool generate = false;
    times *= player->getLanes();
    RandomeNumber* r = r->getInstance();
    if(obstacles.size()<2) {
        if(r->getintpercent()<2){
            generate = true;
        }
    } else if(obstacles.size()<=6) {
        if(r->getintpercent()<5){
            generate = true;
        }
    }
    if(generate){
        double percent = r->getint(3);
        int percent2 = r->getintpercent();
        int lane = percent2 % player->getLanes()+1;
        std::shared_ptr<Hiker> hiker3;
        hiker3 = f->createHiker(std::tuple<double, double>(lanelength / 1.1 - 4, -2.5f),
                                       std::tuple<double, double>(firstlane + lanelength * lane, -3.0f-percent));

        //std::shared_ptr<Hiker> hiker = f->createHikerPlayer(std::tuple<double, double>(extra-4, -2.5f), std::tuple<double, double>(start-extra/2, 0.0f));
//        hiker3->setPosition(firstlane + lanelength * lane, -3.0f-percent);
        hiker3->setLanes(player->getLanes());
        hiker3->setMylane(lane);
//        hiker3->setSize(lanelength, 0.5f);

        entityList.push_back(hiker3);
        obstacles.push_back(hiker3);

    }


}

void World::removeObstacle() {
    std::vector<std::shared_ptr<Entity>> toremove = {};
    for(auto e : obstacles){
        if(e->getPosition().y>8){
            toremove.push_back(e);
        }
    }
    while(toremove.size()!=0){

        remove(toremove.back());
        toremove.pop_back();
    }
}

std::shared_ptr<Entity> World::shout(double i, double j, double z) {
    if(i == 1) {
        std::shared_ptr<Entity> o = player->shout(timer, firstlane, lanelength);
        if (o != nullptr) {
            player->setScore(-10);
            entityList.push_back(o);
            ObstacleInLane(player, 5);

        }
    }
    for(int ii = 0; ii<entityList.size();ii++){
        auto e = entityList[ii];

//    for(auto e: entityList){
        if(e->isWannashout()) {
            e->setWannashout(false);

            std::shared_ptr<Entity> obj = e->shout(timer, firstlane, lanelength);
            if (obj != nullptr) {
                entityList.push_back(obj);
                ObstacleInLane(e, 5);

            }
        }
    }


}

void World::removeBalloon() {

    std::vector<std::shared_ptr<Entity>> toremove = {};
    for(auto obj: entityList) {

        if(obj->isHasballoon()){
            std::shared_ptr<Entity> e = obj->remove_shout(timer);
            if(e){
                toremove.push_back(e);

            }
        }
    }
    while(toremove.size()!=0){

        remove(toremove.back());
        toremove.pop_back();
    }

}

std::shared_ptr<Entity> World::remove_shout(double timer) {
    return std::shared_ptr<Entity>();
}

void World::ObstacleInLane(std::shared_ptr<Entity> e, int distance) {
    for(auto o : obstacles){
        if(e->getMylane() == o->getMylane()){
            if(e->getPosition().y>o->getPosition().y and e->getPosition().y-distance<o->getPosition().y){
                o->shout(timer, 0, 0);
            }
        }

    }
}

void World::fixdebuff(double b) {
    for(auto e : entityList){
        if(e->isDebuff()){
            e->fixdebuff(timer);
        }
    }
}

std::vector<int> World::ai(std::shared_ptr<Entity> e) {
    int v = 0;
    int h = 0;

    if(CheckClosesdObstacleInLane(e, 3)){
        v =1;
    }
    std::vector<bool> horizontal = checklaneswitch(e);
    if (!horizontal[0] and !horizontal[1]){
        h = 3;
    } else if (horizontal[0]){
        h=2;
    } else if (horizontal[1]){
        h=1;
    }
    return {v, h};

}

bool World::CheckClosesdObstacleInLane(std::shared_ptr<Entity> e, int distance) {
    for(auto o : obstacles){
        if(e->getMylane() == o->getMylane()){
            if(e->getPosition().y>o->getPosition().y and e->getPosition().y-distance<o->getPosition().y){
                return true;
            }
        }

    }

    return false;
}
std::vector<bool> World::checklaneswitch(std::shared_ptr<Entity> e){
    bool isgoedleft = true;
    bool isgoedright = true;
    Collider c = Collider();

    for(auto entity : entityList) {
        if (entity != e) {
            if (not c.checklaneswitch(e, entity, true) or e->getMylane()==0) {
                isgoedleft = false;
            }
            if (not c.checklaneswitch(e, entity, false)or e->getMylane()==lanes) {
                isgoedright = false;
            }
        }
    }
    return {isgoedleft, isgoedright};
}

void World::setTracklength(int tracklength) {
    World::tracklength = tracklength;
}

void World::setVieuw(double vieuw) {
    World::vieuw = vieuw;
}

void World::removeEnd() {
    std::vector<std::shared_ptr<Entity>> toremove = {};
    for(auto obj: entityList) {
        if(vieuw-obj->getPosition().y>tracklength) {
            if(obj->isEnemy()){
                finishing++;
                toremove.push_back(obj);
            } else if(obj == player){
                player->setScore(100*lanes-100*finishing);
                toremove.push_back(player);
                player = nullptr;
            }
        }
    }
    while(toremove.size()!=0){
        remove(toremove.back());
        toremove.pop_back();
    }
}

const std::shared_ptr<Hiker> &World::getPlayer() const {
    return player;
}
