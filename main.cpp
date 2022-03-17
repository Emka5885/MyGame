//My first game :)

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyFunctions.h"

void score();
void time();

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Title", sf::Style::Close | sf::Style::Titlebar);


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
        window.display();
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
