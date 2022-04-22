#include "Player.h"

Player::Player(sf::Image* image, sf::Texture* texture, int vibrations, int ammunition, sf::RenderWindow& win, int tv, int select)
{
	this->vibrations = vibrations;
	this->select = select;
	this->ammunition = ammunition;
	this->ammunitionb = ammunition;
	this->score = 0;
	this->image = image;
	this->texture = texture;
	this->tv = tv;
	this->sbm.setSize({ 10, 600 });
	this->sbm.setFillColor(sf::Color::Red);
	this->sbc.setSize({ 10, 600 });
	this->sbc.setFillColor(sf::Color::Red);

	c1.loadFromPixels(this->image->getPixelsPtr(), this->image->getSize(), {});
	win.setMouseCursor(c1);
	this->sbm.setPosition(20, 100);

	rec.setSize(sf::Vector2f(texture->getSize()));
	rec.setTexture(texture);
	rec.setOrigin(rec.getSize().x / 2, rec.getSize().y / 2);
	rec.setPosition(sf::Vector2f(win.getSize().x / 2, win.getSize().y / 2));
	win.draw(rec);
	this->sbc.setPosition(1170, 100);


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
	switch (select)
	{
	case 1:
		b->setPosition(positionm.x + image->getSize().x / 2 - b->getRadius(), positionm.y + image->getSize().y / 2 - b->getRadius());
		break;
	case 2:
		b->setPosition(positionm.x + texture->getSize().x / 2 - b->getRadius(), positionm.y + texture->getSize().y / 2 - b->getRadius());
		break;
	case 3:
		break;
	}
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

int Player::getSelect()
{
	return this->select;
}

sf::RectangleShape& Player::getRec()
{
	return this->rec;
}

sf::RectangleShape& Player::getSB()
{
	switch (select)
	{
	case 1:
		return this->sbm;
		break;
	case 2:
		return this->sbc;
		break;
	case 3:
		break;
	}
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

void Player::setSelect(int select)
{
	this->select = select;
}

void Player::reset()
{
	score = 0;
	ammunition = ammunitionb;
}