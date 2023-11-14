#include "Ball.h"
#include <SFML/Graphics.hpp>
#include "../core/GameManager.h"

Ball::Ball(float x, float y, float diameter, float orientationX, float orientationY) : MovingObject(x, y, diameter, diameter, orientationX, orientationY)
{

	this->shape = new sf::CircleShape(diameter / 2);  //new sf::CircleShape(diameter/2); new sf::RectangleShape({ diameter, diameter });
	this->shape->setPosition(x, y);
	this->shape->setOrigin(diameter/2, diameter/2);
}

Ball::Ball(float x, float y, float radius, float orientationX, float orientationY, sf::Color color) : Ball(x,  y,  radius, orientationX, orientationY)
{
	this->shape->setFillColor(color);
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
	
	if (position.x + size.x >= 640 or position.x <= 0)
	{
		orientation.x = -orientation.x;
	}

	if (position.y + size.y >= 480 or position.y <= 0)
	{
		orientation.y = -orientation.y;
	} 

	MovingObject::update(deltaTime);

	if (position.y + size.y >= 480) {
		GameManager::killGameObject(this);
	}

}

void Ball::onCollision(sf::Vector2f collisionSide) {
	this->bounce(collisionSide.x);
}