#include "GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
{
	this->position[0] = x;
	this->position[1] = y;
	this->size[0] = width;
	this->size[1] = height;
}

GameObject::~GameObject()
{

}

void GameObject::setPosition(float xpos, float ypos)
{
	this->position[0] = xpos;
	this->position[1] = ypos;
}

float GameObject::convertRadiansToDegrees(float radianAngle)
{
	float degreeAngle = radianAngle * 180 / 3.14;
	return degreeAngle;
}
