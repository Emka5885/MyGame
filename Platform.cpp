#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
	rec.setSize(size);
	rec.setTexture(texture);
	rec.setPosition(position);
}

Platform::~Platform()
{
}

void Platform::create(sf::RenderWindow& window)
{
	window.draw(rec);
}
