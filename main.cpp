//My first game :)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML\Graphics.hpp>
#include "MyFunctions.h"
#include "Goal.h"
#include "Platform.h"
#include "Player.h"

const int SPEED = 200;
const int RATE_OF_FIRE = 1400;
float count = 0;
bool test = false;
bool b1 = false;

void score();
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

    //Tekstury do animacji celu
    std::vector<sf::Texture> goalTextures;

    sf::Texture goal00;
    if (!goal00.loadFromFile("Goal/Bunny00.png"))
    {
        std::cout << "ErrorGB00" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goal00);

    sf::Texture goal01;
    if (!goal01.loadFromFile("Goal/Bunny01.png"))
    {
        std::cout << "ErrorGB01" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal02;
    if (!goal02.loadFromFile("Goal/Bunny02.png"))
    {
        std::cout << "ErrorGB02" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal03;
    if (!goal03.loadFromFile("Goal/Bunny03.png"))
    {
        std::cout << "ErrorGB03" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal04;
    if (!goal04.loadFromFile("Goal/Bunny04.png"))
    {
        std::cout << "ErrorGB04" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal05;
    if (!goal05.loadFromFile("Goal/Bunny05.png"))
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
    if (!goal01r.loadFromFile("Goal/Bunny01r.png"))
    {
        std::cout << "ErrorGB01r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal02r;
    if (!goal02r.loadFromFile("Goal/Bunny02r.png"))
    {
        std::cout << "ErrorGB02r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal03r;
    if (!goal03r.loadFromFile("Goal/Bunny03r.png"))
    {
        std::cout << "ErrorGB03r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal04r;
    if (!goal04r.loadFromFile("Goal/Bunny04r.png"))
    {
        std::cout << "ErrorGB04r" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal05r;
    if (!goal05r.loadFromFile("Goal/Bunny05r.png"))
    {
        std::cout << "ErrorGB05r" << std::endl;
        system("PAUSE");
    }
    goalTextures.push_back(goal01r);
    goalTextures.push_back(goal02r);
    goalTextures.push_back(goal03r);
    goalTextures.push_back(goal04r);
    goalTextures.push_back(goal05r);


    Goal* goal1, * goal2, * goal3;

    srand(time(NULL));

    goal1 = new Goal(1, 0, rand() % 1000);
    goal2 = new Goal(2, 0, rand() % 1000);
    goal3 = new Goal(3, 0, rand() % 1000);
    goal1->setTexture(goalTextures);
    goal2->setTexture(goalTextures);
    goal3->setTexture(goalTextures);

    sf::Texture tplat123;
    if (!tplat123.loadFromFile("white.png"))
    {
        std::cout << "Errorp123" << std::endl;
        system("PAUSE");
    }
    sf::Texture tplat456;
    if (!tplat456.loadFromFile("black.png"))
    {
        std::cout << "Errorp456" << std::endl;
        system("PAUSE");
    }

    Platform plat1(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 744.0f));
    Platform plat2(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 494.0f));
    Platform plat3(&tplat123, sf::Vector2f(1100.0f, 6.0f), sf::Vector2f(50.0f, 246.0f));
    Platform plat4(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 500.0f));
    Platform plat5(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 250.0f));
    Platform plat6(&tplat456, sf::Vector2f(1100.0f, 250.0f), sf::Vector2f(50.0f, 0.0f));


    sf::Image tgun00;
    if (!tgun00.loadFromFile("Gun/gun00.png"))
    {
        std::cout << "Errorg00" << std::endl;
        system("PAUSE");
    }

    sf::Mouse::setPosition(sf::Vector2i((window.getSize().x / 2), (window.getSize().y / 2)), window);
    Player p1(&tgun00, 0, 40, window);

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
                break;
            case sf::Event::MouseButtonPressed:
                time = clock.getElapsedTime();
                if ((sf::Mouse::Button::Left == event.mouseButton.button) && (time.asMilliseconds() >= RATE_OF_FIRE))
                {
                    test = true;
                    std::cout << time.asMilliseconds() << std::endl;   //Linijka do usunięcia!!!
                }
                break;
                //case sf::Event::LostFocus:
                //    break;
                //case sf::Event::GainedFocus:
                //    break;
            }
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
            goal1->setTexture(goalTextures);
        }
        if (!goal2->existence())
        {
            delete goal2;
            goal2 = new Goal(2, 0, rand() % 1000);
            goal2->setTexture(goalTextures);
        }
        if (!goal3->existence())
        {
            delete goal3;
            goal3 = new Goal(3, 0, rand() % 1000);
            goal3->setTexture(goalTextures);
        }

        if (count == SPEED)
        {
            goal1->setTexture(goalTextures);
            goal2->setTexture(goalTextures);
            goal3->setTexture(goalTextures);
            count = 0;
            goal1->move();
            goal2->move();
            goal3->move();
        }
        else
        {
            count++;
        }

        window.clear();

        plat6.create(window);
        goal3->create(window);
        plat3.create(window);

        plat5.create(window);
        goal2->create(window);
        plat2.create(window);

        plat4.create(window);
        goal1->create(window);
        plat1.create(window);

        if (test)
        {
            p1.bullet(window, sf::Mouse::getPosition(window));
            test = false;
            b1 = true;
        }

        window.display();
    }

    system("PAUSE");
    return 0;
}