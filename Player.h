#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collision.h"

class Player
{
private:
	sf::Cursor c1;
	sf::Image image;
	sf::CircleShape* b;
	float vibrations;
	int ammunition;
	int score1;

public:
	Player(sf::Image* image, float vibrations, float ammunition, sf::RenderWindow& win);
	~Player();

	void create(sf::RenderWindow& win);
	void bullet_delete();
	void bullet(sf::RenderWindow& win, sf::Vector2i positionm);
	sf::CircleShape getBullet();
	int& getScore();
	int& getAmmunition();
};