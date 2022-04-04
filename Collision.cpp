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
	float dx = (cir1.getPosition().x + (cir1.getGlobalBounds().width / 2) - cir2.getPosition().x + (cir2.getGlobalBounds().width / 2));
	float dy = (cir1.getPosition().y + (cir1.getGlobalBounds().height / 2) - cir2.getPosition().y + (cir2.getGlobalBounds().height / 2));
	float dz = std::sqrt(pow(dx, 2) + pow(dy, 2));

	if (dz <= (cir1.getGlobalBounds().width / 2) + (cir2.getGlobalBounds().width / 2))
	{
		std::cout << "Yes" << std::endl;
		return true;
	}
	else
	{
		std::cout << "No" << std::endl;

		return false;
	}
}
