#include <iostream>
#include "Collision.h"

class Player
{
private:
	sf::Image* image;
	sf::Texture* texture;
	sf::CircleShape* b;
	sf::RectangleShape sbm;
	sf::RectangleShape sbc;
	int vibrations;
	int ammunition;
	int ammunitionb;
	int score;
	int tv;
	int select;
	sf::Cursor c1;
	sf::RectangleShape rec;

public:
	Player(sf::Image* image, sf::Texture* texture, int vibrations, int ammunition, sf::RenderWindow& win, int tv, int select);
	~Player();

	void create(sf::RenderWindow& win);
	void bullet_delete();
	void bullet(sf::RenderWindow& win, sf::Vector2i positionm);
	sf::CircleShape getBullet();
	int& getScore();
	int& getAmmunition();
	int& getVibrations();
	int getTimeV();
	int getSelect();
	sf::RectangleShape& getRec();
	void setRecPos(sf::Vector2f Position);
	sf::RectangleShape& getSB();
	void setImage(sf::Image& nimage, sf::RenderWindow& win);
	void setAmmunition(int ammunition);
	void setVibrations(int vibrations);
	void setTimeV(int tv);
	void setSelect(int select);
	void reset();
};