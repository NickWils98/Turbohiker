//
// Created by nick on 27.12.20.
//

#include <iostream>
#include "Game.h"
#include "sfml/HikerSFML.h"
#include "Factory/SFMLFactory.h"
#include "Factory/SFMLEnemyFactory.h"
#include "Factory/SFMLWandererFactory.h"
#include "Factory/LaneFactory.h"
#include "Factory/SFMLPassingFactory.h"
#include "Factory/TextBalloon.h"
#include "Factory/ScorFactory.h"

Game::Game()
        :   m_window    (sf::VideoMode(1088, 600), "Turbohiker",  sf::Style::Close | sf::Style::Resize),
            view(m_window.getDefaultView()){
    view.move(-300, 0);
    m_window.setFramerateLimit(60);
    world = std::make_shared<World>();
    r = RandomeNumber::getInstance();
    t = Transformation::getInstance();
    t->changeWindow(380, 600);

    double d = t->pixle_to_logic_y(-8350);
    world->setTracklength(-d);

}

Game::~Game() {

}

void Game::run() {

    std::clock_t  deltatime = std::clock();
    std::clock_t  startTime = std::clock();
    init();
    //Main loop of the game
    while (m_window.isOpen()) {

        double d = t->pixle_to_logic_y(view.getCenter().y);
        world->setVieuw(-d);
        //std::cout<<r->getintpercent()<<std::endl;
        std::clock_t  beginRound = startTime;
        startTime = std::clock();
        deltaTime = startTime - beginRound;
        int q = 0;
        while(deltaTime/CLOCKS_PER_SEC<0.016667){
//            std::cout<<deltaTime/CLOCKS_PER_SEC<<std::endl;
//            std::cout<<q<<std::endl;
            q++;
            startTime = std::clock();
            deltaTime = startTime - beginRound;
        }
//        if(deltaTime>1.0f/20.0f){
//            deltaTime= 1.0f/20.0f;
//        }
        //Render

        world->setTimer(beginRound, 1.0f/20.0f);
        world->removeLock();
//        world->removeObstacle();
//        world->generateObstacle(factory, 50);
        world->removeBalloon();

        deltaTime = startTime - beginRound;
        std::vector<int> speed = getInput();
        double oldspeed = world->getplayerspeed();
        world->speedup(speed[0], speed[1]);
        world->shout(speed[2], 0, 0);
        world->fixdebuff(1);
        double oldy = world->getplayerposy();
        m_window.clear();
        world->update();
        world->removeEnd();
        std::shared_ptr<Entity> test = world->getPlayer();
        if(test == nullptr){
            break;
        }
        world->Collision(1);
        double moved = moveView(oldy, oldspeed);
        world->movetoview(moved);
        m_window.setView(view);
        DrawBackground(world->getplayerposy());
        world->render();
        m_window.display();

        //Handle window events
        handleEvent();
    }
    while(m_window.isOpen()){
        std::cout<<"done";
    }
}


void Game::handleEvent() {
    sf::Event evnt;

    while (m_window.pollEvent(evnt)) {
        switch (evnt.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::Resized:
                break;
            default:
                break;

        }
    }
}

void Game::init() {
/*ini graphics TODO:move to world*/
    std::shared_ptr<sf::Texture> texb = std::make_shared<sf::Texture>();
    texb->loadFromFile("./../whaaagh.png");
    textures.push_back(texb);
    std::shared_ptr<FactoryLines> fact = std::make_shared<TextBalloon>(m_window, texb, view);

    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    tex->loadFromFile("./../zombieee.png");
    textures.push_back(tex);
    //TODO: fix pointer
    std::shared_ptr<PlayerFactory> playerfact = std::make_shared<PlayerFactory>(m_window, tex, view);
    playerfact->setFact(fact);

    std::shared_ptr<sf::Texture> enemytex = std::make_shared<sf::Texture>();
    enemytex->loadFromFile("./../enemycuty.png");
    textures.push_back(enemytex);

    std::shared_ptr<SFMLEnemyFactory> enemyfact = std::make_shared<SFMLEnemyFactory>(m_window, enemytex, view);
    enemyfact->setFact(fact);
    std::shared_ptr<sf::Texture> passingtex = std::make_shared<sf::Texture>();
    passingtex->loadFromFile("./../knight.png");
    textures.push_back(passingtex);

    std::shared_ptr<sf::Texture> passingtex2 = std::make_shared<sf::Texture>();
    passingtex2->loadFromFile("./../rat2.png");
    textures.push_back(passingtex2);
    std::shared_ptr<sf::Font> f = std::make_shared<sf::Font>();
    if(!f->loadFromFile("../Hardigan.otf")){
        std::cout<<"error loading file"<<std::endl;
        system("pause");
    }
    fonts.push_back(f);
    std::shared_ptr<FactoryLines> textfact = std::make_shared<ScorFactory>(m_window, sf::Color::White, view, "Score:\n", f);

    std::shared_ptr<SFMLFactory> passingfact = std::make_shared<SFMLWandererFactory>(m_window, passingtex, view);
    std::shared_ptr<SFMLFactory> passingfact2 = std::make_shared<SFMLPassingFactory>(m_window, passingtex2, view);

    std::shared_ptr<LaneFactory> lanefact = std::make_shared<LaneFactory>(LaneFactory(m_window, sf::Color::White, view));

    int chance = r->getintpercent();
    chance = (chance*3) /100.0;




    world->addLane({playerfact, enemyfact}, {lanefact, textfact}, chance +4);
    world->generateObstacle({passingfact, passingfact2}, 10);



    std::shared_ptr<sf::Texture> backgroundTex = std::make_shared<sf::Texture>();
    backgroundTex->loadFromFile("../mapscoree.png");
    textures.push_back(backgroundTex);

    sf::Sprite background(*backgroundTex);
    backgrounds.push_back(background);
    backgrounds[0].setPosition(-300 ,600);


    sf::Sprite background2(*backgroundTex);
    backgrounds.push_back(background2);
    backgrounds[1].setPosition(-300 ,0);

    sf::Sprite background3(*backgroundTex);
    backgrounds.push_back(background3);
    backgrounds[2].setPosition(-300 ,-600);
}

void Game::DrawBackground(double pos) {

    double v = view.getCenter().y;
    double x = backgrounds[2].getPosition().y;
    if(v-(view.getSize().y/2.0)<backgrounds[1].getPosition().y){
        backgrounds[0].move(0,-600);
        backgrounds[1].move(0,-600);
        backgrounds[2].move(0,-600);
    } else if(v-(view.getSize().y/2.0)>backgrounds[0].getPosition().y){
        backgrounds[0].move(0,600);
        backgrounds[1].move(0,600);
        backgrounds[2].move(0,600);
    }
    m_window.draw(backgrounds[0]);
    m_window.draw(backgrounds[1]);
    m_window.draw(backgrounds[2]);
    backgrounds[0].getPosition();

}


std::vector<int> Game::getInput() {

    int speedv = 0;
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if(up){speedv++;}
    if(down){speedv--;}

    int speedh = 0;
    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    if(right){speedh++;}
    if(left){speedh--;}
    int spaceinput = 0;
    bool space = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    if(space){spaceinput++;}
    return {speedv, speedh, spaceinput};
}

double Game::moveView(double oldposy, double oldspeed) {
    double posy = world->getplayerposy();

    if(view.getCenter().y==100 and posy>2){
        return 0;
    }
    double speed = world->getplayerspeed();
    double maxspeed = world->getplayermaxspeed();
    double minspeed = -maxspeed;

    double usedspeed = speed-minspeed;

    double scaledspeed = usedspeed/(maxspeed-minspeed)*3;
    scaledspeed -= 1.5;

    double halfway = view.getCenter().y;
    int beforhalf = 800-t->logic_to_pixle_y(scaledspeed);
    int limitpos = beforhalf-halfway;

    int newposy = t->logic_to_pixle_y(posy);
    int newoldposy = t->logic_to_pixle_y(oldposy);
    double helper = world->gethelper();
    //std::cout<<newposy-300<<"   "<<newposy-newoldposy<<"   "<<helper<<std::endl;
    if(speed>=0){
        if(newposy<beforhalf){
            if(newposy-beforhalf!=newposy-newoldposy){
                int q = 5;
            }
            view.move(0, newposy-beforhalf);
            double speedy = t->pixle_to_logic_y(newposy);
            double newpospixley = t->pixle_to_logic_y(beforhalf);
            double counting = speedy-newpospixley;
            return counting;
        }
    }

//    if(speed<0){
//        if(beforhalf<newposy){
//            view.move(0, newposy-beforhalf);
//            double speedy = t->pixle_to_logic_y(newposy);
//            double newpospixley = t->pixle_to_logic_y(beforhalf);
//            double counting = speedy-newpospixley;
//            return counting;
//        }
//    }

    return 0;



}
