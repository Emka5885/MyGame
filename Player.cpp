#include "Player.h"

Player::Player(sf::Image* image, float vibrations, float ammunition, sf::RenderWindow& win)
{
	this->vibrations = vibrations;
	this->ammunition = ammunition;
	this->score1 = 0;

	c1.loadFromPixels(image->getPixelsPtr(), image->getSize(), {});
	win.setMouseCursor(c1);

	b = new sf::CircleShape(2);
}

Player::~Player()
{
}

void Player::create(sf::RenderWindow& win)
{
	win.setMouseCursor(c1);
}

void Player::bullet_delete()
{
	delete b;
}

void Player::bullet(sf::RenderWindow& win, sf::Vector2i positionm)
{
	b = new sf::CircleShape(2);
	b->setFillColor(sf::Color(255, 0, 0));
	b->setPosition(positionm.x, positionm.y);
	win.draw(*b);
}

sf::CircleShape Player::getBullet()
{
	return *this->b;
}

int& Player::getScore()
{
	return this->score1;
}

int& Player::getAmmunition()
{
	return this->ammunition;
}