#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Goal
{
private:
	sf::CircleShape body;
	int row;
	bool right;
	int number;
	int count;
	int hight;

public:
	Goal(sf::Texture *texture, int row, int number, int r);
	~Goal();

	void position();
	void move();
	void create(sf::RenderWindow& window);
	bool existence();
};

