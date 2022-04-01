#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class Collision
{
private:
	sf::CircleShape& cir1;

public:
	Collision(sf::CircleShape& cir1);
	~Collision();

	bool checkCollision(sf::CircleShape& cir2);
};
