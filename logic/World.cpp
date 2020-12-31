//
// Created by nick on 27.12.20.
//

#include "World.h"

World::World() {
    entityList = {};
    lanelist = {};
}
void World::remove(std::shared_ptr<Entity> toDel) {

}

void World::render() {
    for(auto obj: entityList) {
        obj->render();
    }
}

tuple<double, double> World::update() {
    for (int i = 0; i < entityList.size(); i++){
        auto obj = entityList[i];
        tuple<double, double> changed = obj->update();
        //double moved = Collision(i);
        coordinats pos = obj->getPosition();
        Transformation *t = t->getInstance();
        tuple<int, int> oldp = t->logic_to_pixles(0,0);
        tuple<int, int> newp = t->logic_to_pixles(std::get<0>(changed)*lanelength, std::get<1>(changed));
        tuple<int, int> updatep = make_tuple(std::get<0>(oldp)- std::get<0>(newp), std::get<1>(oldp)- std::get<1>(newp));

        obj->updateVisuals(updatep);

    }
    return make_tuple(0,0);
}

void World::add(std::shared_ptr<Entity> obj) {
    entityList.push_back(obj);
    std::cout<<entityList.size();
}

void World::addLane(std::shared_ptr<Factory> f, const int amount) {
    double extra = 8.0/amount;
    double start = -4 + extra;
    double original =start-extra/2;
    RandomeNumber* r = RandomeNumber::getInstance();
    int chance = r->getintpercent();
    int ance = (chance/100.0)*amount;


    lanelength = extra;
    for(int count = 0; count<amount;count++){
        ColorLogic c = ColorLogic(255, 255, 255);
        if(count<amount-1) {
            std::shared_ptr<Entity> entity = f->addLane(c, std::tuple<double, double>(-3.9f, 3.0f),
                                                        std::tuple<double, double>(start, -3.0f));
            entityList.push_back(entity);
        }
        std::shared_ptr<Hiker> hiker;
        bool playerbool = false;
        if(!player){

            if( ance == count){
                playerbool = true;
                hiker = f->createHikerPlayer(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 0.0f));
            }
            else{
                hiker = f->createHikerEnemy(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 0.0f));
            }
        } else{
            hiker = f->createHikerEnemy(std::tuple<double, double>(extra/1.1-4, -2.5f), std::tuple<double, double>(((start-extra/2)-((extra/1.1-4)-(extra-4))/2), 0.0f));
        }
        //std::shared_ptr<Hiker> hiker = f->createHikerPlayer(std::tuple<double, double>(extra-4, -2.5f), std::tuple<double, double>(start-extra/2, 0.0f));
        hiker->setPosition(start-extra/2, 0.0f);
        hiker->setLanes(amount-1);
        hiker->setMylane(count);
        hiker->setSize(extra, 0.5f);


        entityList.push_back(hiker);
        if(playerbool){
            playerbool = false;
            player = hiker;
        }
        start += extra;
    }


    //Hiker = factory->createHiker(m_window, tex);
}

void World::speedupPlayer(int speedv, int speedh) {
    player->updatePlayerv(speedv);

    if(speedh != 0){
        bool left = (speedh<0) ? true : false;
        bool isgoed = true;
        for(auto entity : entityList){
            Collider c = Collider();
            if(not c.checklaneswitch(player, entity, left)){
                isgoed = false;
            }

        }
        if(not locked and isgoed) {
            player->updatePlayerh(speedh);
            lock = timer + 10000;
            locked = true;
        } else{
            //std::cout<<"     "<<lock<<"    "<<timer<<std::endl;
        }
    }
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

void World::setTimer(double timer) {
    World::timer = timer;
}

void World::removeLock() {
    if(lock<timer){
        locked=false;
    }
}

double World::Collision(int i) {
    double moved = 0;
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
                    Collider col = Collider();
                    moved = col.CheckCollision(entityList[i],entityList[j], 1.0f);
                    if(moved!=0){
                        Transformation *t = t->getInstance();
                        tuple<int, int> oldp = t->logic_to_pixles(0,0);
                        tuple<int, int> newp = t->logic_to_pixles(0, -moved);
                        tuple<int, int> updatep = make_tuple(std::get<0>(oldp)- std::get<0>(newp), std::get<1>(oldp)- std::get<1>(newp));

                        entityList[j]->updateVisuals(updatep);
                        //entityList[j]->updateVisuals(-updatep);
                    }
                }
            }
        }
    }

}