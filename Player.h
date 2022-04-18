#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Collision.h"

class Player
{
private:
	sf::Image* image;
	sf::Texture* texture;
	sf::CircleShape* b;
	sf::RectangleShape sb;
	int vibrations;
	int ammunition;
	int ammunitionb;
	int score;
	int tv;
	bool mouse;
	sf::Cursor c1;
	sf::RectangleShape rec;

public:
	Player(sf::Image* image, sf::Texture* texture, int vibrations, int ammunition, sf::RenderWindow& win, int tv, bool mouse);
	~Player();

	void create(sf::RenderWindow& win);
	void bullet_delete();
	void bullet(sf::RenderWindow& win, sf::Vector2i positionm);
	sf::CircleShape getBullet();
	int& getScore();
	int& getAmmunition();
	int& getVibrations();
	int getTimeV();
	bool getMouse();
	sf::RectangleShape& getRec();
	sf::RectangleShape& getSB();
	void setImage(sf::Image& nimage, sf::RenderWindow& win);
	void setAmmunition(int ammunition);
	void setVibrations(int vibrations);
	void setTimeV(int tv);
	void setMouse(bool mouse);
	void reset();
};
