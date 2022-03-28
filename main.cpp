//My first game :)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <SFML\Graphics.hpp>
#include "MyFunctions.h"
#include "Goal.h"
#include "Platform.h"

const int SPEED = 3;

void score();
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

    //Tekstury do animacji celu
    std::vector<sf::Texture> goalTextures;

    sf::Texture goal01;
    if (!goal01.loadFromFile("Goal/Bunny01.png"))
    {
        std::cout << "ErrorGB01" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal02;
    if (!goal01.loadFromFile("Goal/Bunny02.png"))
    {
        std::cout << "ErrorGB02" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal03;
    if (!goal01.loadFromFile("Goal/Bunny03.png"))
    {
        std::cout << "ErrorGB03" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal04;
    if (!goal01.loadFromFile("Goal/Bunny04.png"))
    {
        std::cout << "ErrorGB04" << std::endl;
        system("PAUSE");
    }
    sf::Texture goal05;
    if (!goal01.loadFromFile("Goal/Bunny05.png"))
    {
        std::cout << "ErrorGB05" << std::endl;
        system("PAUSE");
    }

    goalTextures.push_back(goal01);
    goalTextures.push_back(goal02);
    goalTextures.push_back(goal03);
    goalTextures.push_back(goal04);
    goalTextures.push_back(goal05);

    Goal* goal1, * goal2, * goal3;

    srand(time(NULL));

    sf::Texture tg123;
    if (!tg123.loadFromFile("red.png"))
    {
        std::cout << "Errorg123" << std::endl;
        system("PAUSE");
    }

    goal1 = new Goal(&tg123, 1, 0, rand() % 1000);
    goal2 = new Goal(&tg123, 2, 0, rand() % 1000);
    goal3 = new Goal(&tg123, 3, 0, rand() % 1000);

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

    sf::Clock clock;
    window.setFramerateLimit(SPEED);

    sf::Time time;

    while (window.isOpen())
    {
        sf::Event event;
        clock.restart().asSeconds();
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            }
        }

        if (!goal1->existence())
        {
            delete goal1;
            goal1 = new Goal(&tg123, 1, 0, rand() % 1000);
        }
        if (!goal2->existence())
        {
            delete goal2;
            goal2 = new Goal(&tg123, 2, 0, rand() % 1000);
        }
        if (!goal3->existence())
        {
            delete goal3;
            goal3 = new Goal(&tg123, 3, 0, rand() % 1000);
        }

        goal1->move();
        goal2->move();
        goal3->move();


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

        window.display();

        time = clock.getElapsedTime();
    }

    system("PAUSE");
    return 0;
}