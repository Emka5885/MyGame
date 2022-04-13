#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
class Menu
{
private:
	int timev;
	int vibrations;
	int ammunition;
	bool two_player;
	const int RATE_OF_FIRE;
	sf::Time ts;
	sf::Time tspeed;
	struct P
	{
		int player;
		bool mouse;
	};

public:
	Menu();
	~Menu();
	void create(sf::RenderWindow& win);

};

