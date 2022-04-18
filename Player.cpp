#include "Player.h"

Player::Player(sf::Image* image, sf::Texture* texture, int vibrations, int ammunition, sf::RenderWindow& win, int tv, bool mouse)
{
	this->vibrations = vibrations;
	this->mouse = mouse;
	this->ammunition = ammunition;
	this->ammunitionb = ammunition;
	this->score = 0;
	this->image = image;
	this->texture = texture;
	this->tv = tv;
	this->sb.setSize({ 10, 600 });
	this->sb.setFillColor(sf::Color::Red);

	if (mouse)
	{
		c1.loadFromPixels(this->image->getPixelsPtr(), this->image->getSize(), {});
		win.setMouseCursor(c1);
		this->sb.setPosition(20, 100);
	}
	else
	{
		rec.setSize(sf::Vector2f(texture->getSize()));
		rec.setTexture(texture);
		rec.setOrigin(rec.getSize().x / 2, rec.getSize().y / 2);
		rec.setPosition(sf::Vector2f(win.getSize().x / 2, win.getSize().y / 2));
		win.draw(rec);
		this->sb.setPosition(1170, 100);
	}


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
	b->setOrigin(b->getRadius(), b->getRadius());
	if (mouse)
		b->setPosition(positionm.x + image->getSize().x / 2 - b->getRadius(), positionm.y + image->getSize().y / 2 - b->getRadius());
	else
		b->setPosition(positionm.x + texture->getSize().x / 2 - b->getRadius(), positionm.y + texture->getSize().y / 2 - b->getRadius());
	win.draw(*b);
}

sf::CircleShape Player::getBullet()
{
	return *this->b;
}

int& Player::getScore()
{
	return this->score;
}

int& Player::getAmmunition()
{
	return this->ammunition;
}

int& Player::getVibrations()
{
	return this->vibrations;
}

int Player::getTimeV()
{
	return tv;
}

bool Player::getMouse()
{
	return this->mouse;
}

sf::RectangleShape& Player::getRec()
{
	return this->rec;
}

sf::RectangleShape& Player::getSB()
{
	return this->sb;
}

void Player::setImage(sf::Image& nimage, sf::RenderWindow& win)
{
	image = &nimage;
	c1.loadFromPixels(image->getPixelsPtr(), image->getSize(), {});
	win.setMouseCursor(c1);
}

void Player::setAmmunition(int ammunition)
{
	this->ammunition = ammunition;
	this->ammunitionb = ammunition;
}

void Player::setVibrations(int vibrations)
{
	this->vibrations = vibrations;
}

void Player::setTimeV(int tv)
{
	this->tv = tv;
}

void Player::setMouse(bool mouse)
{
	this->mouse = mouse;
}

void Player::reset()
{
	score = 0;
	ammunition = ammunitionb;
}