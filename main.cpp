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
const int RATE_OF_FIRE = 1000;
float count = 0;
int tv;
bool test = false;
bool b1 = false;
bool hit = false;
bool end = true;
bool focus = true;

void score(int& s, int row);
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

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

    sf::Image tgun00;
    if (!tgun00.loadFromFile("Resources/Gun/gun00.png"))
    {
        std::cout << "Errorg00" << std::endl;
        system("PAUSE");
    }

    sf::Font font;
    if (!font.loadFromFile("Resources/Font/MilkyNice.ttf"))
    {
        std::cout << "Errorf00" << std::endl;
        system("PAUSE");
    }

    sf::Text textScore;
    textScore.setFont(font);
    textScore.setString("Score: 0");
    textScore.setCharacterSize(40);
    textScore.setFillColor(sf::Color::White);
    textScore.setPosition(51, 20);

    sf::Text textAmmunition;
    textAmmunition.setFont(font);
    textAmmunition.setCharacterSize(40);
    textAmmunition.setFillColor(sf::Color::White);
    textAmmunition.setPosition(351, 20);

    sf::Text textEnd;
    textEnd.setFont(font);
    textEnd.setCharacterSize(100);

    sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
    Player p1(&tgun00, 4, 20, window, SPEED * 2);
    tv = p1.getTimeV();
    std::string p1samu = std::to_string(p1.getAmmunition());
    textAmmunition.setString("Ammunition: " + p1samu + "/" + p1samu);

    sf::Clock clock;
    clock.restart().asMilliseconds();
    sf::Time time;

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
            case sf::Event::MouseEntered:
                p1.create(window);
                focus = true;
                break;
            case sf::Event::MouseLeft:
                focus = false;
                break;
            case sf::Event::MouseButtonPressed:
                time = clock.getElapsedTime();
                if ((sf::Mouse::Button::Left == event.mouseButton.button) && (time.asMilliseconds() >= RATE_OF_FIRE) && (p1.getAmmunition() > 0))
                {
                    test = true;
                    std::cout << time.asMilliseconds() << std::endl;   //Linijka do usunięcia!!!
                    p1.getAmmunition()--;
                    std::cout << "amu " << p1.getAmmunition() << std::endl;
                    textAmmunition.setString("Ammunition: " + std::to_string(p1.getAmmunition()) + "/" + p1samu);
                }
                break;
                //case sf::Event::LostFocus:
                //    break;
                //case sf::Event::GainedFocus:
                //    break;
            }
        }

        if (tv == 0 && focus)
        {
            int p1_v = p1.getVibrations();
            int yes_or_no = rand() % 2;
            if (yes_or_no == 0)
            {
                int rmx = (rand() % p1_v);
                int rmy = (rand() % p1_v);
                sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
            }
            else
            {
                int rmx = (rand() % p1_v) * -1;
                int rmy = (rand() % p1_v) * -1;
                sf::Mouse::setPosition({ sf::Mouse::getPosition().x + rmx, sf::Mouse::getPosition().y + rmy });
            }

            tv = p1.getTimeV();
        }
        else if (tv != 0 && focus)
        {
            tv--;
        }

        if (test)
        {
            std::cout << sf::Mouse::getPosition(window).x << ", mouse " << sf::Mouse::getPosition(window).y << std::endl;
            p1.bullet(window, sf::Mouse::getPosition(window));
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

        if (p1.getAmmunition() > 0)
        {
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

            if (count == SPEED)
            {
                goal1->setTexture(goalTextures, hit);
                goal2->setTexture(goalTextures, hit);
                goal3->setTexture(goalTextures, hit);
                count = 0;
                goal1->move(hit);
                goal2->move(hit);
                goal3->move(hit);
            }
            else
            {
                count++;
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

            window.draw(textScore);
            window.draw(textAmmunition);

            window.display();
        }
        else
        {
            window.clear();

            if (count == 5000)
            {
                if (end)
                {
                    textEnd.setString("End");
                    textEnd.setFillColor(sf::Color::Red);
                    textEnd.setPosition(350, 350);
                    end = false;
                }
                else
                {
                    textEnd.setString("Game");
                    textEnd.setFillColor(sf::Color::Black);
                    textEnd.setPosition(600, 350);
                    end = true;
                }
                count = 0;
            }
            else
            {
                count++;
            }

            platformObject[6].create(window);
            platformObject[7].create(window);
            platformObject[8].create(window);
            platformObject[9].create(window);

            platformObject[10].create(window);

            window.draw(textEnd);

            window.draw(textScore);
            window.draw(textAmmunition);

            window.display();
        }
    }

    system("PAUSE");
    return 0;
}