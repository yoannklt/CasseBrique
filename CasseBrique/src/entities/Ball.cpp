#include "Ball.h"

#include <SFML/Graphics.hpp>

Ball::Ball(float x, float y, float radius, float directionX, float directionY) : MovingObject(x, y, radius, radius, directionX, directionY)
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
	float directionTab[2] = { direction.x, direction.y };
	directionTab[side] = -directionTab[side];
	this->direction.x = directionTab[0];
	this->direction.y = directionTab[1];
}

void Ball::update(float deltaTime)
{
	if (position.x + size.x >= 640 or position.x - size.x <= 0)
	{
		direction.x = -direction.x;
		this->speed += 10;
		if (circle->getFillColor() == sf::Color::Green)
			this->circle->setFillColor(sf::Color::White);
		else if (circle->getFillColor() == sf::Color::White)
			this->circle->setFillColor(sf::Color::Green);
	}

	if (position.y + size.y >= 480 or position.y - size.y <= 0)
	{
		direction.y = -direction.y;
		this->speed += 10;
		if (circle->getFillColor() == sf::Color::White)
			this->circle->setFillColor(sf::Color::Green);
		else if (circle->getFillColor() == sf::Color::Green)
			this->circle->setFillColor(sf::Color::White);

	}

	MovingObject::update(deltaTime);
}