#include "Collision.h"

Collision::Collision(sf::CircleShape& cir1)
	: cir1(cir1)
{
}

Collision::~Collision()
{
}

bool Collision::checkCollision(sf::CircleShape& cir2, int row)
{
	if (cir1.getPosition().x < 50 || cir1.getPosition().x > 1150)
	{
		return false;
	}
	if (row == 1)
	{
		//500 744
		if (cir1.getPosition().y < 500 || cir1.getPosition().y > 744)
		{
			return false;
		}
	}
	else if (row == 2)
	{
		//252 494
		if (cir1.getPosition().y < 252 || cir1.getPosition().y > 494)
		{
			return false;
		}
	}
	else if (row == 3)
	{
		//50 246
		if (cir1.getPosition().y < 50 || cir1.getPosition().y > 246)
		{
			return false;
		}
	}

	float dx = (cir1.getPosition().x - cir2.getPosition().x);
	float dy = (cir1.getPosition().y - cir2.getPosition().y);
	float dz = std::sqrt(pow(dx, 2) + pow(dy, 2));
	std::cout << dz << std::endl;

	if (dz <= cir1.getRadius() + cir2.getRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}
