#include "Collision.h"

Collision::Collision(sf::CircleShape& cir1)
	: cir1(cir1)
{
}

Collision::~Collision()
{
}

bool Collision::checkCollision(sf::CircleShape& cir2)
{
	return false;
}
