//My first game :)          (Young master of aiming)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
int speed = 150;
int rate_of_fire = 1200;
int tv = 1000;
int tv2 = 1000;
int sensitivity = 20;
int helpc = 0;
int hcount = 1;
bool menu = true;
bool music = false;
bool musicOn = true;
bool mOn = true;
bool smOn = true;
int hit1_counter = 1;
int hit2_counter = 2;
int reload1_counter = 1;
int reload2_counter = 2;
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
int selectmjk = 1;
int selectmjk1 = 1;
int selectmjk2 = 3;
bool stop = true;
bool p2_exists = false;
bool music_stop = false;
bool pla2;
bool reloadSoundCounter = true;
bool reloadSoundCounter2 = true;
bool volumeM = true;
int times = 60;
int randMusic = 1;
int volumeConst = 25;
int volume = volumeConst;
int volumeConst1 = 40;
int volume1 = volumeConst1;
int mClockS = 1;
sf::Time ts = sf::seconds(times);
sf::Time tspeed = sf::milliseconds(210 - speed);
sf::Time speedb = sf::milliseconds(rate_of_fire);
sf::Time speedb2 = sf::milliseconds(rate_of_fire);
sf::Cursor c;
sf::CircleShape cursor_mouse(2);

sf::SoundBuffer hit01SoundBuffer;
sf::SoundBuffer hit02SoundBuffer;
sf::SoundBuffer hit03SoundBuffer;
sf::SoundBuffer hit04SoundBuffer;
sf::SoundBuffer hit05SoundBuffer;
sf::SoundBuffer hit06SoundBuffer;
sf::SoundBuffer reload01SoundBuffer;
sf::SoundBuffer reload02SoundBuffer;
sf::SoundBuffer reload03SoundBuffer;
sf::SoundBuffer reload04SoundBuffer;
sf::SoundBuffer reload05SoundBuffer;
sf::SoundBuffer reload06SoundBuffer;
sf::SoundBuffer menuSoundBuffer;

sf::Sound hit1Sound;
sf::Sound hit2Sound;
sf::Sound reload1Sound;
sf::Sound reload2Sound;
sf::Sound menuSound;

sf::Music music_01;
sf::Music music_02;
sf::Music music_03;
sf::Music music_04;
sf::Music music_05;
sf::Music music_06;
sf::Music music_07;
sf::Music music_08;
sf::Music music_09;
sf::Clock musicClock;


void score(int& s, int row);

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Young master of aiming", sf::Style::Close | sf::Style::Titlebar);

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

    //Note
    sf::Texture note;
    if (!note.loadFromFile("Resources/Music/note.png"))
    {
        std::cout << "ErrorMN" << std::endl;
        system("PAUSE");
    }
    sf::RectangleShape rec6;
    rec6.setSize({ 50, 50 });
    rec6.setOrigin(rec6.getSize().x / 2, rec6.getSize().y / 2);
    rec6.setPosition(925, 705);
    rec6.setOutlineThickness(1.5);
    rec6.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec7;
    rec7.setSize({ 40, 40 });
    rec7.setTexture(&note);
    rec7.setOrigin(rec7.getSize().x / 2, rec7.getSize().y / 2);
    rec7.setPosition(925, 705);

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
    b1right.setPosition(1005, 192);
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
    b2left.setOrigin(b2left.getSize().x / 2, b2left.getSize().y / 2);
    b2left.setPosition(750, 292);
    sf::RectangleShape b2right;
    b2right.setSize({ 20, 30 });
    b2right.setTexture(&buttonr);
    b2right.setOrigin(b2right.getSize().x / 2, b2right.getSize().y / 2);
    b2right.setPosition(1005, 292);
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
    b3left.setOrigin(b3left.getSize().x / 2, b3left.getSize().y / 2);
    b3left.setPosition(750, 392);
    sf::RectangleShape b3right;
    b3right.setSize({ 20, 30 });
    b3right.setTexture(&buttonr);
    b3right.setOrigin(b3right.getSize().x / 2, b3right.getSize().y / 2);
    b3right.setPosition(1005, 392);
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
    b4left.setOrigin(b4left.getSize().x / 2, b4left.getSize().y / 2);
    b4left.setPosition(750, 492);
    sf::RectangleShape b4right;
    b4right.setSize({ 20, 30 });
    b4right.setTexture(&buttonr);
    b4right.setOrigin(b4right.getSize().x / 2, b4right.getSize().y / 2);
    b4right.setPosition(1005, 492);
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
    b5right.setPosition(1005, 592);
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
    sensitivityt.setString("Sensitivity (J) & (K)");
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
    b6right.setPosition(1005, 692);
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
    window.setIcon(igun00.getSize().x, igun00.getSize().y, igun00.getPixelsPtr());
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
    sf::Texture tgun03;
    if (!tgun03.loadFromFile("Resources/Gun/gun03.png"))
    {
        std::cout << "Errortg03" << std::endl;
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
    sf::RectangleShape reckp;
    reckp.setSize({ 74, 74 });
    reckp.setPosition(312, 365);
    reckp.setTexture(&tgun03);
    sf::Text keyboardp;
    keyboardp.setFont(font);
    keyboardp.setString("Keyboard (K)");
    keyboardp.setCharacterSize(30);
    keyboardp.setFillColor(sf::Color::Black);
    keyboardp.setPosition(260, 475);

    sf::RectangleShape bleft1p;
    bleft1p.setSize({ 20, 30 });
    bleft1p.setTexture(&buttonl);
    bleft1p.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    bleft1p.setPosition(195, 435);
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
    sf::RectangleShape choosep13;
    choosep13.setSize({ 250, 50 });
    choosep13.setPosition(350, 595);
    choosep13.setOrigin(choosep13.getSize().x / 2, choosep13.getSize().y / 2);
    choosep13.setOutlineThickness(2);
    choosep13.setOutlineColor(sf::Color::Black);
    choosep13.setFillColor(sf::Color::White);
    sf::Text select1_text;
    select1_text.setFont(font);
    select1_text.setString("Select");
    select1_text.setCharacterSize(38);
    select1_text.setFillColor(sf::Color::Black);
    select1_text.setPosition(292, 572);
    sf::Text select2_text;
    select2_text.setFont(font);
    select2_text.setString("Select");
    select2_text.setCharacterSize(38);
    select2_text.setFillColor(sf::Color::Black);
    select2_text.setPosition(792, 572);
    sf::Text select3_text;
    select3_text.setFont(font);
    select3_text.setString("Select");
    select3_text.setCharacterSize(38);
    select3_text.setFillColor(sf::Color::Black);
    select3_text.setPosition(292, 572);

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

    sf::RectangleShape bleft2p;
    bleft2p.setSize({ 20, 30 });
    bleft2p.setTexture(&buttonl);
    bleft2p.setOrigin(b2left.getSize().x / 2, b2left.getSize().y / 2);
    bleft2p.setPosition(695, 435);
    sf::RectangleShape bright2p;
    bright2p.setSize({ 20, 30 });
    bright2p.setTexture(&buttonr);
    bright2p.setOrigin(b2right.getSize().x / 2, b2right.getSize().y / 2);
    bright2p.setPosition(1005, 435);

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
    sf::RectangleShape reck2p;
    reck2p.setSize({ 74, 74 });
    reck2p.setPosition(812, 365);
    reck2p.setTexture(&tgun03);
    sf::Text keyboard2p;
    keyboard2p.setFont(font);
    keyboard2p.setString("Keyboard (K)");
    keyboard2p.setCharacterSize(30);
    keyboard2p.setFillColor(sf::Color::Black);
    keyboard2p.setPosition(760, 475);

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
    choosep22.setFillColor(sf::Color::White);
    sf::RectangleShape choosep23;
    choosep23.setSize({ 250, 50 });
    choosep23.setPosition(850, 595);
    choosep23.setOrigin(choosep23.getSize().x / 2, choosep23.getSize().y / 2);
    choosep23.setOutlineThickness(2);
    choosep23.setOutlineColor(sf::Color::Black);
    choosep23.setFillColor(sf::Color(210, 210, 210));

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

    //Help
    sf::Texture tmouse0h;
    if (!tmouse0h.loadFromFile("Resources/Help/Mouse/mouse0.png"))
    {
        std::cout << "Errortm0h" << std::endl;
        system("PAUSE");
    }
    sf::Texture tmouse01h;
    if (!tmouse01h.loadFromFile("Resources/Help/Mouse/mouse01.png"))
    {
        std::cout << "Errortm01h" << std::endl;
        system("PAUSE");
    }
    sf::Texture tmouse1lh;
    if (!tmouse1lh.loadFromFile("Resources/Help/Mouse/mouse1l.png"))
    {
        std::cout << "Errortm1lh" << std::endl;
        system("PAUSE");
    }

    sf::Texture tcontroller0;
    if (!tcontroller0.loadFromFile("Resources/Help/Controller/controller0.png"))
    {
        std::cout << "Errortc0" << std::endl;
        system("PAUSE");
    }
    sf::Texture tcontroller00;
    if (!tcontroller00.loadFromFile("Resources/Help/Controller/controller00.png"))
    {
        std::cout << "Errortc00" << std::endl;
        system("PAUSE");
    }
    sf::Texture tcontroller1lj;
    if (!tcontroller1lj.loadFromFile("Resources/Help/Controller/controller1lj.png"))
    {
        std::cout << "Errortc1lj" << std::endl;
        system("PAUSE");
    }
    sf::Texture tcontroller1rt;
    if (!tcontroller1rt.loadFromFile("Resources/Help/Controller/controller1rt.png"))
    {
        std::cout << "Errortc1rt" << std::endl;
        system("PAUSE");
    }
    sf::Texture tcontroller1s;
    if (!tcontroller1s.loadFromFile("Resources/Help/Controller/controller1s.png"))
    {
        std::cout << "Errortc1s" << std::endl;
        system("PAUSE");
    }

    sf::Texture tkeyboard0;
    if (!tkeyboard0.loadFromFile("Resources/Help/Keyboard/keyboard0.png"))
    {
        std::cout << "Errortk0" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1w;
    if (!tkeyboard1w.loadFromFile("Resources/Help/Keyboard/keyboard1w.png"))
    {
        std::cout << "Errortk1w" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1s;
    if (!tkeyboard1s.loadFromFile("Resources/Help/Keyboard/keyboard1s.png"))
    {
        std::cout << "Errortk1s" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1a;
    if (!tkeyboard1a.loadFromFile("Resources/Help/Keyboard/keyboard1a.png"))
    {
        std::cout << "Errortk1a" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1d;
    if (!tkeyboard1d.loadFromFile("Resources/Help/Keyboard/keyboard1d.png"))
    {
        std::cout << "Errortk1d" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard0Space;
    if (!tkeyboard0Space.loadFromFile("Resources/Help/Keyboard/keyboard0space.png"))
    {
        std::cout << "Errortk0space" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1Space;
    if (!tkeyboard1Space.loadFromFile("Resources/Help/Keyboard/keyboard1space.png"))
    {
        std::cout << "Errortk1space" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard0Esc;
    if (!tkeyboard0Esc.loadFromFile("Resources/Help/Keyboard/keyboard0esc.png"))
    {
        std::cout << "Errortk0esc" << std::endl;
        system("PAUSE");
    }
    sf::Texture tkeyboard1Esc;
    if (!tkeyboard1Esc.loadFromFile("Resources/Help/Keyboard/keyboard1esc.png"))
    {
        std::cout << "Errortk1esc" << std::endl;
        system("PAUSE");
    }

    sf::Text help_text;
    help_text.setFont(font);
    help_text.setString("Help");
    help_text.setCharacterSize(100);
    help_text.setFillColor(sf::Color::Black);
    help_text.setPosition(492, 5);

    sf::RectangleShape rec0h;
    rec0h.setSize({ 600, 600 });
    rec0h.setPosition(300, 150);
    rec0h.setOutlineThickness(3);
    rec0h.setOutlineColor(sf::Color::Black);

    sf::Text textH1;
    textH1.setFont(font);
    textH1.setString("Mouse player");
    textH1.setCharacterSize(40);
    textH1.setFillColor(sf::Color::Black);
    textH1.setPosition(468, 175);

    sf::RectangleShape recm0h;
    recm0h.setSize({ 50, 50 });
    recm0h.setPosition(650, 300);
    recm0h.setTexture(&tgun00);
    sf::RectangleShape recm1h;
    recm1h.setSize({ 100, 125 });
    recm1h.setPosition(400, 265);
    recm1h.setTexture(&tmouse0h);

    sf::RectangleShape recht;
    recht.setSize({ 596, 196 });
    recht.setPosition(302, 552);
    recht.setOutlineThickness(5);
    recht.setOutlineColor(sf::Color::Black);

    sf::Text textm11h;
    textm11h.setFont(font);
    textm11h.setString("The pointer movement in the game");
    textm11h.setCharacterSize(25);
    textm11h.setFillColor(sf::Color::Black);
    textm11h.setPosition(375, 608);
    sf::Text textm12h;
    textm12h.setFont(font);
    textm12h.setString("corresponds to the mouse movement.");
    textm12h.setCharacterSize(25);
    textm12h.setFillColor(sf::Color::Black);
    textm12h.setPosition(375, 658);

    sf::Text textH2;
    textH2.setFont(font);
    textH2.setString("Controller player");
    textH2.setCharacterSize(40);
    textH2.setFillColor(sf::Color::Black);
    textH2.setPosition(434, 175);

    sf::RectangleShape recc0h;
    recc0h.setSize({ 50, 50 });
    recc0h.setPosition(650, 300);
    recc0h.setTexture(&tgun01);
    sf::RectangleShape recc1h;
    recc1h.setSize({ 190, 125 });
    recc1h.setPosition(400, 315);
    recc1h.setTexture(&tcontroller0);

    sf::Text textH3;
    textH3.setFont(font);
    textH3.setString("Keyboard player");
    textH3.setCharacterSize(40);
    textH3.setFillColor(sf::Color::Black);
    textH3.setPosition(437, 175);

    sf::RectangleShape reck0h;
    reck0h.setSize({ 50, 50 });
    reck0h.setPosition(650, 300);
    reck0h.setTexture(&tgun03);
    sf::RectangleShape reck1h;
    reck1h.setSize({ 240, 150 });
    reck1h.setPosition(350, 300);
    reck1h.setTexture(&tkeyboard0);
    sf::RectangleShape reck2h;
    reck2h.setSize({ 500, 100 });
    reck2h.setPosition(350, 350);
    reck2h.setTexture(&tkeyboard0Space);
    sf::RectangleShape reck3h;
    reck3h.setSize({ 200, 200 });
    reck3h.setPosition(500, 300);
    reck3h.setTexture(&tkeyboard0Esc);

    sf::RectangleShape bleft1h;
    bleft1h.setSize({ 20, 30 });
    bleft1h.setTexture(&buttonl);
    bleft1h.setOrigin(b1left.getSize().x / 2, b1left.getSize().y / 2);
    bleft1h.setPosition(255, 435);
    sf::RectangleShape bright1h;
    bright1h.setSize({ 20, 30 });
    bright1h.setTexture(&buttonr);
    bright1h.setOrigin(b1right.getSize().x / 2, b1right.getSize().y / 2);
    bright1h.setPosition(945, 435);

    //Music
    sf::Text music_text;
    music_text.setFont(font);
    music_text.setString("Music");
    music_text.setCharacterSize(100);
    music_text.setFillColor(sf::Color::Black);
    music_text.setPosition(450, 5);

    sf::RectangleShape rec0n;
    rec0n.setSize({ 400, 200 });
    rec0n.setPosition(400, 300);
    rec0n.setOutlineThickness(10);
    rec0n.setOutlineColor(sf::Color::Black);
    sf::Text NoteOn;
    NoteOn.setFont(font);
    NoteOn.setString("On");
    NoteOn.setCharacterSize(65);
    NoteOn.setFillColor(sf::Color::Black);
    NoteOn.setPosition(557, 358);


    sf::Texture tvolume0;
    if (!tvolume0.loadFromFile("Resources/Music/volume.png"))
    {
        std::cout << "Errortv0" << std::endl;
        system("PAUSE");
    }
    sf::Texture tvolume1;
    if (!tvolume1.loadFromFile("Resources/Music/volume_minus.png"))
    {
        std::cout << "Errortv1" << std::endl;
        system("PAUSE");
    }
    sf::Texture tvolume2;
    if (!tvolume2.loadFromFile("Resources/Music/volume_plus.png"))
    {
        std::cout << "Errortv2" << std::endl;
        system("PAUSE");
    }
    sf::Texture tvolume3;
    if (!tvolume3.loadFromFile("Resources/Music/volume_stop.png"))
    {
        std::cout << "Errortv3" << std::endl;
        system("PAUSE");
    }

    if (!hit01SoundBuffer.loadFromFile("Resources/Sounds/hit_01.wav"))
    {
        std::cout << "Errorsbh01" << std::endl;
    }
    if (!hit02SoundBuffer.loadFromFile("Resources/Sounds/hit_02.wav"))
    {
        std::cout << "Errorsbh02" << std::endl;
    }
    if (!hit03SoundBuffer.loadFromFile("Resources/Sounds/hit_03.wav"))
    {
        std::cout << "Errorsbh03" << std::endl;
    }
    if (!hit04SoundBuffer.loadFromFile("Resources/Sounds/hit_04.wav"))
    {
        std::cout << "Errorsbh04" << std::endl;
    }
    if (!hit05SoundBuffer.loadFromFile("Resources/Sounds/hit_05.wav"))
    {
        std::cout << "Errorsbh05" << std::endl;
    }
    if (!hit06SoundBuffer.loadFromFile("Resources/Sounds/hit_06.wav"))
    {
        std::cout << "Errorsbh06" << std::endl;
    }
    hit1Sound.setBuffer(hit01SoundBuffer);
    hit2Sound.setBuffer(hit02SoundBuffer);

    if (!reload01SoundBuffer.loadFromFile("Resources/Sounds/reload_01.wav"))
    {
        std::cout << "Errorsbr01" << std::endl;
    }
    if (!reload02SoundBuffer.loadFromFile("Resources/Sounds/reload_02.wav"))
    {
        std::cout << "Errorsbr02" << std::endl;
    }
    if (!reload03SoundBuffer.loadFromFile("Resources/Sounds/reload_03.wav"))
    {
        std::cout << "Errorsbr03" << std::endl;
    }
    if (!reload04SoundBuffer.loadFromFile("Resources/Sounds/reload_04.wav"))
    {
        std::cout << "Errorsbr04" << std::endl;
    }
    if (!reload05SoundBuffer.loadFromFile("Resources/Sounds/reload_05.wav"))
    {
        std::cout << "Errorsbr05" << std::endl;
    }
    if (!reload06SoundBuffer.loadFromFile("Resources/Sounds/reload_06.wav"))
    {
        std::cout << "Errorsbr06" << std::endl;
    }
    reload1Sound.setBuffer(reload01SoundBuffer);
    reload2Sound.setBuffer(reload02SoundBuffer);

    if (!menuSoundBuffer.loadFromFile("Resources/Sounds/sound_menu.wav"))
    {
        std::cout << "Errorsbm01" << std::endl;
    }
    menuSound.setBuffer(menuSoundBuffer);
    hit1Sound.setVolume(volumeConst1);
    hit2Sound.setVolume(volumeConst1);
    reload1Sound.setVolume(volumeConst1);
    reload2Sound.setVolume(volumeConst1);
    menuSound.setVolume(volumeConst1);


    if (!music_01.openFromFile("Resources/Music/music_01.ogg"))
    {
        std::cout << "Errormm01" << std::endl;
    }
    if (!music_02.openFromFile("Resources/Music/music_02.ogg"))
    {
        std::cout << "Errormm02" << std::endl;
    }
    if (!music_03.openFromFile("Resources/Music/music_03.ogg"))
    {
        std::cout << "Errormm03" << std::endl;
    }
    if (!music_04.openFromFile("Resources/Music/music_04.ogg"))
    {
        std::cout << "Errormm04" << std::endl;
    }
    if (!music_05.openFromFile("Resources/Music/music_05.ogg"))
    {
        std::cout << "Errormm05" << std::endl;
    }
    if (!music_06.openFromFile("Resources/Music/music_06.ogg"))
    {
        std::cout << "Errormm06" << std::endl;
    }
    if (!music_07.openFromFile("Resources/Music/music_07.ogg"))
    {
        std::cout << "Errormm07" << std::endl;
    }
    if (!music_08.openFromFile("Resources/Music/music_08.ogg"))
    {
        std::cout << "Errormm08" << std::endl;
    }
    if (!music_09.openFromFile("Resources/Music/music_09.ogg"))
    {
        std::cout << "Errormm09" << std::endl;
    }
    music_01.setLoop(true);
    music_01.setVolume(volumeConst);
    music_02.setLoop(true);
    music_02.setVolume(volumeConst);
    music_03.setLoop(true);
    music_03.setVolume(volumeConst);
    music_04.setLoop(true);
    music_04.setVolume(volumeConst);
    music_05.setLoop(true);
    music_05.setVolume(volumeConst);
    music_06.setLoop(true);
    music_06.setVolume(volumeConst);
    music_07.setLoop(true);
    music_07.setVolume(volumeConst);
    music_08.setLoop(true);
    music_08.setVolume(volumeConst);
    music_09.setLoop(true);
    music_09.setVolume(volumeConst);


    sf::RectangleShape rec1n;
    rec1n.setSize({ 900, 80 });
    rec1n.setPosition(150, 150);
    rec1n.setOutlineThickness(3);
    rec1n.setOutlineColor(sf::Color::Black);
    sf::Text MusicN;
    MusicN.setFont(font);
    MusicN.setString("Music");
    MusicN.setCharacterSize(38);
    MusicN.setFillColor(sf::Color::Black);
    MusicN.setPosition(180, 165);
    sf::Text musicDash;
    musicDash.setFont(font);
    musicDash.setString("-");
    musicDash.setCharacterSize(38);
    musicDash.setFillColor(sf::Color::Black);
    musicDash.setPosition(610, 170);
    sf::RectangleShape bn1left;
    bn1left.setSize({ 20, 30 });
    bn1left.setTexture(&buttonl);
    bn1left.setOrigin(bn1left.getSize().x / 2, bn1left.getSize().y / 2);
    bn1left.setPosition(750, 192);
    sf::RectangleShape bn1right;
    bn1right.setSize({ 20, 30 });
    bn1right.setTexture(&buttonr);
    bn1right.setOrigin(bn1right.getSize().x / 2, bn1right.getSize().y / 2);
    bn1right.setPosition(1005, 192);
    sf::Text MusicNT;
    MusicNT.setFont(font);
    MusicNT.setString("On");
    MusicNT.setCharacterSize(38);
    MusicNT.setFillColor(sf::Color::Black);
    MusicNT.setPosition(850, 165);

    sf::RectangleShape rec12n;
    rec12n.setSize({ 50, 50 });
    rec12n.setPosition(490, 165);
    rec12n.setOutlineThickness(2);
    rec12n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec121n;
    rec121n.setSize({ 40, 40 });
    rec121n.setPosition(495, 170);
    rec121n.setTexture(&tvolume0);
    sf::RectangleShape rec122n;
    rec122n.setSize({ 40, 40 });
    rec122n.setPosition(495, 170);
    rec122n.setTexture(&tvolume3);
    sf::Text volumeText;
    volumeText.setFont(font);
    volumeText.setString(std::to_string(volumeConst) + "%");
    volumeText.setCharacterSize(30);
    volumeText.setFillColor(sf::Color::Black);
    volumeText.setPosition(385, 172);
    sf::RectangleShape rec13n;
    rec13n.setSize({ 50, 50 });
    rec13n.setPosition(60, 165);
    rec13n.setOutlineThickness(2);
    rec13n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec131n;
    rec131n.setSize({ 40, 40 });
    rec131n.setPosition(65, 170);
    rec131n.setTexture(&tvolume1);
    sf::RectangleShape rec14n;
    rec14n.setSize({ 50, 50 });
    rec14n.setPosition(1090, 165);
    rec14n.setOutlineThickness(2);
    rec14n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec141n;
    rec141n.setSize({ 40, 40 });
    rec141n.setPosition(1095, 170);
    rec141n.setTexture(&tvolume2);

    sf::RectangleShape rec2n;
    rec2n.setSize({ 900, 80 });
    rec2n.setPosition(150, 250);
    rec2n.setOutlineThickness(3);
    rec2n.setOutlineColor(sf::Color::Black);
    sf::Text SoundsN;
    SoundsN.setFont(font);
    SoundsN.setString("Sounds");
    SoundsN.setCharacterSize(38);
    SoundsN.setFillColor(sf::Color::Black);
    SoundsN.setPosition(180, 265);
    sf::Text soundsDash;
    soundsDash.setFont(font);
    soundsDash.setString("-");
    soundsDash.setCharacterSize(38);
    soundsDash.setFillColor(sf::Color::Black);
    soundsDash.setPosition(610, 270);
    sf::RectangleShape bn2left;
    bn2left.setSize({ 20, 30 });
    bn2left.setTexture(&buttonl);
    bn2left.setOrigin(bn2left.getSize().x / 2, bn2left.getSize().y / 2);
    bn2left.setPosition(750, 292);
    sf::RectangleShape bn2right;
    bn2right.setSize({ 20, 30 });
    bn2right.setTexture(&buttonr);
    bn2right.setOrigin(bn2right.getSize().x / 2, bn2right.getSize().y / 2);
    bn2right.setPosition(1005, 292);
    sf::Text SoundsNT;
    SoundsNT.setFont(font);
    SoundsNT.setString("On");
    SoundsNT.setCharacterSize(38);
    SoundsNT.setFillColor(sf::Color::Black);
    SoundsNT.setPosition(850, 265);

    sf::RectangleShape rec22n;
    rec22n.setSize({ 50, 50 });
    rec22n.setPosition(490, 265);
    rec22n.setOutlineThickness(2);
    rec22n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec221n;
    rec221n.setSize({ 40, 40 });
    rec221n.setPosition(495, 270);
    rec221n.setTexture(&tvolume0);
    sf::Text volumeText1;
    volumeText1.setFont(font);
    volumeText1.setString(std::to_string(volumeConst1) + "%");
    volumeText1.setCharacterSize(30);
    volumeText1.setFillColor(sf::Color::Black);
    volumeText1.setPosition(385, 272);
    sf::RectangleShape rec23n;
    rec23n.setSize({ 50, 50 });
    rec23n.setPosition(60, 265);
    rec23n.setOutlineThickness(2);
    rec23n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec231n;
    rec231n.setSize({ 40, 40 });
    rec231n.setPosition(65, 270);
    rec231n.setTexture(&tvolume1);
    sf::RectangleShape rec24n;
    rec24n.setSize({ 50, 50 });
    rec24n.setPosition(1090, 265);
    rec24n.setOutlineThickness(2);
    rec24n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rec241n;
    rec241n.setSize({ 40, 40 });
    rec241n.setPosition(1095, 270);
    rec241n.setTexture(&tvolume2);

    sf::RectangleShape rec21n;
    rec21n.setSize({ 900, 80 });
    rec21n.setPosition(150, 350);
    rec21n.setOutlineThickness(3);
    rec21n.setOutlineColor(sf::Color::Black);
    sf::Text SoundsN1;
    SoundsN1.setFont(font);
    SoundsN1.setString("Hit sound  \t\t(P1)");
    SoundsN1.setCharacterSize(38);
    SoundsN1.setFillColor(sf::Color::Black);
    SoundsN1.setPosition(180, 365);
    sf::Text soundsDash1;
    soundsDash1.setFont(font);
    soundsDash1.setString("-");
    soundsDash1.setCharacterSize(38);
    soundsDash1.setFillColor(sf::Color::Black);
    soundsDash1.setPosition(610, 370);
    sf::RectangleShape bn21left;
    bn21left.setSize({ 20, 30 });
    bn21left.setTexture(&buttonl);
    bn21left.setOrigin(bn21left.getSize().x / 2, bn21left.getSize().y / 2);
    bn21left.setPosition(750, 392);
    sf::RectangleShape bn21right;
    bn21right.setSize({ 20, 30 });
    bn21right.setTexture(&buttonr);
    bn21right.setOrigin(bn21right.getSize().x / 2, bn21right.getSize().y / 2);
    bn21right.setPosition(1005, 392);
    sf::Text SoundsN1T;
    SoundsN1T.setFont(font);
    SoundsN1T.setString("1");
    SoundsN1T.setCharacterSize(38);
    SoundsN1T.setFillColor(sf::Color::Black);
    SoundsN1T.setPosition(868, 365);
    sf::RectangleShape rechs1n;
    rechs1n.setSize({ 50, 50 });
    rechs1n.setPosition(1090, 365);
    rechs1n.setOutlineThickness(2);
    rechs1n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rechs11n;
    rechs11n.setSize({ 40, 40 });
    rechs11n.setPosition(1095, 370);
    rechs11n.setTexture(&tvolume0);

    sf::RectangleShape rec3n;
    rec3n.setSize({ 900, 80 });
    rec3n.setPosition(150, 450);
    rec3n.setOutlineThickness(3);
    rec3n.setOutlineColor(sf::Color::Black);
    sf::Text sMucicN;
    sMucicN.setFont(font);
    sMucicN.setString("Reload sound\t(P1)");
    sMucicN.setCharacterSize(38);
    sMucicN.setFillColor(sf::Color::Black);
    sMucicN.setPosition(180, 465);
    sf::Text smndash;
    smndash.setFont(font);
    smndash.setString("-");
    smndash.setCharacterSize(38);
    smndash.setFillColor(sf::Color::Black);
    smndash.setPosition(610, 470);
    sf::RectangleShape bn3left;
    bn3left.setSize({ 20, 30 });
    bn3left.setTexture(&buttonl);
    bn3left.setOrigin(bn3left.getSize().x / 2, bn3left.getSize().y / 2);
    bn3left.setPosition(750, 492);
    sf::RectangleShape bn3right;
    bn3right.setSize({ 20, 30 });
    bn3right.setTexture(&buttonr);
    bn3right.setOrigin(bn3right.getSize().x / 2, bn3right.getSize().y / 2);
    bn3right.setPosition(1005, 492);
    sf::Text sMucicNT;
    sMucicNT.setFont(font);
    sMucicNT.setString("1");
    sMucicNT.setCharacterSize(38);
    sMucicNT.setFillColor(sf::Color::Black);
    sMucicNT.setPosition(868, 465);
    sf::RectangleShape recrs1n;
    recrs1n.setSize({ 50, 50 });
    recrs1n.setPosition(1090, 465);
    recrs1n.setOutlineThickness(2);
    recrs1n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape recrs11n;
    recrs11n.setSize({ 40, 40 });
    recrs11n.setPosition(1095, 470);
    recrs11n.setTexture(&tvolume0);


    sf::RectangleShape rec4n;
    rec4n.setSize({ 900, 80 });
    rec4n.setPosition(150, 550);
    rec4n.setOutlineThickness(3);
    rec4n.setOutlineColor(sf::Color::Black);
    sf::Text sSoundsN;
    sSoundsN.setFont(font);
    sSoundsN.setString("Hit sound  \t\t(P2)");
    sSoundsN.setCharacterSize(38);
    sSoundsN.setFillColor(sf::Color::Black);
    sSoundsN.setPosition(180, 565);
    sf::Text ssndash;
    ssndash.setFont(font);
    ssndash.setString("-");
    ssndash.setCharacterSize(38);
    ssndash.setFillColor(sf::Color::Black);
    ssndash.setPosition(610, 570);
    sf::RectangleShape bn4left;
    bn4left.setSize({ 20, 30 });
    bn4left.setTexture(&buttonl);
    bn4left.setOrigin(bn4left.getSize().x / 2, bn4left.getSize().y / 2);
    bn4left.setPosition(750, 592);
    sf::RectangleShape bn4right;
    bn4right.setSize({ 20, 30 });
    bn4right.setTexture(&buttonr);
    bn4right.setOrigin(bn4right.getSize().x / 2, bn4right.getSize().y / 2);
    bn4right.setPosition(1005, 592);
    sf::Text sSoundsNT;
    sSoundsNT.setFont(font);
    sSoundsNT.setString("2");
    sSoundsNT.setCharacterSize(38);
    sSoundsNT.setFillColor(sf::Color::Black);
    sSoundsNT.setPosition(868, 565);
    sf::RectangleShape rechs2n;
    rechs2n.setSize({ 50, 50 });
    rechs2n.setPosition(1090, 565);
    rechs2n.setOutlineThickness(2);
    rechs2n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape rechs21n;
    rechs21n.setSize({ 40, 40 });
    rechs21n.setPosition(1095, 570);
    rechs21n.setTexture(&tvolume0);

    sf::RectangleShape rec41n;
    rec41n.setSize({ 900, 80 });
    rec41n.setPosition(150, 650);
    rec41n.setOutlineThickness(3);
    rec41n.setOutlineColor(sf::Color::Black);
    sf::Text sSoundsN1;
    sSoundsN1.setFont(font);
    sSoundsN1.setString("Reload sound\t(P2)");
    sSoundsN1.setCharacterSize(38);
    sSoundsN1.setFillColor(sf::Color::Black);
    sSoundsN1.setPosition(180, 665);
    sf::Text ssndash1;
    ssndash1.setFont(font);
    ssndash1.setString("-");
    ssndash1.setCharacterSize(38);
    ssndash1.setFillColor(sf::Color::Black);
    ssndash1.setPosition(610, 670);
    sf::RectangleShape bn41left;
    bn41left.setSize({ 20, 30 });
    bn41left.setTexture(&buttonl);
    bn41left.setOrigin(bn41left.getSize().x / 2, bn41left.getSize().y / 2);
    bn41left.setPosition(750, 692);
    sf::RectangleShape bn41right;
    bn41right.setSize({ 20, 30 });
    bn41right.setTexture(&buttonr);
    bn41right.setOrigin(bn41right.getSize().x / 2, bn41right.getSize().y / 2);
    bn41right.setPosition(1005, 692);
    sf::Text sSoundsN1T;
    sSoundsN1T.setFont(font);
    sSoundsN1T.setString("2");
    sSoundsN1T.setCharacterSize(38);
    sSoundsN1T.setFillColor(sf::Color::Black);
    sSoundsN1T.setPosition(868, 665);
    sf::RectangleShape recrs2n;
    recrs2n.setSize({ 50, 50 });
    recrs2n.setPosition(1090, 665);
    recrs2n.setOutlineThickness(2);
    recrs2n.setOutlineColor(sf::Color::Black);
    sf::RectangleShape recrs21n;
    recrs21n.setSize({ 40, 40 });
    recrs21n.setPosition(1095, 670);
    recrs21n.setTexture(&tvolume0);



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
    Player p1(&igun02, &tgun02, vibrations, ammun, window, tv, selectmjk1);
    switch (p1.getSelect())
    {
    case 1:
        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
        break;
    case 2:
        window.setMouseCursorVisible(false);
        break;
    case 3:
        window.setMouseCursorVisible(false);
        break;
    }
    std::string p1samu = std::to_string(p1.getAmmunition());
    textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);

    Player p2(&igun02, &tgun02, vibrations, ammun, window, tv2, selectmjk2);
    std::string p2samu = std::to_string(p2.getAmmunition());

    p1.setTimeV(tv);
    p2.setTimeV(tv2);

    sf::Clock dtime;
    float dt;
    float multiplier = 500.f;

    sf::Vector2f currentVelocity;
    sf::Vector2f direction;
    float maxVelocity = 25.f;
    float acceleration = 1.f;
    float drag = 0.125f;

    sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::Clock clock0;
    clock0.restart().asMilliseconds();
    sf::Time timee;
    sf::Time timee2;
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
    sf::Clock clockHelp;
    sf::Text textEndOfTime;
    textEndOfTime.setFont(font);
    textEndOfTime.setCharacterSize(40);
    textEndOfTime.setFillColor(sf::Color::White);
    textEndOfTime.setPosition(951, 20);
    int seconds = ts.asSeconds();
    textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");

    sf::Text text1;
    text1.setFont(font);
    text1.setCharacterSize(30);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(13, 710);
    text1.setString("M");

    sf::Text text2;
    text2.setFont(font);
    text2.setCharacterSize(30);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(1163, 710);
    text2.setString("K");


    sf::Text textName;
    textName.setFont(font);
    textName.setCharacterSize(15);
    textName.setFillColor(sf::Color::Black);
    textName.setPosition(1060, 765);
    textName.setString("© Emilia Masiak");

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
            case sf::Event::KeyReleased:
                if (!menu && !settings && !select_player && !instruction && !music)
                {
                    if (sf::Keyboard::Escape == event.key.code)
                    {
                        menu = true;
                        textName.setFillColor(sf::Color::Black);
                        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
                        focus = true;
                        endg = false;
                        switch (randMusic)
                        {
                        case 1:
                            music_01.pause();
                            break;
                        case 2:
                            music_02.pause();
                            break;
                        case 3:
                            music_03.pause();
                            break;
                        case 4:
                            music_04.pause();
                            break;
                        case 5:
                            music_05.pause();
                            break;
                        case 6:
                            music_06.pause();
                            break;
                        case 7:
                            music_07.pause();
                            break;
                        case 8:
                            music_08.pause();
                            break;
                        case 9:
                            music_09.pause();
                            break;
                        }
                    }
                }
                if (sf::Keyboard::Space == event.key.code && (selectmjk1 == 3 || selectmjk2 == 3))
                {
                    //In Game
                    if (!menu && !settings && !select_player && !instruction && !music)
                    {
                        if (!goal1->getStop() && !goal2->getStop() && !goal3->getStop())
                        {
                            if (clock4.getElapsedTime().asSeconds() > 1)
                            {
                                if (!resetrof)
                                {
                                    if (selectmjk1 == 3)
                                        timee = clock.getElapsedTime();
                                    else if (selectmjk2 == 3)
                                        timee2 = clock0.getElapsedTime();
                                }
                                else
                                {
                                    if (selectmjk1 == 3)
                                        timee = speedb;
                                    else if (selectmjk2 == 3)
                                        timee2 = speedb2;
                                    resetrof = false;
                                }
                                if ((timee.asMilliseconds() >= rate_of_fire) && (p1.getAmmunition() > 0) && (selectmjk1 == 3))
                                {
                                    if (!end_of_time)
                                    {
                                        if (!p2_exists)
                                        {
                                            test = true;
                                            p1.getAmmunition()--;
                                            speedbar = true;
                                            clock3.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                                        }
                                        else
                                        {
                                            test = true;
                                            p1.getAmmunition()--;
                                            speedbar = true;
                                            clock3.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                        }
                                        if (smOn)
                                            hit1Sound.play();
                                    }
                                }
                                if ((timee2.asMilliseconds() >= rate_of_fire) && (p2.getAmmunition() > 0) && (p2_exists))
                                {
                                    if (!end_of_time)
                                    {
                                        if (selectmjk2 == 3)
                                        {
                                            test2 = true;
                                            p2.getAmmunition()--;
                                            speedbar2 = true;
                                            clock32.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                        }
                                        if (smOn)
                                            hit2Sound.play();
                                    }
                                }
                            }
                        }
                    }
                    //Main menu
                    else if (menu && !settings && !select_player && !instruction && !music)
                    {
                        //New Game
                        if (smOn)
                            menuSound.play();
                        if (((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 150 && p1.getRec().getPosition().y < 250) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 150 && p2.getRec().getPosition().y < 250)))
                        {
                            menu = false;
                            textName.setFillColor(sf::Color::White);
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
                            end_of_time = false;
                            cursorEndGame = true;
                            resetrof = true;
                            end = true;
                            clock4.restart().asSeconds();

                            if (mOn)
                            {
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.stop();
                                    break;
                                case 2:
                                    music_02.stop();
                                    break;
                                case 3:
                                    music_03.stop();
                                    break;
                                case 4:
                                    music_04.stop();
                                    break;
                                case 5:
                                    music_05.stop();
                                    break;
                                case 6:
                                    music_06.stop();
                                    break;
                                case 7:
                                    music_07.stop();
                                    break;
                                case 8:
                                    music_08.stop();
                                    break;
                                case 9:
                                    music_09.stop();
                                    break;
                                }
                                music_stop = true;
                                randMusic = rand() % 9 + 1;
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.play();
                                    break;
                                case 2:
                                    music_02.play();
                                    break;
                                case 3:
                                    music_03.play();
                                    break;
                                case 4:
                                    music_04.play();
                                    break;
                                case 5:
                                    music_05.play();
                                    break;
                                case 6:
                                    music_06.play();
                                    break;
                                case 7:
                                    music_07.play();
                                    break;
                                case 8:
                                    music_08.play();
                                    break;
                                case 9:
                                    music_09.play();
                                    break;
                                }
                            }
                        }
                        //Continue
                        else if ((game == true) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 270 && p2.getRec().getPosition().y < 370)))
                        {
                            menu = false;
                            textName.setFillColor(sf::Color::White);
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
                            if (p2_exists && selectmjk2 == 2)
                                p2.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                            else if (selectmjk1 == 2)
                                p1.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);

                            if (mOn)
                            {
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.play();
                                    break;
                                case 2:
                                    music_02.play();
                                    break;
                                case 3:
                                    music_03.play();
                                    break;
                                case 4:
                                    music_04.play();
                                    break;
                                case 5:
                                    music_05.play();
                                    break;
                                case 6:
                                    music_06.play();
                                    break;
                                case 7:
                                    music_07.play();
                                    break;
                                case 8:
                                    music_08.play();
                                    break;
                                case 9:
                                    music_09.play();
                                    break;
                                }
                            }
                        }
                        //Player
                        else if ((game == false) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 270 && p2.getRec().getPosition().y < 370)))
                        {
                            menu = false;
                            select_player = true;
                            if (p1.getSelect() == 1)
                                window.setMouseCursorVisible(true);
                            else
                                window.setMouseCursorVisible(false);
                        }
                        //Help
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 510 && p1.getRec().getPosition().y < 610) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 510 && p2.getRec().getPosition().y < 610)))
                        {
                            menu = false;
                            instruction = true;
                            clockHelp.restart().asMilliseconds();
                            hcount = 1;
                            helpc = 0;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 100, 125 });
                            recm1h.setPosition(400, 265);
                            recm0h.setPosition(650, 300);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("The pointer movement in the game");
                            textm12h.setString("corresponds to the mouse movement.");
                        }
                        //Note
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x > 900 && p1.getRec().getPosition().x < 950 && p1.getRec().getPosition().y > 680 && p1.getRec().getPosition().y < 730) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 900 && p2.getRec().getPosition().x < 950 && p2.getRec().getPosition().y > 680 && p2.getRec().getPosition().y < 730)))
                        {
                            menu = false;
                            music = true;
                        }
                        //Options
                        else if ((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 390 && p1.getRec().getPosition().y < 490) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 390 && p2.getRec().getPosition().y < 490))
                        {
                            menu = false;
                            settings = true;
                        }
                        //Quit
                        if (((p1.getSelect() == 3 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 630 && p1.getRec().getPosition().y < 730) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x > 400 && p2.getRec().getPosition().x < 800 && p2.getRec().getPosition().y > 630 && p2.getRec().getPosition().y < 730)))
                        {
                            window.close();
                        }
                    }
                    //Settings
                    else if (!menu && settings && !select_player && !instruction && !music)
                    {
                        //Back
                        if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)))
                        {
                            settings = false;
                            menu = true;
                        }
                        //Default
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p1.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p1.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p1.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p2.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p2.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p2.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2)))
                        {
                            menuSound.play();
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
                            speed = 150;
                            sot_text.setString(std::to_string(speed));
                            sot_text.setPosition(848, 465);
                            tspeed = sf::milliseconds(210 - speed);
                            rate_of_fire = 1200;
                            rof_text.setString(std::to_string(rate_of_fire));
                            rof_text.setPosition(838, 565);
                            sensitivity = 20;
                            s_text.setString(std::to_string(sensitivity));
                            s_text.setPosition(858, 665);
                            p2.setAmmunition(ammun);
                            p2samu = std::to_string(p2.getAmmunition());
                            p2.setVibrations(vibrations);
                            if (!p2_exists)
                            {
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                            else
                            {
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedb2 = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        //Ammunition
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && p1.getRec().getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && p1.getRec().getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && p1.getRec().getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && p2.getRec().getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && p2.getRec().getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && p2.getRec().getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && p1.getRec().getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && p1.getRec().getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && p1.getRec().getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && p2.getRec().getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && p2.getRec().getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && p2.getRec().getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && p1.getRec().getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && p1.getRec().getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && p1.getRec().getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && p2.getRec().getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && p2.getRec().getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && p2.getRec().getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && p1.getRec().getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && p1.getRec().getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && p1.getRec().getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && p2.getRec().getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && p2.getRec().getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && p2.getRec().getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && p1.getRec().getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && p1.getRec().getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && p1.getRec().getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && p2.getRec().getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && p2.getRec().getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && p2.getRec().getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && p1.getRec().getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && p1.getRec().getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && p1.getRec().getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && p2.getRec().getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && p2.getRec().getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && p2.getRec().getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && p1.getRec().getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && p1.getRec().getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && p1.getRec().getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && p2.getRec().getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && p2.getRec().getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && p2.getRec().getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2)))
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
                            tspeed = sf::milliseconds(210 - speed);
                        }
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && p1.getRec().getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && p1.getRec().getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && p1.getRec().getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && p2.getRec().getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && p2.getRec().getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && p2.getRec().getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2)))
                        {
                            if (speed == 90)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                                sot_text.setPosition(848, 465);
                            }
                            else if (speed != 200)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                            }
                            change = true;
                            tspeed = sf::milliseconds(210 - speed);
                        }
                        //Rate of fire
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && p1.getRec().getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && p1.getRec().getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && p1.getRec().getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && p2.getRec().getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && p2.getRec().getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && p2.getRec().getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2)))
                        {
                            if (rate_of_fire == 1000)
                            {
                                rate_of_fire -= 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                                rof_text.setPosition(848, 565);
                            }
                            else if (rate_of_fire != 800)
                            {
                                rate_of_fire -= 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedb2 = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && p1.getRec().getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && p1.getRec().getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && p1.getRec().getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && p2.getRec().getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && p2.getRec().getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && p2.getRec().getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2)))
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
                            speedb2 = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        //Sensitivity
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && p1.getRec().getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && p1.getRec().getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && p1.getRec().getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && p2.getRec().getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && p2.getRec().getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && p2.getRec().getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2)))
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
                        else if (((p1.getSelect() == 3 && p1.getRec().getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && p1.getRec().getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && p1.getRec().getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && p1.getRec().getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && p2.getRec().getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && p2.getRec().getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && p2.getRec().getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2)))
                        {
                            if (sensitivity == 9)
                            {
                                sensitivity++;
                                s_text.setString(std::to_string(sensitivity));
                                s_text.setPosition(858, 665);
                            }
                            else if (sensitivity != 99)
                            {
                                sensitivity++;
                                s_text.setString(std::to_string(sensitivity));
                            }
                        }
                    }
                    //Help
                    else if (!menu && !settings && !select_player && instruction && !music)
                    {
                        //Back
                        if ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                        {
                            instruction = false;
                            menu = true;
                        }
                        //r
                        else if ((hcount == 1 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 1 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 2;
                            helpc = 1;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 200, 250 });
                            recm1h.setPosition(500, 265);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the left mouse button to shoot.");
                        }
                        else if ((hcount == 2 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 2 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 3;
                            helpc = 0;
                            recc1h.setSize({ 190, 125 });
                            recc1h.setPosition(400, 315);
                            recc0h.setPosition(650, 300);
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Use the Left stick on the controller");
                            textm12h.setString("to move the pointer in the game.");
                        }
                        else if ((hcount == 3 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 3 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 4;
                            helpc = 1;
                            recc1h.setSize({ 380, 250 });
                            recc1h.setPosition(410, 260);
                            recc1h.setTexture(&tcontroller00);
                            textm11h.setString("Click the Right Trigger on the");
                            textm12h.setString("controller to shoot.");
                        }
                        else if ((hcount == 4 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 4 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 5;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Click the Start button on the");
                            textm12h.setString("controller to return to the main menu.");
                        }
                        else if ((hcount == 5 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 5 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 6;
                            helpc = 0;
                            reck1h.setTexture(&tkeyboard0);
                            textm11h.setString("Use the WSDA buttons to move");
                            textm12h.setString("the pointer in the game.");
                        }
                        else if ((hcount == 6 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 6 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 7;
                            helpc = 1;
                            reck2h.setTexture(&tkeyboard0Space);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the Spacebar to shoot.");
                        }
                        else if ((hcount == 7 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2) || (hcount == 7 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p2.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p2.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p2.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                        {
                            hcount = 8;
                            helpc = 1;
                            reck3h.setTexture(&tkeyboard0Esc);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Click the Esc button to return to");
                            textm12h.setString("the main menu.");
                        }
                        //l
                        else if ((hcount == 2 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 2 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 1;
                            helpc = 0;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 100, 125 });
                            recm1h.setPosition(400, 265);
                            recm0h.setPosition(650, 300);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("The pointer movement in the game");
                            textm12h.setString("corresponds to the mouse movement.");
                        }
                        else if ((hcount == 3 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 3 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 2;
                            helpc = 1;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 200, 250 });
                            recm1h.setPosition(500, 265);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the left mouse button to shoot.");
                        }
                        else if ((hcount == 4 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 4 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 3;
                            helpc = 0;
                            recc1h.setSize({ 190, 125 });
                            recc1h.setPosition(400, 315);
                            recc0h.setPosition(650, 300);
                            recc1h.setTexture(&tcontroller0);
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Use the Left stick on the controller");
                            textm12h.setString("to move the pointer in the game.");
                        }
                        else if ((hcount == 5 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 5 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 4;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller00);
                            textm11h.setString("Click the Right Trigger on the");
                            textm12h.setString("controller to shoot.");
                        }
                        else if ((hcount == 6 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 6 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 5;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Click the Start button on the");
                            textm12h.setString("controller to return to the main menu.");
                        }
                        else if ((hcount == 7 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 7 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 6;
                            helpc = 0;
                            reck1h.setTexture(&tkeyboard0);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Use the WSDA buttons to move");
                            textm12h.setString("the pointer in the game.");
                        }
                        else if ((hcount == 8 && p1.getSelect() == 3 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2) || (hcount == 8 && p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                        {
                            hcount = 7;
                            helpc = 1;
                            reck2h.setTexture(&tkeyboard0Space);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the Spacebar to shoot.");
                        }
                    }
                    //Music
                    if (!menu && !settings && !select_player && !instruction && music)
                    {
                        music_01.setVolume(volumeConst);
                        music_02.setVolume(volumeConst);
                        music_03.setVolume(volumeConst);
                        music_04.setVolume(volumeConst);
                        music_05.setVolume(volumeConst);
                        music_06.setVolume(volumeConst);
                        music_07.setVolume(volumeConst);
                        music_08.setVolume(volumeConst);
                        music_09.setVolume(volumeConst);
                        //Back
                        if ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                        {
                            music = false;
                            menu = true;
                        }
                        else if ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p1.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p1.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p1.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p2.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p2.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p2.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2))
                        {
                            hit1_counter = 1;
                            hit2_counter = 2;
                            reload1_counter = 1;
                            reload2_counter = 2;
                            hit1Sound.setBuffer(hit01SoundBuffer);
                            SoundsN1T.setString("1");
                            reload1Sound.setBuffer(reload01SoundBuffer);
                            sMucicNT.setString("1");
                            hit2Sound.setBuffer(hit01SoundBuffer);
                            sSoundsNT.setString("2");
                            reload2Sound.setBuffer(reload01SoundBuffer);
                            sSoundsN1T.setString("2");
                            mOn = true;
                            MusicNT.setString("On");
                            smOn = true;
                            SoundsNT.setString("On");
                            menuSound.play();
                            volumeConst = 25;
                            volumeConst1 = 40;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                            music_01.stop();
                            volumeM = true;
                        }
                        else if (!musicOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec0n.getPosition().x && p1.getRec().getPosition().x <= rec0n.getPosition().x + rec0n.getSize().x && p1.getRec().getPosition().y >= rec0n.getPosition().y && p1.getRec().getPosition().y <= rec0n.getPosition().y + rec0n.getSize().y)) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec0n.getPosition().x && p2.getRec().getPosition().x <= rec0n.getPosition().x + rec0n.getSize().x && p2.getRec().getPosition().y >= rec0n.getPosition().y && p2.getRec().getPosition().y <= rec0n.getPosition().y + rec0n.getSize().y))
                        {
                            musicOn = true;
                            mOn = true;
                            MusicNT.setString("On");
                            smOn = true;
                            SoundsNT.setString("On");
                        }
                        else if (musicOn && mOn && ((p1.getSelect() == 3 && (p1.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p1.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p1.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p1.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p1.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p1.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p1.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2))) || (p2_exists && p2.getSelect() == 3 && (p2.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p2.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p2.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p2.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p2.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p2.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p2.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p2.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2)))
                        {
                            MusicNT.setString("Off");
                            mOn = false;

                            switch (randMusic)
                            {
                            case 1:
                                music_01.stop();
                                break;
                            case 2:
                                music_02.stop();
                                break;
                            case 3:
                                music_03.stop();
                                break;
                            case 4:
                                music_04.stop();
                                break;
                            case 5:
                                music_05.stop();
                                break;
                            case 6:
                                music_06.stop();
                                break;
                            case 7:
                                music_07.stop();
                                break;
                            case 8:
                                music_08.stop();
                                break;
                            case 9:
                                music_09.stop();
                                break;
                            }
                            music_stop = false;
                        }
                        else if (musicOn && !mOn && ((p1.getSelect() == 3 && (p1.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p1.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p1.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p1.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p1.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p1.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p1.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2))) || (p2_exists && p2.getSelect() == 3 && (p2.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p2.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p2.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p2.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p2.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p2.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p2.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p2.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2)))
                        {
                            MusicNT.setString("On");
                            mOn = true;
                        }
                        else if (musicOn && mOn && volumeM && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec12n.getPosition().x && p1.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p1.getRec().getPosition().y >= rec12n.getPosition().y && p1.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec12n.getPosition().x && p2.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p2.getRec().getPosition().y >= rec12n.getPosition().y && p2.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y)))
                        {
                            volumeM = false;
                            music_01.play();
                        }
                        else if (musicOn && mOn && !volumeM && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec12n.getPosition().x && p1.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p1.getRec().getPosition().y >= rec12n.getPosition().y && p1.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec12n.getPosition().x && p2.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p2.getRec().getPosition().y >= rec12n.getPosition().y && p2.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y)))
                        {
                            volumeM = true;
                            music_01.stop();
                        }
                        else if (musicOn && mOn && (volumeConst != 1) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec13n.getPosition().x && p1.getRec().getPosition().x <= rec13n.getPosition().x + rec13n.getSize().x && p1.getRec().getPosition().y >= rec13n.getPosition().y && p1.getRec().getPosition().y <= rec13n.getPosition().y + rec13n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec13n.getPosition().x && p2.getRec().getPosition().x <= rec13n.getPosition().x + rec13n.getSize().x && p2.getRec().getPosition().y >= rec13n.getPosition().y && p2.getRec().getPosition().y <= rec13n.getPosition().y + rec13n.getSize().y)))
                        {
                            music_01.stop();
                            volumeM = true;
                            volumeConst--;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);

                        }
                        else if (musicOn && mOn && (volumeConst != 100) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec14n.getPosition().x && p1.getRec().getPosition().x <= rec14n.getPosition().x + rec14n.getSize().x && p1.getRec().getPosition().y >= rec14n.getPosition().y && p1.getRec().getPosition().y <= rec14n.getPosition().y + rec14n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec14n.getPosition().x && p2.getRec().getPosition().x <= rec14n.getPosition().x + rec14n.getSize().x && p2.getRec().getPosition().y >= rec14n.getPosition().y && p2.getRec().getPosition().y <= rec14n.getPosition().y + rec14n.getSize().y)))
                        {
                            music_01.stop();
                            volumeM = true;
                            volumeConst++;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && (p1.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p1.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p1.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p1.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p1.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p1.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p1.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2))) || (p2_exists && p2.getSelect() == 3 && (p2.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p2.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p2.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p2.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p2.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p2.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p2.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2)))
                        {
                            SoundsNT.setString("Off");
                            smOn = false;
                        }
                        else if (musicOn && !smOn && ((p1.getSelect() == 3 && (p1.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p1.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p1.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p1.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p1.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p1.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p1.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2))) || (p2_exists && p2.getSelect() == 3 && (p2.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p2.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p2.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p2.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p2.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p2.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p2.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2)))
                        {
                            SoundsNT.setString("On");
                            smOn = true;
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec22n.getPosition().x && p1.getRec().getPosition().x <= rec22n.getPosition().x + rec22n.getSize().x && p1.getRec().getPosition().y >= rec22n.getPosition().y && p1.getRec().getPosition().y <= rec22n.getPosition().y + rec22n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec22n.getPosition().x && p2.getRec().getPosition().x <= rec22n.getPosition().x + rec22n.getSize().x && p2.getRec().getPosition().y >= rec22n.getPosition().y && p2.getRec().getPosition().y <= rec22n.getPosition().y + rec22n.getSize().y)))
                        {
                            menuSound.play();
                        }
                        else if (musicOn && smOn && (volumeConst1 != 1) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec23n.getPosition().x && p1.getRec().getPosition().x <= rec23n.getPosition().x + rec23n.getSize().x && p1.getRec().getPosition().y >= rec23n.getPosition().y && p1.getRec().getPosition().y <= rec23n.getPosition().y + rec23n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec23n.getPosition().x && p2.getRec().getPosition().x <= rec23n.getPosition().x + rec23n.getSize().x && p2.getRec().getPosition().y >= rec23n.getPosition().y && p2.getRec().getPosition().y <= rec23n.getPosition().y + rec23n.getSize().y)))
                        {
                            volumeConst1--;
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                        }
                        else if (musicOn && smOn && (volumeConst1 != 100) && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rec24n.getPosition().x && p1.getRec().getPosition().x <= rec24n.getPosition().x + rec24n.getSize().x && p1.getRec().getPosition().y >= rec24n.getPosition().y && p1.getRec().getPosition().y <= rec24n.getPosition().y + rec24n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rec24n.getPosition().x && p2.getRec().getPosition().x <= rec24n.getPosition().x + rec24n.getSize().x && p2.getRec().getPosition().y >= rec24n.getPosition().y && p2.getRec().getPosition().y <= rec24n.getPosition().y + rec24n.getSize().y)))
                        {
                            volumeConst1++;
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                        }
                        //Hit 1
                        if (hit1_counter != 1 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn21left.getPosition().x - bn21left.getSize().x / 2 && p1.getRec().getPosition().x <= bn21left.getPosition().x + bn21left.getSize().x / 2 && p1.getRec().getPosition().y >= bn21left.getPosition().y - bn21left.getSize().y / 2 && p1.getRec().getPosition().y <= bn21left.getPosition().y + bn21left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn21left.getPosition().x - bn21left.getSize().x / 2 && p2.getRec().getPosition().x <= bn21left.getPosition().x + bn21left.getSize().x / 2 && p2.getRec().getPosition().y >= bn21left.getPosition().y - bn21left.getSize().y / 2 && p2.getRec().getPosition().y <= bn21left.getPosition().y + bn21left.getSize().y / 2)))
                        {
                            if (hit1_counter == 6)
                            {
                                hit1Sound.setBuffer(hit05SoundBuffer);
                                SoundsN1T.setString("5");
                            }
                            else if (hit1_counter == 5)
                            {
                                hit1Sound.setBuffer(hit04SoundBuffer);
                                SoundsN1T.setString("4");
                            }
                            else if (hit1_counter == 4)
                            {
                                hit1Sound.setBuffer(hit03SoundBuffer);
                                SoundsN1T.setString("3");
                            }
                            else if (hit1_counter == 3)
                            {
                                hit1Sound.setBuffer(hit02SoundBuffer);
                                SoundsN1T.setString("2");
                            }
                            else if (hit1_counter == 2)
                            {
                                hit1Sound.setBuffer(hit01SoundBuffer);
                                SoundsN1T.setString("1");
                            }
                            hit1_counter--;
                        }
                        else if (hit1_counter != 6 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn21right.getPosition().x - bn21right.getSize().x / 2 && p1.getRec().getPosition().x <= bn21right.getPosition().x + bn21right.getSize().x / 2 && p1.getRec().getPosition().y >= bn21right.getPosition().y - bn21right.getSize().y / 2 && p1.getRec().getPosition().y <= bn21right.getPosition().y + bn21right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn21right.getPosition().x - bn21right.getSize().x / 2 && p2.getRec().getPosition().x <= bn21right.getPosition().x + bn21right.getSize().x / 2 && p2.getRec().getPosition().y >= bn21right.getPosition().y - bn21right.getSize().y / 2 && p2.getRec().getPosition().y <= bn21right.getPosition().y + bn21right.getSize().y / 2)))
                        {
                            if (hit1_counter == 1)
                            {
                                hit1Sound.setBuffer(hit02SoundBuffer);
                                SoundsN1T.setString("2");
                            }
                            else if (hit1_counter == 2)
                            {
                                hit1Sound.setBuffer(hit03SoundBuffer);
                                SoundsN1T.setString("3");
                            }
                            else if (hit1_counter == 3)
                            {
                                hit1Sound.setBuffer(hit04SoundBuffer);
                                SoundsN1T.setString("4");
                            }
                            else if (hit1_counter == 4)
                            {
                                hit1Sound.setBuffer(hit05SoundBuffer);
                                SoundsN1T.setString("5");
                            }
                            else if (hit1_counter == 5)
                            {
                                hit1Sound.setBuffer(hit06SoundBuffer);
                                SoundsN1T.setString("6");
                            }
                            hit1_counter++;
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rechs1n.getPosition().x && p1.getRec().getPosition().x <= rechs1n.getPosition().x + rechs1n.getSize().x && p1.getRec().getPosition().y >= rechs1n.getPosition().y && p1.getRec().getPosition().y <= rechs1n.getPosition().y + rechs1n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rechs1n.getPosition().x && p2.getRec().getPosition().x <= rechs1n.getPosition().x + rechs1n.getSize().x && p2.getRec().getPosition().y >= rechs1n.getPosition().y && p2.getRec().getPosition().y <= rechs1n.getPosition().y + rechs1n.getSize().y)))
                        {
                            hit1Sound.play();
                        }
                        //Reload 1
                        else if (reload1_counter != 1 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn3left.getPosition().x - bn3left.getSize().x / 2 && p1.getRec().getPosition().x <= bn3left.getPosition().x + bn3left.getSize().x / 2 && p1.getRec().getPosition().y >= bn3left.getPosition().y - bn3left.getSize().y / 2 && p1.getRec().getPosition().y <= bn3left.getPosition().y + bn3left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn3left.getPosition().x - bn3left.getSize().x / 2 && p2.getRec().getPosition().x <= bn3left.getPosition().x + bn3left.getSize().x / 2 && p2.getRec().getPosition().y >= bn3left.getPosition().y - bn3left.getSize().y && p2.getRec().getPosition().y <= bn3left.getPosition().y + bn3left.getSize().y / 2)))
                        {
                            if (reload1_counter == 6)
                            {
                                reload1Sound.setBuffer(reload05SoundBuffer);
                                sMucicNT.setString("5");
                            }
                            else if (reload1_counter == 5)
                            {
                                reload1Sound.setBuffer(reload04SoundBuffer);
                                sMucicNT.setString("4");
                            }
                            else if (reload1_counter == 4)
                            {
                                reload1Sound.setBuffer(reload03SoundBuffer);
                                sMucicNT.setString("3");
                            }
                            else if (reload1_counter == 3)
                            {
                                reload1Sound.setBuffer(reload02SoundBuffer);
                                sMucicNT.setString("2");
                            }
                            else if (reload1_counter == 2)
                            {
                                reload1Sound.setBuffer(reload01SoundBuffer);
                                sMucicNT.setString("1");
                            }
                            reload1_counter--;
                        }
                        else if (reload1_counter != 6 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn3right.getPosition().x - bn3right.getSize().x / 2 && p1.getRec().getPosition().x <= bn3right.getPosition().x + bn3right.getSize().x / 2 && p1.getRec().getPosition().y >= bn3right.getPosition().y - bn3right.getSize().y / 2 && p1.getRec().getPosition().y <= bn3right.getPosition().y + bn3right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn3right.getPosition().x - bn3right.getSize().x / 2 && p2.getRec().getPosition().x <= bn3right.getPosition().x + bn3right.getSize().x / 2 && p2.getRec().getPosition().y >= bn3right.getPosition().y - bn3right.getSize().y / 2 && p2.getRec().getPosition().y <= bn3right.getPosition().y + bn3right.getSize().y / 2)))
                        {
                            if (reload1_counter == 1)
                            {
                                reload1Sound.setBuffer(reload02SoundBuffer);
                                sMucicNT.setString("2");
                            }
                            else if (reload1_counter == 2)
                            {
                                reload1Sound.setBuffer(reload03SoundBuffer);
                                sMucicNT.setString("3");
                            }
                            else if (reload1_counter == 3)
                            {
                                reload1Sound.setBuffer(reload04SoundBuffer);
                                sMucicNT.setString("4");
                            }
                            else if (reload1_counter == 4)
                            {
                                reload1Sound.setBuffer(reload05SoundBuffer);
                                sMucicNT.setString("5");
                            }
                            else if (reload1_counter == 5)
                            {
                                reload1Sound.setBuffer(reload06SoundBuffer);
                                sMucicNT.setString("6");
                            }
                            reload1_counter++;
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= recrs1n.getPosition().x && p1.getRec().getPosition().x <= recrs1n.getPosition().x + recrs1n.getSize().x && p1.getRec().getPosition().y >= recrs1n.getPosition().y && p1.getRec().getPosition().y <= recrs1n.getPosition().y + recrs1n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= recrs1n.getPosition().x && p2.getRec().getPosition().x <= recrs1n.getPosition().x + recrs1n.getSize().x && p2.getRec().getPosition().y >= recrs1n.getPosition().y && p2.getRec().getPosition().y <= recrs1n.getPosition().y + recrs1n.getSize().y)))
                        {
                            reload1Sound.play();
                        }
                        //Hit 2
                        else if (hit2_counter != 1 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn4left.getPosition().x - bn4left.getSize().x / 2 && p1.getRec().getPosition().x <= bn4left.getPosition().x + bn4left.getSize().x / 2 && p1.getRec().getPosition().y >= bn4left.getPosition().y - bn4left.getSize().y / 2 && p1.getRec().getPosition().y <= bn4left.getPosition().y + bn4left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn4left.getPosition().x - bn4left.getSize().x / 2 && p2.getRec().getPosition().x <= bn4left.getPosition().x + bn4left.getSize().x / 2 && p2.getRec().getPosition().y >= bn4left.getPosition().y - bn4left.getSize().y / 2 && p2.getRec().getPosition().y <= bn4left.getPosition().y + bn4left.getSize().y / 2)))
                        {
                            if (hit2_counter == 6)
                            {
                                hit2Sound.setBuffer(hit05SoundBuffer);
                                sSoundsNT.setString("5");
                            }
                            else if (hit2_counter == 5)
                            {
                                hit2Sound.setBuffer(hit04SoundBuffer);
                                sSoundsNT.setString("4");
                            }
                            else if (hit2_counter == 4)
                            {
                                hit2Sound.setBuffer(hit03SoundBuffer);
                                sSoundsNT.setString("3");
                            }
                            else if (hit2_counter == 3)
                            {
                                hit2Sound.setBuffer(hit02SoundBuffer);
                                sSoundsNT.setString("2");
                            }
                            else if (hit2_counter == 2)
                            {
                                hit2Sound.setBuffer(hit01SoundBuffer);
                                sSoundsNT.setString("1");
                            }
                            hit2_counter--;
                        }
                        else if (hit2_counter != 6 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn4right.getPosition().x - bn4right.getSize().x / 2 && p1.getRec().getPosition().x <= bn4right.getPosition().x + bn4right.getSize().x / 2 && p1.getRec().getPosition().y >= bn4right.getPosition().y - bn4right.getSize().y / 2 && p1.getRec().getPosition().y <= bn4right.getPosition().y + bn4right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn4right.getPosition().x - bn4right.getSize().x / 2 && p2.getRec().getPosition().x <= bn4right.getPosition().x + bn4right.getSize().x / 2 && p2.getRec().getPosition().y >= bn4right.getPosition().y - bn4right.getSize().y / 2 && p2.getRec().getPosition().y <= bn4right.getPosition().y + bn4right.getSize().y / 2)))
                        {
                            if (hit2_counter == 1)
                            {
                                hit2Sound.setBuffer(hit02SoundBuffer);
                                sSoundsNT.setString("2");
                            }
                            else if (hit2_counter == 2)
                            {
                                hit2Sound.setBuffer(hit03SoundBuffer);
                                sSoundsNT.setString("3");
                            }
                            else if (hit2_counter == 3)
                            {
                                hit2Sound.setBuffer(hit04SoundBuffer);
                                sSoundsNT.setString("4");
                            }
                            else if (hit2_counter == 4)
                            {
                                hit2Sound.setBuffer(hit05SoundBuffer);
                                sSoundsNT.setString("5");
                            }
                            else if (hit2_counter == 5)
                            {
                                hit2Sound.setBuffer(hit06SoundBuffer);
                                sSoundsNT.setString("6");
                            }
                            hit2_counter++;
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= rechs2n.getPosition().x && p1.getRec().getPosition().x <= rechs2n.getPosition().x + rechs2n.getSize().x && p1.getRec().getPosition().y >= rechs2n.getPosition().y && p1.getRec().getPosition().y <= rechs2n.getPosition().y + rechs2n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= rechs2n.getPosition().x && p2.getRec().getPosition().x <= rechs2n.getPosition().x + rechs2n.getSize().x && p2.getRec().getPosition().y >= rechs2n.getPosition().y && p2.getRec().getPosition().y <= rechs2n.getPosition().y + rechs2n.getSize().y)))
                        {
                            hit2Sound.play();
                        }
                        //Reload 2
                        else if (reload2_counter != 1 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn41left.getPosition().x - bn41left.getSize().x / 2 && p1.getRec().getPosition().x <= bn41left.getPosition().x + bn41left.getSize().x / 2 && p1.getRec().getPosition().y >= bn41left.getPosition().y - bn41left.getSize().y / 2 && p1.getRec().getPosition().y <= bn41left.getPosition().y + bn41left.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn41left.getPosition().x - bn41left.getSize().x / 2 && p2.getRec().getPosition().x <= bn41left.getPosition().x + bn41left.getSize().x / 2 && p2.getRec().getPosition().y >= bn41left.getPosition().y - bn41left.getSize().y / 2 && p2.getRec().getPosition().y <= bn41left.getPosition().y + bn41left.getSize().y / 2)))
                        {
                            if (reload2_counter == 6)
                            {
                                reload2Sound.setBuffer(reload05SoundBuffer);
                                sSoundsN1T.setString("5");
                            }
                            else if (reload2_counter == 5)
                            {
                                reload2Sound.setBuffer(reload04SoundBuffer);
                                sSoundsN1T.setString("4");
                            }
                            else if (reload2_counter == 4)
                            {
                                reload2Sound.setBuffer(reload03SoundBuffer);
                                sSoundsN1T.setString("3");
                            }
                            else if (reload2_counter == 3)
                            {
                                reload2Sound.setBuffer(reload02SoundBuffer);
                                sSoundsN1T.setString("2");
                            }
                            else if (reload2_counter == 2)
                            {
                                reload2Sound.setBuffer(reload01SoundBuffer);
                                sSoundsN1T.setString("1");
                            }
                            reload2_counter--;
                        }
                        else if (reload2_counter != 6 && musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= bn41right.getPosition().x - bn41right.getSize().x / 2 && p1.getRec().getPosition().x <= bn41right.getPosition().x + bn41right.getSize().x / 2 && p1.getRec().getPosition().y >= bn41right.getPosition().y - bn41right.getSize().y / 2 && p1.getRec().getPosition().y <= bn41right.getPosition().y + bn41right.getSize().y / 2) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= bn41right.getPosition().x - bn41right.getSize().x / 2 && p2.getRec().getPosition().x <= bn41right.getPosition().x + bn41right.getSize().x / 2 && p2.getRec().getPosition().y >= bn41right.getPosition().y - bn41right.getSize().y / 2 && p2.getRec().getPosition().y <= bn41right.getPosition().y + bn41right.getSize().y / 2)))
                        {
                            if (reload2_counter == 1)
                            {
                                reload2Sound.setBuffer(reload02SoundBuffer);
                                sSoundsN1T.setString("2");
                            }
                            else if (reload2_counter == 2)
                            {
                                reload2Sound.setBuffer(reload03SoundBuffer);
                                sSoundsN1T.setString("3");
                            }
                            else if (reload2_counter == 3)
                            {
                                reload2Sound.setBuffer(reload04SoundBuffer);
                                sSoundsN1T.setString("4");
                            }
                            else if (reload2_counter == 4)
                            {
                                reload2Sound.setBuffer(reload05SoundBuffer);
                                sSoundsN1T.setString("5");
                            }
                            else if (reload2_counter == 5)
                            {
                                reload2Sound.setBuffer(reload06SoundBuffer);
                                sSoundsN1T.setString("6");
                            }
                            reload2_counter++;
                        }
                        else if (musicOn && smOn && ((p1.getSelect() == 3 && p1.getRec().getPosition().x >= recrs2n.getPosition().x && p1.getRec().getPosition().x <= recrs2n.getPosition().x + recrs2n.getSize().x && p1.getRec().getPosition().y >= recrs2n.getPosition().y && p1.getRec().getPosition().y <= recrs2n.getPosition().y + recrs2n.getSize().y) || (p2_exists && p2.getSelect() == 3 && p2.getRec().getPosition().x >= recrs2n.getPosition().x && p2.getRec().getPosition().x <= recrs2n.getPosition().x + recrs2n.getSize().x && p2.getRec().getPosition().y >= recrs2n.getPosition().y && p2.getRec().getPosition().y <= recrs2n.getPosition().y + recrs2n.getSize().y)))
                        {
                            reload2Sound.play();
                        }
                        if (!mOn && !smOn)
                        {
                            musicOn = false;
                        }
                    }
                    //Player
                    else if (!menu && !settings && select_player && !instruction && !music)
                    {
                        //Back
                        if (((p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2) || (p2.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p2.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p2.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p2.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)))
                        {
                            select_player = false;
                            menu = true;
                            window.setMouseCursorVisible(true);
                        }
                        //rl1
                        else if (!p2_exists)
                        {
                            if (selectmjk == 1 && (p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2))
                            {
                                selectmjk = 2;
                            }
                            else if (selectmjk == 2 && (p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2))
                            {
                                selectmjk = 1;
                            }
                            else if (selectmjk == 2 && (p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2))
                            {
                                selectmjk = 3;
                            }
                            else if (selectmjk == 3 && (p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2))
                            {
                                selectmjk = 2;
                            }
                        }
                        else if (p1.getSelect() == 3)
                        {
                            if ((selectmjk == 1 && (p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)) || (selectmjk == 1 && (p2.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p2.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p2.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p2.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)))
                            {
                                selectmjk = 3;
                            }
                            else if ((selectmjk == 3 && (p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)) || (selectmjk == 3 && (p2.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p2.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p2.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p2.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)))
                            {
                                selectmjk = 1;
                            }
                        }
                        //Select
                        if ((p1.getSelect() == 3) && (selectmjk1 != selectmjk) && ((p1.getRec().getPosition().x >= choosep11.getPosition().x - choosep11.getSize().x / 2 && p1.getRec().getPosition().x <= choosep11.getPosition().x + choosep11.getSize().x / 2 && p1.getRec().getPosition().y >= choosep11.getPosition().y - choosep11.getSize().y / 2 && p1.getRec().getPosition().y <= choosep11.getPosition().y + choosep11.getSize().y / 2) || (p2.getRec().getPosition().x >= choosep11.getPosition().x - choosep11.getSize().x / 2 && p2.getRec().getPosition().x <= choosep11.getPosition().x + choosep11.getSize().x / 2 && p2.getRec().getPosition().y >= choosep11.getPosition().y - choosep11.getSize().y / 2 && p2.getRec().getPosition().y <= choosep11.getPosition().y + choosep11.getSize().y / 2)))
                        {
                            if (!p2_exists)
                            {
                                if (stop && (selectmjk == 2))
                                {
                                    std::cout << "Joystick is Disconnected" << std::endl;
                                }
                                else
                                {
                                    selectmjk1 = selectmjk;
                                    p1.setSelect(selectmjk1);
                                    p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                                    switch (selectmjk1)
                                    {
                                    case 1:
                                        selectmjk2 = 3;
                                        choosep11.setFillColor(sf::Color(210, 210, 210));
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color::White);
                                        choosep21.setFillColor(sf::Color::White);
                                        choosep23.setFillColor(sf::Color(210, 210, 210));
                                        text1.setString("M");
                                        text2.setString("K");
                                        break;
                                    case 2:
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color(210, 210, 210));
                                        choosep13.setFillColor(sf::Color::White);
                                        text1.setString("C");
                                        break;
                                    case 3:
                                        selectmjk2 = 1;
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color(210, 210, 210));
                                        choosep21.setFillColor(sf::Color(210, 210, 210));
                                        choosep23.setFillColor(sf::Color::White);
                                        text1.setString("K");
                                        text2.setString("M");
                                        break;
                                    }
                                    p2.setSelect(selectmjk2);
                                }
                            }
                            else
                            {
                                if (selectmjk == 2)
                                {
                                    selectmjk = 1;
                                    selectmjk1 = selectmjk;
                                }
                                else
                                {
                                    selectmjk1 = selectmjk;
                                    p1.setSelect(selectmjk1);
                                    p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                                    switch (selectmjk1)
                                    {
                                    case 1:
                                        choosep11.setFillColor(sf::Color(210, 210, 210));
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color::White);
                                        text1.setString("M");
                                        choosep21.setFillColor(sf::Color::White);
                                        choosep23.setFillColor(sf::Color(210, 210, 210));
                                        text2.setString("K");
                                        selectmjk2 = 3;
                                        p2.setSelect(selectmjk2);
                                        window.setMouseCursorVisible(true);
                                        break;
                                    case 3:
                                        selectmjk2 = 1;
                                        p2.setSelect(selectmjk2);
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color(210, 210, 210));
                                        text1.setString("K");
                                        choosep21.setFillColor(sf::Color(210, 210, 210));
                                        choosep23.setFillColor(sf::Color::White);
                                        text2.setString("M");
                                        break;
                                    }
                                }
                            }
                        }
                        //Click
                        if (selectmjk1 != 2 && p1.getSelect() == 3)
                        {
                            if (((p1.getRec().getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && p1.getRec().getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && p1.getRec().getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && p1.getRec().getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2) || (p2.getRec().getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && p2.getRec().getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && p2.getRec().getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && p2.getRec().getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2)))
                            {
                                p2_exists = true;
                                selectmjk1 = 3;
                                selectmjk2 = 1;
                                selectmjk = 3;
                                choosep13.setFillColor(sf::Color(210, 210, 210));
                                choosep12.setFillColor(sf::Color::White);
                                choosep11.setFillColor(sf::Color::White);
                                choosep23.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color(210, 210, 210));
                                text2.setString("M");
                                text1.setString("K");
                                p1.setSelect(selectmjk1);
                                p2.setSelect(selectmjk2);
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                            if (((p1.getRec().getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && p1.getRec().getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && p1.getRec().getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && p1.getRec().getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2) || (p2.getRec().getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && p2.getRec().getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && p2.getRec().getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && p2.getRec().getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2)))
                            {
                                p2_exists = false;
                                selectmjk1 = 3;
                                selectmjk2 = 1;
                                selectmjk = 3;
                                choosep13.setFillColor(sf::Color(210, 210, 210));
                                choosep12.setFillColor(sf::Color::White);
                                choosep11.setFillColor(sf::Color::White);
                                choosep23.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color(210, 210, 210));
                                text2.setString("M");
                                text1.setString("K");
                                p1.setSelect(selectmjk1);
                                p2.setSelect(selectmjk2);
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                        }
                    }
                    stopClick.restart().asMilliseconds();
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
                if (selectmjk1 == 1 || selectmjk2 == 1)
                {
                    //In Game
                    if (!menu && !settings && !select_player && !instruction && !music)
                    {
                        if (!goal1->getStop() && !goal2->getStop() && !goal3->getStop())
                        {
                            if (clock4.getElapsedTime().asSeconds() > 1)
                            {
                                if (!resetrof)
                                {
                                    if (selectmjk1 == 1)
                                        timee = clock.getElapsedTime();
                                    else if (selectmjk2 == 1)
                                        timee2 = clock0.getElapsedTime();
                                }
                                else
                                {
                                    if (selectmjk1 == 1)
                                        timee = speedb;
                                    else if (selectmjk2 == 1)
                                        timee2 = speedb2;
                                    resetrof = false;
                                }
                                if ((sf::Mouse::Button::Left == event.mouseButton.button) && (timee.asMilliseconds() >= rate_of_fire) && (p1.getAmmunition() > 0) && (selectmjk1 == 1))
                                {
                                    if (!end_of_time)
                                    {
                                        if (!p2_exists)
                                        {
                                            test = true;
                                            p1.getAmmunition()--;
                                            speedbar = true;
                                            clock3.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                                        }
                                        else
                                        {
                                            test = true;
                                            p1.getAmmunition()--;
                                            speedbar = true;
                                            clock3.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                        }
                                        if (smOn)
                                            hit1Sound.play();
                                    }
                                }
                                if ((sf::Mouse::Button::Left == event.mouseButton.button) && (timee2.asMilliseconds() >= rate_of_fire) && (p2.getAmmunition() > 0) && (p2_exists))
                                {
                                    if (!end_of_time)
                                    {
                                        if (selectmjk2 == 1)
                                        {
                                            test2 = true;
                                            p2.getAmmunition()--;
                                            speedbar2 = true;
                                            clock32.restart().asMilliseconds();
                                            textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                        }
                                        if (smOn)
                                            hit2Sound.play();
                                    }
                                }
                            }
                        }
                    }
                    //Main menu
                    else if (menu && !settings && !select_player && !instruction && !music)
                    {
                        cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                        cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                        //New Game
                        if (smOn)
                            menuSound.play();
                        if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 150 && cursor_mouse.getPosition().y < 250)
                        {
                            menu = false;
                            textName.setFillColor(sf::Color::White);
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
                            end_of_time = false;
                            cursorEndGame = true;
                            resetrof = true;
                            end = true;
                            clock4.restart().asSeconds();

                            if (mOn)
                            {
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.stop();
                                    break;
                                case 2:
                                    music_02.stop();
                                    break;
                                case 3:
                                    music_03.stop();
                                    break;
                                case 4:
                                    music_04.stop();
                                    break;
                                case 5:
                                    music_05.stop();
                                    break;
                                case 6:
                                    music_06.stop();
                                    break;
                                case 7:
                                    music_07.stop();
                                    break;
                                case 8:
                                    music_08.stop();
                                    break;
                                case 9:
                                    music_09.stop();
                                    break;
                                }
                                music_stop = true;
                                volume = volumeConst;
                                randMusic = rand() % 9 + 1;
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.setVolume(volume);
                                    music_01.play();
                                    break;
                                case 2:
                                    music_02.setVolume(volume);
                                    music_02.play();
                                    break;
                                case 3:
                                    music_03.setVolume(volume);
                                    music_03.play();
                                    break;
                                case 4:
                                    music_04.setVolume(volume);
                                    music_04.play();
                                    break;
                                case 5:
                                    music_05.setVolume(volume);
                                    music_05.play();
                                    break;
                                case 6:
                                    music_06.setVolume(volume);
                                    music_06.play();
                                    break;
                                case 7:
                                    music_07.setVolume(volume);
                                    music_07.play();
                                    break;
                                case 8:
                                    music_08.setVolume(volume);
                                    music_08.play();
                                    break;
                                case 9:
                                    music_09.setVolume(volume);
                                    music_09.play();
                                    break;
                                }
                            }
                        }
                        //Continue
                        else if (game == true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 270 && cursor_mouse.getPosition().y < 370)
                        {
                            menu = false;
                            textName.setFillColor(sf::Color::White);
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
                            if (p2_exists && selectmjk2 == 2)
                                p2.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                            else if (selectmjk1 == 2)
                                p1.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);

                            if (mOn)
                            {
                                switch (randMusic)
                                {
                                case 1:
                                    music_01.play();
                                    break;
                                case 2:
                                    music_02.play();
                                    break;
                                case 3:
                                    music_03.play();
                                    break;
                                case 4:
                                    music_04.play();
                                    break;
                                case 5:
                                    music_05.play();
                                    break;
                                case 6:
                                    music_06.play();
                                    break;
                                case 7:
                                    music_07.play();
                                    break;
                                case 8:
                                    music_08.play();
                                    break;
                                case 9:
                                    music_09.play();
                                    break;
                                }
                            }
                        }
                        //Player
                        else if (game == false && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 270 && cursor_mouse.getPosition().y < 370)
                        {
                            menu = false;
                            select_player = true;
                            if (p1.getSelect() == 1)
                                window.setMouseCursorVisible(true);
                            else
                                window.setMouseCursorVisible(false);
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
                            menu = false;
                            instruction = true;
                            clockHelp.restart().asMilliseconds();
                            hcount = 1;
                            helpc = 0;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 100, 125 });
                            recm1h.setPosition(400, 265);
                            recm0h.setPosition(650, 300);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("The pointer movement in the game");
                            textm12h.setString("corresponds to the mouse movement.");

                        }
                        //Note
                        else if (cursor_mouse.getPosition().x > 900 && cursor_mouse.getPosition().x < 950 && cursor_mouse.getPosition().y > 680 && cursor_mouse.getPosition().y < 730)
                        {
                            menu = false;
                            music = true;
                        }
                        //Quit
                        else if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 630 && cursor_mouse.getPosition().y < 730)
                        {
                            window.close();
                        }
                    }
                    //Settings
                    else if (!menu && settings && !select_player && !instruction && !music)
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
                            menuSound.play();
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
                            speed = 150;
                            sot_text.setString(std::to_string(speed));
                            sot_text.setPosition(848, 465);
                            tspeed = sf::milliseconds(210 - speed);
                            rate_of_fire = 1200;
                            rof_text.setString(std::to_string(rate_of_fire));
                            rof_text.setPosition(838, 565);
                            sensitivity = 20;
                            s_text.setString(std::to_string(sensitivity));
                            s_text.setPosition(858, 665);
                            p2.setAmmunition(ammun);
                            p2samu = std::to_string(p2.getAmmunition());
                            p2.setVibrations(vibrations);
                            if (!p2_exists)
                            {
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                            else
                            {
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedb2 = sf::milliseconds(rate_of_fire);
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
                            tspeed = sf::milliseconds(210 - speed);
                        }
                        else if (cursor_mouse.getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && cursor_mouse.getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && cursor_mouse.getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && cursor_mouse.getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2)
                        {
                            if (speed == 90)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                                sot_text.setPosition(848, 465);
                            }
                            else if (speed != 200)
                            {
                                speed += 10;
                                sot_text.setString(std::to_string(speed));
                            }
                            change = true;
                            tspeed = sf::milliseconds(210 - speed);
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
                            else if (rate_of_fire != 800)
                            {
                                rate_of_fire -= 100;
                                rof_text.setString(std::to_string(rate_of_fire));
                            }
                            change = true;
                            speedb = sf::milliseconds(rate_of_fire);
                            speedb2 = sf::milliseconds(rate_of_fire);
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
                            speedb2 = sf::milliseconds(rate_of_fire);
                            speedbar = true;
                            speedbar2 = true;
                        }
                        //Sensitivity
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
                            else if (sensitivity != 99)
                            {
                                sensitivity++;
                                s_text.setString(std::to_string(sensitivity));
                            }
                        }
                    }
                    //Help
                    else if (!menu && !settings && !select_player && instruction && !music)
                    {
                        cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                        cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                        //Back
                        if (cursor_mouse.getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && cursor_mouse.getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && cursor_mouse.getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && cursor_mouse.getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)
                        {
                            instruction = false;
                            menu = true;
                        }
                        //r
                        else if (hcount == 1 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 2;
                            helpc = 1;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 200, 250 });
                            recm1h.setPosition(500, 265);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the left mouse button to shoot.");
                        }
                        else if (hcount == 2 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 3;
                            helpc = 0;
                            recc1h.setSize({ 190, 125 });
                            recc1h.setPosition(400, 315);
                            recc0h.setPosition(650, 300);
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Use the Left stick on the controller");
                            textm12h.setString("to move the pointer in the game.");
                        }
                        else if (hcount == 3 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 4;
                            helpc = 1;
                            recc1h.setSize({ 380, 250 });
                            recc1h.setPosition(410, 260);
                            recc1h.setTexture(&tcontroller00);
                            textm11h.setString("Click the Right Trigger on the");
                            textm12h.setString("controller to shoot.");
                        }
                        else if (hcount == 4 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 5;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Click the Start button on the");
                            textm12h.setString("controller to return to the main menu.");
                        }
                        else if (hcount == 5 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 6;
                            helpc = 0;
                            reck1h.setTexture(&tkeyboard0);
                            textm11h.setString("Use the WSDA buttons to move");
                            textm12h.setString("the pointer in the game.");
                        }
                        else if (hcount == 6 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 7;
                            helpc = 1;
                            reck2h.setTexture(&tkeyboard0Space);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the Spacebar to shoot.");
                        }
                        else if (hcount == 7 && cursor_mouse.getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2)
                        {
                            hcount = 8;
                            helpc = 1;
                            reck3h.setTexture(&tkeyboard0Esc);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Click the Esc button to return to");
                            textm12h.setString("the main menu.");
                        }
                        //l
                        else if (hcount == 2 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 1;
                            helpc = 0;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 100, 125 });
                            recm1h.setPosition(400, 265);
                            recm0h.setPosition(650, 300);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("The pointer movement in the game");
                            textm12h.setString("corresponds to the mouse movement.");
                        }
                        else if (hcount == 3 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 2;
                            helpc = 1;
                            recm1h.setTexture(&tmouse0h);
                            recm1h.setSize({ 200, 250 });
                            recm1h.setPosition(500, 265);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the left mouse button to shoot.");
                        }
                        else if (hcount == 4 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 3;
                            helpc = 0;
                            recc1h.setSize({ 190, 125 });
                            recc1h.setPosition(400, 315);
                            recc0h.setPosition(650, 300);
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Use the Left stick on the controller");
                            textm12h.setString("to move the pointer in the game.");
                        }
                        else if (hcount == 5 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 4;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller00);
                            textm11h.setString("Click the Right Trigger on the");
                            textm12h.setString("controller to shoot.");
                        }
                        else if (hcount == 6 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 5;
                            helpc = 1;
                            recc1h.setTexture(&tcontroller0);
                            textm11h.setString("Click the Start button on the");
                            textm12h.setString("controller to return to the main menu.");
                        }
                        else if (hcount == 7 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 6;
                            helpc = 0;
                            reck1h.setTexture(&tkeyboard0);
                            textm11h.setPosition(375, 608);
                            textm11h.setString("Use the WSDA buttons to move");
                            textm12h.setString("the pointer in the game.");
                        }
                        else if (hcount == 8 && cursor_mouse.getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2)
                        {
                            hcount = 7;
                            helpc = 1;
                            reck2h.setTexture(&tkeyboard0Space);
                            textm11h.setPosition(375, 632);
                            textm11h.setString("Click the Spacebar to shoot.");
                        }
                    }
                    //Music
                    if (!menu && !settings && !select_player && !instruction && music)
                    {
                        cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                        cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                        music_01.setVolume(volumeConst);
                        music_02.setVolume(volumeConst);
                        music_03.setVolume(volumeConst);
                        music_04.setVolume(volumeConst);
                        music_05.setVolume(volumeConst);
                        music_06.setVolume(volumeConst);
                        music_07.setVolume(volumeConst);
                        music_08.setVolume(volumeConst);
                        music_09.setVolume(volumeConst);
                        //Back
                        if (cursor_mouse.getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && cursor_mouse.getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && cursor_mouse.getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && cursor_mouse.getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)
                        {
                            music = false;
                            menu = true;
                        }
                        else if (cursor_mouse.getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && cursor_mouse.getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && cursor_mouse.getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && cursor_mouse.getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2)
                        {
                            hit1_counter = 1;
                            hit2_counter = 2;
                            reload1_counter = 1;
                            reload2_counter = 2;
                            hit1Sound.setBuffer(hit01SoundBuffer);
                            SoundsN1T.setString("1");
                            reload1Sound.setBuffer(reload01SoundBuffer);
                            sMucicNT.setString("1");
                            hit2Sound.setBuffer(hit01SoundBuffer);
                            sSoundsNT.setString("2");
                            reload2Sound.setBuffer(reload01SoundBuffer);
                            sSoundsN1T.setString("2");
                            mOn = true;
                            MusicNT.setString("On");
                            smOn = true;
                            SoundsNT.setString("On");
                            menuSound.play();
                            volumeConst = 25;
                            volumeConst1 = 40;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                            music_01.stop();
                            volumeM = true;
                        }
                        else if (!musicOn && (cursor_mouse.getPosition().x >= rec0n.getPosition().x && cursor_mouse.getPosition().x <= rec0n.getPosition().x + rec0n.getSize().x && cursor_mouse.getPosition().y >= rec0n.getPosition().y && cursor_mouse.getPosition().y <= rec0n.getPosition().y + rec0n.getSize().y))
                        {
                            musicOn = true;
                            mOn = true;
                            MusicNT.setString("On");
                            smOn = true;
                            SoundsNT.setString("On");
                        }
                        else if (musicOn && mOn && ((cursor_mouse.getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (cursor_mouse.getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2)))
                        {
                            MusicNT.setString("Off");
                            mOn = false;

                            switch (randMusic)
                            {
                            case 1:
                                music_01.stop();
                                break;
                            case 2:
                                music_02.stop();
                                break;
                            case 3:
                                music_03.stop();
                                break;
                            case 4:
                                music_04.stop();
                                break;
                            case 5:
                                music_05.stop();
                                break;
                            case 6:
                                music_06.stop();
                                break;
                            case 7:
                                music_07.stop();
                                break;
                            case 8:
                                music_08.stop();
                                break;
                            case 9:
                                music_09.stop();
                                break;
                            }
                            music_stop = false;
                        }
                        else if (musicOn && !mOn && ((cursor_mouse.getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (cursor_mouse.getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2)))
                        {
                            MusicNT.setString("On");
                            mOn = true;
                        }
                        else if (musicOn && mOn && volumeM && (cursor_mouse.getPosition().x >= rec12n.getPosition().x && cursor_mouse.getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && cursor_mouse.getPosition().y >= rec12n.getPosition().y && cursor_mouse.getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y))
                        {
                            volumeM = false;
                            music_01.play();
                        }
                        else if (musicOn && mOn && !volumeM && (cursor_mouse.getPosition().x >= rec12n.getPosition().x && cursor_mouse.getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && cursor_mouse.getPosition().y >= rec12n.getPosition().y && cursor_mouse.getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y))
                        {
                            volumeM = true;
                            music_01.stop();
                        }
                        else if (musicOn && mOn && (volumeConst != 1) && (cursor_mouse.getPosition().x >= rec13n.getPosition().x && cursor_mouse.getPosition().x <= rec13n.getPosition().x + rec13n.getSize().x && cursor_mouse.getPosition().y >= rec13n.getPosition().y && cursor_mouse.getPosition().y <= rec13n.getPosition().y + rec13n.getSize().y))
                        {
                            music_01.stop();
                            volumeM = true;
                            volumeConst--;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);

                        }
                        else if (musicOn && mOn && (volumeConst != 100) && (cursor_mouse.getPosition().x >= rec14n.getPosition().x && cursor_mouse.getPosition().x <= rec14n.getPosition().x + rec14n.getSize().x && cursor_mouse.getPosition().y >= rec14n.getPosition().y && cursor_mouse.getPosition().y <= rec14n.getPosition().y + rec14n.getSize().y))
                        {
                            music_01.stop();
                            volumeM = true;
                            volumeConst++;
                            volumeText.setString(std::to_string(volumeConst) + "%");
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);
                        }
                        else if (musicOn && smOn && ((cursor_mouse.getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (cursor_mouse.getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2)))
                        {
                            SoundsNT.setString("Off");
                            smOn = false;
                        }
                        else if (musicOn && !smOn && ((cursor_mouse.getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (cursor_mouse.getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2)))
                        {
                            SoundsNT.setString("On");
                            smOn = true;
                        }
                        else if (musicOn && smOn && (cursor_mouse.getPosition().x >= rec22n.getPosition().x && cursor_mouse.getPosition().x <= rec22n.getPosition().x + rec22n.getSize().x && cursor_mouse.getPosition().y >= rec22n.getPosition().y && cursor_mouse.getPosition().y <= rec22n.getPosition().y + rec22n.getSize().y))
                        {
                            menuSound.play();
                        }
                        else if (musicOn && smOn && (volumeConst1 != 1) && (cursor_mouse.getPosition().x >= rec23n.getPosition().x && cursor_mouse.getPosition().x <= rec23n.getPosition().x + rec23n.getSize().x && cursor_mouse.getPosition().y >= rec23n.getPosition().y && cursor_mouse.getPosition().y <= rec23n.getPosition().y + rec23n.getSize().y))
                        {
                            volumeConst1--;
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                        }
                        else if (musicOn && smOn && (volumeConst1 != 100) && (cursor_mouse.getPosition().x >= rec24n.getPosition().x && cursor_mouse.getPosition().x <= rec24n.getPosition().x + rec24n.getSize().x && cursor_mouse.getPosition().y >= rec24n.getPosition().y && cursor_mouse.getPosition().y <= rec24n.getPosition().y + rec24n.getSize().y))
                        {
                            volumeConst1++;
                            volumeText1.setString(std::to_string(volumeConst1) + "%");
                            hit1Sound.setVolume(volumeConst1);
                            hit2Sound.setVolume(volumeConst1);
                            reload1Sound.setVolume(volumeConst1);
                            reload2Sound.setVolume(volumeConst1);
                            menuSound.setVolume(volumeConst1);
                        }
                        //Hit 1
                        if (hit1_counter != 1 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn21left.getPosition().x - bn21left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn21left.getPosition().x + bn21left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn21left.getPosition().y - bn21left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn21left.getPosition().y + bn21left.getSize().y / 2))
                        {
                            if (hit1_counter == 6)
                            {
                                hit1Sound.setBuffer(hit05SoundBuffer);
                                SoundsN1T.setString("5");
                            }
                            else if (hit1_counter == 5)
                            {
                                hit1Sound.setBuffer(hit04SoundBuffer);
                                SoundsN1T.setString("4");
                            }
                            else if (hit1_counter == 4)
                            {
                                hit1Sound.setBuffer(hit03SoundBuffer);
                                SoundsN1T.setString("3");
                            }
                            else if (hit1_counter == 3)
                            {
                                hit1Sound.setBuffer(hit02SoundBuffer);
                                SoundsN1T.setString("2");
                            }
                            else if (hit1_counter == 2)
                            {
                                hit1Sound.setBuffer(hit01SoundBuffer);
                                SoundsN1T.setString("1");
                            }
                            hit1_counter--;
                        }
                        else if (hit1_counter != 6 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn21right.getPosition().x - bn21right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn21right.getPosition().x + bn21right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn21right.getPosition().y - bn21right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn21right.getPosition().y + bn21right.getSize().y / 2))
                        {
                            if (hit1_counter == 1)
                            {
                                hit1Sound.setBuffer(hit02SoundBuffer);
                                SoundsN1T.setString("2");
                            }
                            else if (hit1_counter == 2)
                            {
                                hit1Sound.setBuffer(hit03SoundBuffer);
                                SoundsN1T.setString("3");
                            }
                            else if (hit1_counter == 3)
                            {
                                hit1Sound.setBuffer(hit04SoundBuffer);
                                SoundsN1T.setString("4");
                            }
                            else if (hit1_counter == 4)
                            {
                                hit1Sound.setBuffer(hit05SoundBuffer);
                                SoundsN1T.setString("5");
                            }
                            else if (hit1_counter == 5)
                            {
                                hit1Sound.setBuffer(hit06SoundBuffer);
                                SoundsN1T.setString("6");
                            }
                            hit1_counter++;
                        }
                        else if (musicOn && smOn && (cursor_mouse.getPosition().x >= rechs1n.getPosition().x && cursor_mouse.getPosition().x <= rechs1n.getPosition().x + rechs1n.getSize().x && cursor_mouse.getPosition().y >= rechs1n.getPosition().y && cursor_mouse.getPosition().y <= rechs1n.getPosition().y + rechs1n.getSize().y))
                        {
                            hit1Sound.play();
                        }
                        //Reload 1
                        else if (reload1_counter != 1 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn3left.getPosition().x - bn3left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn3left.getPosition().x + bn3left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn3left.getPosition().y - bn3left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn3left.getPosition().y + bn3left.getSize().y / 2))
                        {
                            if (reload1_counter == 6)
                            {
                                reload1Sound.setBuffer(reload05SoundBuffer);
                                sMucicNT.setString("5");
                            }
                            else if (reload1_counter == 5)
                            {
                                reload1Sound.setBuffer(reload04SoundBuffer);
                                sMucicNT.setString("4");
                            }
                            else if (reload1_counter == 4)
                            {
                                reload1Sound.setBuffer(reload03SoundBuffer);
                                sMucicNT.setString("3");
                            }
                            else if (reload1_counter == 3)
                            {
                                reload1Sound.setBuffer(reload02SoundBuffer);
                                sMucicNT.setString("2");
                            }
                            else if (reload1_counter == 2)
                            {
                                reload1Sound.setBuffer(reload01SoundBuffer);
                                sMucicNT.setString("1");
                            }
                            reload1_counter--;
                        }
                        else if (reload1_counter != 6 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn3right.getPosition().x - bn3right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn3right.getPosition().x + bn3right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn3right.getPosition().y - bn3right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn3right.getPosition().y + bn3right.getSize().y / 2))
                        {
                            if (reload1_counter == 1)
                            {
                                reload1Sound.setBuffer(reload02SoundBuffer);
                                sMucicNT.setString("2");
                            }
                            else if (reload1_counter == 2)
                            {
                                reload1Sound.setBuffer(reload03SoundBuffer);
                                sMucicNT.setString("3");
                            }
                            else if (reload1_counter == 3)
                            {
                                reload1Sound.setBuffer(reload04SoundBuffer);
                                sMucicNT.setString("4");
                            }
                            else if (reload1_counter == 4)
                            {
                                reload1Sound.setBuffer(reload05SoundBuffer);
                                sMucicNT.setString("5");
                            }
                            else if (reload1_counter == 5)
                            {
                                reload1Sound.setBuffer(reload06SoundBuffer);
                                sMucicNT.setString("6");
                            }
                            reload1_counter++;
                        }
                        else if (musicOn && smOn && (cursor_mouse.getPosition().x >= recrs1n.getPosition().x && cursor_mouse.getPosition().x <= recrs1n.getPosition().x + recrs1n.getSize().x && cursor_mouse.getPosition().y >= recrs1n.getPosition().y && cursor_mouse.getPosition().y <= recrs1n.getPosition().y + recrs1n.getSize().y))
                        {
                            reload1Sound.play();
                        }
                        //Hit 2
                        else if (hit2_counter != 1 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn4left.getPosition().x - bn4left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn4left.getPosition().x + bn4left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn4left.getPosition().y - bn4left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn4left.getPosition().y + bn4left.getSize().y / 2))
                        {
                            if (hit2_counter == 6)
                            {
                                hit2Sound.setBuffer(hit05SoundBuffer);
                                sSoundsNT.setString("5");
                            }
                            else if (hit2_counter == 5)
                            {
                                hit2Sound.setBuffer(hit04SoundBuffer);
                                sSoundsNT.setString("4");
                            }
                            else if (hit2_counter == 4)
                            {
                                hit2Sound.setBuffer(hit03SoundBuffer);
                                sSoundsNT.setString("3");
                            }
                            else if (hit2_counter == 3)
                            {
                                hit2Sound.setBuffer(hit02SoundBuffer);
                                sSoundsNT.setString("2");
                            }
                            else if (hit2_counter == 2)
                            {
                                hit2Sound.setBuffer(hit01SoundBuffer);
                                sSoundsNT.setString("1");
                            }
                            hit2_counter--;
                        }
                        else if (hit2_counter != 6 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn4right.getPosition().x - bn4right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn4right.getPosition().x + bn4right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn4right.getPosition().y - bn4right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn4right.getPosition().y + bn4right.getSize().y / 2))
                        {
                            if (hit2_counter == 1)
                            {
                                hit2Sound.setBuffer(hit02SoundBuffer);
                                sSoundsNT.setString("2");
                            }
                            else if (hit2_counter == 2)
                            {
                                hit2Sound.setBuffer(hit03SoundBuffer);
                                sSoundsNT.setString("3");
                            }
                            else if (hit2_counter == 3)
                            {
                                hit2Sound.setBuffer(hit04SoundBuffer);
                                sSoundsNT.setString("4");
                            }
                            else if (hit2_counter == 4)
                            {
                                hit2Sound.setBuffer(hit05SoundBuffer);
                                sSoundsNT.setString("5");
                            }
                            else if (hit2_counter == 5)
                            {
                                hit2Sound.setBuffer(hit06SoundBuffer);
                                sSoundsNT.setString("6");
                            }
                            hit2_counter++;
                        }
                        else if (musicOn && smOn && (cursor_mouse.getPosition().x >= rechs2n.getPosition().x && cursor_mouse.getPosition().x <= rechs2n.getPosition().x + rechs2n.getSize().x && cursor_mouse.getPosition().y >= rechs2n.getPosition().y && cursor_mouse.getPosition().y <= rechs2n.getPosition().y + rechs2n.getSize().y))
                        {
                            hit2Sound.play();
                        }
                        //Reload 2
                        else if (reload2_counter != 1 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn41left.getPosition().x - bn41left.getSize().x / 2 && cursor_mouse.getPosition().x <= bn41left.getPosition().x + bn41left.getSize().x / 2 && cursor_mouse.getPosition().y >= bn41left.getPosition().y - bn41left.getSize().y / 2 && cursor_mouse.getPosition().y <= bn41left.getPosition().y + bn41left.getSize().y / 2))
                        {
                            if (reload2_counter == 6)
                            {
                                reload2Sound.setBuffer(reload05SoundBuffer);
                                sSoundsN1T.setString("5");
                            }
                            else if (reload2_counter == 5)
                            {
                                reload2Sound.setBuffer(reload04SoundBuffer);
                                sSoundsN1T.setString("4");
                            }
                            else if (reload2_counter == 4)
                            {
                                reload2Sound.setBuffer(reload03SoundBuffer);
                                sSoundsN1T.setString("3");
                            }
                            else if (reload2_counter == 3)
                            {
                                reload2Sound.setBuffer(reload02SoundBuffer);
                                sSoundsN1T.setString("2");
                            }
                            else if (reload2_counter == 2)
                            {
                                reload2Sound.setBuffer(reload01SoundBuffer);
                                sSoundsN1T.setString("1");
                            }
                            reload2_counter--;
                        }
                        else if (reload2_counter != 6 && musicOn && smOn && (cursor_mouse.getPosition().x >= bn41right.getPosition().x - bn41right.getSize().x / 2 && cursor_mouse.getPosition().x <= bn41right.getPosition().x + bn41right.getSize().x / 2 && cursor_mouse.getPosition().y >= bn41right.getPosition().y - bn41right.getSize().y / 2 && cursor_mouse.getPosition().y <= bn41right.getPosition().y + bn41right.getSize().y / 2))
                        {
                            if (reload2_counter == 1)
                            {
                                reload2Sound.setBuffer(reload02SoundBuffer);
                                sSoundsN1T.setString("2");
                            }
                            else if (reload2_counter == 2)
                            {
                                reload2Sound.setBuffer(reload03SoundBuffer);
                                sSoundsN1T.setString("3");
                            }
                            else if (reload2_counter == 3)
                            {
                                reload2Sound.setBuffer(reload04SoundBuffer);
                                sSoundsN1T.setString("4");
                            }
                            else if (reload2_counter == 4)
                            {
                                reload2Sound.setBuffer(reload05SoundBuffer);
                                sSoundsN1T.setString("5");
                            }
                            else if (reload2_counter == 5)
                            {
                                reload2Sound.setBuffer(reload06SoundBuffer);
                                sSoundsN1T.setString("6");
                            }
                            reload2_counter++;
                        }
                        else if (musicOn && smOn && (cursor_mouse.getPosition().x >= recrs2n.getPosition().x && cursor_mouse.getPosition().x <= recrs2n.getPosition().x + recrs2n.getSize().x && cursor_mouse.getPosition().y >= recrs2n.getPosition().y && cursor_mouse.getPosition().y <= recrs2n.getPosition().y + recrs2n.getSize().y))
                        {
                            reload2Sound.play();
                        }
                        if (!mOn && !smOn)
                        {
                            musicOn = false;
                        }
                    }
                    //Player
                    else if (!menu && !settings && select_player && !instruction && !music)
                    {
                        cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                        cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                        //Back
                        if (cursor_mouse.getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && cursor_mouse.getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && cursor_mouse.getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && cursor_mouse.getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2)
                        {
                            select_player = false;
                            menu = true;
                            window.setMouseCursorVisible(true);
                        }
                        //rl1
                        else if (!p2_exists)
                        {
                            if (selectmjk == 1 && cursor_mouse.getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)
                            {
                                selectmjk = 2;
                            }
                            else if (selectmjk == 2 && cursor_mouse.getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)
                            {
                                selectmjk = 1;
                            }
                            else if (selectmjk == 2 && cursor_mouse.getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)
                            {
                                selectmjk = 3;
                            }
                            else if (selectmjk == 3 && cursor_mouse.getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)
                            {
                                selectmjk = 2;
                            }
                        }
                        else if (p1.getSelect() == 1)
                        {
                            if (selectmjk == 1 && cursor_mouse.getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2)
                            {
                                selectmjk = 3;
                            }
                            else if (selectmjk == 3 && cursor_mouse.getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && cursor_mouse.getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && cursor_mouse.getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && cursor_mouse.getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2)
                            {
                                selectmjk = 1;
                            }
                        }
                        //Select
                        if (p1.getSelect() == 1 && selectmjk1 != selectmjk && cursor_mouse.getPosition().x >= choosep12.getPosition().x - choosep12.getSize().x / 2 && cursor_mouse.getPosition().x <= choosep12.getPosition().x + choosep12.getSize().x / 2 && cursor_mouse.getPosition().y >= choosep12.getPosition().y - choosep12.getSize().y / 2 && cursor_mouse.getPosition().y <= choosep12.getPosition().y + choosep12.getSize().y / 2)
                        {
                            if (!p2_exists)
                            {
                                if (stop && (selectmjk == 2))
                                {
                                    std::cout << "Joystick is Disconnected" << std::endl;
                                }
                                else
                                {
                                    selectmjk1 = selectmjk;
                                    p1.setSelect(selectmjk1);
                                    p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                                    switch (selectmjk1)
                                    {
                                    case 1:
                                        selectmjk2 = 3;
                                        choosep11.setFillColor(sf::Color(210, 210, 210));
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color::White);
                                        choosep21.setFillColor(sf::Color::White);
                                        choosep23.setFillColor(sf::Color(210, 210, 210));
                                        text1.setString("M");
                                        text2.setString("K");
                                        break;
                                    case 2:
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color(210, 210, 210));
                                        choosep13.setFillColor(sf::Color::White);
                                        text1.setString("C");
                                        break;
                                    case 3:
                                        selectmjk2 = 1;
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color(210, 210, 210));
                                        choosep21.setFillColor(sf::Color(210, 210, 210));
                                        choosep23.setFillColor(sf::Color::White);
                                        text1.setString("K");
                                        text2.setString("M");
                                        break;
                                    }
                                    p2.setSelect(selectmjk2);
                                }
                            }
                            else
                            {
                                if (selectmjk == 2)
                                {
                                    selectmjk = 1;
                                    selectmjk1 = selectmjk;
                                }
                                else
                                {
                                    selectmjk1 = selectmjk;
                                    p1.setSelect(selectmjk1);
                                    p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                                    switch (selectmjk1)
                                    {
                                    case 1:
                                        choosep11.setFillColor(sf::Color(210, 210, 210));
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color::White);
                                        text1.setString("M");
                                        choosep21.setFillColor(sf::Color::White);
                                        choosep23.setFillColor(sf::Color(210, 210, 210));
                                        text2.setString("K");
                                        selectmjk2 = 3;
                                        p2.setSelect(selectmjk2);
                                        break;
                                    case 3:
                                        selectmjk2 = 1;
                                        p2.setSelect(selectmjk2);
                                        choosep11.setFillColor(sf::Color::White);
                                        choosep12.setFillColor(sf::Color::White);
                                        choosep13.setFillColor(sf::Color(210, 210, 210));
                                        text1.setString("K");
                                        choosep21.setFillColor(sf::Color(210, 210, 210));
                                        choosep23.setFillColor(sf::Color::White);
                                        text2.setString("M");
                                        window.setMouseCursorVisible(false);
                                        break;
                                    }
                                }
                            }
                        }
                        //Click
                        if (selectmjk1 != 2 && p1.getSelect() == 1)
                        {
                            if (cursor_mouse.getPosition().x >= rec4p.getPosition().x - rec4p.getSize().x / 2 && cursor_mouse.getPosition().x <= rec4p.getPosition().x + rec4p.getSize().x / 2 && cursor_mouse.getPosition().y >= rec4p.getPosition().y - rec4p.getSize().y / 2 && cursor_mouse.getPosition().y <= rec4p.getPosition().y + rec4p.getSize().y / 2)
                            {
                                p2_exists = true;
                                selectmjk1 = 1;
                                selectmjk2 = 3;
                                selectmjk = 1;
                                choosep11.setFillColor(sf::Color(210, 210, 210));
                                choosep12.setFillColor(sf::Color::White);
                                choosep13.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color::White);
                                choosep23.setFillColor(sf::Color(210, 210, 210));
                                text1.setString("M");
                                text2.setString("K");
                                p1.setSelect(selectmjk1);
                                p2.setSelect(selectmjk2);
                                textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                                window.setMouseCursorVisible(true);
                            }
                            if (cursor_mouse.getPosition().x >= Offr.getPosition().x - Offr.getSize().x / 2 && cursor_mouse.getPosition().x <= Offr.getPosition().x + Offr.getSize().x / 2 && cursor_mouse.getPosition().y >= Offr.getPosition().y - Offr.getSize().y / 2 && cursor_mouse.getPosition().y <= Offr.getPosition().y + Offr.getSize().y / 2)
                            {
                                p2_exists = false;
                                selectmjk1 = 1;
                                selectmjk2 = 3;
                                selectmjk = 1;
                                choosep11.setFillColor(sf::Color(210, 210, 210));
                                choosep12.setFillColor(sf::Color::White);
                                choosep13.setFillColor(sf::Color::White);
                                choosep21.setFillColor(sf::Color::White);
                                choosep23.setFillColor(sf::Color(210, 210, 210));
                                text1.setString("M");
                                text2.setString("K");
                                p1.setSelect(selectmjk1);
                                p2.setSelect(selectmjk2);
                                textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                            }
                        }
                    }
                }
                break;
            case sf::Event::JoystickDisconnected:
                stop = true;
                break;
            case sf::Event::JoystickButtonPressed:
                if (!menu && !settings && !select_player && !instruction)
                {
                    if (sf::Joystick::isButtonPressed(0, 7))
                    {
                        menu = true;
                        textName.setFillColor(sf::Color::White);
                        p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                        endg = false;
                        switch (randMusic)
                        {
                        case 1:
                            music_01.pause();
                            break;
                        case 2:
                            music_02.pause();
                            break;
                        case 3:
                            music_03.pause();
                            break;
                        case 4:
                            music_04.pause();
                            break;
                        case 5:
                            music_05.pause();
                            break;
                        case 6:
                            music_06.pause();
                            break;
                        case 7:
                            music_07.pause();
                            break;
                        case 8:
                            music_08.pause();
                            break;
                        case 9:
                            music_09.pause();
                            break;
                        }
                    }
                }
                break;
            case sf::Event::JoystickMoved:
                if (selectmjk1 == 2 && !p2_exists)
                {
                    if (stopClick.getElapsedTime().asMilliseconds() >= 250)
                    {
                        //In Game
                        if (!menu && !settings && !select_player && !instruction && !music)
                        {
                            if (!goal1->getStop() && !goal2->getStop() && !goal3->getStop())
                            {
                                if (clock4.getElapsedTime().asSeconds() > 1)
                                {
                                    if (!resetrof)
                                    {
                                        if (selectmjk1 == 2)
                                            timee = clock.getElapsedTime();
                                        else if (selectmjk2 == 2)
                                            timee2 = clock0.getElapsedTime();
                                    }
                                    else
                                    {
                                        if (selectmjk1 == 2)
                                            timee = speedb;
                                        else if (selectmjk2 == 2)
                                            timee2 = speedb2;
                                        resetrof = false;
                                    }
                                    if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (timee.asMilliseconds() >= rate_of_fire) && (p1.getAmmunition() > 0) && (selectmjk1 == 2))
                                    {
                                        if (!end_of_time)
                                        {
                                            if (!p2_exists)
                                            {
                                                test = true;
                                                p1.getAmmunition()--;
                                                speedbar = true;
                                                clock3.restart().asMilliseconds();
                                                textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                                            }
                                            else
                                            {
                                                test = true;
                                                p1.getAmmunition()--;
                                                speedbar = true;
                                                clock3.restart().asMilliseconds();
                                                textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                            }
                                            if (smOn)
                                                hit1Sound.play();
                                        }
                                    }
                                    if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (timee2.asMilliseconds() >= rate_of_fire) && (p2.getAmmunition() > 0) && (p2_exists))
                                    {
                                        if (!end_of_time)
                                        {
                                            if (selectmjk2 == 2)
                                            {
                                                test2 = true;
                                                p2.getAmmunition()--;
                                                speedbar2 = true;
                                                clock32.restart().asMilliseconds();
                                                textAmmunition.setString("Ammunition: 1p." + std::to_string(p1.getAmmunition()) + "/" + p1samu + "  2p." + std::to_string(p2.getAmmunition()) + "/" + p2samu);
                                            }
                                            if (smOn)
                                                hit2Sound.play();
                                        }
                                    }
                                }
                            }
                        }
                        //Main menu
                        else if (menu && !settings && !select_player && !instruction && !music)
                        {
                            //New Game
                            if (smOn && sf::Joystick::Axis::Z == event.joystickMove.axis)
                                menuSound.play();
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 150 && p1.getRec().getPosition().y < 250))
                            {
                                menu = false;
                                textName.setFillColor(sf::Color::White);
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
                                end_of_time = false;
                                cursorEndGame = true;
                                resetrof = true;
                                end = true;
                                clock4.restart().asSeconds();

                                if (mOn)
                                {
                                    switch (randMusic)
                                    {
                                    case 1:
                                        music_01.stop();
                                        break;
                                    case 2:
                                        music_02.stop();
                                        break;
                                    case 3:
                                        music_03.stop();
                                        break;
                                    case 4:
                                        music_04.stop();
                                        break;
                                    case 5:
                                        music_05.stop();
                                        break;
                                    case 6:
                                        music_06.stop();
                                        break;
                                    case 7:
                                        music_07.stop();
                                        break;
                                    case 8:
                                        music_08.stop();
                                        break;
                                    case 9:
                                        music_09.stop();
                                        break;
                                    }
                                    music_stop = true;
                                    randMusic = rand() % 9 + 1;
                                    switch (randMusic)
                                    {
                                    case 1:
                                        music_01.play();
                                        break;
                                    case 2:
                                        music_02.play();
                                        break;
                                    case 3:
                                        music_03.play();
                                        break;
                                    case 4:
                                        music_04.play();
                                        break;
                                    case 5:
                                        music_05.play();
                                        break;
                                    case 6:
                                        music_06.play();
                                        break;
                                    case 7:
                                        music_07.play();
                                        break;
                                    case 8:
                                        music_08.play();
                                        break;
                                    case 9:
                                        music_09.play();
                                        break;
                                    }
                                }
                            }
                            //Continue
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (game == true) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370))
                            {
                                menu = false;
                                textName.setFillColor(sf::Color::White);
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
                                if (p2_exists && selectmjk2 == 2)
                                    p2.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);
                                else if (selectmjk1 == 2)
                                    p1.getRec().setPosition(window.getSize().x / 2, window.getSize().y / 2);

                                if (mOn)
                                {
                                    switch (randMusic)
                                    {
                                    case 1:
                                        music_01.play();
                                        break;
                                    case 2:
                                        music_02.play();
                                        break;
                                    case 3:
                                        music_03.play();
                                        break;
                                    case 4:
                                        music_04.play();
                                        break;
                                    case 5:
                                        music_05.play();
                                        break;
                                    case 6:
                                        music_06.play();
                                        break;
                                    case 7:
                                        music_07.play();
                                        break;
                                    case 8:
                                        music_08.play();
                                        break;
                                    case 9:
                                        music_09.play();
                                        break;
                                    }
                                }
                            }
                            //Player
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (game == false) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 270 && p1.getRec().getPosition().y < 370))
                            {
                                menu = false;
                                select_player = true;
                            }
                            //Help
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 510 && p1.getRec().getPosition().y < 610))
                            {
                                menu = false;
                                instruction = true;
                                clockHelp.restart().asMilliseconds();
                                hcount = 1;
                                helpc = 0;
                                recm1h.setTexture(&tmouse0h);
                                recm1h.setSize({ 100, 125 });
                                recm1h.setPosition(400, 265);
                                recm0h.setPosition(650, 300);
                                textm11h.setPosition(375, 608);
                                textm11h.setString("The pointer movement in the game");
                                textm12h.setString("corresponds to the mouse movement.");
                            }
                            //Note
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 900 && p1.getRec().getPosition().x < 950 && p1.getRec().getPosition().y > 680 && p1.getRec().getPosition().y < 730))
                            {
                                menu = false;
                                music = true;
                            }
                            //Options
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 390 && p1.getRec().getPosition().y < 490))
                            {
                                menu = false;
                                settings = true;
                            }
                            //Quit
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x > 400 && p1.getRec().getPosition().x < 800 && p1.getRec().getPosition().y > 630 && p1.getRec().getPosition().y < 730))
                            {
                                window.close();
                            }
                        }
                        //Settings
                        else if (!menu && settings && !select_player && !instruction && !music)
                        {
                            //Back
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                            {
                                settings = false;
                                menu = true;
                            }
                            //Default
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p1.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p1.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p1.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2))
                            {
                                menuSound.play();
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
                                speed = 150;
                                sot_text.setString(std::to_string(speed));
                                sot_text.setPosition(848, 465);
                                tspeed = sf::milliseconds(210 - speed);
                                rate_of_fire = 1200;
                                rof_text.setString(std::to_string(rate_of_fire));
                                rof_text.setPosition(838, 565);
                                sensitivity = 20;
                                s_text.setString(std::to_string(sensitivity));
                                s_text.setPosition(858, 665);
                                p2.setAmmunition(ammun);
                                p2samu = std::to_string(p2.getAmmunition());
                                p2.setVibrations(vibrations);
                                if (!p2_exists)
                                {
                                    textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                                }
                                else
                                {
                                    textAmmunition.setString("Ammunition: 1p." + p1samu + "/" + p1samu + "  2p." + p2samu + "/" + p2samu);
                                }
                                change = true;
                                speedb = sf::milliseconds(rate_of_fire);
                                speedb2 = sf::milliseconds(rate_of_fire);
                                speedbar = true;
                                speedbar2 = true;
                            }
                            //Ammunition
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b1left.getPosition().x - b1left.getSize().x / 2 && p1.getRec().getPosition().x <= b1left.getPosition().x + b1left.getSize().x / 2 && p1.getRec().getPosition().y >= b1left.getPosition().y - b1left.getSize().y / 2 && p1.getRec().getPosition().y <= b1left.getPosition().y + b1left.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b1right.getPosition().x - b1right.getSize().x / 2 && p1.getRec().getPosition().x <= b1right.getPosition().x + b1right.getSize().x / 2 && p1.getRec().getPosition().y >= b1right.getPosition().y - b1right.getSize().y / 2 && p1.getRec().getPosition().y <= b1right.getPosition().y + b1right.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b2left.getPosition().x - b2left.getSize().x / 2 && p1.getRec().getPosition().x <= b2left.getPosition().x + b2left.getSize().x / 2 && p1.getRec().getPosition().y >= b2left.getPosition().y - b2left.getSize().y / 2 && p1.getRec().getPosition().y <= b2left.getPosition().y + b2left.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b2right.getPosition().x - b2right.getSize().x / 2 && p1.getRec().getPosition().x <= b2right.getPosition().x + b2right.getSize().x / 2 && p1.getRec().getPosition().y >= b2right.getPosition().y - b2right.getSize().y / 2 && p1.getRec().getPosition().y <= b2right.getPosition().y + b2right.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b3left.getPosition().x - b3left.getSize().x / 2 && p1.getRec().getPosition().x <= b3left.getPosition().x + b3left.getSize().x / 2 && p1.getRec().getPosition().y >= b3left.getPosition().y - b3left.getSize().y / 2 && p1.getRec().getPosition().y <= b3left.getPosition().y + b3left.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b3right.getPosition().x - b3right.getSize().x / 2 && p1.getRec().getPosition().x <= b3right.getPosition().x + b3right.getSize().x / 2 && p1.getRec().getPosition().y >= b3right.getPosition().y - b3right.getSize().y / 2 && p1.getRec().getPosition().y <= b3right.getPosition().y + b3right.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b4left.getPosition().x - b4left.getSize().x / 2 && p1.getRec().getPosition().x <= b4left.getPosition().x + b4left.getSize().x / 2 && p1.getRec().getPosition().y >= b4left.getPosition().y - b4left.getSize().y / 2 && p1.getRec().getPosition().y <= b4left.getPosition().y + b4left.getSize().y / 2))
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
                                tspeed = sf::milliseconds(210 - speed);
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b4right.getPosition().x - b4right.getSize().x / 2 && p1.getRec().getPosition().x <= b4right.getPosition().x + b4right.getSize().x / 2 && p1.getRec().getPosition().y >= b4right.getPosition().y - b4right.getSize().y / 2 && p1.getRec().getPosition().y <= b4right.getPosition().y + b4right.getSize().y / 2))
                            {
                                if (speed == 90)
                                {
                                    speed += 10;
                                    sot_text.setString(std::to_string(speed));
                                    sot_text.setPosition(848, 465);
                                }
                                else if (speed != 200)
                                {
                                    speed += 10;
                                    sot_text.setString(std::to_string(speed));
                                }
                                change = true;
                                tspeed = sf::milliseconds(210 - speed);
                            }
                            //Rate of fire
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b5left.getPosition().x - b5left.getSize().x / 2 && p1.getRec().getPosition().x <= b5left.getPosition().x + b5left.getSize().x / 2 && p1.getRec().getPosition().y >= b5left.getPosition().y - b5left.getSize().y / 2 && p1.getRec().getPosition().y <= b5left.getPosition().y + b5left.getSize().y / 2))
                            {
                                if (rate_of_fire == 1000)
                                {
                                    rate_of_fire -= 100;
                                    rof_text.setString(std::to_string(rate_of_fire));
                                    rof_text.setPosition(848, 565);
                                }
                                else if (rate_of_fire != 800)
                                {
                                    rate_of_fire -= 100;
                                    rof_text.setString(std::to_string(rate_of_fire));
                                }
                                change = true;
                                speedb = sf::milliseconds(rate_of_fire);
                                speedb2 = sf::milliseconds(rate_of_fire);
                                speedbar = true;
                                speedbar2 = true;
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b5right.getPosition().x - b5right.getSize().x / 2 && p1.getRec().getPosition().x <= b5right.getPosition().x + b5right.getSize().x / 2 && p1.getRec().getPosition().y >= b5right.getPosition().y - b5right.getSize().y / 2 && p1.getRec().getPosition().y <= b5right.getPosition().y + b5right.getSize().y / 2))
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
                            //Sensitivity
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b6left.getPosition().x - b6left.getSize().x / 2 && p1.getRec().getPosition().x <= b6left.getPosition().x + b6left.getSize().x / 2 && p1.getRec().getPosition().y >= b6left.getPosition().y - b6left.getSize().y / 2 && p1.getRec().getPosition().y <= b6left.getPosition().y + b6left.getSize().y / 2))
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
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= b6right.getPosition().x - b6right.getSize().x / 2 && p1.getRec().getPosition().x <= b6right.getPosition().x + b6right.getSize().x / 2 && p1.getRec().getPosition().y >= b6right.getPosition().y - b6right.getSize().y / 2 && p1.getRec().getPosition().y <= b6right.getPosition().y + b6right.getSize().y / 2))
                            {
                                if (sensitivity == 9)
                                {
                                    sensitivity++;
                                    s_text.setString(std::to_string(sensitivity));
                                    s_text.setPosition(858, 665);
                                }
                                else if (sensitivity != 99)
                                {
                                    sensitivity++;
                                    s_text.setString(std::to_string(sensitivity));
                                }
                            }
                        }
                        //Help
                        else if (!menu && !settings && !select_player && instruction && !music)
                        {
                            //Back
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                            {
                                instruction = false;
                                menu = true;
                            }
                            //r
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 1 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 2;
                                helpc = 1;
                                recm1h.setTexture(&tmouse0h);
                                recm1h.setSize({ 200, 250 });
                                recm1h.setPosition(500, 265);
                                textm11h.setPosition(375, 632);
                                textm11h.setString("Click the left mouse button to shoot.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 2 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 3;
                                helpc = 0;
                                recc1h.setSize({ 190, 125 });
                                recc1h.setPosition(400, 315);
                                recc0h.setPosition(650, 300);
                                recc1h.setTexture(&tcontroller0);
                                textm11h.setPosition(375, 608);
                                textm11h.setString("Use the Left stick on the controller");
                                textm12h.setString("to move the pointer in the game.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 3 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 4;
                                helpc = 1;
                                recc1h.setSize({ 380, 250 });
                                recc1h.setPosition(410, 260);
                                recc1h.setTexture(&tcontroller00);
                                textm11h.setString("Click the Right Trigger on the");
                                textm12h.setString("controller to shoot.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 4 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 5;
                                helpc = 1;
                                recc1h.setTexture(&tcontroller0);
                                textm11h.setString("Click the Start button on the");
                                textm12h.setString("controller to return to the main menu.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 5 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 6;
                                helpc = 0;
                                reck1h.setTexture(&tkeyboard0);
                                textm11h.setString("Use the WSDA buttons to move");
                                textm12h.setString("the pointer in the game.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 6 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 7;
                                helpc = 1;
                                reck2h.setTexture(&tkeyboard0Space);
                                textm11h.setPosition(375, 632);
                                textm11h.setString("Click the Spacebar to shoot.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 7 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1h.getPosition().x - bright1h.getSize().x / 2 && p1.getRec().getPosition().x <= bright1h.getPosition().x + bright1h.getSize().x / 2 && p1.getRec().getPosition().y >= bright1h.getPosition().y - bright1h.getSize().y / 2 && p1.getRec().getPosition().y <= bright1h.getPosition().y + bright1h.getSize().y / 2))
                            {
                                hcount = 8;
                                helpc = 1;
                                reck3h.setTexture(&tkeyboard0Esc);
                                textm11h.setPosition(375, 608);
                                textm11h.setString("Click the Esc button to return to");
                                textm12h.setString("the main menu.");
                            }
                            //l
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 1;
                                helpc = 0;
                                recm1h.setTexture(&tmouse0h);
                                recm1h.setSize({ 100, 125 });
                                recm1h.setPosition(400, 265);
                                recm0h.setPosition(650, 300);
                                textm11h.setPosition(375, 608);
                                textm11h.setString("The pointer movement in the game");
                                textm12h.setString("corresponds to the mouse movement.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 3 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 2;
                                helpc = 1;
                                recm1h.setTexture(&tmouse0h);
                                recm1h.setSize({ 200, 250 });
                                recm1h.setPosition(500, 265);
                                textm11h.setPosition(375, 632);
                                textm11h.setString("Click the left mouse button to shoot.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 4 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 3;
                                helpc = 0;
                                recc1h.setSize({ 190, 125 });
                                recc1h.setPosition(400, 315);
                                recc0h.setPosition(650, 300);
                                recc1h.setTexture(&tcontroller0);
                                textm11h.setString("Use the Left stick on the controller");
                                textm12h.setString("to move the pointer in the game.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 5 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 4;
                                helpc = 1;
                                recc1h.setTexture(&tcontroller00);
                                textm11h.setString("Click the Right Trigger on the");
                                textm12h.setString("controller to shoot.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 6 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 5;
                                helpc = 1;
                                recc1h.setTexture(&tcontroller0);
                                textm11h.setString("Click the Start button on the");
                                textm12h.setString("controller to return to the main menu.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 7 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 6;
                                helpc = 0;
                                reck1h.setTexture(&tkeyboard0);
                                textm11h.setPosition(375, 608);
                                textm11h.setString("Use the WSDA buttons to move");
                                textm12h.setString("the pointer in the game.");
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (hcount == 8 && p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1h.getPosition().x - bleft1h.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1h.getPosition().x + bleft1h.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1h.getPosition().y - bleft1h.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1h.getPosition().y + bleft1h.getSize().y / 2))
                            {
                                hcount = 7;
                                helpc = 1;
                                reck2h.setTexture(&tkeyboard0Space);
                                textm11h.setPosition(375, 632);
                                textm11h.setString("Click the Spacebar to shoot.");
                            }
                        }
                        //Music
                        if (!menu && !settings && !select_player && !instruction && music)
                        {
                            music_01.setVolume(volumeConst);
                            music_02.setVolume(volumeConst);
                            music_03.setVolume(volumeConst);
                            music_04.setVolume(volumeConst);
                            music_05.setVolume(volumeConst);
                            music_06.setVolume(volumeConst);
                            music_07.setVolume(volumeConst);
                            music_08.setVolume(volumeConst);
                            music_09.setVolume(volumeConst);
                            //Back
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                            {
                                music = false;
                                menu = true;
                            }
                            else if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= recdo.getPosition().x - recdo.getSize().x / 2 && p1.getRec().getPosition().x <= recdo.getPosition().x + recdo.getSize().x / 2 && p1.getRec().getPosition().y >= recdo.getPosition().y - recdo.getSize().y / 2 && p1.getRec().getPosition().y <= recdo.getPosition().y + recdo.getSize().y / 2))
                            {
                                hit1_counter = 1;
                                hit2_counter = 2;
                                reload1_counter = 1;
                                reload2_counter = 2;
                                hit1Sound.setBuffer(hit01SoundBuffer);
                                SoundsN1T.setString("1");
                                reload1Sound.setBuffer(reload01SoundBuffer);
                                sMucicNT.setString("1");
                                hit2Sound.setBuffer(hit01SoundBuffer);
                                sSoundsNT.setString("2");
                                reload2Sound.setBuffer(reload01SoundBuffer);
                                sSoundsN1T.setString("2");
                                mOn = true;
                                MusicNT.setString("On");
                                smOn = true;
                                SoundsNT.setString("On");
                                menuSound.play();
                                volumeConst = 25;
                                volumeConst1 = 40;
                                volumeText.setString(std::to_string(volumeConst) + "%");
                                music_01.setVolume(volumeConst);
                                music_02.setVolume(volumeConst);
                                music_03.setVolume(volumeConst);
                                music_04.setVolume(volumeConst);
                                music_05.setVolume(volumeConst);
                                music_06.setVolume(volumeConst);
                                music_07.setVolume(volumeConst);
                                music_08.setVolume(volumeConst);
                                music_09.setVolume(volumeConst);
                                volumeText1.setString(std::to_string(volumeConst1) + "%");
                                hit1Sound.setVolume(volumeConst1);
                                hit2Sound.setVolume(volumeConst1);
                                reload1Sound.setVolume(volumeConst1);
                                reload2Sound.setVolume(volumeConst1);
                                menuSound.setVolume(volumeConst1);
                                music_01.stop();
                                volumeM = true;
                            }
                            else if (!musicOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec0n.getPosition().x && p1.getRec().getPosition().x <= rec0n.getPosition().x + rec0n.getSize().x && p1.getRec().getPosition().y >= rec0n.getPosition().y && p1.getRec().getPosition().y <= rec0n.getPosition().y + rec0n.getSize().y)))
                            {
                                musicOn = true;
                                mOn = true;
                                MusicNT.setString("On");
                                smOn = true;
                                SoundsNT.setString("On");
                            }
                            else if (musicOn && mOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && (p1.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p1.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p1.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p1.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p1.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p1.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p1.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2))))
                            {
                                MusicNT.setString("Off");
                                mOn = false;

                                switch (randMusic)
                                {
                                case 1:
                                    music_01.stop();
                                    break;
                                case 2:
                                    music_02.stop();
                                    break;
                                case 3:
                                    music_03.stop();
                                    break;
                                case 4:
                                    music_04.stop();
                                    break;
                                case 5:
                                    music_05.stop();
                                    break;
                                case 6:
                                    music_06.stop();
                                    break;
                                case 7:
                                    music_07.stop();
                                    break;
                                case 8:
                                    music_08.stop();
                                    break;
                                case 9:
                                    music_09.stop();
                                    break;
                                }
                                music_stop = false;
                            }
                            else if (musicOn && !mOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && (p1.getRec().getPosition().x >= bn1left.getPosition().x - bn1left.getSize().x / 2 && p1.getRec().getPosition().x <= bn1left.getPosition().x + bn1left.getSize().x / 2 && p1.getRec().getPosition().y >= bn1left.getPosition().y - bn1left.getSize().y / 2 && p1.getRec().getPosition().y <= bn1left.getPosition().y + bn1left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn1right.getPosition().x - bn1right.getSize().x / 2 && p1.getRec().getPosition().x <= bn1right.getPosition().x + bn1right.getSize().x / 2 && p1.getRec().getPosition().y >= bn1right.getPosition().y - bn1right.getSize().y / 2 && p1.getRec().getPosition().y <= bn1right.getPosition().y + bn1right.getSize().y / 2))))
                            {
                                MusicNT.setString("On");
                                mOn = true;
                            }
                            else if (musicOn && mOn && volumeM && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec12n.getPosition().x && p1.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p1.getRec().getPosition().y >= rec12n.getPosition().y && p1.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y)))
                            {
                                volumeM = false;
                                music_01.play();
                            }
                            else if (musicOn && mOn && !volumeM && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec12n.getPosition().x && p1.getRec().getPosition().x <= rec12n.getPosition().x + rec12n.getSize().x && p1.getRec().getPosition().y >= rec12n.getPosition().y && p1.getRec().getPosition().y <= rec12n.getPosition().y + rec12n.getSize().y)))
                            {
                                volumeM = true;
                                music_01.stop();
                            }
                            else if (musicOn && mOn && (volumeConst != 1) && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec13n.getPosition().x && p1.getRec().getPosition().x <= rec13n.getPosition().x + rec13n.getSize().x && p1.getRec().getPosition().y >= rec13n.getPosition().y && p1.getRec().getPosition().y <= rec13n.getPosition().y + rec13n.getSize().y)))
                            {
                                music_01.stop();
                                volumeM = true;
                                volumeConst--;
                                volumeText.setString(std::to_string(volumeConst) + "%");
                                music_01.setVolume(volumeConst);
                                music_02.setVolume(volumeConst);
                                music_03.setVolume(volumeConst);
                                music_04.setVolume(volumeConst);
                                music_05.setVolume(volumeConst);
                                music_06.setVolume(volumeConst);
                                music_07.setVolume(volumeConst);
                                music_08.setVolume(volumeConst);
                                music_09.setVolume(volumeConst);

                            }
                            else if (musicOn && mOn && (volumeConst != 100) && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec14n.getPosition().x && p1.getRec().getPosition().x <= rec14n.getPosition().x + rec14n.getSize().x && p1.getRec().getPosition().y >= rec14n.getPosition().y && p1.getRec().getPosition().y <= rec14n.getPosition().y + rec14n.getSize().y)))
                            {
                                music_01.stop();
                                volumeM = true;
                                volumeConst++;
                                volumeText.setString(std::to_string(volumeConst) + "%");
                                music_01.setVolume(volumeConst);
                                music_02.setVolume(volumeConst);
                                music_03.setVolume(volumeConst);
                                music_04.setVolume(volumeConst);
                                music_05.setVolume(volumeConst);
                                music_06.setVolume(volumeConst);
                                music_07.setVolume(volumeConst);
                                music_08.setVolume(volumeConst);
                                music_09.setVolume(volumeConst);
                            }
                            else if (musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && (p1.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p1.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p1.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p1.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p1.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p1.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p1.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2))))
                            {
                                SoundsNT.setString("Off");
                                smOn = false;
                            }
                            else if (musicOn && !smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && (p1.getRec().getPosition().x >= bn2left.getPosition().x - bn2left.getSize().x / 2 && p1.getRec().getPosition().x <= bn2left.getPosition().x + bn2left.getSize().x / 2 && p1.getRec().getPosition().y >= bn2left.getPosition().y - bn2left.getSize().y / 2 && p1.getRec().getPosition().y <= bn2left.getPosition().y + bn2left.getSize().y / 2) || (p1.getRec().getPosition().x >= bn2right.getPosition().x - bn2right.getSize().x / 2 && p1.getRec().getPosition().x <= bn2right.getPosition().x + bn2right.getSize().x / 2 && p1.getRec().getPosition().y >= bn2right.getPosition().y - bn2right.getSize().y / 2 && p1.getRec().getPosition().y <= bn2right.getPosition().y + bn2right.getSize().y / 2))))
                            {
                                SoundsNT.setString("On");
                                smOn = true;
                            }
                            else if (musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec22n.getPosition().x && p1.getRec().getPosition().x <= rec22n.getPosition().x + rec22n.getSize().x && p1.getRec().getPosition().y >= rec22n.getPosition().y && p1.getRec().getPosition().y <= rec22n.getPosition().y + rec22n.getSize().y)))
                            {
                                menuSound.play();
                            }
                            else if (musicOn && smOn && (volumeConst1 != 1) && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec23n.getPosition().x && p1.getRec().getPosition().x <= rec23n.getPosition().x + rec23n.getSize().x && p1.getRec().getPosition().y >= rec23n.getPosition().y && p1.getRec().getPosition().y <= rec23n.getPosition().y + rec23n.getSize().y)))
                            {
                                volumeConst1--;
                                volumeText1.setString(std::to_string(volumeConst1) + "%");
                                hit1Sound.setVolume(volumeConst1);
                                hit2Sound.setVolume(volumeConst1);
                                reload1Sound.setVolume(volumeConst1);
                                reload2Sound.setVolume(volumeConst1);
                                menuSound.setVolume(volumeConst1);
                            }
                            else if (musicOn && smOn && (volumeConst1 != 100) && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec24n.getPosition().x && p1.getRec().getPosition().x <= rec24n.getPosition().x + rec24n.getSize().x && p1.getRec().getPosition().y >= rec24n.getPosition().y && p1.getRec().getPosition().y <= rec24n.getPosition().y + rec24n.getSize().y)))
                            {
                                volumeConst1++;
                                volumeText1.setString(std::to_string(volumeConst1) + "%");
                                hit1Sound.setVolume(volumeConst1);
                                hit2Sound.setVolume(volumeConst1);
                                reload1Sound.setVolume(volumeConst1);
                                reload2Sound.setVolume(volumeConst1);
                                menuSound.setVolume(volumeConst1);
                            }
                            //Hit 1
                            if (hit1_counter != 1 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn21left.getPosition().x - bn21left.getSize().x / 2 && p1.getRec().getPosition().x <= bn21left.getPosition().x + bn21left.getSize().x / 2 && p1.getRec().getPosition().y >= bn21left.getPosition().y - bn21left.getSize().y / 2 && p1.getRec().getPosition().y <= bn21left.getPosition().y + bn21left.getSize().y / 2)))
                            {
                                if (hit1_counter == 6)
                                {
                                    hit1Sound.setBuffer(hit05SoundBuffer);
                                    SoundsN1T.setString("5");
                                }
                                else if (hit1_counter == 5)
                                {
                                    hit1Sound.setBuffer(hit04SoundBuffer);
                                    SoundsN1T.setString("4");
                                }
                                else if (hit1_counter == 4)
                                {
                                    hit1Sound.setBuffer(hit03SoundBuffer);
                                    SoundsN1T.setString("3");
                                }
                                else if (hit1_counter == 3)
                                {
                                    hit1Sound.setBuffer(hit02SoundBuffer);
                                    SoundsN1T.setString("2");
                                }
                                else if (hit1_counter == 2)
                                {
                                    hit1Sound.setBuffer(hit01SoundBuffer);
                                    SoundsN1T.setString("1");
                                }
                                hit1_counter--;
                            }
                            else if (hit1_counter != 6 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn21right.getPosition().x - bn21right.getSize().x / 2 && p1.getRec().getPosition().x <= bn21right.getPosition().x + bn21right.getSize().x / 2 && p1.getRec().getPosition().y >= bn21right.getPosition().y - bn21right.getSize().y / 2 && p1.getRec().getPosition().y <= bn21right.getPosition().y + bn21right.getSize().y / 2)))
                            {
                                if (hit1_counter == 1)
                                {
                                    hit1Sound.setBuffer(hit02SoundBuffer);
                                    SoundsN1T.setString("2");
                                }
                                else if (hit1_counter == 2)
                                {
                                    hit1Sound.setBuffer(hit03SoundBuffer);
                                    SoundsN1T.setString("3");
                                }
                                else if (hit1_counter == 3)
                                {
                                    hit1Sound.setBuffer(hit04SoundBuffer);
                                    SoundsN1T.setString("4");
                                }
                                else if (hit1_counter == 4)
                                {
                                    hit1Sound.setBuffer(hit05SoundBuffer);
                                    SoundsN1T.setString("5");
                                }
                                else if (hit1_counter == 5)
                                {
                                    hit1Sound.setBuffer(hit06SoundBuffer);
                                    SoundsN1T.setString("6");
                                }
                                hit1_counter++;
                            }
                            else if (musicOn && smOn && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rechs1n.getPosition().x && p1.getRec().getPosition().x <= rechs1n.getPosition().x + rechs1n.getSize().x && p1.getRec().getPosition().y >= rechs1n.getPosition().y && p1.getRec().getPosition().y <= rechs1n.getPosition().y + rechs1n.getSize().y))
                            {
                                hit1Sound.play();
                            }
                            //Reload 1
                            else if (reload1_counter != 1 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn3left.getPosition().x - bn3left.getSize().x / 2 && p1.getRec().getPosition().x <= bn3left.getPosition().x + bn3left.getSize().x / 2 && p1.getRec().getPosition().y >= bn3left.getPosition().y - bn3left.getSize().y / 2 && p1.getRec().getPosition().y <= bn3left.getPosition().y + bn3left.getSize().y / 2)))
                            {
                                if (reload1_counter == 6)
                                {
                                    reload1Sound.setBuffer(reload05SoundBuffer);
                                    sMucicNT.setString("5");
                                }
                                else if (reload1_counter == 5)
                                {
                                    reload1Sound.setBuffer(reload04SoundBuffer);
                                    sMucicNT.setString("4");
                                }
                                else if (reload1_counter == 4)
                                {
                                    reload1Sound.setBuffer(reload03SoundBuffer);
                                    sMucicNT.setString("3");
                                }
                                else if (reload1_counter == 3)
                                {
                                    reload1Sound.setBuffer(reload02SoundBuffer);
                                    sMucicNT.setString("2");
                                }
                                else if (reload1_counter == 2)
                                {
                                    reload1Sound.setBuffer(reload01SoundBuffer);
                                    sMucicNT.setString("1");
                                }
                                reload1_counter--;
                            }
                            else if (reload1_counter != 6 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn3right.getPosition().x - bn3right.getSize().x / 2 && p1.getRec().getPosition().x <= bn3right.getPosition().x + bn3right.getSize().x / 2 && p1.getRec().getPosition().y >= bn3right.getPosition().y - bn3right.getSize().y / 2 && p1.getRec().getPosition().y <= bn3right.getPosition().y + bn3right.getSize().y / 2)))
                            {
                                if (reload1_counter == 1)
                                {
                                    reload1Sound.setBuffer(reload02SoundBuffer);
                                    sMucicNT.setString("2");
                                }
                                else if (reload1_counter == 2)
                                {
                                    reload1Sound.setBuffer(reload03SoundBuffer);
                                    sMucicNT.setString("3");
                                }
                                else if (reload1_counter == 3)
                                {
                                    reload1Sound.setBuffer(reload04SoundBuffer);
                                    sMucicNT.setString("4");
                                }
                                else if (reload1_counter == 4)
                                {
                                    reload1Sound.setBuffer(reload05SoundBuffer);
                                    sMucicNT.setString("5");
                                }
                                else if (reload1_counter == 5)
                                {
                                    reload1Sound.setBuffer(reload06SoundBuffer);
                                    sMucicNT.setString("6");
                                }
                                reload1_counter++;
                            }
                            else if (musicOn && smOn && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= recrs1n.getPosition().x && p1.getRec().getPosition().x <= recrs1n.getPosition().x + recrs1n.getSize().x && p1.getRec().getPosition().y >= recrs1n.getPosition().y && p1.getRec().getPosition().y <= recrs1n.getPosition().y + recrs1n.getSize().y))
                            {
                                reload1Sound.play();
                            }
                            //Hit 2
                            else if (hit2_counter != 1 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn4left.getPosition().x - bn4left.getSize().x / 2 && p1.getRec().getPosition().x <= bn4left.getPosition().x + bn4left.getSize().x / 2 && p1.getRec().getPosition().y >= bn4left.getPosition().y - bn4left.getSize().y / 2 && p1.getRec().getPosition().y <= bn4left.getPosition().y + bn4left.getSize().y / 2)))
                            {
                                if (hit2_counter == 6)
                                {
                                    hit2Sound.setBuffer(hit05SoundBuffer);
                                    sSoundsNT.setString("5");
                                }
                                else if (hit2_counter == 5)
                                {
                                    hit2Sound.setBuffer(hit04SoundBuffer);
                                    sSoundsNT.setString("4");
                                }
                                else if (hit2_counter == 4)
                                {
                                    hit2Sound.setBuffer(hit03SoundBuffer);
                                    sSoundsNT.setString("3");
                                }
                                else if (hit2_counter == 3)
                                {
                                    hit2Sound.setBuffer(hit02SoundBuffer);
                                    sSoundsNT.setString("2");
                                }
                                else if (hit2_counter == 2)
                                {
                                    hit2Sound.setBuffer(hit01SoundBuffer);
                                    sSoundsNT.setString("1");
                                }
                                hit2_counter--;
                            }
                            else if (hit2_counter != 6 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn4right.getPosition().x - bn4right.getSize().x / 2 && p1.getRec().getPosition().x <= bn4right.getPosition().x + bn4right.getSize().x / 2 && p1.getRec().getPosition().y >= bn4right.getPosition().y - bn4right.getSize().y / 2 && p1.getRec().getPosition().y <= bn4right.getPosition().y + bn4right.getSize().y / 2)))
                            {
                                if (hit2_counter == 1)
                                {
                                    hit2Sound.setBuffer(hit02SoundBuffer);
                                    sSoundsNT.setString("2");
                                }
                                else if (hit2_counter == 2)
                                {
                                    hit2Sound.setBuffer(hit03SoundBuffer);
                                    sSoundsNT.setString("3");
                                }
                                else if (hit2_counter == 3)
                                {
                                    hit2Sound.setBuffer(hit04SoundBuffer);
                                    sSoundsNT.setString("4");
                                }
                                else if (hit2_counter == 4)
                                {
                                    hit2Sound.setBuffer(hit05SoundBuffer);
                                    sSoundsNT.setString("5");
                                }
                                else if (hit2_counter == 5)
                                {
                                    hit2Sound.setBuffer(hit06SoundBuffer);
                                    sSoundsNT.setString("6");
                                }
                                hit2_counter++;
                            }
                            else if (musicOn && smOn && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rechs2n.getPosition().x && p1.getRec().getPosition().x <= rechs2n.getPosition().x + rechs2n.getSize().x && p1.getRec().getPosition().y >= rechs2n.getPosition().y && p1.getRec().getPosition().y <= rechs2n.getPosition().y + rechs2n.getSize().y))
                            {
                                hit2Sound.play();
                            }
                            //Reload 2
                            else if (reload2_counter != 1 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn41left.getPosition().x - bn41left.getSize().x / 2 && p1.getRec().getPosition().x <= bn41left.getPosition().x + bn41left.getSize().x / 2 && p1.getRec().getPosition().y >= bn41left.getPosition().y - bn41left.getSize().y / 2 && p1.getRec().getPosition().y <= bn41left.getPosition().y + bn41left.getSize().y / 2)))
                            {
                                if (reload2_counter == 6)
                                {
                                    reload2Sound.setBuffer(reload05SoundBuffer);
                                    sSoundsN1T.setString("5");
                                }
                                else if (reload2_counter == 5)
                                {
                                    reload2Sound.setBuffer(reload04SoundBuffer);
                                    sSoundsN1T.setString("4");
                                }
                                else if (reload2_counter == 4)
                                {
                                    reload2Sound.setBuffer(reload03SoundBuffer);
                                    sSoundsN1T.setString("3");
                                }
                                else if (reload2_counter == 3)
                                {
                                    reload2Sound.setBuffer(reload02SoundBuffer);
                                    sSoundsN1T.setString("2");
                                }
                                else if (reload2_counter == 2)
                                {
                                    reload2Sound.setBuffer(reload01SoundBuffer);
                                    sSoundsN1T.setString("1");
                                }
                                reload2_counter--;
                            }
                            else if (reload2_counter != 6 && musicOn && smOn && ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bn41right.getPosition().x - bn41right.getSize().x / 2 && p1.getRec().getPosition().x <= bn41right.getPosition().x + bn41right.getSize().x / 2 && p1.getRec().getPosition().y >= bn41right.getPosition().y - bn41right.getSize().y / 2 && p1.getRec().getPosition().y <= bn41right.getPosition().y + bn41right.getSize().y / 2)))
                            {
                                if (reload2_counter == 1)
                                {
                                    reload2Sound.setBuffer(reload02SoundBuffer);
                                    sSoundsN1T.setString("2");
                                }
                                else if (reload2_counter == 2)
                                {
                                    reload2Sound.setBuffer(reload03SoundBuffer);
                                    sSoundsN1T.setString("3");
                                }
                                else if (reload2_counter == 3)
                                {
                                    reload2Sound.setBuffer(reload04SoundBuffer);
                                    sSoundsN1T.setString("4");
                                }
                                else if (reload2_counter == 4)
                                {
                                    reload2Sound.setBuffer(reload05SoundBuffer);
                                    sSoundsN1T.setString("5");
                                }
                                else if (reload2_counter == 5)
                                {
                                    reload2Sound.setBuffer(reload06SoundBuffer);
                                    sSoundsN1T.setString("6");
                                }
                                reload2_counter++;
                            }
                            else if (musicOn && smOn && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= recrs2n.getPosition().x && p1.getRec().getPosition().x <= recrs2n.getPosition().x + recrs2n.getSize().x && p1.getRec().getPosition().y >= recrs2n.getPosition().y && p1.getRec().getPosition().y <= recrs2n.getPosition().y + recrs2n.getSize().y))
                            {
                                reload2Sound.play();
                            }
                            if (!mOn && !smOn)
                            {
                                musicOn = false;
                            }
                        }
                        //Player
                        else if (!menu && !settings && select_player && !instruction && !music)
                        {
                            //Back
                            if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= rec0o.getPosition().x - rec0o.getSize().x / 2 && p1.getRec().getPosition().x <= rec0o.getPosition().x + rec0o.getSize().x / 2 && p1.getRec().getPosition().y >= rec0o.getPosition().y - rec0o.getSize().y / 2 && p1.getRec().getPosition().y <= rec0o.getPosition().y + rec0o.getSize().y / 2))
                            {
                                select_player = false;
                                menu = true;
                            }
                            //rl1
                            else if (!p2_exists)
                            {
                                if ((selectmjk == 1) && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2))
                                {
                                    selectmjk = 2;
                                }
                                else if ((selectmjk == 2) && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2))
                                {
                                    selectmjk = 1;
                                }
                                else if ((selectmjk == 2) && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bright1p.getPosition().x - bright1p.getSize().x / 2 && p1.getRec().getPosition().x <= bright1p.getPosition().x + bright1p.getSize().x / 2 && p1.getRec().getPosition().y >= bright1p.getPosition().y - bright1p.getSize().y / 2 && p1.getRec().getPosition().y <= bright1p.getPosition().y + bright1p.getSize().y / 2))
                                {
                                    selectmjk = 3;
                                }
                                else if ((selectmjk == 3) && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= bleft1p.getPosition().x - bleft1p.getSize().x / 2 && p1.getRec().getPosition().x <= bleft1p.getPosition().x + bleft1p.getSize().x / 2 && p1.getRec().getPosition().y >= bleft1p.getPosition().y - bleft1p.getSize().y / 2 && p1.getRec().getPosition().y <= bleft1p.getPosition().y + bleft1p.getSize().y / 2))
                                {
                                    selectmjk = 2;
                                }
                            }
                            //Select
                            if ((selectmjk1 != selectmjk) && (sf::Joystick::Axis::Z == event.joystickMove.axis) && (p1.getSelect() == 2 && p1.getRec().getPosition().x >= choosep11.getPosition().x - choosep11.getSize().x / 2 && p1.getRec().getPosition().x <= choosep11.getPosition().x + choosep11.getSize().x / 2 && p1.getRec().getPosition().y >= choosep11.getPosition().y - choosep11.getSize().y / 2 && p1.getRec().getPosition().y <= choosep11.getPosition().y + choosep11.getSize().y / 2))
                            {
                                if (!p2_exists)
                                {
                                    if (stop && (selectmjk == 2))
                                    {
                                        std::cout << "Joystick is Disconnected" << std::endl;
                                    }
                                    else
                                    {
                                        selectmjk1 = selectmjk;
                                        p1.setSelect(selectmjk1);
                                        p1.getRec().setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
                                        switch (selectmjk1)
                                        {
                                        case 1:
                                            selectmjk2 = 3;
                                            choosep11.setFillColor(sf::Color(210, 210, 210));
                                            choosep12.setFillColor(sf::Color::White);
                                            choosep13.setFillColor(sf::Color::White);
                                            choosep21.setFillColor(sf::Color::White);
                                            choosep23.setFillColor(sf::Color(210, 210, 210));
                                            text1.setString("M");
                                            text2.setString("K");
                                            break;
                                        case 2:
                                            choosep11.setFillColor(sf::Color::White);
                                            choosep12.setFillColor(sf::Color(210, 210, 210));
                                            choosep13.setFillColor(sf::Color::White);
                                            text1.setString("C");
                                            break;
                                        case 3:
                                            selectmjk2 = 1;
                                            choosep11.setFillColor(sf::Color::White);
                                            choosep12.setFillColor(sf::Color::White);
                                            choosep13.setFillColor(sf::Color(210, 210, 210));
                                            choosep21.setFillColor(sf::Color(210, 210, 210));
                                            choosep23.setFillColor(sf::Color::White);
                                            text1.setString("K");
                                            text2.setString("M");
                                            break;
                                        }
                                        p2.setSelect(selectmjk2);
                                    }
                                }
                            }
                        }
                        stopClick.restart().asMilliseconds();
                    }
                }
                break;
            }
        }

        dt = dtime.restart().asSeconds();

        if (sf::Joystick::isConnected(0))
        {
            stop = false;
        }

        if (!p2_exists)
        {
            if (p1.getSelect() != 1)
                window.setMouseCursorVisible(false);
            else
                window.setMouseCursorVisible(true);
        }

        if (p1.getRec().getPosition().x < 0 + p1.getRec().getSize().x)
            p1.setRecPos(sf::Vector2f{ 0 + p1.getRec().getSize().x, p1.getRec().getPosition().y });
        else if (p1.getRec().getPosition().x > window.getSize().x - p1.getRec().getSize().x)
            p1.setRecPos(sf::Vector2f{ window.getSize().x - p1.getRec().getSize().x, p1.getRec().getPosition().y });
        if (p1.getRec().getPosition().y < 0 + 1.5 * p1.getRec().getSize().y)
            p1.setRecPos(sf::Vector2f{ p1.getRec().getPosition().x, 0 + float(1.5 * p1.getRec().getSize().y) });
        else if (p1.getRec().getPosition().y > window.getSize().y - p1.getRec().getSize().y)
            p1.setRecPos(sf::Vector2f{ p1.getRec().getPosition().x, window.getSize().y - p1.getRec().getSize().y });
        if (p2_exists)
        {
            if (p2.getRec().getPosition().x < 0 + p2.getRec().getSize().x)
                p2.setRecPos(sf::Vector2f{ 0 + p2.getRec().getSize().x, p2.getRec().getPosition().y });
            else if (p2.getRec().getPosition().x > window.getSize().x - p2.getRec().getSize().x)
                p2.setRecPos(sf::Vector2f{ window.getSize().x - p2.getRec().getSize().x, p2.getRec().getPosition().y });
            if (p2.getRec().getPosition().y < 0 + 1.5 * p2.getRec().getSize().y)
                p2.setRecPos(sf::Vector2f{ p2.getRec().getPosition().x, 0 + float(1.5 * p2.getRec().getSize().y) });
            else if (p2.getRec().getPosition().y > window.getSize().y - p2.getRec().getSize().y)
                p2.setRecPos(sf::Vector2f{ p2.getRec().getPosition().x, window.getSize().y - p2.getRec().getSize().y });
        }



        if (menu)
        {
            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
                }
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 3)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    {
                        p2.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    {
                        p2.getRec().move(100 * 0.01 * dt * multiplier, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                    {
                        p2.getRec().move(0, -100 * 0.01 * dt * multiplier);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    {
                        p2.getRec().move(0, 100 * 0.01 * dt * multiplier);
                    }
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

            window.draw(menu_text);

            window.draw(rec1);
            window.draw(n_game);
            window.draw(rec6);
            window.draw(rec7);

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

            window.draw(textName);


            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }
            if (p2_exists && p2.getSelect() != 1)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else if (settings)
        {
            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
                }
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 3)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    {
                        p2.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    {
                        p2.getRec().move(100 * 0.01 * dt * multiplier, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                    {
                        p2.getRec().move(0, -100 * 0.01 * dt * multiplier);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    {
                        p2.getRec().move(0, 100 * 0.01 * dt * multiplier);
                    }
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

            window.draw(textName);

            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }
            if (p2_exists && p2.getSelect() != 1)
            {
                window.draw(p2.getRec());
            }

            window.display();

        }
        else if (select_player)
        {
            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
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

            if (!p2_exists)
            {
                if (selectmjk1 != 2)
                {
                    switch (selectmjk)
                    {
                    case 1:
                        window.draw(recmp);
                        window.draw(mousep);
                        window.draw(bright1p);
                        window.draw(choosep11);
                        select1_text.setPosition(292, 572);
                        window.draw(select1_text);
                        window.draw(On_text);
                        break;
                    case 2:
                        window.draw(reccp);
                        window.draw(controllerp);
                        window.draw(bleft1p);
                        window.draw(bright1p);
                        window.draw(choosep12);
                        select2_text.setPosition(292, 572);
                        window.draw(select2_text);
                        window.draw(On_text);
                        break;
                    case 3:
                        window.draw(reckp);
                        window.draw(keyboardp);
                        window.draw(bleft1p);
                        window.draw(choosep13);
                        select3_text.setPosition(292, 572);
                        window.draw(select3_text);
                        window.draw(On_text);
                        break;
                    }
                }
                else
                {
                    switch (selectmjk)
                    {
                    case 1:
                        window.draw(recmp);
                        window.draw(mousep);
                        window.draw(bright1p);
                        window.draw(choosep11);
                        select1_text.setPosition(292, 572);
                        window.draw(select1_text);
                        break;
                    case 2:
                        window.draw(reccp);
                        window.draw(controllerp);
                        window.draw(bleft1p);
                        window.draw(bright1p);
                        window.draw(choosep12);
                        select2_text.setPosition(292, 572);
                        window.draw(select2_text);
                        break;
                    case 3:
                        window.draw(reckp);
                        window.draw(keyboardp);
                        window.draw(bleft1p);
                        window.draw(choosep13);
                        select3_text.setPosition(292, 572);
                        window.draw(select3_text);
                        break;
                    }
                }
            }
            else
            {
                switch (selectmjk)
                {
                case 1:
                    window.draw(recmp);
                    window.draw(mousep);
                    window.draw(bright1p);
                    window.draw(choosep11);
                    select1_text.setPosition(292, 572);
                    window.draw(select1_text);

                    window.draw(Offr);
                    window.draw(Off_text);

                    window.draw(reck2p);
                    window.draw(keyboard2p);
                    window.draw(choosep23);
                    break;
                case 3:
                    window.draw(reckp);
                    window.draw(keyboardp);
                    window.draw(bleft1p);
                    window.draw(choosep13);
                    select3_text.setPosition(292, 572);
                    window.draw(select3_text);

                    window.draw(Offr);
                    window.draw(Off_text);

                    window.draw(recm2p);
                    window.draw(mouse2p);
                    window.draw(choosep21);
                    break;
                }
            }

            window.draw(textName);

            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }

            window.display();
        }
        else if (instruction)
        {
            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
                }
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 3)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    {
                        p2.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    {
                        p2.getRec().move(100 * 0.01 * dt * multiplier, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                    {
                        p2.getRec().move(0, -100 * 0.01 * dt * multiplier);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    {
                        p2.getRec().move(0, 100 * 0.01 * dt * multiplier);
                    }
                }
            }

            window.clear(sf::Color::White);

            window.draw(rec0o);
            window.draw(back_text);

            window.draw(help_text);
            window.draw(rec0h);

            sf::Time th = clockHelp.getElapsedTime();
            int thelp = th.asMilliseconds();

            switch (hcount)
            {
            case 1:
                window.draw(textH1);
                if (helpc == 0 && thelp > 2500)
                {
                    recm1h.setPosition(400, 265);
                    recm0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                else if (helpc == 1 && thelp > 450)
                {
                    recm1h.setTexture(&tmouse01h);
                    recm1h.setPosition(425, 265);
                    recm0h.setPosition(675, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 450)
                {
                    recm1h.setPosition(450, 265);
                    recm0h.setPosition(700, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 3;
                }
                else if (helpc == 3 && thelp > 450)
                {
                    recm1h.setPosition(475, 265);
                    recm0h.setPosition(725, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 4;
                }
                else if (helpc == 4 && thelp > 450)
                {
                    recm1h.setPosition(500, 265);
                    recm0h.setPosition(750, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 5;
                }
                else if (helpc == 5 && thelp > 450)
                {
                    recm1h.setPosition(500, 290);
                    recm0h.setPosition(750, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 6;
                }
                else if (helpc == 6 && thelp > 450)
                {
                    recm1h.setPosition(500, 315);
                    recm0h.setPosition(750, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 7;
                }
                else if (helpc == 7 && thelp > 450)
                {
                    recm1h.setPosition(500, 340);
                    recm0h.setPosition(750, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 8;
                }
                else if (helpc == 8 && thelp > 450)
                {
                    recm1h.setPosition(500, 365);
                    recm0h.setPosition(750, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 9;
                }
                else if (helpc == 9 && thelp > 450)
                {
                    recm1h.setPosition(475, 365);
                    recm0h.setPosition(725, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 10;
                }
                else if (helpc == 10 && thelp > 450)
                {
                    recm1h.setPosition(450, 365);
                    recm0h.setPosition(700, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 11;
                }
                else if (helpc == 11 && thelp > 450)
                {
                    recm1h.setPosition(425, 365);
                    recm0h.setPosition(675, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 12;
                }
                else if (helpc == 12 && thelp > 450)
                {
                    recm1h.setPosition(400, 365);
                    recm0h.setPosition(650, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 13;
                }
                else if (helpc == 13 && thelp > 450)
                {
                    recm1h.setPosition(400, 340);
                    recm0h.setPosition(650, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 14;
                }
                else if (helpc == 14 && thelp > 450)
                {
                    recm1h.setPosition(400, 315);
                    recm0h.setPosition(650, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 15;
                }
                else if (helpc == 15 && thelp > 450)
                {
                    recm1h.setPosition(400, 290);
                    recm0h.setPosition(650, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 16;
                }
                else if (helpc == 16 && thelp > 450)
                {
                    recm1h.setPosition(400, 265);
                    recm0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 0;
                    recm1h.setTexture(&tmouse0h);
                }
                window.draw(recm1h);
                window.draw(recm0h);
                window.draw(bright1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            case 2:
                window.draw(textH1);
                if (helpc == 1 && thelp > 1500)
                {
                    recm1h.setTexture(&tmouse0h);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 1500)
                {
                    recm1h.setTexture(&tmouse1lh);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                window.draw(recm1h);
                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                break;
            case 3:
                window.draw(textH2);
                if (helpc == 0 && thelp > 2500)
                {
                    recc0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                if (helpc == 1 && thelp > 450)
                {
                    recc1h.setTexture(&tcontroller1lj);
                    recc0h.setPosition(675, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 450)
                {
                    recc0h.setPosition(700, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 3;
                }
                else if (helpc == 3 && thelp > 450)
                {
                    recc0h.setPosition(725, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 4;
                }
                else if (helpc == 4 && thelp > 450)
                {
                    recc0h.setPosition(750, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 5;
                }
                else if (helpc == 5 && thelp > 450)
                {
                    recc0h.setPosition(750, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 6;
                }
                else if (helpc == 6 && thelp > 450)
                {
                    recc0h.setPosition(750, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 7;
                }
                else if (helpc == 7 && thelp > 450)
                {
                    recc0h.setPosition(750, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 8;
                }
                else if (helpc == 8 && thelp > 450)
                {
                    recc0h.setPosition(750, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 9;
                }
                else if (helpc == 9 && thelp > 450)
                {
                    recc0h.setPosition(725, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 10;
                }
                else if (helpc == 10 && thelp > 450)
                {
                    recc0h.setPosition(700, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 11;
                }
                else if (helpc == 11 && thelp > 450)
                {
                    recc0h.setPosition(675, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 12;
                }
                else if (helpc == 12 && thelp > 450)
                {
                    recc0h.setPosition(650, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 13;
                }
                else if (helpc == 13 && thelp > 450)
                {
                    recc0h.setPosition(650, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 14;
                }
                else if (helpc == 14 && thelp > 450)
                {
                    recc0h.setPosition(650, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 15;
                }
                else if (helpc == 15 && thelp > 450)
                {
                    recc0h.setPosition(650, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 16;
                }
                else if (helpc == 16 && thelp > 450)
                {
                    recc0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 0;
                    recc1h.setTexture(&tcontroller0);
                }
                window.draw(recc1h);
                window.draw(recc0h);
                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            case 4:
                window.draw(textH2);
                if (helpc == 1 && thelp > 1500)
                {
                    recc1h.setTexture(&tcontroller00);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 1500)
                {
                    recc1h.setTexture(&tcontroller1rt);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                window.draw(recc1h);
                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            case 5:
                window.draw(textH2);
                if (helpc == 1 && thelp > 1500)
                {
                    recc1h.setTexture(&tcontroller0);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 1500)
                {
                    recc1h.setTexture(&tcontroller1s);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                window.draw(recc1h);
                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            case 6:
                window.draw(textH3);

                if (helpc == 0 && thelp > 2500)
                {
                    reck0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                if (helpc == 1 && thelp > 450)
                {
                    reck1h.setTexture(&tkeyboard1d);
                    reck0h.setPosition(675, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 450)
                {
                    reck0h.setPosition(700, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 3;
                }
                else if (helpc == 3 && thelp > 450)
                {
                    reck0h.setPosition(725, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 4;
                }
                else if (helpc == 4 && thelp > 450)
                {
                    reck0h.setPosition(750, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 5;
                }
                else if (helpc == 5 && thelp > 450)
                {
                    reck1h.setTexture(&tkeyboard1s);
                    reck0h.setPosition(750, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 6;
                }
                else if (helpc == 6 && thelp > 450)
                {
                    reck0h.setPosition(750, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 7;
                }
                else if (helpc == 7 && thelp > 450)
                {
                    reck0h.setPosition(750, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 8;
                }
                else if (helpc == 8 && thelp > 450)
                {
                    reck0h.setPosition(750, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 9;
                }
                else if (helpc == 9 && thelp > 450)
                {
                    reck1h.setTexture(&tkeyboard1a);
                    reck0h.setPosition(725, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 10;
                }
                else if (helpc == 10 && thelp > 450)
                {
                    reck0h.setPosition(700, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 11;
                }
                else if (helpc == 11 && thelp > 450)
                {
                    reck0h.setPosition(675, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 12;
                }
                else if (helpc == 12 && thelp > 450)
                {
                    reck0h.setPosition(650, 400);
                    clockHelp.restart().asMilliseconds();
                    helpc = 13;
                }
                else if (helpc == 13 && thelp > 450)
                {
                    reck1h.setTexture(&tkeyboard1w);
                    reck0h.setPosition(650, 375);
                    clockHelp.restart().asMilliseconds();
                    helpc = 14;
                }
                else if (helpc == 14 && thelp > 450)
                {
                    reck0h.setPosition(650, 350);
                    clockHelp.restart().asMilliseconds();
                    helpc = 15;
                }
                else if (helpc == 15 && thelp > 450)
                {
                    reck0h.setPosition(650, 325);
                    clockHelp.restart().asMilliseconds();
                    helpc = 16;
                }
                else if (helpc == 16 && thelp > 450)
                {
                    reck0h.setPosition(650, 300);
                    clockHelp.restart().asMilliseconds();
                    helpc = 0;
                    reck1h.setTexture(&tkeyboard0);
                }

                window.draw(reck0h);
                window.draw(reck1h);

                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            case 7:
                window.draw(textH3);
                if (helpc == 1 && thelp > 1500)
                {
                    reck2h.setTexture(&tkeyboard0Space);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 1500)
                {
                    reck2h.setTexture(&tkeyboard1Space);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                window.draw(reck2h);
                window.draw(bright1h);
                window.draw(bleft1h);

                window.draw(recht);
                break;
            case 8:
                window.draw(textH3);
                if (helpc == 1 && thelp > 1500)
                {
                    reck3h.setTexture(&tkeyboard0Esc);
                    clockHelp.restart().asMilliseconds();
                    helpc = 2;
                }
                else if (helpc == 2 && thelp > 1500)
                {
                    reck3h.setTexture(&tkeyboard1Esc);
                    clockHelp.restart().asMilliseconds();
                    helpc = 1;
                }
                window.draw(reck3h);
                window.draw(bleft1h);

                window.draw(recht);
                window.draw(textm12h);
                break;
            }
            window.draw(textm11h);

            window.draw(textName);

            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }
            if (p2_exists && p2.getSelect() != 1)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else if (music)
        {
            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
                }
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 3)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    {
                        p2.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    {
                        p2.getRec().move(100 * 0.01 * dt * multiplier, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                    {
                        p2.getRec().move(0, -100 * 0.01 * dt * multiplier);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    {
                        p2.getRec().move(0, 100 * 0.01 * dt * multiplier);
                    }
                }
            }

            window.clear(sf::Color::White);

            window.draw(music_text);

            window.draw(rec0o);
            window.draw(back_text);

            if (musicOn)
            {
                window.draw(recdo);
                window.draw(default_text);

                window.draw(rec1n);
                window.draw(MusicN);
                window.draw(musicDash);
                window.draw(bn1left);
                window.draw(bn1right);
                window.draw(MusicNT);
                if (mOn)
                {
                    window.draw(volumeText);
                    window.draw(rec12n);
                    window.draw(rec13n);
                    window.draw(rec131n);
                    window.draw(rec14n);
                    window.draw(rec141n);

                    if (volumeM)
                    {
                        window.draw(rec121n);
                    }
                    else
                    {
                        window.draw(rec122n);
                    }
                }


                window.draw(rec2n);
                window.draw(SoundsN);
                window.draw(soundsDash);
                window.draw(bn2left);
                window.draw(bn2right);
                window.draw(SoundsNT);
                if (smOn)
                {
                    window.draw(volumeText1);
                    window.draw(rec22n);
                    window.draw(rec221n);
                    window.draw(rec23n);
                    window.draw(rec231n);
                    window.draw(rec24n);
                    window.draw(rec241n);


                    window.draw(rec21n);
                    window.draw(SoundsN1);
                    window.draw(soundsDash1);
                    window.draw(bn21left);
                    window.draw(bn21right);
                    window.draw(SoundsN1T);
                    window.draw(rechs1n);
                    window.draw(rechs11n);

                    window.draw(rec3n);
                    window.draw(sMucicN);
                    window.draw(smndash);
                    window.draw(bn3left);
                    window.draw(bn3right);
                    window.draw(sMucicNT);
                    window.draw(recrs1n);
                    window.draw(recrs11n);

                    if (p2_exists)
                    {
                        window.draw(rec4n);
                        window.draw(sSoundsN);
                        window.draw(ssndash);
                        window.draw(bn4left);
                        window.draw(bn4right);
                        window.draw(sSoundsNT);
                        window.draw(rechs2n);
                        window.draw(rechs21n);

                        window.draw(rec41n);
                        window.draw(sSoundsN1);
                        window.draw(ssndash1);
                        window.draw(bn41left);
                        window.draw(bn41right);
                        window.draw(sSoundsN1T);
                        window.draw(recrs2n);
                        window.draw(recrs21n);
                    }
                }
            }
            else
            {
                window.draw(rec0n);
                window.draw(NoteOn);
            }



            window.draw(textName);

            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }
            if (p2_exists && p2.getSelect() != 1)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else if (end_of_time || endg)
        {
            if (cursorEndGame)
            {
                window.setMouseCursor(c);
                p1.setImage(igun02, window);
                p1.getRec().setTexture(&tgun02);
                p2.setImage(igun02, window);
                p2.getRec().setTexture(&tgun02);
                end_of_time1 = false;
                game = false;
                cursorEndGame = false;
                if (mOn)
                    musicClock.restart();
            }

            if (mOn)
            {
                sf::Time mClockT = musicClock.getElapsedTime();
                int mClock = mClockT.asSeconds();
                if (music_stop && (mClock >= mClockS))
                {
                    switch (randMusic)
                    {
                    case 1:
                        if (volume <= 0)
                        {
                            music_01.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_01.setVolume(volume);
                        }
                        break;
                    case 2:
                        if (volume <= 0)
                        {
                            music_02.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_02.setVolume(volume);
                        }
                        break;
                    case 3:
                        if (volume <= 0)
                        {
                            music_03.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_03.setVolume(volume);
                        }
                        break;
                    case 4:
                        if (volume <= 0)
                        {
                            music_04.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_04.setVolume(volume);
                        }
                        break;
                    case 5:
                        if (volume <= 0)
                        {
                            music_05.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_05.setVolume(volume);
                        }
                        break;
                    case 6:
                        if (volume <= 0)
                        {
                            music_06.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_06.setVolume(volume);
                        }
                        break;
                    case 7:
                        if (volume <= 0)
                        {
                            music_07.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_07.setVolume(volume);
                        }
                        break;
                    case 8:
                        if (volume <= 0)
                        {
                            music_08.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_08.setVolume(volume);
                        }
                        break;
                    case 9:
                        if (volume <= 0)
                        {
                            music_09.stop();
                            music_stop = false;
                        }
                        else
                        {
                            volume--;
                            music_09.setVolume(volume);
                        }
                        break;
                    }
                    musicClock.restart();
                }
            }

            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.01 * dt * multiplier, m.y * 0.01 * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                {
                    p1.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                {
                    p1.getRec().move(100 * 0.01 * dt * multiplier, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                {
                    p1.getRec().move(0, -100 * 0.01 * dt * multiplier);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                {
                    p1.getRec().move(0, 100 * 0.01 * dt * multiplier);
                }
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 3)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
                    {
                        p2.getRec().move(-100 * 0.01 * dt * multiplier, 0);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
                    {
                        p2.getRec().move(100 * 0.01 * dt * multiplier, 0);
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
                    {
                        p2.getRec().move(0, -100 * 0.01 * dt * multiplier);
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
                    {
                        p2.getRec().move(0, 100 * 0.01 * dt * multiplier);
                    }
                }
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

            window.draw(textScore);
            window.draw(textAmmunition);
            window.draw(textEndOfTime);

            window.draw(textName);

            if (p1.getSelect() != 1)
            {
                window.draw(p1.getRec());
            }
            if (p2_exists && p2.getSelect() != 1)
            {
                window.draw(p2.getRec());
            }

            window.display();
        }
        else
        {
            if (sf::Mouse::getPosition(window).x < 0 + 0.5 * igun00.getSize().x)
                sf::Mouse::setPosition(sf::Vector2i((0 + 0.5 * igun00.getSize().x), (sf::Mouse::getPosition(window).y)), window);
            else if (sf::Mouse::getPosition(window).x > window.getSize().x - 1.5 * igun00.getSize().x)
                sf::Mouse::setPosition(sf::Vector2i((window.getSize().x - 1.5 * igun00.getSize().x), (sf::Mouse::getPosition(window).y)), window);
            if (sf::Mouse::getPosition(window).y < 0 + igun00.getSize().y)
                sf::Mouse::setPosition(sf::Vector2i((sf::Mouse::getPosition(window).x), (0 + igun00.getSize().y)), window);
            else if (sf::Mouse::getPosition(window).y > window.getSize().y - 1.5 * igun00.getSize().y)
                sf::Mouse::setPosition(sf::Vector2i((sf::Mouse::getPosition(window).x), (window.getSize().y - 1.5 * igun00.getSize().y)), window);

            if (p1.getSelect() == 3 || (p2_exists && p2.getSelect() == 3))
            {
                direction = sf::Vector2f(0.f, 0.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    direction.x = -1.f;

                    if (currentVelocity.x > -maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    direction.x = 1.f;

                    if (currentVelocity.x < maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    direction.y = -1.f;

                    if (currentVelocity.y > -maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    direction.y = 1.f;

                    if (currentVelocity.y < maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
            }

            if (currentVelocity.x > 0.f)
            {
                currentVelocity.x -= drag * dt * multiplier;

                if (currentVelocity.x < 0.f)
                    currentVelocity.x = 0.f;
            }
            else if (currentVelocity.x < 0.f)
            {
                currentVelocity.x += drag * dt * multiplier;

                if (currentVelocity.x > 0.f)
                    currentVelocity.x = 0.f;
            }
            if (currentVelocity.y > 0.f)
            {
                currentVelocity.y -= drag * dt * multiplier;

                if (currentVelocity.y < 0.f)
                    currentVelocity.y = 0.f;
            }
            else if (currentVelocity.y < 0.f)
            {
                currentVelocity.y += drag * dt * multiplier;

                if (currentVelocity.y > 0.f)
                    currentVelocity.y = 0.f;
            }

            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                p1.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 2)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p2.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                    }
                }
                else if (p2.getSelect() == 3)
                {
                    p2.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
                }
            }

            if (!cursorMenu)
            {
                p1.setImage(igun00, window);
                if (p1.getSelect() == 2)
                    p1.getRec().setTexture(&tgun01);
                else if (p1.getSelect() == 3)
                    p1.getRec().setTexture(&tgun03);
                cursorMenu = true;
                p2.setImage(igun00, window);
                if (p2.getSelect() == 2)
                    p2.getRec().setTexture(&tgun01);
                else if (p2.getSelect() == 3)
                    p2.getRec().setTexture(&tgun03);
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

            if (p1.getSelect() == 3 || (p2_exists && p2.getSelect() == 3))
            {
                direction = sf::Vector2f(0.f, 0.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    direction.x = -1.f;

                    if (currentVelocity.x > -maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    direction.x = 1.f;

                    if (currentVelocity.x < maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    direction.y = -1.f;

                    if (currentVelocity.y > -maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    direction.y = 1.f;

                    if (currentVelocity.y < maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
            }

            if (currentVelocity.x > 0.f)
            {
                currentVelocity.x -= drag * dt * multiplier;

                if (currentVelocity.x < 0.f)
                    currentVelocity.x = 0.f;
            }
            else if (currentVelocity.x < 0.f)
            {
                currentVelocity.x += drag * dt * multiplier;

                if (currentVelocity.x > 0.f)
                    currentVelocity.x = 0.f;
            }
            if (currentVelocity.y > 0.f)
            {
                currentVelocity.y -= drag * dt * multiplier;

                if (currentVelocity.y < 0.f)
                    currentVelocity.y = 0.f;
            }
            else if (currentVelocity.y < 0.f)
            {
                currentVelocity.y += drag * dt * multiplier;

                if (currentVelocity.y > 0.f)
                    currentVelocity.y = 0.f;
            }

            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                p1.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 2)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p2.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                    }
                }
                else if (p2.getSelect() == 3)
                {
                    p2.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
                }
            }

            if (test || test2)
            {
                if (p2_exists && p2.getSelect() == 1 && test2)
                {
                    p2.bullet(window, sf::Mouse::getPosition(window));
                    pla2 = true;
                }
                else if (p2_exists && p2.getSelect() != 1 && test2)
                {
                    p2.bullet(window, sf::Vector2i(p2.getRec().getPosition().x - p2.getRec().getSize().x / 2, p2.getRec().getPosition().y - p2.getRec().getSize().y / 2));
                    pla2 = true;
                }
                else if (p1.getSelect() == 1)
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

            if (p1.getSelect() == 3 || (p2_exists && p2.getSelect() == 3))
            {
                direction = sf::Vector2f(0.f, 0.f);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    direction.x = -1.f;

                    if (currentVelocity.x > -maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    direction.x = 1.f;

                    if (currentVelocity.x < maxVelocity)
                        currentVelocity.x += acceleration * direction.x * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    direction.y = -1.f;

                    if (currentVelocity.y > -maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    direction.y = 1.f;

                    if (currentVelocity.y < maxVelocity)
                        currentVelocity.y += acceleration * direction.y * dt * multiplier;
                }
            }

            if (currentVelocity.x > 0.f)
            {
                currentVelocity.x -= drag * dt * multiplier;

                if (currentVelocity.x < 0.f)
                    currentVelocity.x = 0.f;
            }
            else if (currentVelocity.x < 0.f)
            {
                currentVelocity.x += drag * dt * multiplier;

                if (currentVelocity.x > 0.f)
                    currentVelocity.x = 0.f;
            }
            if (currentVelocity.y > 0.f)
            {
                currentVelocity.y -= drag * dt * multiplier;

                if (currentVelocity.y < 0.f)
                    currentVelocity.y = 0.f;
            }
            else if (currentVelocity.y < 0.f)
            {
                currentVelocity.y += drag * dt * multiplier;

                if (currentVelocity.y > 0.f)
                    currentVelocity.y = 0.f;
            }

            if (p1.getSelect() == 2)
            {
                if (event.type == sf::Event::JoystickMoved)
                {
                    sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                    p1.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                }
            }
            else if (p1.getSelect() == 3)
            {
                p1.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
            }
            if (p2_exists)
            {
                if (p2.getSelect() == 2)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p2.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                    }
                }
                else if (p2.getSelect() == 3)
                {
                    p2.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
                }
            }

            if ((p2.getAmmunition() >= 0 || p1.getAmmunition() >= 0) && !end_of_time && !endg)
            {
                if (!p2_exists && p1.getAmmunition() == 0)
                {
                    endg = true;
                }
                else if (p2_exists && p1.getAmmunition() == 0 && p2.getAmmunition() == 0)
                {
                    endg = true;
                }
                if (tv == 0 && ((p1.getSelect() == 1 && focus) || (p1.getSelect() == 2 || p1.getSelect() == 3)))
                {
                    int p1_v = p1.getVibrations();
                    int yes_or_no = rand() % 2;
                    if (yes_or_no == 0)
                    {
                        int rmx = (rand() % p1_v);
                        int rmy = (rand() % p1_v);
                        if (p1.getSelect() == 1)
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p1.getRec().move(rmx, rmy);
                    }
                    else
                    {
                        int rmx = (rand() % p1_v) * -1;
                        int rmy = (rand() % p1_v) * -1;
                        if (p1.getSelect() == 1)
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p1.getRec().move(rmx, rmy);
                    }

                    tv = p1.getTimeV();
                }
                else if (tv != 0 && ((p1.getSelect() == 1 && focus) || (p1.getSelect() == 2 || p1.getSelect() == 3)))
                {
                    tv -= tv * 1 * dt;
                }

                if (tv2 == 0 && ((p2_exists && p2.getSelect() == 1 && focus) || (p2_exists && p2.getSelect() == 3)))
                {
                    int p2_v = p2.getVibrations();
                    int yes_or_no = rand() % 2;
                    if (yes_or_no == 0)
                    {
                        int rmx = (rand() % p2_v);
                        int rmy = (rand() % p2_v);
                        if (p2.getSelect() == 1)
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p2.getRec().move(rmx, rmy);
                    }
                    else
                    {
                        int rmx = (rand() % p2_v) * -1;
                        int rmy = (rand() % p2_v) * -1;
                        if (p2.getSelect() == 1)
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            p2.getRec().move(rmx, rmy);
                    }

                    tv2 = p2.getTimeV();
                }
                else if (tv2 != 0 && ((p2_exists && p2.getSelect() == 1 && focus) || (p2_exists && p2.getSelect() == 3)))
                {
                    tv2 -= tv2 * 1 * dt;
                }

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
                    clock0.restart().asMilliseconds();
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

                if (p1.getSelect() == 3 || (p2_exists && p2.getSelect() == 3))
                {
                    direction = sf::Vector2f(0.f, 0.f);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        direction.x = -1.f;

                        if (currentVelocity.x > -maxVelocity)
                            currentVelocity.x += acceleration * direction.x * dt * multiplier;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        direction.x = 1.f;

                        if (currentVelocity.x < maxVelocity)
                            currentVelocity.x += acceleration * direction.x * dt * multiplier;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        direction.y = -1.f;

                        if (currentVelocity.y > -maxVelocity)
                            currentVelocity.y += acceleration * direction.y * dt * multiplier;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        direction.y = 1.f;

                        if (currentVelocity.y < maxVelocity)
                            currentVelocity.y += acceleration * direction.y * dt * multiplier;
                    }
                }

                if (currentVelocity.x > 0.f)
                {
                    currentVelocity.x -= drag * dt * multiplier;

                    if (currentVelocity.x < 0.f)
                        currentVelocity.x = 0.f;
                }
                else if (currentVelocity.x < 0.f)
                {
                    currentVelocity.x += drag * dt * multiplier;

                    if (currentVelocity.x > 0.f)
                        currentVelocity.x = 0.f;
                }
                if (currentVelocity.y > 0.f)
                {
                    currentVelocity.y -= drag * dt * multiplier;

                    if (currentVelocity.y < 0.f)
                        currentVelocity.y = 0.f;
                }
                else if (currentVelocity.y < 0.f)
                {
                    currentVelocity.y += drag * dt * multiplier;

                    if (currentVelocity.y > 0.f)
                        currentVelocity.y = 0.f;
                }

                if (p1.getSelect() == 2)
                {
                    if (event.type == sf::Event::JoystickMoved)
                    {
                        sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                        p1.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                    }
                }
                else if (p1.getSelect() == 3)
                {
                    p1.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
                }
                if (p2_exists)
                {
                    if (p2.getSelect() == 2)
                    {
                        if (event.type == sf::Event::JoystickMoved)
                        {
                            sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                            p2.getRec().move(m.x * 0.0001 * sensitivity * dt * multiplier, m.y * 0.0001 * sensitivity * dt * multiplier);
                        }
                    }
                    else if (p2.getSelect() == 3)
                    {
                        p2.getRec().move(0.0015 * sensitivity * currentVelocity.x * dt * multiplier, 0.0015 * sensitivity * currentVelocity.y * dt * multiplier);
                    }
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
                float tym0 = 0;
                if (resetrof)
                {
                    speedbar = false;
                    speedbar2 = false;
                    if (!p2_exists)
                    {
                        p1.getSB().setSize({ 10.0f, 600.0f });
                        p1.getSB().setPosition(20, 100);
                    }
                    else
                    {
                        p1.getSB().setSize({ 10.0f, 600.0f });
                        p2.getSB().setSize({ 10.0f, 600.0f });
                        p1.getSB().setPosition(20, 100);
                        p2.getSB().setPosition(1170, 100);
                    }
                    resetrof = false;

                }
                if (speedbar && clock3.getElapsedTime() < speedb)
                {
                    if (reloadSoundCounter)
                    {
                        if (smOn)
                            reload1Sound.play();
                        reloadSoundCounter = false;
                    }
                    tym = clock3.getElapsedTime().asMilliseconds() - tym;
                    int change = tym / rate_of_fire * COUNT;
                    p1.getSB().setSize({ 10.0f, 600.0f - change });
                    p1.getSB().setPosition(20, 100 + change);
                    window.draw(p1.getSB());
                }
                else if (speedbar && clock3.getElapsedTime() >= speedb)
                {
                    speedbar = false;
                    reloadSoundCounter = true;
                    p1.getSB().setSize({ 10.0f, 600.0f });
                    p1.getSB().setPosition(20, 100);
                }
                if (speedbar2 && clock32.getElapsedTime() < speedb2)
                {
                    if (reloadSoundCounter2)
                    {
                        if (smOn)
                            reload2Sound.play();
                        reloadSoundCounter2 = false;
                    }
                    tym0 = clock32.getElapsedTime().asMilliseconds() - tym0;
                    int change = tym0 / rate_of_fire * COUNT;
                    p2.getSB().setSize({ 10.0f, 600.0f - change });
                    p2.getSB().setPosition(1170, 100 + change);
                    window.draw(p2.getSB());
                }
                else if (speedbar2 && clock32.getElapsedTime() >= speedb2)
                {
                    speedbar2 = false;
                    reloadSoundCounter2 = true;
                    p2.getSB().setSize({ 10.0f, 600.0f });
                    p2.getSB().setPosition(1170, 100);
                }

                window.draw(textScore);
                window.draw(textAmmunition);
                window.draw(textEndOfTime);
                if (!p2_exists)
                    window.draw(text1);
                else
                {
                    window.draw(text1);
                    window.draw(text2);
                }

                window.draw(textName);


                if (p1.getSelect() != 1)
                {
                    window.draw(p1.getRec());
                }
                if (p2_exists && p2.getSelect() != 1)
                {
                    window.draw(p2.getRec());
                }

                window.display();
            }
        }
    }

    system("PAUSE");
    return 0;
}