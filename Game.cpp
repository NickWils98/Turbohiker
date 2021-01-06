//
// Created by nick on 27.12.20.
//

#include <iostream>
#include "Game.h"
#include "sfml/HikerSFML.h"
#include "Factory/HikerFactory/EnemyFactory.h"
#include "Factory/HikerFactory/KnightFactory.h"
#include "Factory/LayoutFactory/LineFactory.h"
#include "Factory/HikerFactory/VerminFactory.h"
#include "Factory/LayoutFactory/SpeechBubbleFactory.h"
#include "Factory/LayoutFactory/ScoreFactory.h"

Game::Game()
        :   m_window    (sf::VideoMode(1088, 600), "Turbohiker",  sf::Style::Close | sf::Style::Resize),
            view(m_window.getDefaultView()){
    view.move(-300, 0);
    m_window.setFramerateLimit(60);
    world = std::make_shared<World>();
    r = RandomeNumber::getInstance();
    t = Transformation::getInstance();
    t->changeWindow(380, 600);

    double d = t->pixle_to_logic_y(-8000);
    world->setTracklength(-d);

}

Game::~Game() {

}

bool Game::run() {

    std::clock_t  deltatime = std::clock();
    std::clock_t  startTime = std::clock();
    init();
    //Main loop of the game
    int finished = 0;
    int score = 0;
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
            finished = world->getFinishing();
            score = world->getScore1();
            scores.push_back(score);
            writeHighscore();
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
    if(m_window.isOpen()) {
        desperate(finished + 1, score);
    }
    return goagain;

}
void Game::desperate(int finished, int player) {

    view.setCenter(300,300);
    sf::Text victorytext;
    sf::Font f;
    std::string printing = "You finnished:\n"+std::to_string(finished) + " / " +std::to_string(playercount)+"\n";
    printing += "With a score of:\n"+std::to_string(player) + "\n";
    printing += "To restart the game:\n Press 'R'";
    victorytext.setString(printing);
    victorytext.setCharacterSize( 35);
//    body.setSize(size);
    victorytext.setFillColor(sf::Color::Black);
    victorytext.setPosition(0,100);
    if(!f.loadFromFile("../Hardigan.otf")){
        std::cout<<"error loading file"<<std::endl;
        system("pause");
    }
    m_window.setView(view);
    victorytext.setFont(f);

    sort(scores.begin(), scores.end());
    std::reverse(scores.begin(), scores.end());

    std::string higscoretext = "Highscores:\n";

    int y=0;
    for(auto score : scores){
        y++;
        if(y==10){
            break;
        }
        higscoretext+= std::to_string(score)+"\n";
    }
    sf::Text highscoretext;
    highscoretext.setString(higscoretext);
    highscoretext.setFillColor(sf::Color::White);
    highscoretext.setPosition(600,100);
    highscoretext.setFont(f);
    highscoretext.setCharacterSize( 35);
    while(m_window.isOpen()){
        DrawBackground(0);
        m_window.draw(victorytext);
        m_window.draw(highscoretext);
        m_window.display();
        handleEvent();
        if(restart()){
            goagain = true;
            break;
        }
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
    getHighscores();
    std::shared_ptr<sf::Texture> texb = std::make_shared<sf::Texture>();
    texb->loadFromFile("./../whaaagh.png");
    textures.push_back(texb);
    std::shared_ptr<LayoutFactory> fact = std::make_shared<SpeechBubbleFactory>(m_window, texb, view);

    std::shared_ptr<sf::Texture> tex = std::make_shared<sf::Texture>();
    tex->loadFromFile("./../zombieee.png");
    textures.push_back(tex);
    //TODO: fix pointer
    std::shared_ptr<PlayerFactory> playerfact = std::make_shared<PlayerFactory>(m_window, tex, view, fact);

    std::shared_ptr<sf::Texture> enemytex = std::make_shared<sf::Texture>();
    enemytex->loadFromFile("./../enemycuty.png");
    textures.push_back(enemytex);

    std::shared_ptr<EnemyFactory> enemyfact = std::make_shared<EnemyFactory>(m_window, enemytex, view, fact);
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
    std::shared_ptr<LayoutFactory> textfact = std::make_shared<ScoreFactory>(m_window, sf::Color::White, view, "Score:\n", f, true);


    std::string higscoretext = "Highscores:\n";
    int y=0;
    for(auto score : scores){
        y++;
        if(y==10){
            break;
        }
        higscoretext+= std::to_string(score)+"\n";
    }
    std::shared_ptr<LayoutFactory> textfact2 = std::make_shared<ScoreFactory>(m_window, sf::Color::White, view, higscoretext, f, false);


    std::shared_ptr<HikerFactory> passingfact = std::make_shared<KnightFactory>(m_window, passingtex, view);
    std::shared_ptr<HikerFactory> passingfact2 = std::make_shared<VerminFactory>(m_window, passingtex2, view);

    std::shared_ptr<LineFactory> lanefact = std::make_shared<LineFactory>(LineFactory(m_window, sf::Color::White, view, true));
    std::shared_ptr<LineFactory> lanefact2 = std::make_shared<LineFactory>(LineFactory(m_window, sf::Color::White, view, false));

    int chance = r->getintpercent();
    chance = (chance*3) /100.0;
    playercount = chance +4;




    world->addLane({playerfact, enemyfact}, {lanefact, lanefact2, textfact, textfact2}, chance +4);
    world->generateObstacle({passingfact, passingfact2}, 20);



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

bool Game::restart() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
}

void Game::writeHighscore( ) {
//    std::string filename("../score.txt");
//    std::fstream file;
//
//    file.open(filename, std::ios_base::app | std::ios_base::in);
//    if (file.is_open()) {
//        file << std::to_string(score) << std::endl;
//    } else{
//        std::ofstream myfile;
//        myfile.open ("../score.txt");
//        myfile << std::to_string(score)<<std::endl;
//        myfile.close();
//    }
    std::ofstream myfile;
    myfile.open ("../score.txt");
    int y=0;
    for(auto score : scores){
        y++;
        if(y==10){
            break;
        }
        myfile << std::to_string(score)<<std::endl;
    }

    myfile.close();
}

void Game::getHighscores() {
    std::string myText;

    std::ifstream MyReadFile("../score.txt");
    while (getline (MyReadFile, myText)) {

        try{
            int x = std::stoi(myText);
            scores.push_back(x);

        }
        catch(std::exception &err)
        {
            std::cout<<"Corrupted highscore"<<std::endl;
        }
    }
    sort(scores.begin(), scores.end());
    std::reverse(scores.begin(), scores.end());


}


