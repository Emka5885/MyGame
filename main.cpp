//My first game :)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML\Graphics.hpp>
#include "MyFunctions.h"
#include "Collision.h"
#include "Goal.h"
#include "Platform.h"
#include "Player.h"

const int COUNT = 600;
int seconds1;
int seconds2;
int ammun = 30;
int vibrations = 6;
int speed = 50;
int rate_of_fire = 1200;
int tv = 200;
int tv2 = 200;
int sensitivity = 10;
bool menu = true;
bool test = false;
bool test2 = false;
bool b1 = false;
bool hit = false;
bool end = true;
bool focus = true;
bool end_of_time = false;
bool end_of_time1 = true;
bool endg = false;
bool cursorEndGame = true;
bool cursorMenu = true;
bool speedbar = false;
bool speedbar2 = false;
bool game = false;
bool pause = false;
bool pause1 = true;
bool settings = false;
bool instruction = false;
bool select_player = false;
bool change = false;
bool resetrof = false;
bool select_mouse = true;
bool select_mouse2 = false;
bool stop = true;
bool p2_exists = false;
bool pla2;
int times = 60;
sf::Time ts = sf::seconds(times);
sf::Time tspeed = sf::milliseconds(speed);
sf::Time speedb = sf::milliseconds(rate_of_fire);
sf::Cursor c;
sf::CircleShape cursor_mouse(2);
sf::CircleShape cursor_mouse2(2);

void score(int& s, int row);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

    //Menu
    sf::Font font;
    if (!font.loadFromFile("Resources/Font/MilkyNice.ttf"))
    {
        std::cout << "Errorf00" << std::endl;
        system("PAUSE");
    }
    sf::Text menu_text;
    menu_text.setFont(font);
    menu_text.setString("Menu");
    menu_text.setCharacterSize(100);
    menu_text.setFillColor(sf::Color::Black);
    menu_text.setPosition(465, 5);

    sf::RectangleShape rec1;
    rec1.setSize({ 400, 100 });
    rec1.setPosition(400, 150);
    rec1.setOutlineThickness(3);
    rec1.setOutlineColor(sf::Color::Black);
    sf::Text n_game;
    n_game.setFont(font);
    n_game.setString("New Game");
    n_game.setCharacterSize(60);
    n_game.setFillColor(sf::Color::Black);
    n_game.setPosition(450, 160);

    sf::RectangleShape rec2;
    rec2.setSize({ 400, 100 });
    rec2.setPosition(400, 270);
    rec2.setOutlineThickness(3);
    rec2.setOutlineColor(sf::Color::Black);
    sf::Text continue_game;
    continue_game.setFont(font);
    continue_game.setString("Continue");
    continue_game.setCharacterSize(60);
    continue_game.setFillColor(sf::Color::Black);
    continue_game.setPosition(470, 280);

    sf::Text player;
    player.setFont(font);
    player.setString("Player");
    player.setCharacterSize(60);
    player.setFillColor(sf::Color::Black);
    player.setPosition(506, 280);

    sf::RectangleShape rec3;
    rec3.setSize({ 400, 100 });
    rec3.setOutlineThickness(3);
    rec3.setOutlineColor(sf::Color::Black);
    rec3.setPosition(400, 390);
    sf::Text options;
    options.setFont(font);
    options.setString("Options");
    options.setCharacterSize(60);
    options.setFillColor(sf::Color::Black);
    options.setPosition(480, 400);

    sf::RectangleShape rec4;
    rec4.setSize({ 400, 100 });
    rec4.setOutlineThickness(3);
    rec4.setOutlineColor(sf::Color::Black);
    rec4.setPosition(400, 510);
    sf::Text manual;
    manual.setFont(font);
    manual.setString("Help");
    manual.setCharacterSize(60);
    manual.setFillColor(sf::Color::Black);
    manual.setPosition(532, 520);

    sf::RectangleShape rec5;
    rec5.setSize({ 400, 100 });
    rec5.setOutlineThickness(3);
    rec5.setOutlineColor(sf::Color::Black);
    rec5.setPosition(400, 630);
    sf::Text quit;
    quit.setFont(font);
    quit.setString("Quit");
    quit.setCharacterSize(60);
    quit.setFillColor(sf::Color::Black);
    quit.setPosition(533, 640);

    //Options
    sf::Texture buttonl;
    if (!buttonl.loadFromFile("Resources/Button/Left.png"))
    {
        std::cout << "ErrorBL" << std::endl;
        system("PAUSE");
    }
    sf::Texture buttonr;
    if (!buttonr.loadFromFile("Resources/Button/Right.png"))
    {
        std::cout << "ErrorBR" << std::endl;
        system("PAUSE");
    }

    sf::Text options_text;
    options_text.setFont(font);
    options_text.setString("Options");
    options_text.setCharacterSize(100);
    options_text.setFillColor(sf::Color::Black);
    options_text.setPosition(413, 5);

    //Back
    sf::RectangleShape rec0o;
    rec0o.setSize({ 100, 50 });
    rec0o.setOrigin(rec0o.getSize().x / 2, rec0o.getSize().y / 2);
    rec0o.setPosition(200, 90);
    rec0o.setOutlineThickness(3);
    rec0o.setOutlineColor(sf::Color::Black);
    sf::Text back_text;
    back_text.setFont(font);
    back_text.setString("Back");
    back_text.setCharacterSize(30);
    back_text.setFillColor(sf::Color::Black);
    back_text.setPosition(162, 70);

    //Default
    sf::RectangleShape recdo;
    recdo.setSize({ 130, 50 });
    recdo.setOrigin(recdo.getSize().x / 2, recdo.getSize().y / 2);
    recdo.setPosition(983, 90);
    recdo.setOutlineThickness(3);
    recdo.setOutlineColor(sf::Color::Black);
    sf::Text default_text;
    default_text.setFont(font);
    default_text.setString("Default");
    default_text.setCharacterSize(30);
    default_text.setFillColor(sf::Color::Black);
    default_text.setPosition(925, 70);

    //Ammunition
    sf::RectangleShape rec1o;
    rec1o.setSize({ 900, 80 });
    rec1o.setPosition(150, 150);
    rec1o.setOutlineThickness(3);
    rec1o.setOutlineColor(sf::Color::Black);
    sf::Text ammuo;
    ammuo.setFont(font);
    ammuo.setString("Ammunition");
    ammuo.setCharacterSize(38);
    ammuo.setFillColor(sf::Color::Black);
    ammuo.setPosition(180, 165);
    sf::Text ammuodash;
    ammuodash.setFont(font);
    ammuodash.setString("-");
    ammuodash.setCharacterSize(38);
    ammuodash.setFillColor(sf::Color::Black);
    ammuodash.setPosition(598, 170);
    sf::RectangleShape b1left;
    b1left.setSize({ 20, 30 });
    b1left.setTexture(&buttonl);
    b1left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b1left.setPosition(750, 192);
    sf::RectangleShape b1right;
    b1right.setSize({ 20, 30 });
    b1right.setTexture(&buttonr);
    b1right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b1right.setPosition(1000, 192);
    sf::Text ammun_text;
    ammun_text.setFont(font);
    ammun_text.setString(std::to_string(ammun));
    ammun_text.setCharacterSize(38);
    ammun_text.setFillColor(sf::Color::Black);
    if (ammun > 1 && ammun < 10)
        ammun_text.setPosition(868, 165);
    else
        ammun_text.setPosition(858, 165);

    //Time
    sf::RectangleShape rec2o;
    rec2o.setSize({ 900, 80 });
    rec2o.setPosition(150, 250);
    rec2o.setOutlineThickness(3);
    rec2o.setOutlineColor(sf::Color::Black);
    sf::Text timeso;
    timeso.setFont(font);
    timeso.setString("Time");
    timeso.setCharacterSize(38);
    timeso.setFillColor(sf::Color::Black);
    timeso.setPosition(180, 265);
    sf::Text timeodash;
    timeodash.setFont(font);
    timeodash.setString("-");
    timeodash.setCharacterSize(38);
    timeodash.setFillColor(sf::Color::Black);
    timeodash.setPosition(598, 270);
    sf::RectangleShape b2left;
    b2left.setSize({ 20, 30 });
    b2left.setTexture(&buttonl);
    b2left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b2left.setPosition(750, 292);
    sf::RectangleShape b2right;
    b2right.setSize({ 20, 30 });
    b2right.setTexture(&buttonr);
    b2right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b2right.setPosition(1000, 292);
    sf::Text times_text;
    times_text.setFont(font);
    times_text.setString(std::to_string(times));
    times_text.setCharacterSize(38);
    times_text.setFillColor(sf::Color::Black);
    if (times > 9 && times < 100)
        times_text.setPosition(858, 265);
    else
        times_text.setPosition(848, 265);

    //Vibrations
    sf::RectangleShape rec3o;
    rec3o.setSize({ 900, 80 });
    rec3o.setPosition(150, 350);
    rec3o.setOutlineThickness(3);
    rec3o.setOutlineColor(sf::Color::Black);
    sf::Text vibrationso;
    vibrationso.setFont(font);
    vibrationso.setString("Vibrations");
    vibrationso.setCharacterSize(38);
    vibrationso.setFillColor(sf::Color::Black);
    vibrationso.setPosition(180, 365);
    sf::Text vibodash;
    vibodash.setFont(font);
    vibodash.setString("-");
    vibodash.setCharacterSize(38);
    vibodash.setFillColor(sf::Color::Black);
    vibodash.setPosition(598, 370);
    sf::RectangleShape b3left;
    b3left.setSize({ 20, 30 });
    b3left.setTexture(&buttonl);
    b3left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b3left.setPosition(750, 392);
    sf::RectangleShape b3right;
    b3right.setSize({ 20, 30 });
    b3right.setTexture(&buttonr);
    b3right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b3right.setPosition(1000, 392);
    sf::Text vib_text;
    vib_text.setFont(font);
    vib_text.setString(std::to_string(vibrations));
    vib_text.setCharacterSize(38);
    vib_text.setFillColor(sf::Color::Black);
    if (vibrations > 1 && vibrations < 10)
        vib_text.setPosition(868, 365);
    else
        vib_text.setPosition(858, 365);

    //Speed of targets
    sf::RectangleShape rec4o;
    rec4o.setSize({ 900, 80 });
    rec4o.setPosition(150, 450);
    rec4o.setOutlineThickness(3);
    rec4o.setOutlineColor(sf::Color::Black);
    sf::Text speedoto;
    speedoto.setFont(font);
    speedoto.setString("Speed of targets");
    speedoto.setCharacterSize(38);
    speedoto.setFillColor(sf::Color::Black);
    speedoto.setPosition(180, 465);
    sf::Text sotodash;
    sotodash.setFont(font);
    sotodash.setString("-");
    sotodash.setCharacterSize(38);
    sotodash.setFillColor(sf::Color::Black);
    sotodash.setPosition(598, 470);
    sf::RectangleShape b4left;
    b4left.setSize({ 20, 30 });
    b4left.setTexture(&buttonl);
    b4left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b4left.setPosition(750, 492);
    sf::RectangleShape b4right;
    b4right.setSize({ 20, 30 });
    b4right.setTexture(&buttonr);
    b4right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b4right.setPosition(1000, 492);
    sf::Text sot_text;
    sot_text.setFont(font);
    sot_text.setString(std::to_string(speed));
    sot_text.setCharacterSize(38);
    sot_text.setFillColor(sf::Color::Black);
    if (speed > 9 && speed < 100)
        sot_text.setPosition(858, 465);
    else
        sot_text.setPosition(848, 465);

    //Rate of fire
    sf::RectangleShape rec5o;
    rec5o.setSize({ 900, 80 });
    rec5o.setPosition(150, 550);
    rec5o.setOutlineThickness(3);
    rec5o.setOutlineColor(sf::Color::Black);
    sf::Text rateoffireo;
    rateoffireo.setFont(font);
    rateoffireo.setString("Rate of fire");
    rateoffireo.setCharacterSize(38);
    rateoffireo.setFillColor(sf::Color::Black);
    rateoffireo.setPosition(180, 565);
    sf::Text rofodash;
    rofodash.setFont(font);
    rofodash.setString("-");
    rofodash.setCharacterSize(38);
    rofodash.setFillColor(sf::Color::Black);
    rofodash.setPosition(598, 570);
    sf::RectangleShape b5left;
    b5left.setSize({ 20, 30 });
    b5left.setTexture(&buttonl);
    b5left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b5left.setPosition(750, 592);
    sf::RectangleShape b5right;
    b5right.setSize({ 20, 30 });
    b5right.setTexture(&buttonr);
    b5right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b5right.setPosition(1000, 592);
    sf::Text rof_text;
    rof_text.setFont(font);
    rof_text.setString(std::to_string(rate_of_fire));
    rof_text.setCharacterSize(38);
    rof_text.setFillColor(sf::Color::Black);
    rof_text.setPosition(838, 565);

    //Vibration speed
    sf::RectangleShape rec6o;
    rec6o.setSize({ 900, 80 });
    rec6o.setPosition(150, 650);
    rec6o.setOutlineThickness(3);
    rec6o.setOutlineColor(sf::Color::Black);
    sf::Text sensitivityt;
    sensitivityt.setFont(font);
    sensitivityt.setString("Sensitivity (J)");
    sensitivityt.setCharacterSize(38);
    sensitivityt.setFillColor(sf::Color::Black);
    sensitivityt.setPosition(180, 665);
    sf::Text sodash;
    sodash.setFont(font);
    sodash.setString("-");
    sodash.setCharacterSize(38);
    sodash.setFillColor(sf::Color::Black);
    sodash.setPosition(598, 670);
    sf::RectangleShape b6left;
    b6left.setSize({ 20, 30 });
    b6left.setTexture(&buttonl);
    b6left.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    b6left.setPosition(750, 692);
    sf::RectangleShape b6right;
    b6right.setSize({ 20, 30 });
    b6right.setTexture(&buttonr);
    b6right.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    b6right.setPosition(1000, 692);
    sf::Text s_text;
    s_text.setFont(font);
    s_text.setString(std::to_string(sensitivity));
    s_text.setCharacterSize(38);
    s_text.setFillColor(sf::Color::Black);
    s_text.setPosition(858, 665);

    //Player
    sf::Image igun00;
    if (!igun00.loadFromFile("Resources/Gun/gun00.png"))
    {
        std::cout << "Errorig00" << std::endl;
        system("PAUSE");
    }
    sf::Texture tgun00;
    if (!tgun00.loadFromFile("Resources/Gun/gun00.png"))
    {
        std::cout << "Errortg00" << std::endl;
        system("PAUSE");
    }
    sf::Texture tgun01;
    if (!tgun01.loadFromFile("Resources/Gun/gun01.png"))
    {
        std::cout << "Errortg01" << std::endl;
        system("PAUSE");
    }
    sf::Image igun02;
    if (!igun02.loadFromFile("Resources/Gun/gun02.png"))
    {
        std::cout << "Errorig02" << std::endl;
        system("PAUSE");
    }
    sf::Texture tgun02;
    if (!tgun02.loadFromFile("Resources/Gun/gun02.png"))
    {
        std::cout << "Errortg02" << std::endl;
        system("PAUSE");
    }

    sf::Text player_text;
    player_text.setFont(font);
    player_text.setString("Player");
    player_text.setCharacterSize(100);
    player_text.setFillColor(sf::Color::Black);
    player_text.setPosition(445, 5);

    sf::RectangleShape rec1p;
    rec1p.setSize({ 400, 60 });
    rec1p.setPosition(150, 150);
    rec1p.setOutlineThickness(3);
    rec1p.setOutlineColor(sf::Color::Black);
    sf::Text player1;
    player1.setFont(font);
    player1.setString("Player 1");
    player1.setCharacterSize(38);
    player1.setFillColor(sf::Color::Black);
    player1.setPosition(270, 155);

    sf::RectangleShape rec3p;
    rec3p.setSize({ 400, 440 });
    rec3p.setPosition(150, 230);
    rec3p.setOutlineThickness(3);
    rec3p.setOutlineColor(sf::Color::Black);
    sf::RectangleShape recmp;
    recmp.setSize({ 74, 74 });
    recmp.setPosition(312, 365);
    recmp.setTexture(&tgun00);
    sf::Text mousep;
    mousep.setFont(font);
    mousep.setString("Mouse (M)");
    mousep.setCharacterSize(30);
    mousep.setFillColor(sf::Color::Black);
    mousep.setPosition(277, 475);
    sf::RectangleShape reccp;
    reccp.setSize({ 74, 74 });
    reccp.setPosition(312, 365);
    reccp.setTexture(&tgun01);
    sf::Text controllerp;
    controllerp.setFont(font);
    controllerp.setString("Joystick (J)");
    controllerp.setCharacterSize(30);
    controllerp.setFillColor(sf::Color::Black);
    controllerp.setPosition(273, 475);

    sf::RectangleShape bleft1p;
    bleft1p.setSize({ 20, 30 });
    bleft1p.setTexture(&buttonl);
    bleft1p.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    bleft1p.setPosition(175, 435);
    sf::RectangleShape bright1p;
    bright1p.setSize({ 20, 30 });
    bright1p.setTexture(&buttonr);
    bright1p.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    bright1p.setPosition(505, 435);

    sf::RectangleShape choosep11;
    choosep11.setSize({ 250, 50 });
    choosep11.setPosition(350, 595);
    choosep11.setOrigin(choosep11.getSize().x / 2, choosep11.getSize().y / 2);
    choosep11.setOutlineThickness(2);
    choosep11.setOutlineColor(sf::Color::Black);
    choosep11.setFillColor(sf::Color(210, 210, 210));
    sf::RectangleShape choosep12;
    choosep12.setSize({ 250, 50 });
    choosep12.setPosition(350, 595);
    choosep12.setOrigin(choosep12.getSize().x / 2, choosep12.getSize().y / 2);
    choosep12.setOutlineThickness(2);
    choosep12.setOutlineColor(sf::Color::Black);
    choosep12.setFillColor(sf::Color::White);
    sf::Text select1_text;
    select1_text.setFont(font);
    select1_text.setString("Select");
    select1_text.setCharacterSize(38);
    select1_text.setFillColor(sf::Color::Black);
    select1_text.setPosition(292, 572);

    sf::RectangleShape rec2p;
    rec2p.setSize({ 400, 60 });
    rec2p.setPosition(650, 150);
    rec2p.setOutlineThickness(3);
    rec2p.setOutlineColor(sf::Color::Black);
    sf::Text player2;
    player2.setFont(font);
    player2.setString("Player 2");
    player2.setCharacterSize(38);
    player2.setFillColor(sf::Color::Black);
    player2.setPosition(770, 155);
    sf::Text On_text;
    On_text.setFont(font);
    On_text.setString("Click");
    On_text.setCharacterSize(100);
    On_text.setFillColor(sf::Color::Black);
    On_text.setPosition(736, 386);

    sf::RectangleShape rec4p;
    rec4p.setSize({ 400, 440 });
    rec4p.setPosition(850, 450);
    rec4p.setOrigin(rec4p.getSize().x / 2, rec4p.getSize().y / 2);
    rec4p.setOutlineThickness(3);
    rec4p.setOutlineColor(sf::Color::Black);
    sf::RectangleShape recm2p;
    recm2p.setSize({ 74, 74 });
    recm2p.setPosition(812, 365);
    recm2p.setTexture(&tgun00);
    sf::Text mouse2p;
    mouse2p.setFont(font);
    mouse2p.setString("Mouse (M)");
    mouse2p.setCharacterSize(30);
    mouse2p.setFillColor(sf::Color::Black);
    mouse2p.setPosition(777, 475);
    sf::RectangleShape recc2p;
    recc2p.setSize({ 74, 74 });
    recc2p.setPosition(812, 365);
    recc2p.setTexture(&tgun01);
    sf::Text controller2p;
    controller2p.setFont(font);
    controller2p.setString("Joystick (J)");
    controller2p.setCharacterSize(30);
    controller2p.setFillColor(sf::Color::Black);
    controller2p.setPosition(771, 475);
    sf::RectangleShape choosep21;
    choosep21.setSize({ 250, 50 });
    choosep21.setPosition(850, 595);
    choosep21.setOrigin(choosep21.getSize().x / 2, choosep21.getSize().y / 2);
    choosep21.setOutlineThickness(2);
    choosep21.setOutlineColor(sf::Color::Black);
    choosep21.setFillColor(sf::Color::White);
    sf::RectangleShape choosep22;
    choosep22.setSize({ 250, 50 });
    choosep22.setPosition(850, 595);
    choosep22.setOrigin(choosep22.getSize().x / 2, choosep22.getSize().y / 2);
    choosep22.setOutlineThickness(2);
    choosep22.setOutlineColor(sf::Color::Black);
    choosep22.setFillColor(sf::Color(210, 210, 210));
    sf::Text select2_text;
    select2_text.setFont(font);
    select2_text.setString("Select");
    select2_text.setCharacterSize(38);
    select2_text.setFillColor(sf::Color::Black);
    select2_text.setPosition(792, 572);

    sf::Text Off_text;
    Off_text.setFont(font);
    Off_text.setString("Click to disable");
    Off_text.setCharacterSize(30);
    Off_text.setFillColor(sf::Color::Black);
    Off_text.setPosition(740, 257);
    sf::RectangleShape Offr;
    Offr.setSize({ 250, 50 });
    Offr.setOrigin(Offr.getSize().x / 2, Offr.getSize().y / 2);
    Offr.setPosition(850, 275);
    Offr.setOutlineThickness(2);
    Offr.setOutlineColor(sf::Color::Black);


    //Tekstury do animacji celu
    std::vector<sf::Texture> goalTextures;

    sf::Texture goal00;
    if (!goal00.loadFromFile("Resources/Goal/Bunny00.png"))
    {
        std::cout << "ErrorGB00" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goal00);

    sf::Texture goal01;
    if (!goal01.loadFromFile("Resources/Goal/Bunny01.png"))
    {
        std::cout << "ErrorGB01" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal02;
    if (!goal02.loadFromFile("Resources/Goal/Bunny02.png"))
    {
        std::cout << "ErrorGB02" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal03;
    if (!goal03.loadFromFile("Resources/Goal/Bunny03.png"))
    {
        std::cout << "ErrorGB03" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal04;
    if (!goal04.loadFromFile("Resources/Goal/Bunny04.png"))
    {
        std::cout << "ErrorGB04" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal05;
    if (!goal05.loadFromFile("Resources/Goal/Bunny05.png"))
    {
        std::cout << "ErrorGB05" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goal01);
    goalTextures.push_back(goal02);
    goalTextures.push_back(goal03);
    goalTextures.push_back(goal04);
    goalTextures.push_back(goal05);

    sf::Texture goal01r;
    if (!goal01r.loadFromFile("Resources/Goal/Bunny01r.png"))
    {
        std::cout << "ErrorGB01r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal02r;
    if (!goal02r.loadFromFile("Resources/Goal/Bunny02r.png"))
    {
        std::cout << "ErrorGB02r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal03r;
    if (!goal03r.loadFromFile("Resources/Goal/Bunny03r.png"))
    {
        std::cout << "ErrorGB03r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal04r;
    if (!goal04r.loadFromFile("Resources/Goal/Bunny04r.png"))
    {
        std::cout << "ErrorGB04r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal05r;
    if (!goal05r.loadFromFile("Resources/Goal/Bunny05r.png"))
    {
        std::cout << "ErrorGB05r" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goal01r);
    goalTextures.push_back(goal02r);
    goalTextures.push_back(goal03r);
    goalTextures.push_back(goal04r);
    goalTextures.push_back(goal05r);

    sf::Texture goalHit;
    if (!goalHit.loadFromFile("Resources/Goal/BunnyHit.png"))
    {
        std::cout << "ErrorGBH" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goalHit);


    Goal* goal1, * goal2, * goal3;

    srand(time(NULL));

    goal1 = new Goal(1, 0, rand() % 1000);
    goal2 = new Goal(2, 0, rand() % 1000);
    goal3 = new Goal(3, 0, rand() % 1000);
    goal1->setTexture(goalTextures, hit);
    goal2->setTexture(goalTextures, hit);
    goal3->setTexture(goalTextures, hit);

    Collision* collision;

    sf::Color c0(sf::Color(26, 26, 26));
    sf::Color c1(sf::Color(51, 51, 51));
    sf::Color c2(sf::Color(77, 77, 77));
    sf::Color c345(sf::Color::White);
    sf::Color c678910(sf::Color::Black);

    //Platforms
    std::vector<Platform> platformObject;

    Platform plat0(&c0, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 744.0f));
    Platform plat1(&c1, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 494.0f));
    Platform plat2(&c2, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 246.0f));
    platformObject.push_back(plat0);
    platformObject.push_back(plat1);
    platformObject.push_back(plat2);

    Platform plat3(&c345, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 500.0f));
    Platform plat4(&c345, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 250.0f));
    Platform plat5(&c345, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 0.0f));
    platformObject.push_back(plat3);
    platformObject.push_back(plat4);
    platformObject.push_back(plat5);

    Platform plat6(&c678910, sf::Vector2f(1200.0f, 80.0f), sf::Vector2f(0.0f, 0.0f));
    Platform plat7(&c678910, sf::Vector2f(1200.0f, 50.0f), sf::Vector2f(0.0f, 750.0f));
    Platform plat8(&c678910, sf::Vector2f(50.0f, 1200.0f), sf::Vector2f(0.0f, 0.0f));
    Platform plat9(&c678910, sf::Vector2f(50.0f, 1200.0f), sf::Vector2f(1150.0f, 0.0f));
    platformObject.push_back(plat6);
    platformObject.push_back(plat7);
    platformObject.push_back(plat8);
    platformObject.push_back(plat9);

    Platform plat10(&c678910, sf::Vector2f(1100.0f, 670.0f), sf::Vector2f(50.0f, 80.0f));
    platformObject.push_back(plat10);

    sf::Text textScore;
    textScore.setFont(font);
    textScore.setString("Score: 0");
    textScore.setCharacterSize(30);
    textScore.setFillColor(sf::Color::White);
    textScore.setPosition(51, 25);

    sf::Text textAmmunition;
    textAmmunition.setFont(font);
    textAmmunition.setCharacterSize(30);
    textAmmunition.setFillColor(sf::Color::White);
    textAmmunition.setPosition(251, 25);

    sf::Text textEnd;
    textEnd.setFont(font);
    textEnd.setCharacterSize(100);


    c.loadFromPixels(igun02.getPixelsPtr(), igun02.getSize(), {});
    Player p1(&igun02, &tgun02, vibrations, ammun, window, tv, select_mouse);
    if (p1.getMouse())
    {
        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
    }
    else
    {
        window.setMouseCursorVisible(false);
    }
    tv = p1.getTimeV();
    std::string p1samu = std::to_string(p1.getAmmunition());
    textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);

    Player p2(&igun02, &tgun02, vibrations, ammun, window, tv2, select_mouse2);
    std::string p2samu = std::to_string(p2.getAmmunition());

    sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::Time time;
    sf::Clock clock1;
    clock1.restart().asMilliseconds();
    sf::Clock clock2;
    clock2.restart().asMilliseconds();
    sf::Clock clock3;
    sf::Clock clock32;
    sf::Clock clock4;
    sf::Clock stopClick;
    stopClick.restart().asMilliseconds();
    clock4.restart().asSeconds();
    sf::Text textEndOfTime;
    textEndOfTime.setFont(font);
    textEndOfTime.setCharacterSize(40);
    textEndOfTime.setFillColor(sf::Color::White);
    textEndOfTime.setPosition(951, 20);
    int seconds = ts.asSeconds();
    textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");

    sf::Text textM;
    textM.setFont(font);
    textM.setCharacterSize(30);
    textM.setFillColor(sf::Color::White);
    textM.setPosition(13, 710);
    textM.setString("M");

    sf::Text textC;
    textC.setFont(font);
    textC.setCharacterSize(30);
    textC.setFillColor(sf::Color::White);
    textC.setPosition(1163, 710);
    textC.setString("C");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (!menu && !settings && !instruction)
                {
                    if (sf::Keyboard::Escape == event.key.code)
                    {
                        menu = true;
                        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
                        focus = true;
                    }
                }
                break;
            case sf::Event::MouseEntered:
                if (!menu)
                {
                    p1.create(window);
                    focus = true;
                    if (p1.getAmmunition() <= 0 || end_of_time)
                    {
                        window.setMouseCursor(c);
                    }
                }
                break;
            case sf::Event::MouseLeft:
                if (!menu)
                    focus = false;
                break;
            case sf::Event::MouseButtonReleased:
                //In Game
                if (!menu && !settings && !select_player)
                {
                    if (clock4.getElapsedTime().asSeconds() > 1)
                    {
                        if (!resetrof)
                            time = clock.getElapsedTime();
                        else
                        {
                            time = speedb;
                            resetrof = false;
                        }
                        if ((sf::Mouse::Button::Left == event.mouseButton.button) && (time.asMilliseconds() >= rate_of_fire) && (p1.getAmmunition() > 0) && (!p2_exists))
                        {
                            if (!end_of_time)
                            {
                                test = true;
                                p1.getAmmunition()--;
                                speedbar = true;
                                clock3.restart().asMilliseconds();
                                textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                            }
                        }
                        if ((sf::Mouse::Button::Left == event.mouseButton.button) && (time.asMilliseconds() >= rate_of_fire) && (p2.getAmmunition() > 0) && (p2_exists))
                        {
                            if (!end_of_time)
                            {
                                if (select_mouse2)
                                {
                                    test2 = true;
                                    p2.getAmmunition()--;
                                    speedbar2 = true;
                                    clock32.restart().asMilliseconds();
                                    textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                }
                                else
                                {
                                    test = true;
                                    p1.getAmmunition()--;
                                    speedbar = true;
                                    clock3.restart().asMilliseconds();
                                    textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                }
                            }
                        }
                    }
                }
                //Main menu
                else if (menu && !settings && !select_player)
                {
                    cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                    cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                    //New Game
                    if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 150 && cursor_mouse.getPosition().y < 250)
                    {
                        menu = false;
                        p1.reset();
                        if (p2_exists)
                            p2.reset();
                        seconds = ts.asSeconds();
                        end_of_time1 = true;
                        clock1.restart().asSeconds();
                        textScore.setString("Score: 0");
                        p1samu = std::to_string(p1.getAmmunition());
                        if (p2_exists)
                        {
                            p2samu = std::to_string(p2.getAmmunition());
                            textAmmunition.setPosition(401, 25);
                            textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                        }
                        else
                        {
                            textAmmunition.setPosition(251, 25);
                            textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        }
                        textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                        game = true;
                        pause = false;
                        pause1 = false;
                        change = false;
                        cursorEndGame = true;
                        resetrof = true;
                        end = true;
                        clock4.restart().asSeconds();
                    }
                    //Continue
                    else if (game == true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 270 && cursor_mouse.getPosition().y < 370)
                    {
                        menu = false;
                        if (pause1)
                        {
                            seconds2 = seconds2 - seconds1;
                            textEndOfTime.setString("Time: " + std::to_string(seconds2) + "s");
                        }
                        else
                        {
                            seconds2 = seconds - seconds1;
                            textEndOfTime.setString("Time: " + std::to_string(seconds2) + "s");
                        }
                        pause = true;
                        clock1.restart().asSeconds();
                        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
                        if (p2_exists && select_mouse2)
                            p1.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                        else
                            p2.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                    }
                    //Player
                    else if (game == false && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 270 && cursor_mouse.getPosition().y < 370)
                    {
                        menu = false;
                        select_player = true;
                    }
                    //Options
                    else if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 390 && cursor_mouse.getPosition().y < 490)
                    {
                        menu = false;
                        settings = true;
                    }
                    //Help
                    else if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 510 && cursor_mouse.getPosition().y < 610)
                    {
                        //menu = false;
                        //instruction = true;
                        std::cout << "Help" << std::endl;
                    }
                    //Quit
                    else if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 630 && cursor_mouse.getPosition().y < 730)
                    {
                        window.close();
                    }
                }
                //Settings
                else if (!menu && settings && !select_player)
                {
                    cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                    cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                    //Back
                    if (cursor_mouse.getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && cursor_mouse.getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && cursor_mouse.getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && cursor_mouse.getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)
                    {
                        settings = false;
                        menu = true;
                    }
                    //Default
                    else if (cursor_mouse.getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && cursor_mouse.getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && cursor_mouse.getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && cursor_mouse.getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2)
                    {
                        ammun = 30;
                        ammun_text.setString(std::to_string(ammun));
                        ammun_text.setPosition(858, 165);
                        p1.setAmmunition(ammun);
                        p1samu = std::to_string(p1.getAmmunition());
                        times = 60;
                        times_text.setString(std::to_string(times));
                        times_text.setPosition(858, 265);
                        vibrations = 6;
                        vib_text.setString(std::to_string(vibrations));
                        vib_text.setPosition(868, 365);
                        p1.setVibrations(vibrations);
                        speed = 50;
                        sot_text.setString(std::to_string(speed));
                        sot_text.setPosition(858, 465);
                        tspeed = sf::milliseconds(speed);
                        rate_of_fire = 1200;
                        rof_text.setString(std::to_string(rate_of_fire));
                        rof_text.setPosition(838, 565);
                        sensitivity = 10;
                        s_text.setString(std::to_string(sensitivity));
                        s_text.setPosition(858, 665);
                        p1.setTimeV(tv);
                        p2.setAmmunition(ammun);
                        p2samu = std::to_string(p2.getAmmunition());
                        p2.setVibrations(vibrations);
                        p2.setTimeV(tv);
                        if (!p2_exists)
                        {
                            textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        }
                        else
                        {
                            textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                        }
                        change = true;
                        speedbar = true;
                        speedbar2 = true;
                    }
                    //Ammunition
                    else if (cursor_mouse.getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && cursor_mouse.getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && cursor_mouse.getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && cursor_mouse.getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2)
                    {
                        if (ammun == 10)
                        {
                            ammun--;
                            ammun_text.setString(std::to_string(ammun));
                            ammun_text.setPosition(868, 165);
                        }
                        else if (ammun != 1)
                        {
                            ammun--;
                            ammun_text.setString(std::to_string(ammun));
                        }
                        change = true;
                        p1.setAmmunition(ammun);
                        p1samu = std::to_string(p1.getAmmunition());
                        p2.setAmmunition(ammun);
                        p2samu = std::to_string(p2.getAmmunition());
                        if (!p2_exists)
                            textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        else
                        {
                            textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                        }
                    }
                    else if (cursor_mouse.getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && cursor_mouse.getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && cursor_mouse.getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && cursor_mouse.getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2)
                    {
                        if (ammun == 9)
                        {
                            ammun++;
                            ammun_text.setString(std::to_string(ammun));
                            ammun_text.setPosition(858, 165);
                        }
                        else if (ammun != 99)
                        {
                            ammun++;
                            ammun_text.setString(std::to_string(ammun));
                        }
                        change = true;
                        p1.setAmmunition(ammun);
                        p1samu = std::to_string(p1.getAmmunition());
                        p2.setAmmunition(ammun);
                        p2samu = std::to_string(p2.getAmmunition());
                        if (!p2_exists)
                            textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        else
                        {
                            textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                        }
                    }
                    //Time
                    else if (cursor_mouse.getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && cursor_mouse.getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && cursor_mouse.getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && cursor_mouse.getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2)
                    {
                        if (times == 120)
                        {
                            times -= 30;
                            times_text.setString(std::to_string(times));
                            times_text.setPosition(858, 265);
                        }
                        else if (times != 30)
                        {
                            times -= 30;
                            times_text.setString(std::to_string(times));
                        }
                        change = true;
                        ts = sf::seconds(times);
                        seconds = ts.asSeconds();
                        textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                    }
                    else if (cursor_mouse.getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && cursor_mouse.getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && cursor_mouse.getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && cursor_mouse.getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2)
                    {
                        if (times == 120)
                        {
                            times += 30;
                            times_text.setString(std::to_string(times));
                            times_text.setPosition(848, 265);
                        }
                        else if (times != 990)
                        {
                            times += 30;
                            times_text.setString(std::to_string(times));
                        }
                        change = true;
                        ts = sf::seconds(times);
                        seconds = ts.asSeconds();
                        textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                    }
                    //Vibrations
                    else if (cursor_mouse.getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && cursor_mouse.getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && cursor_mouse.getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && cursor_mouse.getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2)
                    {
                        if (vibrations == 10)
                        {
                            vibrations--;
                            vib_text.setString(std::to_string(vibrations));
                            vib_text.setPosition(868, 365);
                        }
                        else if (vibrations != 1)
                        {
                            vibrations--;
                            vib_text.setString(std::to_string(vibrations));
                        }
                        p1.setVibrations(vibrations);
                        p2.setVibrations(vibrations);
                    }
                    else if (cursor_mouse.getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && cursor_mouse.getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && cursor_mouse.getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && cursor_mouse.getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2)
                    {
                        if (vibrations == 9)
                        {
                            vibrations++;
                            vib_text.setString(std::to_string(vibrations));
                            vib_text.setPosition(858, 365);
                        }
                        else if (vibrations != 50)
                        {
                            vibrations++;
                            vib_text.setString(std::to_string(vibrations));
                        }
                        p1.setVibrations(vibrations);
                        p2.setVibrations(vibrations);
                    }
                    //Speed of targets
                    else if (cursor_mouse.getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && cursor_mouse.getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && cursor_mouse.getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && cursor_mouse.getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2)
                    {
                        if (speed == 100)
                        {
                            speed -= 10;
                            sot_text.setString(std::to_string(speed));
                            sot_text.setPosition(858, 465);
                        }
                        else if (speed != 10)
                        {
                            speed -= 10;
                            sot_text.setString(std::to_string(speed));
                        }
                        change = true;
                        tspeed = sf::milliseconds(speed);
                    }
                    else if (cursor_mouse.getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && cursor_mouse.getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && cursor_mouse.getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && cursor_mouse.getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2)
                    {
                        if (speed == 90)
                        {
                            speed += 10;
                            sot_text.setString(std::to_string(speed));
                            sot_text.setPosition(848, 465);
                        }
                        else if (speed != 400)
                        {
                            speed += 10;
                            sot_text.setString(std::to_string(speed));
                        }
                        change = true;
                        tspeed = sf::milliseconds(speed);
                    }
                    //Rate of fire
                    else if (cursor_mouse.getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && cursor_mouse.getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && cursor_mouse.getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && cursor_mouse.getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2)
                    {
                        if (rate_of_fire == 1000)
                        {
                            rate_of_fire -= 100;
                            rof_text.setString(std::to_string(rate_of_fire));
                            rof_text.setPosition(848, 565);
                        }
                        else if (rate_of_fire != 100)
                        {
                            rate_of_fire -= 100;
                            rof_text.setString(std::to_string(rate_of_fire));
                        }
                        change = true;
                        speedb = sf::milliseconds(rate_of_fire);
                        speedbar = true;
                        speedbar2 = true;
                    }
                    else if (cursor_mouse.getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && cursor_mouse.getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && cursor_mouse.getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && cursor_mouse.getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2)
                    {
                        if (rate_of_fire == 900)
                        {
                            rate_of_fire += 100;
                            rof_text.setString(std::to_string(rate_of_fire));
                            rof_text.setPosition(838, 565);
                        }
                        else if (rate_of_fire != 5000)
                        {
                            rate_of_fire += 100;
                            rof_text.setString(std::to_string(rate_of_fire));
                        }
                        change = true;
                        speedb = sf::milliseconds(rate_of_fire);
                        speedbar = true;
                        speedbar2 = true;
                    }
                    //Vibration speed
                    else if (cursor_mouse.getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && cursor_mouse.getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && cursor_mouse.getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && cursor_mouse.getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2)
                    {
                        if (sensitivity == 10)
                        {
                            sensitivity--;
                            s_text.setString(std::to_string(sensitivity));
                            s_text.setPosition(868, 665);
                        }
                        else if (sensitivity != 1)
                        {
                            sensitivity--;
                            s_text.setString(std::to_string(sensitivity));
                        }
                    }
                    else if (cursor_mouse.getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && cursor_mouse.getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && cursor_mouse.getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && cursor_mouse.getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2)
                    {
                        if (sensitivity == 9)
                        {
                            sensitivity++;
                            s_text.setString(std::to_string(sensitivity));
                            s_text.setPosition(858, 665);
                        }
                        else if (sensitivity != 40)
                        {
                            sensitivity++;
                            s_text.setString(std::to_string(sensitivity));
                        }
                    }
                }
                else if (!menu && !settings && select_player)
                {
                    cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                    cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                    //Back
                    if (cursor_mouse.getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && cursor_mouse.getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && cursor_mouse.getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && cursor_mouse.getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)
                    {
                        select_player = false;
                        menu = true;
                    }
                    //
                    else if (cursor_mouse.getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)
                    {
                        select_mouse = false;
                    }
                    else if (cursor_mouse.getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)
                    {
                        select_mouse = true;
                    }
                    //Select
                    else if (cursor_mouse.getPosition().x >= choosep12.getPosition().x - choosep12.getSize().x / 2 && cursor_mouse.getPosition().x <= choosep12.getPosition().x + choosep12.getSize().x / 2 && cursor_mouse.getPosition().y >= choosep12.getPosition().y - choosep12.getSize().y / 2 && cursor_mouse.getPosition().y <= choosep12.getPosition().y + choosep12.getSize().y / 2)
                    {
                        if (stop)
                        {
                            std::cout << "Joystick is Disconnected" << std::endl;
                        }
                        else
                        {
                            p1.setMouse(select_mouse);
                            p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                            if (select_mouse)
                            {
                                select_mouse2 = false;
                                choosep11.setFillColor(sf::Color(210, 210, 210));
                                choosep12.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color::White);
                                choosep22.setFillColor(sf::Color(210, 210, 210));
                            }
                            else
                            {
                                select_mouse2 = true;
                                choosep11.setFillColor(sf::Color::White);
                                choosep12.setFillColor(sf::Color(210, 210, 210));
                                choosep21.setFillColor(sf::Color(210, 210, 210));
                                choosep22.setFillColor(sf::Color::White);
                            }
                            p2.setMouse(select_mouse2);
                        }
                    }
                    //Click
                    if (cursor_mouse.getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && cursor_mouse.getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && cursor_mouse.getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && cursor_mouse.getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2)
                    {
                        p2_exists = true;
                        textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                    }
                    if (cursor_mouse.getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && cursor_mouse.getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && cursor_mouse.getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && cursor_mouse.getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2)
                    {
                        p2_exists = false;
                        textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                    }
                }
                break;
            case sf::Event::JoystickDisconnected:
                stop = true;
                break;
            case sf::Event::JoystickButtonPressed:
                if (!menu && !settings && !instruction)
                {
                    if (sf::Joystick::isButtonPressed(0, 7))
                    {
                        menu = true;
                        p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                    }
                }
                break;
            case sf::Event::JoystickMoved:
                if (stopClick.getElapsedTime().asMilliseconds() >= 250)
                {
                    if (!menu && !settings && !select_player)
                    {
                        if (clock4.getElapsedTime().asSeconds() > 1)
                        {
                            if (!resetrof)
                                time = clock.getElapsedTime();
                            else
                            {
                                time = speedb;
                                resetrof = false;
                            }
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (time.asMilliseconds() >= rate_of_fire) && (p1.getAmmunition() > 0))
                            {
                                if (!end_of_time)
                                {
                                    if (p2_exists && !select_mouse2)
                                    {
                                        test2 = true;
                                        p2.getAmmunition()--;
                                        speedbar2 = true;
                                        clock32.restart().asMilliseconds();
                                    }
                                    else
                                    {
                                        test = true;
                                        p1.getAmmunition()--;
                                        speedbar = true;
                                        clock3.restart().asMilliseconds();
                                    }
                                    if (!p2_exists)
                                        textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                                    else
                                        textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                }
                            }
                        }
                    }
                    //Main menu
                    else if (menu && !settings && !select_player)
                    {
                        //New Game
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 150 && p1.getRec().getPosition().y < 250) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 150 && p2.getRec().getPosition().y < 250)))
                        {
                            menu = false;
                            p1.reset();
                            if (p2_exists)
                                p2.reset();
                            seconds = ts.asSeconds();
                            end_of_time1 = true;
                            clock1.restart().asSeconds();
                            textScore.setString("Score: 0");
                            p1samu = std::to_string(p1.getAmmunition());
                            if (p2_exists)
                            {
                                p2samu = std::to_string(p2.getAmmunition());
                                textAmmunition.setPosition(401, 25);
                                textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                            }
                            else
                            {
                                textAmmunition.setPosition(251, 25);
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                            textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                            game = true;
                            pause = false;
                            pause1 = false;
                            change = false;
                            cursorEndGame = true;
                            resetrof = true;
                            end = true;
                            clock4.restart().asSeconds();
                        }
                        //Continue
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (game == true) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 270 && p2.getRec().getPosition().y < 370)))
                        {
                            menu = false;
                            if (pause1)
                            {
                                seconds2 = seconds2 - seconds1;
                                textEndOfTime.setString("Time: " + std::to_string(seconds2) + "s");
                            }
                            else
                            {
                                seconds2 = seconds - seconds1;
                                textEndOfTime.setString("Time: " + std::to_string(seconds2) + "s");
                            }
                            pause = true;
                            clock1.restart().asSeconds();
                            if (select_mouse)
                                p1.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                            else
                                p2.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                            if (p2_exists)
                                sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
                        }
                        //Player
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (game == false) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 270 && p2.getRec().getPosition().y < 370)))
                        {
                            menu = false;
                            select_player = true;
                        }
                        //Options
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 390 && p1.getRec().getPosition().y < 490) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 390 && p2.getRec().getPosition().y < 490)))
                        {
                            menu = false;
                            settings = true;
                        }
                        //Help
                        //else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 510 && p1.getRec().getPosition().y < 610) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 510 && p2.getRec().getPosition().y < 610)))
                        //{
                        //    //menu = false;
                        //    //instruction = true;
                        //    std::cout << "Help" << std::endl;
                        //}
                        //Quit
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 630 && p1.getRec().getPosition().y < 730) || (p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 630 && p2.getRec().getPosition().y < 730)))
                        {
                            window.close();
                        }
                    }
                    //Settings
                    else if (!menu && settings && !select_player)
                    {
                        //Back
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)))
                        {
                            settings = false;
                            menu = true;
                        }
                        //Default
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p1.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p1.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p1.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2) || (p2.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p2.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p2.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p2.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2)))
                        {
                            ammun = 30;
                            ammun_text.setString(std::to_string(ammun));
                            ammun_text.setPosition(858, 165);
                            p1.setAmmunition(ammun);
                            p1samu = std::to_string(p1.getAmmunition());
                            times = 60;
                            times_text.setString(std::to_string(times));
                            times_text.setPosition(858, 265);
                            vibrations = 6;
                            vib_text.setString(std::to_string(vibrations));
                            vib_text.setPosition(868, 365);
                            p1.setVibrations(vibrations);
                            speed = 50;
                            sot_text.setString(std::to_string(speed));
                            sot_text.setPosition(858, 465);
                            tspeed = sf::milliseconds(speed);
                            rate_of_fire = 1200;
                            rof_text.setString(std::to_string(rate_of_fire));
                            rof_text.setPosition(838, 565);
                            sensitivity = 10;
                            s_text.setString(std::to_string(sensitivity));
                            s_text.setPosition(858, 665);
                            p1.setTimeV(tv);
                            p2.setAmmunition(ammun);
                            p2samu = std::to_string(p2.getAmmunition());
                            p2.setVibrations(vibrations);
                            p2.setTimeV(tv);
                            if (!p2_exists)
                            {
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                            else
                            {
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                            change = true;
                            speedbar = true;
                            speedbar2 = true;
                        }
                        //Ammunition
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && p1.getRec().getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && p1.getRec().getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && p1.getRec().getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2) || (p2.getRec().getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && p2.getRec().getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && p2.getRec().getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && p2.getRec().getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2)))
                        {
                            if (ammun == 10)
                            {
                                ammun--;
                                ammun_text.setString(std::to_string(ammun));
                                ammun_text.setPosition(868, 165);
                            }
                            else if (ammun != 1)
                            {
                                ammun--;
                                ammun_text.setString(std::to_string(ammun));
                            }
                            change = true;
                            p1.setAmmunition(ammun);
                            p1samu = std::to_string(p1.getAmmunition());
                            p2.setAmmunition(ammun);
                            p2samu = std::to_string(p2.getAmmunition());
                            if (!p2_exists)
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            else
                            {
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && p1.getRec().getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && p1.getRec().getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && p1.getRec().getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2) || (p2.getRec().getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && p2.getRec().getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && p2.getRec().getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && p2.getRec().getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2)))
                        {
                            if (ammun == 9)
                            {
                                ammun++;
                                ammun_text.setString(std::to_string(ammun));
                                ammun_text.setPosition(858, 165);
                            }
                            else if (ammun != 99)
                            {
                                ammun++;
                                ammun_text.setString(std::to_string(ammun));
                            }
                            change = true;
                            p1.setAmmunition(ammun);
                            p1samu = std::to_string(p1.getAmmunition());
                            p2.setAmmunition(ammun);
                            p2samu = std::to_string(p2.getAmmunition());
                            if (!p2_exists)
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            else
                            {
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                        }
                        //Time
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && p1.getRec().getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && p1.getRec().getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && p1.getRec().getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2) || (p2.getRec().getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && p2.getRec().getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && p2.getRec().getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && p2.getRec().getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2)))
                        {
                            if (times == 120)
                            {
                                times -= 30;
                                times_text.setString(std::to_string(times));
                                times_text.setPosition(858, 265);
                            }
                            else if (times != 30)
                            {
                                times -= 30;
                                times_text.setString(std::to_string(times));
                            }
                            change = true;
                            ts = sf::seconds(times);
                            seconds = ts.asSeconds();
                            textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && p1.getRec().getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && p1.getRec().getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && p1.getRec().getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2) || (p2.getRec().getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && p2.getRec().getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && p2.getRec().getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && p2.getRec().getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2)))
                        {
                            if (times == 120)
                            {
                                times += 30;
                                times_text.setString(std::to_string(times));
                                times_text.setPosition(848, 265);
                            }
                            else if (times != 990)
                            {
                                times += 30;
                                times_text.setString(std::to_string(times));
                            }
                            change = true;
                            ts = sf::seconds(times);
                            seconds = ts.asSeconds();
                            textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                        }
                        //Vibrations
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && p1.getRec().getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && p1.getRec().getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && p1.getRec().getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2) || (p2.getRec().getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && p2.getRec().getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && p2.getRec().getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && p2.getRec().getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2)))
                        {
                            if (vibrations == 10)
                            {
                                vibrations--;
                                vib_text.setString(std::to_string(vibrations));
                                vib_text.setPosition(868, 365);
                            }
                            else if (vibrations != 1)
                            {
                                vibrations--;
                                vib_text.setString(std::to_string(vibrations));
                            }
                            p1.setVibrations(vibrations);
                            p2.setVibrations(vibrations);
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && p1.getRec().getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && p1.getRec().getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && p1.getRec().getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2) || (p2.getRec().getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && p2.getRec().getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && p2.getRec().getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && p2.getRec().getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2)))
                        {
                            if (vibrations == 9)
                            {
                                vibrations++;
                                vib_text.setString(std::to_string(vibrations));
                                vib_text.setPosition(858, 365);
                            }
                            else if (vibrations != 50)
                            {
                                vibrations++;
                                vib_text.setString(std::to_string(vibrations));
                            }
                            p1.setVibrations(vibrations);
                            p2.setVibrations(vibrations);
                        }
                        //Speed of targets
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && p1.getRec().getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && p1.getRec().getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && p1.getRec().getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2) || (p2.getRec().getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && p2.getRec().getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && p2.getRec().getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && p2.getRec().getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2)))
                        {
                            if (speed == 100)
                            {
                                speed -= 10;
                                sot_text.setString(std::to_string(speed));
                                sot_text.setPosition(858, 465);
                            }
                            else if (speed != 10)
                            {
                                speed -= 10;
                                sot_text.setString(std::to_string(speed));
                            }
                            change = true;
                            tspeed = sf::milliseconds(speed);
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && p1.getRec().getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && p1.getRec().getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && p1.getRec().getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2) || (p2.getRec().getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && p2.getRec().getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && p2.getRec().getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && p2.getRec().getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2)))
                        {
                            if (speed == 90)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                                sot_text.setPosition(848, 465);
                            }
                            else if (speed != 400)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                            }
                            change = true;
                            tspeed = sf::milliseconds(speed);
                        }
                        //Rate of fire
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && p1.getRec().getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && p1.getRec().getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && p1.getRec().getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2) || (p2.getRec().getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && p2.getRec().getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && p2.getRec().getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && p2.getRec().getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2)))
                        {
                            if (rate_of_fire == 1000)
                            {
                                rate_of_fire -= 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                                rof_text.setPosition(848, 565);
                            }
                            else if (rate_of_fire != 100)
                            {
                                rate_of_fire -= 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && p1.getRec().getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && p1.getRec().getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && p1.getRec().getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2) || (p2.getRec().getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && p2.getRec().getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && p2.getRec().getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && p2.getRec().getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2)))
                        {
                            if (rate_of_fire == 900)
                            {
                                rate_of_fire += 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                                rof_text.setPosition(838, 565);
                            }
                            else if (rate_of_fire != 5000)
                            {
                                rate_of_fire += 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        //Vibration speed
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && p1.getRec().getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && p1.getRec().getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && p1.getRec().getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2) || (p2.getRec().getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && p2.getRec().getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && p2.getRec().getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && p2.getRec().getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2)))
                        {
                            if (sensitivity == 10)
                            {
                                sensitivity--;
                                s_text.setString(std::to_string(sensitivity));
                                s_text.setPosition(868, 665);
                            }
                            else if (sensitivity != 1)
                            {
                                sensitivity--;
                                s_text.setString(std::to_string(sensitivity));
                            }
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && p1.getRec().getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && p1.getRec().getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && p1.getRec().getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2) || (p2.getRec().getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && p2.getRec().getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && p2.getRec().getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && p2.getRec().getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2)))
                        {
                            if (sensitivity == 9)
                            {
                                sensitivity++;
                                s_text.setString(std::to_string(sensitivity));
                                s_text.setPosition(858, 665);
                            }
                            else if (sensitivity != 40)
                            {
                                sensitivity++;
                                s_text.setString(std::to_string(sensitivity));
                            }
                        }
                    }
                    else if (!menu && !settings && select_player)
                    {
                        //Back
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)))
                        {
                            select_player = false;
                            menu = true;
                        }
                        //
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2) || (p2.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p2.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p2.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p2.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)))
                        {
                            select_mouse = false;
                        }
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2) || (p2.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)))
                        {
                            select_mouse = true;
                        }
                        //Select
                        else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= choosep11.getPosition().x - choosep11.getSize().x / 2 && p1.getRec().getPosition().x <= choosep11.getPosition().x + choosep11.getSize().x / 2 && p1.getRec().getPosition().y >= choosep11.getPosition().y - choosep11.getSize().y / 2 && p1.getRec().getPosition().y <= choosep11.getPosition().y + choosep11.getSize().y / 2) || (p2.getRec().getPosition().x >= choosep11.getPosition().x - choosep11.getSize().x / 2 && p2.getRec().getPosition().x <= choosep11.getPosition().x + choosep11.getSize().x / 2 && p2.getRec().getPosition().y >= choosep11.getPosition().y - choosep11.getSize().y / 2 && p2.getRec().getPosition().y <= choosep11.getPosition().y + choosep11.getSize().y / 2)))
                        {
                            p1.setMouse(select_mouse);
                            sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
                            if (select_mouse)
                            {
                                select_mouse2 = false;
                                choosep12.setFillColor(sf::Color::White);
                                choosep11.setFillColor(sf::Color(210, 210, 210));
                                choosep22.setFillColor(sf::Color(210, 210, 210));
                                choosep21.setFillColor(sf::Color::White);
                            }
                            else
                            {
                                select_mouse2 = true;
                                choosep12.setFillColor(sf::Color(210, 210, 210));
                                choosep11.setFillColor(sf::Color::White);
                                choosep22.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color(210, 210, 210));
                            }
                            p2.setMouse(select_mouse2);
                        }
                        //Click
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && p1.getRec().getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && p1.getRec().getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && p1.getRec().getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2) || (p2.getRec().getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && p2.getRec().getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && p2.getRec().getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && p2.getRec().getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2)))
                        {
                            p2_exists = true;
                            textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                        }
                        if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && ((p1.getRec().getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && p1.getRec().getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && p1.getRec().getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && p1.getRec().getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2) || (p2.getRec().getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && p2.getRec().getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && p2.getRec().getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && p2.getRec().getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2)))
                        {
                            p2_exists = false;
                            textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        }
                    }
                    stopClick.restart().asMilliseconds();
                }

                //if (!p1.getMouse())
                //{
                //    if (event.type == sf::Event::JoystickMoved)
                //    {
                //        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                //        p1.getRec().move(m.x * 0.05, m.y * 0.05);
                //    }
                //}
                //else if (p2_exists)
                //{
                //    if (event.type == sf::Event::JoystickMoved)
                //    {
                //        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                //        p2.getRec().move(m.x * 0.05, m.y * 0.05);
                //    }
                //}
                break;
            }
        }
        if (sf::Joystick::isConnected(0))
        {
            stop = false;
        }

        if (p2_exists)
        {
            window.setMouseCursorVisible(true);
        }
        else if (!p1.getMouse())
        {
            window.setMouseCursorVisible(false);
        }
        else
        {
            window.setMouseCursorVisible(true);
        }



        if (menu)
        {
            if (!p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }
            else if (p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }

            if (cursorMenu)
            {
                p1.setImage(igun02, window);
                p1.getRec().setTexture(&tgun02);
                cursorMenu = false;
                p2.setImage(igun02, window);
                p2.getRec().setTexture(&tgun02);
            }
            window.clear(sf::Color::White);

            //platformObject[6].create(window);
            //platformObject[7].create(window);
            //platformObject[8].create(window);
            //platformObject[9].create(window);

            window.draw(menu_text);

            window.draw(rec1);
            window.draw(n_game);

            if (game && !change)
            {
                window.draw(rec2);
                window.draw(continue_game);
                window.draw(rec3);
                window.draw(options);
                window.draw(rec4);
                window.draw(manual);
                window.draw(rec5);
                window.draw(quit);
            }
            else
            {
                game = false;
                window.draw(rec2);
                window.draw(player);
                window.draw(rec3);
                window.draw(options);
                window.draw(rec4);
                window.draw(manual);
                window.draw(rec5);
                window.draw(quit);
            }


            if (!p1.getMouse())
            {
                window.draw(p1.getRec());
            }
            else if (p2_exists)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else if (settings)
        {
            if (!p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }
            else if (p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }

            window.clear(sf::Color::White);

            window.draw(options_text);

            window.draw(rec0o);
            window.draw(back_text);

            window.draw(recdo);
            window.draw(default_text);

            window.draw(rec1o);
            window.draw(ammuo);
            window.draw(ammuodash);
            window.draw(b1left);
            window.draw(b1right);
            window.draw(ammun_text);

            window.draw(rec2o);
            window.draw(timeso);
            window.draw(timeodash);
            window.draw(b2left);
            window.draw(b2right);
            window.draw(times_text);

            window.draw(rec3o);
            window.draw(vibrationso);
            window.draw(vibodash);
            window.draw(b3left);
            window.draw(b3right);
            window.draw(vib_text);

            window.draw(rec4o);
            window.draw(speedoto);
            window.draw(sotodash);
            window.draw(b4left);
            window.draw(b4right);
            window.draw(sot_text);

            window.draw(rec5o);
            window.draw(rateoffireo);
            window.draw(rofodash);
            window.draw(b5left);
            window.draw(b5right);
            window.draw(rof_text);

            window.draw(rec6o);
            window.draw(sensitivityt);
            window.draw(sodash);
            window.draw(b6left);
            window.draw(b6right);
            window.draw(s_text);

            if (!p1.getMouse())
            {
                window.draw(p1.getRec());
            }
            else if (p2_exists)
            {
                window.draw(p2.getRec());
            }

            window.display();

        }
        else if (select_player)
        {
            if (!p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }
            else if (p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.001, m.y * 0.001);
                }
            }

            window.clear(sf::Color::White);

            window.draw(player_text);

            window.draw(rec0o);
            window.draw(back_text);

            window.draw(rec1p);
            window.draw(player1);
            window.draw(rec3p);

            window.draw(rec2p);
            window.draw(player2);
            window.draw(rec4p);

            if (select_mouse)
            {
                window.draw(recmp);
                window.draw(mousep);
                window.draw(bright1p);
                window.draw(choosep11);
                select1_text.setPosition(292, 572);
                window.draw(select1_text);
            }
            else
            {
                window.draw(reccp);
                window.draw(controllerp);
                window.draw(bleft1p);
                window.draw(choosep12);
                select2_text.setPosition(292, 572);
                window.draw(select2_text);
            }

            if (p2_exists && !select_mouse2)
            {
                window.draw(Offr);
                window.draw(Off_text);

                window.draw(recc2p);
                window.draw(controller2p);
                window.draw(choosep22);
                select1_text.setPosition(792, 572);
                window.draw(select1_text);
            }
            else if (p2_exists && select_mouse2)
            {
                window.draw(Offr);
                window.draw(Off_text);

                window.draw(recm2p);
                window.draw(mouse2p);
                window.draw(choosep21);
                select2_text.setPosition(792, 572);
                window.draw(select2_text);
            }
            else
            {
                window.draw(On_text);
            }


            if (!p1.getMouse())
            {
                window.draw(p1.getRec());
            }
            else if (p2_exists)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else if (instruction)
        {

        }
        else
        {
            if (!p1.getMouse() && p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (p2_exists && p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (!p1.getMouse() && !p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0008, m.y * 0.0008);
                }
            }

            if (!cursorMenu)
            {
                p1.setImage(igun00, window);
                p1.getRec().setTexture(&tgun01);
                cursorMenu = true;
                p2.setImage(igun00, window);
                p2.getRec().setTexture(&tgun01);
            }

            sf::Time c1get = clock1.getElapsedTime();
            seconds1 = c1get.asSeconds();

            if (end_of_time1 && !pause)
            {
                if (seconds - seconds1 == 0)
                {
                    end_of_time = true;
                    textEndOfTime.setString("Time: " + std::to_string(seconds - seconds1) + "s");
                    end_of_time1 = false;
                    if (!p2_exists)
                        textAmmunition.setString("Ammunition: 0/" + p1samu);
                    else
                        textAmmunition.setString("Ammunition: p1.0/" + p1samu + "  p2.0/" + p2samu);
                }
                else
                {
                    textEndOfTime.setString("Time: " + std::to_string(seconds - seconds1) + "s");
                }
            }
            else if (end_of_time1 && pause)
            {
                if (seconds2 - seconds1 == 0)
                {
                    end_of_time = true;
                    textEndOfTime.setString("Time: " + std::to_string(seconds2 - seconds1) + "s");
                    end_of_time1 = false;
                    if (!p2_exists)
                        textAmmunition.setString("Ammunition: 0/" + p1samu);
                    else
                        textAmmunition.setString("Ammunition: p1.0/" + p1samu + "  p2.0/" + p2samu);
                }
                else
                {
                    textEndOfTime.setString("Time: " + std::to_string(seconds2 - seconds1) + "s");
                }
                pause1 = true;
            }
            else
            {
                textEndOfTime.setString("Time: 0s");
            }

            if (!p1.getMouse() && p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (p2_exists && p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (!p1.getMouse() && !p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0008, m.y * 0.0008);
                }
            }

            if (test || test2)
            {
                if (p2_exists && select_mouse2 && test2)
                {
                    p2.bullet(window, sf::Mouse::getPosition(window));
                    pla2 = true;
                }
                else if (p2_exists && !select_mouse2 && test2)
                {
                    p2.bullet(window, sf::Vector2i(p2.getRec().getPosition().x - p2.getRec().getSize().x / 2, p2.getRec().getPosition().y - p2.getRec().getSize().y / 2));
                    pla2 = true;
                }
                else if (p1.getMouse())
                {
                    p1.bullet(window, sf::Mouse::getPosition(window));
                    pla2 = false;
                }
                else
                {
                    p1.bullet(window, sf::Vector2i(p1.getRec().getPosition().x - p1.getRec().getSize().x / 2, p1.getRec().getPosition().y - p1.getRec().getSize().y / 2));
                    pla2 = false;
                }

                sf::CircleShape circle1;
                if (p2_exists && pla2)
                    circle1 = p2.getBullet();
                else
                    circle1 = p1.getBullet();
                Collision collision(circle1);
                sf::CircleShape g1 = goal1->getBody();   //row1
                sf::CircleShape g2 = goal2->getBody();   //row2
                sf::CircleShape g3 = goal3->getBody();   //row3

                if (collision.checkCollision(g1, 1) && !p2_exists)
                {
                    score(p1.getScore(), 1);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g2, 2) && !p2_exists)
                {
                    score(p1.getScore(), 2);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g3, 3) && !p2_exists)
                {
                    score(p1.getScore(), 3);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g1, 1) && !pla2)
                {
                    score(p1.getScore(), 1);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g2, 2) && !pla2)
                {
                    score(p1.getScore(), 2);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g3, 3) && !pla2)
                {
                    score(p1.getScore(), 3);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g1, 1) && pla2)
                {
                    score(p2.getScore(), 1);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g2, 2) && pla2)
                {
                    score(p2.getScore(), 2);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g3, 3) && pla2)
                {
                    score(p2.getScore(), 3);
                    textScore.setString("Score: 1p." + std::to_string(p1.getScore()) + "  2p." + std::to_string(p2.getScore()));
                    hit = true;
                }

                test = false;
                test2 = false;
                b1 = true;
            }

            if (!p1.getMouse() && p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (p2_exists && p1.getMouse())
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p2.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                }
            }
            else if (!p1.getMouse() && !p2_exists)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0008, m.y * 0.0008);
                }
            }

            if ((p2.getAmmunition() > 0 || p1.getAmmunition() > 0) && !end_of_time && !endg)
            {
                if (!p2_exists && p1.getAmmunition() == 0)
                {
                    endg = true;
                }
                if (tv == 0 && ((select_mouse && focus) || (!select_mouse)) && !p2_exists)
                {
                    int p1_v = p1.getVibrations();
                    int yes_or_no = rand() % 2;
                    if (yes_or_no == 0)
                    {
                        int rmx = (rand() % p1_v);
                        int rmy = (rand() % p1_v);
                        if (p1.getMouse())
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p1.getRec().move(rmx, rmy);
                    }
                    else
                    {
                        int rmx = (rand() % p1_v) * -1;
                        int rmy = (rand() % p1_v) * -1;
                        if (p1.getMouse())
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p1.getRec().move(rmx, rmy);
                    }

                    tv = p1.getTimeV();
                }
                else if (tv != 0 && ((select_mouse && focus) || (!select_mouse)) && !p2_exists)
                {
                    tv--;
                }

                /*if (tv2 == 0 && ((p2_exists && !select_mouse && focus) || (p2_exists && select_mouse)))
                {
                    int p2_v = p2.getVibrations();
                    int yes_or_no = rand() % 2;
                    if (yes_or_no == 0)
                    {
                        int rmx = (rand() % p2_v);
                        int rmy = (rand() % p2_v);
                        if (p2.getMouse())
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p2.getRec().move(rmx, rmy);
                    }
                    else
                    {
                        int rmx = (rand() % p2_v) * -1;
                        int rmy = (rand() % p2_v) * -1;
                        if (p2.getMouse())
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p2.getRec().move(rmx, rmy);
                    }

                    tv2 = p2.getTimeV();
                }
                else if (tv2 != 0 && ((p2_exists && !select_mouse && focus) || (p2_exists && select_mouse)))
                {
                    tv2--;
                }*/

                if (b1 && !pla2)
                {
                    p1.bullet_delete();
                    b1 = false;
                    clock.restart().asMilliseconds();
                }
                else if (b1 && pla2)
                {
                    p2.bullet_delete();
                    b1 = false;
                    clock.restart().asMilliseconds();
                }

                if (!goal1->existence())
                {
                    delete goal1;
                    goal1 = new Goal(1, 0, rand() % 1000);
                    goal1->setTexture(goalTextures, hit);
                }
                if (!goal2->existence())
                {
                    delete goal2;
                    goal2 = new Goal(2, 0, rand() % 1000);
                    goal2->setTexture(goalTextures, hit);
                }
                if (!goal3->existence())
                {
                    delete goal3;
                    goal3 = new Goal(3, 0, rand() % 1000);
                    goal3->setTexture(goalTextures, hit);
                }

                if (clock2.getElapsedTime() >= tspeed)
                {
                    goal1->setTexture(goalTextures, hit);
                    goal2->setTexture(goalTextures, hit);
                    goal3->setTexture(goalTextures, hit);
                    goal1->move(hit);
                    goal2->move(hit);
                    goal3->move(hit);
                    clock2.restart().asMilliseconds();
                }

                window.clear();

                platformObject[5].create(window);
                goal3->create(window);
                platformObject[2].create(window);

                platformObject[4].create(window);
                goal2->create(window);
                platformObject[1].create(window);

                platformObject[3].create(window);
                goal1->create(window);
                platformObject[0].create(window);


                platformObject[6].create(window);
                platformObject[7].create(window);
                platformObject[8].create(window);
                platformObject[9].create(window);

                float tym = 0;
                if (resetrof)
                {
                    speedbar = false;
                    speedbar2 = false;
                    if (!p2_exists)
                    {
                        p1.getSB().setSize({ 10.0f, 600.0f });
                        if (p1.getMouse())
                            p1.getSB().setPosition(20, 100);
                        else
                            p1.getSB().setPosition(1170, 100);
                    }
                    else
                    {
                        p1.getSB().setSize({ 10.0f, 600.0f });
                        p2.getSB().setSize({ 10.0f, 600.0f });
                        if (p1.getMouse())
                            p1.getSB().setPosition(20, 100);
                        else
                            p1.getSB().setPosition(1170, 100);
                        if (p2.getMouse())
                            p2.getSB().setPosition(20, 100);
                        else
                            p2.getSB().setPosition(1170, 100);
                    }

                }
                if (speedbar && clock3.getElapsedTime() < speedb)
                {
                    tym = clock3.getElapsedTime().asMilliseconds() - tym;
                    int change = tym / rate_of_fire * COUNT;
                    p1.getSB().setSize({ 10.0f, 600.0f - change });
                    if (p1.getMouse())
                        p1.getSB().setPosition(20, 100 + change);
                    else
                        p1.getSB().setPosition(1170, 100 + change);
                    window.draw(p1.getSB());
                    if (clock3.getElapsedTime() >= speedb)
                    {
                        speedbar = false;
                        p1.getSB().setSize({ 10.0f, 600.0f });
                        if (p1.getMouse())
                            p1.getSB().setPosition(20, 100);
                        else
                            p1.getSB().setPosition(1170, 100);
                    }
                }
                if (speedbar2 && clock32.getElapsedTime() < speedb)
                {
                    tym = clock32.getElapsedTime().asMilliseconds() - tym;
                    int change = tym / rate_of_fire * COUNT;
                    p2.getSB().setSize({ 10.0f, 600.0f - change });
                    if (p2.getMouse())
                        p2.getSB().setPosition(20, 100 + change);
                    else
                        p2.getSB().setPosition(1170, 100 + change);
                    window.draw(p2.getSB());
                    if (clock32.getElapsedTime() >= speedb)
                    {
                        speedbar2 = false;
                        p2.getSB().setSize({ 10.0f, 600.0f });
                        if (p2.getMouse())
                            p2.getSB().setPosition(20, 100);
                        else
                            p2.getSB().setPosition(1170, 100);
                    }
                }

                if (!p1.getMouse())
                {
                    window.draw(p1.getRec());
                }
                else if (p2_exists)
                {
                    window.draw(p2.getRec());
                }

                window.draw(textScore);
                window.draw(textAmmunition);
                window.draw(textEndOfTime);
                if (p1.getMouse() && !p2_exists)
                    window.draw(textM);
                else if (!p1.getMouse() && !p2_exists)
                    window.draw(textC);
                else
                {
                    window.draw(textM);
                    window.draw(textC);
                }

                window.display();
            }
            else
            {
                if (!p1.getMouse() && p2_exists)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p1.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                    }
                }
                else if (p2_exists && p1.getMouse())
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p2.getRec().move(m.x * 0.0001 * sensitivity, m.y * 0.0001 * sensitivity);
                    }
                }
                else if (!p1.getMouse() && !p2_exists)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p1.getRec().move(m.x * 0.001, m.y * 0.001);
                    }
                }

                if (cursorEndGame)
                {
                    window.setMouseCursor(c);
                    p1.setImage(igun02, window);
                    p1.getRec().setTexture(&tgun02);
                    p2.setImage(igun02, window);
                    p2.getRec().setTexture(&tgun02);
                    cursorEndGame = false;
                    end_of_time1 = false;
                    game = false;
                    endg = false;
                }

                window.clear(sf::Color::White);

                int check = clock2.getElapsedTime().asMilliseconds();
                platformObject[6].create(window);
                platformObject[7].create(window);
                platformObject[8].create(window);
                platformObject[9].create(window);

                if (check >= 50 * 30)
                {
                    if (end)
                    {
                        textEnd.setString("End");
                        textEnd.setFillColor(sf::Color::Red);
                        textEnd.setPosition(400, 350);
                        end = false;
                    }
                    else
                    {
                        textEnd.setString("Game");
                        textEnd.setFillColor(sf::Color::Black);
                        textEnd.setPosition(650, 350);
                        end = true;
                    }
                    clock2.restart().asMilliseconds();
                }

                window.draw(textEnd);

                if (!p1.getMouse())
                {
                    window.draw(p1.getRec());
                }
                else if (p2_exists)
                {
                    window.draw(p2.getRec());
                }

                window.draw(textScore);
                window.draw(textAmmunition);
                window.draw(textEndOfTime);

                window.display();
            }
        }
    }

    system("PAUSE");
    return 0;
}