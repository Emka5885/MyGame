#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collision.h"

class Player
{
private:
	sf::Cursor c1;
	sf::Image* image;
	sf::CircleShape* b;
	int vibrations;
	int ammunition;
	int score1;
	int tv;

public:
	Player(sf::Image* image, int vibrations, float ammunition, sf::RenderWindow& win, int tv);
	~Player();

	void create(sf::RenderWindow& win);
	void bullet_delete();
	void bullet(sf::RenderWindow& win, sf::Vector2i positionm);
	sf::CircleShape getBullet();
	int& getScore();
	int& getAmmunition();
	int& getVibrations();
	int getTimeV();
};
