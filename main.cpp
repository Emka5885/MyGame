//My first game :)

#include <iostream>
#include <SFML\Graphics.hpp>
#include "MyFunctions.h"
#include "Platform.h"

void score();
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);

    Platform plat1(nullptr, sf::Vector2f(1000.0f, 6.0f), sf::Vector2f(100.0f, 744.0f));
    Platform plat2(nullptr, sf::Vector2f(1000.0f, 6.0f), sf::Vector2f(100.0f, 494.0f));
    Platform plat3(nullptr, sf::Vector2f(1000.0f, 6.0f), sf::Vector2f(100.0f, 240.0f));

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

        window.clear();

        plat1.create(window);
        plat2.create(window);
        plat3.create(window);

        window.display();
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
