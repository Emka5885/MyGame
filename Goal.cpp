#include "Goal.h"

void Goal::position()
{
	int x;
	if (this->right)
	{
		x = rand() % 900 + 100;
		switch (this->row)
		{
		case 1:
			body.setPosition((x), 740);
			break;
		case 2:
			body.setPosition((x), 475);
			break;
		case 3:
			body.setPosition((x), 235);
			break;
		}
	}
	else {
		x = rand() % 1000 + 50;
		switch (this->row)
		{
		case 1:
			body.setPosition((x), 740);
			break;
		case 2:
			body.setPosition((x), 475);
			break;
		case 3:
			body.setPosition((x), 235);
			break;
		}
	}
}

Goal::Goal(sf::Texture* texture, int row, int number, int r)
{
	this->row = row;
	this->number = number;

	body.setTexture(texture);

	srand((time(NULL) + r));

	int random = rand() % 2;

	if (random == 0)
	{
		this->right = true;
	}
	else {
		this->right = false;
	}

	if (this->row == 1)
	{
		body.setRadius(100);
	}
	else if (this->row == 2)
	{
		body.setRadius(75);
	}
	else if (this->row == 3)
	{
		body.setRadius(50);
	}

	this->hight = rand() % 3 + 1;

	position();
}

Goal::~Goal()
{
}

void Goal::move()
{
	if (right)
	{
		switch (this->row)
		{
		case 1:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(rand() % 60 + 10, -(rand() % 50 + 40));
				break;
			case 2:
				body.move(rand() % 60 + 20, -(rand() % 40 + 30));
				break;
			case 3:
				body.move(rand() % 60 + 30, -(rand() % 30 + 20));
				break;
			case 4:
				body.move(rand() % 60 + 30, (rand() % 30 + 20));
				break;
			case 5:
				body.move(rand() % 60 + 20, (rand() % 40 + 30));
				break;
			case 6:
				body.move(rand() % 60 + 10, (rand() % 50 + 40));
				break;
			}
			break;

		case 2:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(rand() % 55 + 10, -(rand() % 50 + 40));
				break;
			case 2:
				body.move(rand() % 55 + 20, -(rand() % 40 + 30));
				break;
			case 3:
				body.move(rand() % 55 + 30, -(rand() % 30 + 20));
				break;
			case 4:
				body.move(rand() % 55 + 30, (rand() % 30 + 20));
				break;
			case 5:
				body.move(rand() % 55 + 20, (rand() % 40 + 30));
				break;
			case 6:
				body.move(rand() % 55 + 10, (rand() % 50 + 40));
				break;
			}
			break;

		case 3:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(rand() % 50 + 10, -(rand() % 50 + 30));
				break;
			case 2:
				body.move(rand() % 50 + 20, -(rand() % 40 + 20));
				break;
			case 3:
				body.move(rand() % 50 + 30, -(rand() % 30 + 10));
				break;
			case 4:
				body.move(rand() % 50 + 30, (rand() % 30 + 10));
				break;
			case 5:
				body.move(rand() % 50 + 20, (rand() % 40 + 20));
				break;
			case 6:
				body.move(rand() % 50 + 10, (rand() % 50 + 30));
				break;
			}
			break;
		}
	}
	else {
		switch (this->row)
		{
		case 1:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(-(rand() % 60 + 10), -(rand() % 50 + 40));
				break;
			case 2:
				body.move(-(rand() % 60 + 20), -(rand() % 40 + 30));
				break;
			case 3:
				body.move(-(rand() % 60 + 30), -(rand() % 30 + 20));
				break;
			case 4:
				body.move(-(rand() % 60 + 30), (rand() % 30 + 20));
				break;
			case 5:
				body.move(-(rand() % 60 + 20), (rand() % 40 + 30));
				break;
			case 6:
				body.move(-(rand() % 60 + 10), (rand() % 50 + 40));
				break;
			}
			break;

		case 2:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(-(rand() % 55 + 10), -(rand() % 50 + 40));
				break;
			case 2:
				body.move(-(rand() % 55 + 20), -(rand() % 40 + 30));
				break;
			case 3:
				body.move(-(rand() % 55 + 30), -(rand() % 30 + 20));
				break;
			case 4:
				body.move(-(rand() % 55 + 30), (rand() % 30 + 20));
				break;
			case 5:
				body.move(-(rand() % 55 + 20), (rand() % 40 + 30));
				break;
			case 6:
				body.move(-(rand() % 55 + 10), (rand() % 50 + 40));
				break;
			}
			break;

		case 3:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				body.move(-(rand() % 50 + 10), -(rand() % 50 + 30));
				break;
			case 2:
				body.move(-(rand() % 50 + 20), -(rand() % 40 + 20));
				break;
			case 3:
				body.move(-(rand() % 50 + 30), -(rand() % 30 + 10));
				break;
			case 4:
				body.move(-(rand() % 50 + 30), (rand() % 30 + 10));
				break;
			case 5:
				body.move(-(rand() % 50 + 20), (rand() % 40 + 20));
				break;
			case 6:
				body.move(-(rand() % 50 + 10), (rand() % 50 + 30));
				break;
			}
			break;
		}
	}

	this->number++;
}

void Goal::create(sf::RenderWindow& window)
{
	window.draw(body);
}

bool Goal::existence()
{
	if (this->number == 7)
		return false;
	else
		return true;
}
