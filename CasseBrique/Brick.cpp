#include "Brick.h"

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	this->rectangle->setPosition(x, y);
	//this->rectangle->setOrigin(width / 2, height);
}

Brick::~Brick()
{
}
