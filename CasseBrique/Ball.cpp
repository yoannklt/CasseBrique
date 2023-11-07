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


void Ball::bounce()
{

}

void Ball::update(float deltaTime)
{
	MovingObject::update(deltaTime); 
	this->circle->setFillColor(sf::Color::White);
}

void Ball::updateShape()
{
	this->circle->setPosition(position[0], position[1]);
}

