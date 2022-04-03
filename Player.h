#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::Cursor c1;
	sf::Image image;
	sf::CircleShape* b;
	float vibrations;
	float ammunition;

public:
	Player(sf::Image* image, float vibrations, float ammunition, sf::RenderWindow& win);
	~Player();

	void create(sf::RenderWindow& win);
	void bullet_delete();
	void bullet(sf::RenderWindow& win, sf::Vector2i positionm);
};
