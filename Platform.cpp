#include "Platform.h"

Platform::Platform(sf::Color* c, sf::Vector2f size, sf::Vector2f position)
{
	rec.setSize(size);
	rec.setFillColor(*c);
	rec.setPosition(position);
}

Platform::~Platform()
{
}

void Platform::create(sf::RenderWindow& window)
{
	window.draw(rec);
}