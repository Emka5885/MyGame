#pragma once
#include <SFML\Graphics.hpp>

class Player
{
private:
	sf::RectangleShape body;
	const sf::Vector2f size;
	float vibrations;
	float ammunition;

public:
	Player(sf::Texture* texture, float vibrations, float size, float ammunition, sf::RenderWindow& win);
	~Player();

	void position(float x, float y);
	void create(sf::RenderWindow& win);
	void bullet(sf::RenderWindow& win, float x, float y);
};
