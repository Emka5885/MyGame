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
