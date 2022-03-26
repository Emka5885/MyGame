//My first game :)

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SFML\Graphics.hpp>
//#include "windows.h"
#include "MyFunctions.h"
#include "Goal.h"
#include "Platform.h"

const int SPEED = 1;
int num1 = 1;
int num2 = 1;
int num3 = 1;

void score();
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

    Goal *goal1, *goal2, *goal3;

    srand(time(NULL));

    sf::Texture tg123;
    if (!tg123.loadFromFile("red.png"))
    {
        std::cout << "Errorg123" << std::endl;
        system("PAUSE");
    }

    goal1 = new Goal(&tg123, 1, num1, 0, rand() % 1000);
    goal2 = new Goal(&tg123, 2, num2, 0, rand() % 1000);
    goal3 = new Goal(&tg123, 3, num3, 0, rand() % 1000);

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
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            }
        }

        //if (!goal1->existence())
        //{
        //    delete goal1;
        //    goal1 = new Goal(&tg123, 1, num1, 0, rand() % 1000);
        //}
        //if (!goal2->existence())
        //{
        //    delete goal2;
        //    goal2 = new Goal(&tg123, 2, num2, 0, rand() % 1000);
        //}
        //if (!goal3->existence())
        //{
        //    delete goal3;
        //    goal3 = new Goal(&tg123, 3, num3, 0, rand() % 1000);
        //}

        //num1 = goal1->move();
        //num2 = goal2->move();
        //num3 = goal3->move();
        

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

        //Sleep(1000);
    }

    system("PAUSE");
    return 0;
}
