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
			body.setPosition((x), 800);
			break;
		case 2:
			body.setPosition((x), 525);
			break;
		case 3:
			body.setPosition((x), 285);
			break;
		}
	}
	else {
		x = rand() % 1000 + 50;
		switch (this->row)
		{
		case 1:
			body.setPosition((x), 800);
			break;
		case 2:
			body.setPosition((x), 525);
			break;
		case 3:
			body.setPosition((x), 285);
			break;
		}
	}
}

Goal::Goal(int row, int number, int r)
{
	this->stop = false;
	this->row = row;
	this->number = number;

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
	body.setOutlineColor(sf::Color(0, 0, 0));
	body.setOutlineThickness(1);
	body.setOrigin(body.getRadius(), body.getRadius());

	this->hight = rand() % 3 + 1;

	position();
}

Goal::~Goal()
{
}

void Goal::setTexture(std::vector<sf::Texture>& goalT, bool hit)
{
	if (hit == false)
	{
		if (!this->right)
		{
			switch (this->number)
			{
				//1
			case 5:
				this->body.setTexture(&goalT[1]);
				break;
			case 6:
				this->body.setTexture(&goalT[1]);
				break;
			case 7:
				this->body.setTexture(&goalT[1]);
				break;
			case 8:
				this->body.setTexture(&goalT[1]);
				break;
			case 9:
				this->body.setTexture(&goalT[1]);
				break;
				//2
			case 10:
				this->body.setTexture(&goalT[2]);
				break;
			case 11:
				this->body.setTexture(&goalT[2]);
				break;
			case 12:
				this->body.setTexture(&goalT[2]);
				break;
			case 13:
				this->body.setTexture(&goalT[2]);
				break;
			case 14:
				this->body.setTexture(&goalT[2]);
				break;
				//3
			case 15:
				this->body.setTexture(&goalT[3]);
				break;
			case 16:
				this->body.setTexture(&goalT[3]);
				break;
			case 17:
				this->body.setTexture(&goalT[3]);
				break;
			case 18:
				this->body.setTexture(&goalT[3]);
				break;
			case 19:
				this->body.setTexture(&goalT[3]);
				break;
				//4
			case 20:
				this->body.setTexture(&goalT[4]);
				break;
			case 21:
				this->body.setTexture(&goalT[4]);
				break;
			case 22:
				this->body.setTexture(&goalT[4]);
				break;
			case 23:
				this->body.setTexture(&goalT[4]);
				break;
			case 24:
				this->body.setTexture(&goalT[4]);
				break;
				//5
			case 25:
				this->body.setTexture(&goalT[5]);
				break;
			case 26:
				this->body.setTexture(&goalT[5]);
				break;
			case 27:
				this->body.setTexture(&goalT[5]);
				break;
			case 28:
				this->body.setTexture(&goalT[5]);
				break;
			case 29:
				this->body.setTexture(&goalT[5]);
				break;
			default:
				this->body.setTexture(&goalT[0]);
			}
		}
		else
		{
			switch (this->number)
			{
				//1
			case 5:
				this->body.setTexture(&goalT[6]);
				break;
			case 6:
				this->body.setTexture(&goalT[6]);
				break;
			case 7:
				this->body.setTexture(&goalT[6]);
				break;
			case 8:
				this->body.setTexture(&goalT[6]);
				break;
			case 9:
				this->body.setTexture(&goalT[6]);
				break;
				//2
			case 10:
				this->body.setTexture(&goalT[7]);
				break;
			case 11:
				this->body.setTexture(&goalT[7]);
				break;
			case 12:
				this->body.setTexture(&goalT[7]);
				break;
			case 13:
				this->body.setTexture(&goalT[7]);
				break;
			case 14:
				this->body.setTexture(&goalT[7]);
				break;
				//3
			case 15:
				this->body.setTexture(&goalT[8]);
				break;
			case 16:
				this->body.setTexture(&goalT[8]);
				break;
			case 17:
				this->body.setTexture(&goalT[8]);
				break;
			case 18:
				this->body.setTexture(&goalT[8]);
				break;
			case 19:
				this->body.setTexture(&goalT[8]);
				break;
				//4
			case 20:
				this->body.setTexture(&goalT[9]);
				break;
			case 21:
				this->body.setTexture(&goalT[9]);
				break;
			case 22:
				this->body.setTexture(&goalT[9]);
				break;
			case 23:
				this->body.setTexture(&goalT[9]);
				break;
			case 24:
				this->body.setTexture(&goalT[9]);
				break;
				//5
			case 25:
				this->body.setTexture(&goalT[10]);
				break;
			case 26:
				this->body.setTexture(&goalT[10]);
				break;
			case 27:
				this->body.setTexture(&goalT[10]);
				break;
			case 28:
				this->body.setTexture(&goalT[10]);
				break;
			case 29:
				this->body.setTexture(&goalT[10]);
				break;
			default:
				this->body.setTexture(&goalT[0]);
			}
		}
	}
	else
	{
		this->body.setTexture(&goalT[11]);
		this->stop = true;
	}
}

void Goal::move(bool& hit)
{
	if (hit == false)
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
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(rand() % 12 + 2, -(rand() % 10 + 8));
					break;
				case 6:
					body.move(rand() % 12 + 2, -(rand() % 10 + 8));
					break;
				case 7:
					body.move(rand() % 12 + 2, -(rand() % 10 + 8));
					break;
				case 8:
					body.move(rand() % 12 + 2, -(rand() % 10 + 8));
					break;
				case 9:
					body.move(rand() % 12 + 2, -(rand() % 10 + 8));
					break;
					//2
				case 10:
					body.move(rand() % 12 + 4, -(rand() % 8 + 6));
					break;
				case 11:
					body.move(rand() % 12 + 4, -(rand() % 8 + 6));
					break;
				case 12:
					body.move(rand() % 12 + 4, -(rand() % 8 + 6));
					break;
				case 13:
					body.move(rand() % 12 + 4, -(rand() % 8 + 6));
					break;
				case 14:
					body.move(rand() % 12 + 4, -(rand() % 8 + 6));
					break;
					//3
				case 15:
					body.move(rand() % 12 + 6, -(rand() % 6 + 4));
					break;
				case 16:
					body.move(rand() % 12 + 6, -(rand() % 6 + 4));
					break;
				case 17:
					body.move(rand() % 12 + 6, -(rand() % 6 + 4));
					break;
				case 18:
					body.move(rand() % 12 + 6, -(rand() % 6 + 4));
					break;
				case 19:
					body.move(rand() % 12 + 6, -(rand() % 6 + 4));
					break;
					//4
				case 20:
					body.move(rand() % 12 + 6, (rand() % 6 + 4));
					break;
				case 21:
					body.move(rand() % 12 + 6, (rand() % 6 + 4));
					break;
				case 22:
					body.move(rand() % 12 + 6, (rand() % 6 + 4));
					break;
				case 23:
					body.move(rand() % 12 + 6, (rand() % 6 + 4));
					break;
				case 24:
					body.move(rand() % 12 + 6, (rand() % 6 + 4));
					break;
					//5
				case 25:
					body.move(rand() % 12 + 4, (rand() % 8 + 6));
					break;
				case 26:
					body.move(rand() % 12 + 4, (rand() % 8 + 6));
					break;
				case 27:
					body.move(rand() % 12 + 4, (rand() % 8 + 6));
					break;
				case 28:
					body.move(rand() % 12 + 4, (rand() % 8 + 6));
					break;
				case 29:
					body.move(rand() % 12 + 4, (rand() % 8 + 6));
					break;
					//6
				case 30:
					body.move(rand() % 12 + 2, (rand() % 10 + 8));
					break;
				case 31:
					body.move(rand() % 12 + 2, (rand() % 10 + 8));
					break;
				case 32:
					body.move(rand() % 12 + 2, (rand() % 10 + 8));
					break;
				case 33:
					body.move(rand() % 12 + 2, (rand() % 10 + 8));
					break;
				case 34:
					body.move(rand() % 12 + 2, (rand() % 10 + 8));
					break;
				}
				break;

			case 2:
				switch (this->number)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(rand() % 11 + 2, -(rand() % 10 + 8));
					break;
				case 6:
					body.move(rand() % 11 + 2, -(rand() % 10 + 8));
					break;
				case 7:
					body.move(rand() % 11 + 2, -(rand() % 10 + 8));
					break;
				case 8:
					body.move(rand() % 11 + 2, -(rand() % 10 + 8));
					break;
				case 9:
					body.move(rand() % 11 + 2, -(rand() % 10 + 8));
					break;
					//2
				case 10:
					body.move(rand() % 11 + 4, -(rand() % 8 + 6));
					break;
				case 11:
					body.move(rand() % 11 + 4, -(rand() % 8 + 6));
					break;
				case 12:
					body.move(rand() % 11 + 4, -(rand() % 8 + 6));
					break;
				case 13:
					body.move(rand() % 11 + 4, -(rand() % 8 + 6));
					break;
				case 14:
					body.move(rand() % 11 + 4, -(rand() % 8 + 6));
					break;
					//3
				case 15:
					body.move(rand() % 11 + 6, -(rand() % 6 + 4));
					break;
				case 16:
					body.move(rand() % 11 + 6, -(rand() % 6 + 4));
					break;
				case 17:
					body.move(rand() % 11 + 6, -(rand() % 6 + 4));
					break;
				case 18:
					body.move(rand() % 11 + 6, -(rand() % 6 + 4));
					break;
				case 19:
					body.move(rand() % 11 + 6, -(rand() % 6 + 4));
					break;
					//4
				case 20:
					body.move(rand() % 11 + 6, (rand() % 6 + 4));
					break;
				case 21:
					body.move(rand() % 11 + 6, (rand() % 6 + 4));
					break;
				case 22:
					body.move(rand() % 11 + 6, (rand() % 6 + 4));
					break;
				case 23:
					body.move(rand() % 11 + 6, (rand() % 6 + 4));
					break;
				case 24:
					body.move(rand() % 11 + 6, (rand() % 6 + 4));
					break;
					//5
				case 25:
					body.move(rand() % 11 + 4, (rand() % 8 + 6));
					break;
				case 26:
					body.move(rand() % 11 + 4, (rand() % 8 + 6));
					break;
				case 27:
					body.move(rand() % 11 + 4, (rand() % 8 + 6));
					break;
				case 28:
					body.move(rand() % 11 + 4, (rand() % 8 + 6));
					break;
				case 29:
					body.move(rand() % 11 + 4, (rand() % 8 + 6));
					break;
					//6
				case 30:
					body.move(rand() % 11 + 2, (rand() % 10 + 8));
					break;
				case 31:
					body.move(rand() % 11 + 2, (rand() % 10 + 8));
					break;
				case 32:
					body.move(rand() % 11 + 2, (rand() % 10 + 8));
					break;
				case 33:
					body.move(rand() % 11 + 2, (rand() % 10 + 8));
					break;
				case 34:
					body.move(rand() % 11 + 2, (rand() % 10 + 8));
					break;
				}
				break;

			case 3:
				switch (this->number)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(rand() % 10 + 2, -(rand() % 10 + 6));
					break;
				case 6:
					body.move(rand() % 10 + 2, -(rand() % 10 + 6));
					break;
				case 7:
					body.move(rand() % 10 + 2, -(rand() % 10 + 6));
					break;
				case 8:
					body.move(rand() % 10 + 2, -(rand() % 10 + 6));
					break;
				case 9:
					body.move(rand() % 10 + 2, -(rand() % 10 + 6));
					break;
					//2
				case 10:
					body.move(rand() % 10 + 4, -(rand() % 8 + 4));
					break;
				case 11:
					body.move(rand() % 10 + 4, -(rand() % 8 + 4));
					break;
				case 12:
					body.move(rand() % 10 + 4, -(rand() % 8 + 4));
					break;
				case 13:
					body.move(rand() % 10 + 4, -(rand() % 8 + 4));
					break;
				case 14:
					body.move(rand() % 10 + 4, -(rand() % 8 + 4));
					break;
					//3
				case 15:
					body.move(rand() % 10 + 6, -(rand() % 6 + 2));
					break;
				case 16:
					body.move(rand() % 10 + 6, -(rand() % 6 + 2));
					break;
				case 17:
					body.move(rand() % 10 + 6, -(rand() % 6 + 2));
					break;
				case 18:
					body.move(rand() % 10 + 6, -(rand() % 6 + 2));
					break;
				case 19:
					body.move(rand() % 10 + 6, -(rand() % 6 + 2));
					break;
					//4
				case 20:
					body.move(rand() % 10 + 6, (rand() % 6 + 2));
					break;
				case 21:
					body.move(rand() % 10 + 6, (rand() % 6 + 2));
					break;
				case 22:
					body.move(rand() % 10 + 6, (rand() % 6 + 2));
					break;
				case 23:
					body.move(rand() % 10 + 6, (rand() % 6 + 2));
					break;
				case 24:
					body.move(rand() % 10 + 6, (rand() % 6 + 2));
					break;
					//5
				case 25:
					body.move(rand() % 10 + 4, (rand() % 8 + 4));
					break;
				case 26:
					body.move(rand() % 10 + 4, (rand() % 8 + 4));
					break;
				case 27:
					body.move(rand() % 10 + 4, (rand() % 8 + 4));
					break;
				case 28:
					body.move(rand() % 10 + 4, (rand() % 8 + 4));
					break;
				case 29:
					body.move(rand() % 10 + 4, (rand() % 8 + 4));
					break;
					//6
				case 30:
					body.move(rand() % 10 + 2, (rand() % 10 + 6));
					break;
				case 31:
					body.move(rand() % 10 + 2, (rand() % 10 + 6));
					break;
				case 32:
					body.move(rand() % 10 + 2, (rand() % 10 + 6));
					break;
				case 33:
					body.move(rand() % 10 + 2, (rand() % 10 + 6));
					break;
				case 34:
					body.move(rand() % 10 + 2, (rand() % 10 + 6));
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
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(-(rand() % 12 + 2), -(rand() % 10 + 8));
					break;
				case 6:
					body.move(-(rand() % 12 + 2), -(rand() % 10 + 8));
					break;
				case 7:
					body.move(-(rand() % 12 + 2), -(rand() % 10 + 8));
					break;
				case 8:
					body.move(-(rand() % 12 + 2), -(rand() % 10 + 8));
					break;
				case 9:
					body.move(-(rand() % 12 + 2), -(rand() % 10 + 8));
					break;
					//2
				case 10:
					body.move(-(rand() % 12 + 4), -(rand() % 8 + 6));
					break;
				case 11:
					body.move(-(rand() % 12 + 4), -(rand() % 8 + 6));
					break;
				case 12:
					body.move(-(rand() % 12 + 4), -(rand() % 8 + 6));
					break;
				case 13:
					body.move(-(rand() % 12 + 4), -(rand() % 8 + 6));
					break;
				case 14:
					body.move(-(rand() % 12 + 4), -(rand() % 8 + 6));
					break;
					//3
				case 15:
					body.move(-(rand() % 12 + 6), -(rand() % 6 + 4));
					break;
				case 16:
					body.move(-(rand() % 12 + 6), -(rand() % 6 + 4));
					break;
				case 17:
					body.move(-(rand() % 12 + 6), -(rand() % 6 + 4));
					break;
				case 18:
					body.move(-(rand() % 12 + 6), -(rand() % 6 + 4));
					break;
				case 19:
					body.move(-(rand() % 12 + 6), -(rand() % 6 + 4));
					break;
					//4
				case 20:
					body.move(-(rand() % 12 + 6), (rand() % 6 + 4));
					break;
				case 21:
					body.move(-(rand() % 12 + 6), (rand() % 6 + 4));
					break;
				case 22:
					body.move(-(rand() % 12 + 6), (rand() % 6 + 4));
					break;
				case 23:
					body.move(-(rand() % 12 + 6), (rand() % 6 + 4));
					break;
				case 24:
					body.move(-(rand() % 12 + 6), (rand() % 6 + 4));
					break;
					//5
				case 25:
					body.move(-(rand() % 12 + 4), (rand() % 8 + 6));
					break;
				case 26:
					body.move(-(rand() % 12 + 4), (rand() % 8 + 6));
					break;
				case 27:
					body.move(-(rand() % 12 + 4), (rand() % 8 + 6));
					break;
				case 28:
					body.move(-(rand() % 12 + 4), (rand() % 8 + 6));
					break;
				case 29:
					body.move(-(rand() % 12 + 4), (rand() % 8 + 6));
					break;
					//6
				case 30:
					body.move(-(rand() % 12 + 2), (rand() % 10 + 8));
					break;
				case 31:
					body.move(-(rand() % 12 + 2), (rand() % 10 + 8));
					break;
				case 32:
					body.move(-(rand() % 12 + 2), (rand() % 10 + 8));
					break;
				case 33:
					body.move(-(rand() % 12 + 2), (rand() % 10 + 8));
					break;
				case 34:
					body.move(-(rand() % 12 + 2), (rand() % 10 + 8));
					break;
				}
				break;

			case 2:
				switch (this->number)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(-(rand() % 11 + 2), -(rand() % 10 + 8));
					break;
				case 6:
					body.move(-(rand() % 11 + 2), -(rand() % 10 + 8));
					break;
				case 7:
					body.move(-(rand() % 11 + 2), -(rand() % 10 + 8));
					break;
				case 8:
					body.move(-(rand() % 11 + 2), -(rand() % 10 + 8));
					break;
				case 9:
					body.move(-(rand() % 11 + 2), -(rand() % 10 + 8));
					break;
					//2
				case 10:
					body.move(-(rand() % 11 + 4), -(rand() % 8 + 6));
					break;
				case 11:
					body.move(-(rand() % 11 + 4), -(rand() % 8 + 6));
					break;
				case 12:
					body.move(-(rand() % 11 + 4), -(rand() % 8 + 6));
					break;
				case 13:
					body.move(-(rand() % 11 + 4), -(rand() % 8 + 6));
					break;
				case 14:
					body.move(-(rand() % 11 + 4), -(rand() % 8 + 6));
					break;
					//3
				case 15:
					body.move(-(rand() % 11 + 6), -(rand() % 6 + 4));
					break;
				case 16:
					body.move(-(rand() % 11 + 6), -(rand() % 6 + 4));
					break;
				case 17:
					body.move(-(rand() % 11 + 6), -(rand() % 6 + 4));
					break;
				case 18:
					body.move(-(rand() % 11 + 6), -(rand() % 6 + 4));
					break;
				case 19:
					body.move(-(rand() % 11 + 6), -(rand() % 6 + 4));
					break;
					//4
				case 20:
					body.move(-(rand() % 11 + 6), (rand() % 6 + 4));
					break;
				case 21:
					body.move(-(rand() % 11 + 6), (rand() % 6 + 4));
					break;
				case 22:
					body.move(-(rand() % 11 + 6), (rand() % 6 + 4));
					break;
				case 23:
					body.move(-(rand() % 11 + 6), (rand() % 6 + 4));
					break;
				case 24:
					body.move(-(rand() % 11 + 6), (rand() % 6 + 4));
					break;
					//5
				case 25:
					body.move(-(rand() % 11 + 4), (rand() % 8 + 6));
					break;
				case 26:
					body.move(-(rand() % 11 + 4), (rand() % 8 + 6));
					break;
				case 27:
					body.move(-(rand() % 11 + 4), (rand() % 8 + 6));
					break;
				case 28:
					body.move(-(rand() % 11 + 4), (rand() % 8 + 6));
					break;
				case 29:
					body.move(-(rand() % 11 + 4), (rand() % 8 + 6));
					break;
					//6
				case 30:
					body.move(-(rand() % 11 + 2), (rand() % 10 + 8));
					break;
				case 31:
					body.move(-(rand() % 11 + 2), (rand() % 10 + 8));
					break;
				case 32:
					body.move(-(rand() % 11 + 2), (rand() % 10 + 8));
					break;
				case 33:
					body.move(-(rand() % 11 + 2), (rand() % 10 + 8));
					break;
				case 34:
					body.move(-(rand() % 11 + 2), (rand() % 10 + 8));
					break;
				}
				break;

			case 3:
				switch (this->number)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					//1
				case 5:
					body.move(-(rand() % 10 + 2), -(rand() % 10 + 6));
					break;
				case 6:
					body.move(-(rand() % 10 + 2), -(rand() % 10 + 6));
					break;
				case 7:
					body.move(-(rand() % 10 + 2), -(rand() % 10 + 6));
					break;
				case 8:
					body.move(-(rand() % 10 + 2), -(rand() % 10 + 6));
					break;
				case 9:
					body.move(-(rand() % 10 + 2), -(rand() % 10 + 6));
					break;
					//2
				case 10:
					body.move(-(rand() % 10 + 4), -(rand() % 8 + 4));
					break;
				case 11:
					body.move(-(rand() % 10 + 4), -(rand() % 8 + 4));
					break;
				case 12:
					body.move(-(rand() % 10 + 4), -(rand() % 8 + 4));
					break;
				case 13:
					body.move(-(rand() % 10 + 4), -(rand() % 8 + 4));
					break;
				case 14:
					body.move(-(rand() % 10 + 4), -(rand() % 8 + 4));
					break;
					//3
				case 15:
					body.move(-(rand() % 10 + 6), -(rand() % 6 + 2));
					break;
				case 16:
					body.move(-(rand() % 10 + 6), -(rand() % 6 + 2));
					break;
				case 17:
					body.move(-(rand() % 10 + 6), -(rand() % 6 + 2));
					break;
				case 18:
					body.move(-(rand() % 10 + 6), -(rand() % 6 + 2));
					break;
				case 19:
					body.move(-(rand() % 10 + 6), -(rand() % 6 + 2));
					break;
					//4
				case 20:
					body.move(-(rand() % 10 + 6), (rand() % 6 + 2));
					break;
				case 21:
					body.move(-(rand() % 10 + 6), (rand() % 6 + 2));
					break;
				case 22:
					body.move(-(rand() % 10 + 6), (rand() % 6 + 2));
					break;
				case 23:
					body.move(-(rand() % 10 + 6), (rand() % 6 + 2));
					break;
				case 24:
					body.move(-(rand() % 10 + 6), (rand() % 6 + 2));
					break;
					//5
				case 25:
					body.move(-(rand() % 10 + 4), (rand() % 8 + 4));
					break;
				case 26:
					body.move(-(rand() % 10 + 4), (rand() % 8 + 4));
					break;
				case 27:
					body.move(-(rand() % 10 + 4), (rand() % 8 + 4));
					break;
				case 28:
					body.move(-(rand() % 10 + 4), (rand() % 8 + 4));
					break;
				case 29:
					body.move(-(rand() % 10 + 4), (rand() % 8 + 4));
					break;
					//6
				case 30:
					body.move(-(rand() % 10 + 2), (rand() % 10 + 6));
					break;
				case 31:
					body.move(-(rand() % 10 + 2), (rand() % 10 + 6));
					break;
				case 32:
					body.move(-(rand() % 10 + 2), (rand() % 10 + 6));
					break;
				case 33:
					body.move(-(rand() % 10 + 2), (rand() % 10 + 6));
					break;
				case 34:
					body.move(-(rand() % 10 + 2), (rand() % 10 + 6));
					break;
				}
				break;
			}
		}
	}
	else
	{
		switch (this->row)
		{
		case 1:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
				//1
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
				//2
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
				//3
			case 15:
				break;
			case 16:
				break;
			case 17:
				break;
			case 18:
				break;
			case 19:
				break;
				//4
			case 20:
				body.move(0, (rand() % 6 + 4));
				break;
			case 21:
				body.move(0, (rand() % 6 + 4));
				break;
			case 22:
				body.move(0, (rand() % 6 + 4));
				break;
			case 23:
				body.move(0, (rand() % 6 + 4));
				break;
			case 24:
				body.move(0, (rand() % 6 + 4));
				break;
				//5
			case 25:
				body.move(0, (rand() % 8 + 6));
				break;
			case 26:
				body.move(0, (rand() % 8 + 6));
				break;
			case 27:
				body.move(0, (rand() % 8 + 6));
				break;
			case 28:
				body.move(0, (rand() % 8 + 6));
				break;
			case 29:
				body.move(0, (rand() % 8 + 6));
				break;
				//6
			case 30:
				body.move(0, (rand() % 10 + 8));
				break;
			case 31:
				body.move(0, (rand() % 10 + 8));
				break;
			case 32:
				body.move(0, (rand() % 10 + 8));
				break;
			case 33:
				body.move(0, (rand() % 10 + 8));
				break;
			case 34:
				body.move(0, (rand() % 10 + 8));
				hit = false;
				break;
			}
			break;

		case 2:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
				//1
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
				//2
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
				//3
			case 15:
				break;
			case 16:
				break;
			case 17:
				break;
			case 18:
				break;
			case 19:
				break;
				//4
			case 20:
				body.move(0, (rand() % 6 + 4));
				break;
			case 21:
				body.move(0, (rand() % 6 + 4));
				break;
			case 22:
				body.move(0, (rand() % 6 + 4));
				break;
			case 23:
				body.move(0, (rand() % 6 + 4));
				break;
			case 24:
				body.move(0, (rand() % 6 + 4));
				break;
				//5
			case 25:
				body.move(0, (rand() % 8 + 6));
				break;
			case 26:
				body.move(0, (rand() % 8 + 6));
				break;
			case 27:
				body.move(0, (rand() % 8 + 6));
				break;
			case 28:
				body.move(0, (rand() % 8 + 6));
				break;
			case 29:
				body.move(0, (rand() % 8 + 6));
				break;
				//6
			case 30:
				body.move(0, (rand() % 10 + 8));
				break;
			case 31:
				body.move(0, (rand() % 10 + 8));
				break;
			case 32:
				body.move(0, (rand() % 10 + 8));
				break;
			case 33:
				body.move(0, (rand() % 10 + 8));
				break;
			case 34:
				body.move(0, (rand() % 10 + 8));
				hit = false;
				break;
			}
			break;

		case 3:
			switch (this->number)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
				//1
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
				//2
			case 10:
				break;
			case 11:
				break;
			case 12:
				break;
			case 13:
				break;
			case 14:
				break;
				//3
			case 15:
				break;
			case 16:
				break;
			case 17:
				break;
			case 18:
				break;
			case 19:
				break;
				//4
			case 20:
				body.move(0, (rand() % 6 + 2));
				break;
			case 21:
				body.move(0, (rand() % 6 + 2));
				break;
			case 22:
				body.move(0, (rand() % 6 + 2));
				break;
			case 23:
				body.move(0, (rand() % 6 + 2));
				break;
			case 24:
				body.move(0, (rand() % 6 + 2));
				break;
				//5
			case 25:
				body.move(0, (rand() % 8 + 4));
				break;
			case 26:
				body.move(0, (rand() % 8 + 4));
				break;
			case 27:
				body.move(0, (rand() % 8 + 4));
				break;
			case 28:
				body.move(0, (rand() % 8 + 4));
				break;
			case 29:
				body.move(0, (rand() % 8 + 4));
				break;
				//6
			case 30:
				body.move(0, (rand() % 10 + 6));
				break;
			case 31:
				body.move(0, (rand() % 10 + 6));
				break;
			case 32:
				body.move(0, (rand() % 10 + 6));
				break;
			case 33:
				body.move(0, (rand() % 10 + 6));
				break;
			case 34:
				body.move(0, (rand() % 10 + 6));
				hit = false;
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
	if (this->number == 35)
		return false;
	else
		return true;
}

sf::CircleShape Goal::getBody()
{
	return this->body;
}

bool Goal::getStop()
{
	return this->stop;
}
