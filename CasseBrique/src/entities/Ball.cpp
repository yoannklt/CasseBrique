#include "Ball.h"

#include <SFML/Graphics.hpp>

Ball::Ball(float x, float y, float radius, float directionX, float directionY) : MovingObject(x, y, radius, radius, directionX, directionY)
{
	this->shape = new sf::CircleShape(radius);
	this->shape->setPosition(x, y);
}

Ball::~Ball()
{
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
		if (shape->getFillColor() == sf::Color::Green)
			this->shape->setFillColor(sf::Color::White);
		else if (shape->getFillColor() == sf::Color::White)
			this->shape->setFillColor(sf::Color::Green);
	}

	if (position.y + size.y >= 480 or position.y - size.y <= 0)
	{
		direction.y = -direction.y;
		this->speed += 10;
		if (shape->getFillColor() == sf::Color::White)
			this->shape->setFillColor(sf::Color::Green);
		else if (shape->getFillColor() == sf::Color::Green)
			this->shape->setFillColor(sf::Color::White);

	}

	MovingObject::update(deltaTime);
}