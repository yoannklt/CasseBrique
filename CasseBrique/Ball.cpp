#include "Ball.h"



Ball::Ball(float x, float y, float radius) : MovingObject(x, y, radius, radius)
{
	this->circle = new sf::CircleShape(radius);
	this->circle->setPosition(x, y);
}

Ball::~Ball()
{
	delete this->circle;
}


void Ball::bounce(int side)
{
	this->direction[side] = -direction[side];
}

void Ball::update(float deltaTime)
{
	if (position[0] + size[0] * 2 >= 640 or position[0] <= 0)
	{
		direction[0] = -direction[0];
		if (circle->getFillColor() == sf::Color::Green)
			this->circle->setFillColor(sf::Color::White);
		else if (circle->getFillColor() == sf::Color::White) 
			this->circle->setFillColor(sf::Color::Green); 
	}
	
	if (position[1] + size[1] * 2 >= 480 or position[1] <= 0)
	{
		direction[1] = -direction[1];
		if (circle->getFillColor() == sf::Color::White)
			this->circle->setFillColor(sf::Color::Green);
		else if (circle->getFillColor() == sf::Color::White)
			this->circle->setFillColor(sf::Color::Green);

	}

	MovingObject::update(deltaTime);
	
}

void Ball::updateShape()
{
	this->circle->setPosition(position[0], position[1]);
}

