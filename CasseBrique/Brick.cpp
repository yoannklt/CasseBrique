#include "Brick.h"
#include "Ball.h"

Brick::Brick(float x, float y, float width, float height) : GameObject(x, y, width, height)
{
	this->rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
}

Brick::~Brick()
{
	delete this->rectangle;
}
