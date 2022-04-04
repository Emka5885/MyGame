#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

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
	Goal(int row, int number, int r);
	~Goal();

	void setTexture(std::vector<sf::Texture>& goalT);
	void position();
	void move();
	void create(sf::RenderWindow& window);
	bool existence();
	sf::CircleShape getBody();
};

