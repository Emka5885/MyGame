#include "Player.h"

void Player::position(float x, float y)
{
	body.setPosition(x, y);
}

Player::Player(sf::Texture* texture, float vibrations, float size, float ammunition, sf::RenderWindow& win)
	: size(size, size)
{
	this->vibrations = vibrations;
	this->ammunition = ammunition;

	body.setSize(this->size);
	body.setTexture(texture);

	position((win.getSize().x / 2), (win.getSize().y / 2));
}

Player::~Player()
{
}

void Player::create(sf::RenderWindow& win)
{
	win.draw(body);
}

void Player::bullet(sf::RenderWindow& win, float x, float y)
{
	sf::CircleShape bullet(2);
	bullet.setFillColor(sf::Color(255, 0, 0));
	bullet.setPosition(x, y);
	win.draw(bullet);
}
