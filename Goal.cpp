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
			body.setPosition((x), 700);
			break;
		case 2:
			body.setPosition((x), 450);
			break;
		case 3:
			body.setPosition((x), 200);
			break;
		}
	}
	else {
		x = rand() % 1000 + 50;
		switch (this->row)
		{
		case 1:
			body.setPosition((x), 700);
			break;
		case 2:
			body.setPosition((x), 450);
			break;
		case 3:
			body.setPosition((x), 200);
			break;
		}
	}
}

Goal::Goal(sf::Texture* texture, int row, int number, int count, int r)
{
	this->row = row;
	this->number = number;
	this->count = count;

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

int Goal::move()
{
	//if (right)
	//{
	//	switch (this->row)
	//	{
	//	case 1:
	//		switch (this->number)
	//		{
	//		case 1:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(90, -60);
	//				break;
	//			case 2:
	//				body.move(65, -75);
	//				break;
	//			case 3:
	//				body.move(40, -100);
	//				break;
	//			}
	//			break;

	//		case 2:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(60, -50);
	//				break;
	//			case 2:
	//				body.move(40, -65);
	//				break;
	//			case 3:
	//				body.move(25, -85);
	//				break;
	//			}
	//			break;

	//		case 3:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(30, -40);
	//				break;
	//			case 2:
	//				body.move(15, -60);
	//				break;
	//			case 3:
	//				body.move(10, -65);
	//				break;
	//			}
	//			break;

	//		case 4:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(30, 40);
	//				break;
	//			case 2:
	//				body.move(15, 60);
	//				break;
	//			case 3:
	//				body.move(10, 65);
	//				break;
	//			}
	//			break;

	//		case 5:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(60, 50);
	//				break;
	//			case 2:
	//				body.move(40, 65);
	//				break;
	//			case 3:
	//				body.move(25, 85);
	//				break;
	//			}
	//			break;

	//		case 6:
	//			switch (this->hight)
	//			{
	//			case 1:
	//				body.move(90, 60);
	//				break;
	//			case 2:
	//				body.move(65, 75);
	//				break;
	//			case 3:
	//				body.move(40, 100);
	//				break;
	//			}
	//			break;
	//		}
	//	}
	//}
	//else {
	//}

	return this->number++;
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
