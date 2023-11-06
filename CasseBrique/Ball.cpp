#include "Ball.h"

Ball::Ball(float x, float y, float radius) : MovingObject(x, y, radius, radius)
{
	this->circle = new sf::CircleShape(radius);
}

Ball::~Ball()
{
	delete this->circle;
}

void Ball::updateShape()
{
	this->circle->setPosition(position[0], position[1]);
}

