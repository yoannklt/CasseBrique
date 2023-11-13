#include "MovingObject.h"
#include <SFML/Graphics.hpp>

#include "../utils/Maths.h"
#include <iostream>

MovingObject::MovingObject(float x, float y, float width, float height, float orientationX, float orientationY) : GameObject(x, y, width, height)
{
	this->orientation = Maths::normalize(sf::Vector2f({ orientationX, orientationY }));
}

void MovingObject::update(float deltaTime)
{
	this->position.x += this->orientation.x * this->speed * deltaTime;
	this->position.y += this->orientation.y * this->speed * deltaTime;
	this->shape->setPosition(this->position.x+this->shape->getOrigin().x, this->position.y + this->shape->getOrigin().y);
}

