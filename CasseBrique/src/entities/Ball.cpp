#include "Ball.h"
#include <SFML/Graphics.hpp>

Ball::Ball(float x, float y, float radius, float orientationX, float orientationY) : MovingObject(x, y, radius, radius, orientationX, orientationY)
{
	this->shape = new sf::CircleShape(radius);
	this->shape->setPosition(x, y);
	this->shape->setOrigin(radius, radius);
}

Ball::~Ball()
{
}


void Ball::bounce(int side)
{
	float orientationTab[2] = { orientation.x, orientation.y };
	orientationTab[side] = -orientationTab[side];
	this->orientation.x = orientationTab[0];
	this->orientation.y = orientationTab[1];
}

void Ball::update(float deltaTime)
{
	if (position.x + size.x >= 640 or position.x - size.x <= 0)
	{
		orientation.x = -orientation.x;
		this->speed += 10;
		if (shape->getFillColor() == sf::Color::Green)
			this->shape->setFillColor(sf::Color::White);
		else if (shape->getFillColor() == sf::Color::White)
			this->shape->setFillColor(sf::Color::Green);
	}

	if (position.y + size.y >= 480 or position.y - size.y <= 0)
	{
		orientation.y = -orientation.y;
		this->speed += 10;

		if (shape->getFillColor() == sf::Color::White)
			this->shape->setFillColor(sf::Color::Green);
		else if (shape->getFillColor() == sf::Color::Green)
			this->shape->setFillColor(sf::Color::White);

	}

	MovingObject::update(deltaTime);
}