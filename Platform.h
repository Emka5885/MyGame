#pragma once
#include <SFML\Graphics.hpp>

class Platform
{
private:
	sf::RectangleShape rec;

public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void create(sf::RenderWindow& window);
};

