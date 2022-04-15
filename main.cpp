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

const int SPEED = 200;
const int RATE_OF_FIRE = 1200;
int tv;
int count = 600;
int seconds1;
int seconds2;
bool menu = true;
bool test = false;
bool b1 = false;
bool hit = false;
bool end = true;
bool focus = true;
bool end_of_time = false;
bool end_of_time1 = true;
bool cursorEndGame = true;
bool cursorMenu = true;
bool speedbar = false;
bool game = false;
bool pause = false;
bool pause1 = true;
bool settings = false;
bool instruction = false;
sf::Time ts = sf::seconds(60.0f);
sf::Time tspeed = sf::milliseconds(50);
sf::Time speedb = sf::milliseconds(RATE_OF_FIRE);
sf::Cursor c;
sf::RectangleShape joystick;
sf::CircleShape cursor_mouse(2);

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

    sf::RectangleShape rec3;
    rec3.setSize({ 400, 100 });
    rec3.setPosition(400, 280);   //410
    rec3.setOutlineThickness(3);
    rec3.setOutlineColor(sf::Color::Black);
    sf::Text options;
    options.setFont(font);
    options.setString("Options");
    options.setCharacterSize(60);
    options.setFillColor(sf::Color::Black);
    options.setPosition(480, 290);   //420

    sf::RectangleShape rec4;
    rec4.setSize({ 400, 100 });
    rec4.setPosition(400, 410);   //540
    rec4.setOutlineThickness(3);
    rec4.setOutlineColor(sf::Color::Black);
    sf::Text manual;
    manual.setFont(font);
    manual.setString("Manual");
    manual.setCharacterSize(60);
    manual.setFillColor(sf::Color::Black);
    manual.setPosition(492, 420);   //550

    sf::RectangleShape rec5;
    rec5.setSize({ 400, 100 });
    rec5.setPosition(400, 540);   //670
    rec5.setOutlineThickness(3);
    rec5.setOutlineColor(sf::Color::Black);
    sf::Text quit;
    quit.setFont(font);
    quit.setString("Quit");
    quit.setCharacterSize(60);
    quit.setFillColor(sf::Color::Black);
    quit.setPosition(533, 550);   //680


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

    sf::Texture tplat123;
    if (!tplat123.loadFromFile("Resources/black.png"))
    {
        std::cout << "Errorp123" << std::endl;
        system("PAUSE");
    }
    sf::Texture tplat456;
    if (!tplat456.loadFromFile("Resources/white.png"))
    {
        std::cout << "Errorp456" << std::endl;
        system("PAUSE");
    }

    sf::Texture tplat78910;
    if (!tplat78910.loadFromFile("Resources/black.png"))
    {
        std::cout << "Errorp78910" << std::endl;
        system("PAUSE");
    }

    //Platforms
    std::vector<Platform> platformObject;

    Platform plat0(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 744.0f));
    Platform plat1(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 494.0f));
    Platform plat2(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 246.0f));
    platformObject.push_back(plat0);
    platformObject.push_back(plat1);
    platformObject.push_back(plat2);

    Platform plat3(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 500.0f));
    Platform plat4(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 250.0f));
    Platform plat5(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 0.0f));
    platformObject.push_back(plat3);
    platformObject.push_back(plat4);
    platformObject.push_back(plat5);

    Platform plat6(&tplat78910, sf::Vector2f(1200.0f, 80.0f), sf::Vector2f(0.0f, 0.0f));
    Platform plat7(&tplat78910, sf::Vector2f(1200.0f, 50.0f), sf::Vector2f(0.0f, 750.0f));
    Platform plat8(&tplat78910, sf::Vector2f(50.0f, 1200.0f), sf::Vector2f(0.0f, 0.0f));
    Platform plat9(&tplat78910, sf::Vector2f(50.0f, 1200.0f), sf::Vector2f(1150.0f, 0.0f));
    platformObject.push_back(plat6);
    platformObject.push_back(plat7);
    platformObject.push_back(plat8);
    platformObject.push_back(plat9);

    Platform plat10(&tplat456, sf::Vector2f(1100.0f, 670.0f), sf::Vector2f(50.0f, 80.0f));
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

    sf::Image igun00;
    if (!igun00.loadFromFile("Resources/Gun/gun00.png"))
    {
        std::cout << "Errorig00" << std::endl;
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

    c.loadFromPixels(igun02.getPixelsPtr(), igun02.getSize(), {});
    Player p1(&igun00, &tgun01, 6, 20, window, SPEED * 2, true);
    if (p1.getMouse())
    {
        sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
    }
    else
    {
        window.setMouseCursorVisible(false);
        sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
        joystick = p1.getRec();
    }
    tv = p1.getTimeV();
    std::string p1samu = std::to_string(p1.getAmmunition());
    textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);

    sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::Time time;
    sf::Clock clock1;
    clock1.restart().asMilliseconds();
    sf::Clock clock2;
    clock2.restart().asMilliseconds();
    sf::Clock clock3;
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
                if (!menu)
                {
                    if (sf::Keyboard::Escape == event.key.code)
                    {
                        menu = true;
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
            case sf::Event::MouseButtonPressed:
                if (!menu)
                {
                    time = clock.getElapsedTime();
                    if ((sf::Mouse::Button::Left == event.mouseButton.button) && (time.asMilliseconds() >= RATE_OF_FIRE) && (p1.getAmmunition() > 0))
                    {
                        if (!end_of_time)
                        {
                            test = true;
                            p1.getAmmunition()--;
                            textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                            speedbar = true;
                            clock3.restart().asMilliseconds();
                        }
                    }
                }
                else
                {
                    cursor_mouse.setOrigin(cursor_mouse.getRadius() / 2, cursor_mouse.getRadius() / 2);
                    cursor_mouse.setPosition(sf::Mouse::getPosition(window).x + (igun02.getSize().x / 2), sf::Mouse::getPosition(window).y + (igun02.getSize().y / 2));
                    if (cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 150 && cursor_mouse.getPosition().y < 250)
                    {
                        menu = false;
                        p1.reset();
                        clock1.restart().asSeconds();
                        textScore.setString("Score: 0");
                        std::string p1samu = std::to_string(p1.getAmmunition());
                        textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);
                        textEndOfTime.setString("Time: " + std::to_string(seconds) + "s");
                        game = true;
                        pause = false;
                        pause1 = false;
                    }
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
                    }
                    else if ((game != true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 280 && cursor_mouse.getPosition().y < 380) || (game == true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 390 && cursor_mouse.getPosition().y < 490))
                    {
                        settings = true;
                    }
                    else if ((game == false && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 410 && cursor_mouse.getPosition().y < 510) || (game == true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 510 && cursor_mouse.getPosition().y < 610))
                    {
                        instruction = true;
                    }
                    else if ((game == false && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 540 && cursor_mouse.getPosition().y < 640) || (game == true && cursor_mouse.getPosition().x > 400 && cursor_mouse.getPosition().x < 800 && cursor_mouse.getPosition().y > 630 && cursor_mouse.getPosition().y < 730))
                    {
                        window.close();
                    }
                }
                break;
            case sf::Event::JoystickMoved:
                if (!menu)
                {
                    time = clock.getElapsedTime();
                    if ((sf::Joystick::Axis::Z == event.joystickMove.axis) && (time.asMilliseconds() >= RATE_OF_FIRE) && (p1.getAmmunition() > 0))
                    {
                        if (!end_of_time)
                        {
                            test = true;
                            p1.getAmmunition()--;
                            textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                            speedbar = true;
                            clock3.restart().asMilliseconds();
                        }
                    }
                }
                break;
                //case sf::Event::LostFocus:
                //    break;
                //case sf::Event::GainedFocus:
                //    break;
            }
        }

        if (!p1.getMouse())
        {
            if (event.type == sf::Event::JoystickMoved)
            {
                sf::Vector2f m = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));
                joystick.move(m.x * 0.002, m.y * 0.002);
            }
        }

        if (menu)
        {
            if (cursorMenu)
            {
                p1.setImage(igun02, window);
                joystick.setTexture(&tgun02);
                cursorMenu = false;
            }
            window.clear(sf::Color::White);

            //platformObject[6].create(window);
            //platformObject[7].create(window);
            //platformObject[8].create(window);
            //platformObject[9].create(window);

            window.draw(menu_text);

            window.draw(rec1);
            window.draw(n_game);

            if (game)
            {
                window.draw(rec2);
                window.draw(continue_game);
                rec3.setPosition(400, 390);
                options.setPosition(480, 400);
                window.draw(rec3);
                window.draw(options);
                rec4.setPosition(400, 510);
                manual.setPosition(492, 520);
                window.draw(rec4);
                window.draw(manual);
                rec5.setPosition(400, 630);
                quit.setPosition(533, 640);
                window.draw(rec5);
                window.draw(quit);
            }
            else
            {
                window.draw(rec3);
                window.draw(options);
                window.draw(rec4);
                window.draw(manual);
                window.draw(rec5);
                window.draw(quit);
            }



            if (!p1.getMouse())
            {
                window.draw(joystick);
            }

            window.display();
        }
        else if (settings)
        {

        }
        else if (instruction)
        {

        }
        else
        {
            if (!cursorMenu)
            {
                p1.setImage(igun00, window);
                joystick.setTexture(&tgun01);
                cursorMenu = true;
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
                    textAmmunition.setString("Ammunition: 0/" + p1samu);
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
                    textAmmunition.setString("Ammunition: 0/" + p1samu);
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

            if (test)
            {
                if (p1.getMouse())
                {
                    std::cout << sf::Mouse::getPosition(window).x << ", mouse " << sf::Mouse::getPosition(window).y << std::endl;
                    p1.bullet(window, sf::Mouse::getPosition(window));
                }
                else
                {
                    p1.bullet(window, sf::Vector2i(joystick.getPosition()));
                    std::cout << "d" << std::endl;
                }
                sf::CircleShape circle1 = p1.getBullet();
                Collision collision(circle1);
                sf::CircleShape g1 = goal1->getBody();   //row1
                sf::CircleShape g2 = goal2->getBody();   //row2
                sf::CircleShape g3 = goal3->getBody();   //row3

                if (collision.checkCollision(g1, 1))
                {
                    score(p1.getScore(), 1);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g2, 2))
                {
                    score(p1.getScore(), 2);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }
                else if (collision.checkCollision(g3, 3))
                {
                    score(p1.getScore(), 3);
                    textScore.setString("Score: " + std::to_string(p1.getScore()));
                    hit = true;
                }

                test = false;
                b1 = true;
            }

            if (p1.getAmmunition() > 0 && !end_of_time)
            {
                if (tv == 0 && focus)
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
                            joystick.move(rmx, rmy);
                    }
                    else
                    {
                        int rmx = (rand() % p1_v) * -1;
                        int rmy = (rand() % p1_v) * -1;
                        if (p1.getMouse())
                            sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
                        else
                            joystick.move(rmx, rmy);
                    }

                    tv = p1.getTimeV();
                }
                else if (tv != 0 && focus)
                {
                    tv--;
                }

                if (b1)
                {
                    p1.bullet_delete();
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
                if (speedbar && clock3.getElapsedTime() < speedb)
                {
                    tym = clock3.getElapsedTime().asMilliseconds() - tym;
                    int change = tym / RATE_OF_FIRE * count;
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

                if (!p1.getMouse())
                {
                    window.draw(joystick);
                }

                window.draw(textScore);
                window.draw(textAmmunition);
                window.draw(textEndOfTime);
                if (p1.getMouse())
                    window.draw(textM);
                else
                    window.draw(textC);

                window.display();
            }
            else
            {
                if (cursorEndGame)
                {
                    window.setMouseCursor(c);
                    joystick.setTexture(&tgun02);
                    cursorEndGame = false;
                    end_of_time1 = false;
                    game = false;
                }

                window.clear();

                int check = clock2.getElapsedTime().asMilliseconds();
                if (check >= tspeed.asMilliseconds() * 30)
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

                platformObject[6].create(window);
                platformObject[7].create(window);
                platformObject[8].create(window);
                platformObject[9].create(window);

                platformObject[10].create(window);

                window.draw(textEnd);

                if (!p1.getMouse())
                {
                    window.draw(joystick);
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