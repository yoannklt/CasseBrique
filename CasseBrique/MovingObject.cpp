#include "MovingObject.h"

MovingObject::MovingObject(float x, float y, float width, float height) : GameObject( x, y, width,height)
{

}

MovingObject::~MovingObject()
{
}

void MovingObject::update(float deltaTime)
{
	this->position[0] += this->direction[0] * this->speed * deltaTime;
	this->position[1] += this->direction[1] * this->speed * deltaTime;

}

