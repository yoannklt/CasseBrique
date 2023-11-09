#include "MovingObject.h"
#include <SFML/Graphics.hpp>

#include "../utils/Maths.h"

MovingObject::MovingObject(float x, float y, float width, float height, float directionX, float directionY) : GameObject(x, y, width, height)
{
	this->shape = new sf::RectangleShape(sf::Vector2f(width, height));
	this->shape->setPosition(x, y);
	
	this->direction = Maths::normalize(sf::Vector2f({ directionX, directionY }));
}

MovingObject::~MovingObject()
{
}

void MovingObject::update(float deltaTime)
{
	this->position.x += this->direction.x * this->speed * deltaTime;
	this->position.y += this->direction.y * this->speed * deltaTime;
	this->shape->setPosition(this->position.x, this->position.y);
}

void MovingObject::setDirection(float directionX, float directionY) {
	this->direction.x = directionX;
	this->direction.y = directionY;
}
